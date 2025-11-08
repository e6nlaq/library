import { beforeAll, describe, expect, test } from "bun:test";
import { faker } from "@faker-js/faker";
import { compile, randomCases, run_cases } from "@/util";

beforeAll(
    async () => {
        await compile(import.meta.dir, "isqrt.cpp");
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

// Tests

test.concurrent("小さい平方数", async () => {
    const cases: bigint[] = [];
    const ans: bigint[] = [];
    for (let i = 1n; i <= 500n; ++i) {
        cases.push(i * i);
        ans.push(i);
    }
    expect(await runs(cases)).toStrictEqual(ans);
});

test.concurrent("負", async () => {
    expect(async () => await run(-1n)).toThrow();
});

test.concurrent.each([
    [4503599761588224n, 67108864n],
    [18014398509481983n, 134217727n],
])("悪意コーナー #%#", async (n, ans) => {
    expect(await run(n)).toBe(ans);
});

describe.each([10, 10 ** 8])("random(min: %i)", (min) => {
    test.concurrent(
        "平方数",
        async () => {
            const cases: bigint[] = [];
            const ans: bigint[] = [];
            for (let _ = 0; _ < randomCases; _++) {
                const n = faker.number.bigInt({ min, max: 10 ** 9 });
                cases.push(n * n);
                ans.push(n);
            }
            expect(await runs(cases)).toStrictEqual(ans);
        },
        { timeout: 15000 },
    );

    test.concurrent.each([1n, 2n, 3n, 4n])(
        "平方数 -%p",
        async (x) => {
            const cases: bigint[] = [];
            const ans: bigint[] = [];
            for (let _ = 0; _ < randomCases; _++) {
                const n = faker.number.bigInt({ min, max: 10 ** 9 });
                cases.push(n * n - x);
                ans.push(n - 1n);
            }
            expect(await runs(cases)).toStrictEqual(ans);
        },
        { timeout: 15000 },
    );

    test.concurrent.each([1n, 2n, 3n, 4n])(
        "平方数 +%p",
        async (x) => {
            const cases: bigint[] = [];
            const ans: bigint[] = [];
            for (let _ = 0; _ < randomCases; _++) {
                const n = faker.number.bigInt({ min, max: 10 ** 9 });
                cases.push(n * n + x);
                ans.push(n);
            }
            expect(await runs(cases)).toStrictEqual(ans);
        },
        { timeout: 15000 },
    );

    test.concurrent(
        "普通の数",
        async () => {
            const cases: bigint[] = [];
            for (let _ = 0; _ < randomCases; _++) {
                const n = faker.number.bigInt({ min, max: 10 ** 18 });
                cases.push(n);
            }

            const ret = await runs(cases);

            for (let i = 0; i < cases.length; i++) {
                const n = cases[i];
                const ans = ret[i];

                expect(ans * ans).toBeLessThanOrEqual(n);
                expect((ans + 1n) ** 2n).toBeGreaterThan(n);
            }
        },
        { timeout: 15000 },
    );
});
