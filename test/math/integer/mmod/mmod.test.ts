import { beforeAll, describe, expect, test } from "bun:test";
import { faker } from "@faker-js/faker";
import { compile, randomCases, run_cases } from "@/util";

beforeAll(
    async () => {
        await compile(import.meta.dir, "mmod.cpp");
    },
    { timeout: -1 },
);

async function run(x: bigint, m: bigint) {
    return (await runs([[x, m]]))[0];
}

async function runs(inputs: [bigint, bigint][]) {
    const outs = await run_cases(import.meta.dir, inputs);
    return outs.map((out) => BigInt(out[0]));
}

function mmod_ts(x: bigint, m: bigint): bigint {
    const M = m < 0 ? -m : m;
    if (M === 0n) {
        throw new Error("Division by zero");
    }
    const r = x % M;
    return r < 0n ? r + M : r;
}

// Tests

describe("mmod", () => {
    test.concurrent("正の数同士の剰余", async () => {
        expect(await run(10n, 3n)).toBe(1n);
        expect(await run(10n, 5n)).toBe(0n);
        expect(await run(10n, 7n)).toBe(3n);
    });

    test.concurrent("負の数を含む剰余", async () => {
        // 正の法
        expect(await run(-1n, 5n)).toBe(4n); // -1 ≡ 4 mod 5
        expect(await run(-10n, 7n)).toBe(4n); // -10 ≡ 4 mod 7

        // 負の数に対して正の結果を返す
        expect(await run(10n, -7n)).toBe(3n); // 10 ≡ 3 mod 7
        expect(await run(-10n, -7n)).toBe(4n); // -10 ≡ 4 mod 7
    });

    test.concurrent("法が1の場合は常に0", async () => {
        expect(await run(0n, 1n)).toBe(0n);
        expect(await run(1n, 1n)).toBe(0n);
        expect(await run(-1n, 1n)).toBe(0n);
        expect(await run(100n, 1n)).toBe(0n);
    });

    test.concurrent("大きな値のテスト", async () => {
        const maxSafe = BigInt(Number.MAX_SAFE_INTEGER);
        const minSafe = BigInt(Number.MIN_SAFE_INTEGER);

        // 大きな正の数
        expect(await run(maxSafe, 1000n)).toBe(BigInt(maxSafe % 1000n));

        // 大きな負の数
        expect(await run(minSafe, 1000n)).toBe(
            (1000n + (minSafe % 1000n)) % 1000n,
        );

        // 大きな法
        expect(await run(100n, maxSafe)).toBe(100n);
    });

    test.concurrent("境界値テスト", async () => {
        // 0の剰余
        expect(await run(0n, 10n)).toBe(0n);

        // 法と同じ値
        expect(await run(10n, 10n)).toBe(0n);

        // 法より1小さい負の値
        expect(await run(-1n, 10n)).toBe(9n);
    });

    describe("random tests", () => {
        test.concurrent("small random", async () => {
            const inputs: [bigint, bigint][] = [];
            for (let i = 0; i < randomCases; i++) {
                const x = faker.number.bigInt(100000);
                const m = faker.number.bigInt({ min: 1, max: 100000 });
                inputs.push([x, m]);
            }
            const results = await runs(inputs);
            const expected = inputs.map(([x, m]) => mmod_ts(x, m));
            expect(results).toStrictEqual(expected);
        });

        test.concurrent("large random", async () => {
            const inputs: [bigint, bigint][] = [];
            for (let i = 0; i < randomCases; i++) {
                const x = faker.number.bigInt(2n ** 62n);
                const m = faker.number.bigInt({ min: 1, max: 2n ** 30n });
                inputs.push([x, m]);
                inputs.push([x, -m]);
                inputs.push([-x, m]);
                inputs.push([-x, -m]);
            }
            const results = await runs(inputs);
            const expected = inputs.map(([x, m]) => mmod_ts(x, m));
            expect(results).toStrictEqual(expected);
        });
    });
});
