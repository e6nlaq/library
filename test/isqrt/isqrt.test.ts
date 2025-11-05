import { beforeAll, describe, expect, test } from "bun:test";
import { faker } from "@faker-js/faker";
import { compile, run_case } from "../util";

beforeAll(async () => {
	await compile(import.meta.dir, "isqrt.cpp");
});

async function run(n: bigint) {
	if (-(10n ** 18n) > n || n > 10n ** 18n) {
		throw new Error(`Out of range: ${n}`);
	}

	const out = await run_case(import.meta.dir, [n]);

	return BigInt(out[0]);
}

// Tests

test.concurrent("小さい平方数", async () => {
	for (let i = 1n; i <= 500n; ++i) {
		expect(await run(i * i)).toBe(i);
	}
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

const randomCases = 500;
describe.each([10, 10 ** 8])("random(min: %i)", (min) => {
	test.concurrent(
		"平方数",
		async () => {
			for (let _ = 0; _ < randomCases; _++) {
				const n = faker.number.bigInt({ min, max: 10 ** 9 });
				expect(await run(n * n)).toBe(n);
			}
		},
		{ timeout: 15000 },
	);

	test.concurrent.each([1n, 2n, 3n, 4n])(
		"平方数 -%p",
		async (x) => {
			for (let _ = 0; _ < randomCases; _++) {
				const n = faker.number.bigInt({ min, max: 10 ** 9 });
				expect(await run(n * n - x)).toBe(n - 1n);
			}
		},
		{ timeout: 15000 },
	);

	test.concurrent.each([1n, 2n, 3n, 4n])(
		"平方数 +%p",
		async (x) => {
			for (let _ = 0; _ < randomCases; _++) {
				const n = faker.number.bigInt({ min, max: 10 ** 9 });
				expect(await run(n * n + x)).toBe(n);
			}
		},
		{ timeout: 15000 },
	);

	test.concurrent(
		"普通の数",
		async () => {
			for (let _ = 0; _ < randomCases; _++) {
				const n = faker.number.bigInt({ min, max: 10 ** 18 });
				const ans = await run(n);

				expect(ans * ans).toBeLessThanOrEqual(n);
				expect((ans + 1n) ** 2n).toBeGreaterThan(n);
			}
		},
		{ timeout: 15000 },
	);
});
