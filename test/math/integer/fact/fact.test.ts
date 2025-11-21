import { beforeAll, describe, expect, test } from "bun:test";
import { compile, run_cases } from "@/util";

beforeAll(
    async () => {
        await compile(import.meta.dir, "fact.cpp");
    },
    { timeout: -1 },
);

async function run(n: bigint) {
    return (await runs([n]))[0];
}

async function runs(inputs: bigint[]) {
    const outs = await run_cases(
        import.meta.dir,
        inputs.map((n) => [n]),
    );
    return outs.map((out) => BigInt(out[0]));
}

function fact_ts(n: bigint): bigint {
    if (n < 0n) {
        throw new Error("n must be non-negative");
    }
    let res = 1n;
    for (let i = 2n; i <= n; i++) {
        res *= i;
    }
    return res;
}

// Tests
describe.concurrent("factorial", () => {
    test.concurrent("0の階乗は1", async () => {
        expect(await run(0n)).toBe(1n);
    });

    test.concurrent("1の階乗は1", async () => {
        expect(await run(1n)).toBe(1n);
    });

    test.concurrent("5の階乗は120", async () => {
        expect(await run(5n)).toBe(120n);
    });

    test.concurrent("10の階乗は3628800", async () => {
        expect(await run(10n)).toBe(3628800n);
    });

    test.concurrent("20の階乗は2432902008176640000", async () => {
        expect(await run(20n)).toBe(2432902008176640000n);
    });

    test.concurrent("0-20の階乗", async () => {
        const inputs: bigint[] = [];
        for (let i = 0n; i <= 20n; i++) {
            inputs.push(i);
        }
        const results = await runs(inputs);
        const expected = inputs.map(fact_ts);
        expect(results).toStrictEqual(expected);
    });
});
