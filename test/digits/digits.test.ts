import { beforeAll, describe, expect, test } from "bun:test";
import { faker } from "@faker-js/faker";
import { compile, run_case } from "../util";

beforeAll(async () => {
	await compile(import.meta.dir, "digits-int.cpp", "int.out");
	await compile(import.meta.dir, "digits-ll.cpp", "ll.out");
});

async function run_int(n: bigint) {
	const out = await run_case(import.meta.dir, [n], "int.out");

	return Number(out[0]);
}

async function run_ll(n: bigint) {
	const out = await run_case(import.meta.dir, [n], "ll.out");

	return Number(out[0]);
}

// Tests

const func = [
	["int", run_int],
	["ll", run_ll],
] as const;

const max = {
	int: 2n ** 30n,
	ll: 2n ** 62n,
};

describe.concurrent.each(func)("%s", (type, f) => {
	test.concurrent("0", async () => {
		expect(await f(0n)).toBe(1);
	});

	const n = 1000n;
	test.concurrent(`<=${n.toString()}`, async () => {
		for (let i = 1n; i <= n; i++) {
			expect(await f(i)).toBe(i.toString().length);
		}
	});

	test.concurrent("small random", async () => {
		for (let _ = 0; _ < 1000; _++) {
			const n = faker.number.bigInt(100000);
			expect(await f(n)).toBe(n.toString().length);
		}
	});

	test.concurrent.each([0n, 1n, 2n, 5n, 10n])("10^n+%p", async (p) => {
		for (let i = 1n; i < (type === "int" ? 9n : 18n); i++) {
			const n = 10n ** i + p;
			expect(await f(n)).toBe(n.toString().length);
		}
	});

	test.concurrent.each([0n, 1n, 2n, 5n, 10n])("2^n+%p", async (p) => {
		for (let i = 1n; i < (type === "int" ? 30n : 62n); i++) {
			const n = 2n ** i + p;
			expect(await f(n)).toBe(n.toString().length);
		}
	});

	test.concurrent("正 random", async () => {
		for (let _ = 0; _ < 1000; _++) {
			const n = faker.number.bigInt(max[type]);
			expect(await f(n)).toBe(n.toString().length);
		}
	});

	test.concurrent("負 random", async () => {
		for (let _ = 0; _ < 1000; _++) {
			const n = faker.number.bigInt(max[type]);
			expect(await f(-n)).toBe(n.toString().length);
		}
	});
});
