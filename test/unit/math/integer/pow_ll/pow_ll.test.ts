import { beforeAll, describe, expect, test } from "bun:test";
import { faker } from "@faker-js/faker";
import { compile, randomCases, run_cases } from "@/util";

beforeAll(
    async () => {
        await compile(import.meta.dir, "pow_ll.cpp");
    },
    { timeout: -1 },
);

async function run(x: bigint, n: bigint) {
    return (await runs([[x, n]]))[0];
}

async function runs(inputs: [bigint, bigint][]) {
    const outs = await run_cases(
        import.meta.dir,
        inputs.map(([x, n]) => [x, n]),
    );
    return outs.map((out) => BigInt(out[0]));
}

function pow_ts(x: bigint, n: bigint): bigint {
    return x ** n;
}

test.concurrent("基本ケース", async () => {
    expect(await run(2n, 3n)).toBe(8n);
    expect(await run(3n, 2n)).toBe(9n);
    expect(await run(5n, 1n)).toBe(5n);
    expect(await run(10n, 0n)).toBe(1n);
    expect(await run(1n, 100n)).toBe(1n);
});

test.concurrent("0^n", async () => {
    expect(await run(0n, 5n)).toBe(0n);
    expect(await run(0n, 2n ** 60n)).toBe(0n);
    expect(await run(0n, 0n)).toBe(1n);
});

test.concurrent("n^0", async () => {
    expect(await run(5n, 0n)).toBe(1n);
    expect(await run(2n ** 60n, 0n)).toBe(1n);
    expect(await run(1n, 0n)).toBe(1n);
});

describe("random tests", () => {
    test.concurrent("small random", async () => {
        const inputs: [bigint, bigint][] = [];
        for (let i = 0; i < randomCases; i++) {
            const x = faker.number.bigInt({ min: 0, max: 20 });
            const n = faker.number.bigInt({ min: 0, max: 10 });
            inputs.push([x, n]);
        }
        const results = await runs(inputs);
        const expected = inputs.map(([x, n]) => pow_ts(x, n));
        expect(results).toStrictEqual(expected);
    });

    test.concurrent("overflow wrapping", async () => {
        const inputs: [bigint, bigint][] = [];
        for (let i = 0; i < randomCases; i++) {
            const x = faker.number.bigInt({ min: 2, max: 1000 });
            const n = faker.number.bigInt({ min: 20, max: 50 });
            inputs.push([x, n]);
        }
        const results = await runs(inputs);
        const expected = inputs.map(([x, n]) =>
            BigInt.asUintN(64, pow_ts(x, n)),
        );
        expect(results).toStrictEqual(expected);
    });
});
