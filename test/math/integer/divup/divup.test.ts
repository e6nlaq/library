import { beforeAll, describe, expect, test } from "bun:test";
import { faker } from "@faker-js/faker";
import { compile, randomCases, run_cases } from "@/util";

beforeAll(
    async () => {
        await compile(import.meta.dir, "divup.cpp");
    },
    { timeout: -1 },
);

async function run(a: bigint, b: bigint) {
    return (await runs([[a, b]]))[0];
}

async function runs(inputs: [bigint, bigint][]) {
    const outs = await run_cases(
        import.meta.dir,
        inputs.map(([a, b]) => [a, b]),
    );
    return outs.map((out) => BigInt(out[0]));
}

function divup_ts(a: bigint, b: bigint): bigint {
    const q = a / b;
    const r = a % b;
    if (r === 0n) {
        return q;
    }
    if ((a > 0n && b > 0n) || (a < 0n && b < 0n)) {
        return q + 1n;
    }
    return q;
}

// Tests

test.concurrent("正の数同士の切り上げ除算", async () => {
    expect(await run(10n, 3n)).toBe(4n);
    expect(await run(10n, 5n)).toBe(2n);
    expect(await run(10n, 7n)).toBe(2n);
    expect(await run(1n, 1n)).toBe(1n);
});

test.concurrent("負の数を含む切り上げ除算", async () => {
    expect(await run(-10n, 3n)).toBe(-3n); // -3.333... → -3
    expect(await run(10n, -3n)).toBe(-3n); // -3.333... → -3
    expect(await run(-10n, -3n)).toBe(4n); // 3.333... → 4
});

test.concurrent("割り切れる場合", async () => {
    expect(await run(100n, 10n)).toBe(10n);
    expect(await run(0n, 1n)).toBe(0n);
    expect(await run(0n, 100n)).toBe(0n);
});

test.concurrent("大きな値のテスト", async () => {
    const maxSafe = BigInt(Number.MAX_SAFE_INTEGER);
    // const minSafe = BigInt(Number.MIN_SAFE_INTEGER);
    expect(await run(maxSafe, 2n)).toBe(4503599627370496n);
    // expect(await run(minSafe, -2n)).toBe(4503599627370496n);
});

describe("random tests", () => {
    test.concurrent("small random", async () => {
        const inputs: [bigint, bigint][] = [];
        for (let i = 0; i < randomCases; i++) {
            const a = faker.number.bigInt(100000);
            const b = faker.number.bigInt({ min: 1, max: 100000 });
            inputs.push([a, b]);
        }
        const results = await runs(inputs);
        const expected = inputs.map(([a, b]) => divup_ts(a, b));
        expect(results).toStrictEqual(expected);
    });

    test.concurrent("large random", async () => {
        const inputs: [bigint, bigint][] = [];
        for (let i = 0; i < randomCases; i++) {
            const a = faker.number.bigInt(2n ** 62n);
            const b = faker.number.bigInt({ min: 1, max: 2n ** 30n });
            inputs.push([a, b]);
            inputs.push([a, -b]);
            inputs.push([-a, b]);
            inputs.push([-a, -b]);
        }
        const results = await runs(inputs);
        const expected = inputs.map(([a, b]) => divup_ts(a, b));
        expect(results).toStrictEqual(expected);
    });
});
