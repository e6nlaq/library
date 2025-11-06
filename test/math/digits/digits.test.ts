import { beforeAll, describe, expect, test } from "bun:test";
import { faker } from "@faker-js/faker";
import { compile, run_cases,randomCases } from "@/util";

beforeAll(async () => {
	await compile(import.meta.dir, "digits-int.cpp", "int.out");
	await compile(import.meta.dir, "digits-ll.cpp", "ll.out");
});

async function run_int(n: bigint) {
	return (await run_ints([n]))[0];
}

async function run_ints(inputs: bigint[]) {
	const outs = await run_cases(import.meta.dir, inputs.map((n) => [n]),"int.out");
	return outs.map((out) => Number(out[0]));
}

async function run_ll(n: bigint) {
	return (await run_lls([n]))[0];
}

async function run_lls(inputs: bigint[]) {
	const outs = await run_cases(import.meta.dir, inputs.map((n) => [n]),"ll.out");
	return outs.map((out) => Number(out[0]));
}

const to_result=(outs: bigint[])=>outs.map((n)=>(n<0?-n:n).toString().length);

// Tests

const func = [
	["int", run_int, run_ints],
	["ll", run_ll, run_lls],
] as const;

const max = {
	int: 2n ** 30n,
	ll: 2n ** 62n,
};

describe.concurrent.each(func)("%s", (type, f, fs) => {
	test.concurrent("0", async () => {
		expect(await f(0n)).toBe(1);
	});

	test.concurrent(`<=${randomCases.toString()}`, async () => {
		const inputs: bigint[] = [];
		for (let i = 1n; i <= randomCases; i++) {
			inputs.push(i);
		}
		expect(await fs(inputs)).toStrictEqual(to_result(inputs));
	});

	test.concurrent("small random", async () => {
		const inputs: bigint[] = [];
		for (let _ = 0; _ < randomCases; _++) {
			const n = faker.number.bigInt(100000);
			inputs.push(n);
		}
		expect(await fs(inputs)).toStrictEqual(to_result(inputs));
	});

	test.concurrent.each([0n, 1n, 2n, 5n, 10n])("10^n+%p", async (p) => {
		const inputs: bigint[] = [];
		for (let i = 1n; i < (type === "int" ? 9n : 18n); i++) {
			const n = 10n ** i + p;
			inputs.push(n);
		}
		expect(await fs(inputs)).toStrictEqual(to_result(inputs));
	});

	test.concurrent.each([0n, 1n, 2n, 5n, 10n])("2^n+%p", async (p) => {
		const inputs: bigint[] = [];
		for (let i = 1n; i < (type === "int" ? 30n : 62n); i++) {
			const n = 2n ** i + p;
			inputs.push(n);
		}
		expect(await fs(inputs)).toStrictEqual(to_result(inputs));
	});

	test.concurrent("正 random", async () => {
		const inputs: bigint[] = [];
		for (let _ = 0; _ < randomCases; _++) {
			const n = faker.number.bigInt(max[type]);
			inputs.push(n);
		}
		expect(await fs(inputs)).toStrictEqual(to_result(inputs));
	});

	test.concurrent("負 random", async () => {
		const inputs: bigint[] = [];
		for (let _ = 0; _ < randomCases; _++) {
			const n = faker.number.bigInt(max[type]);
			inputs.push(-n);
		}

		const res=await fs(inputs);
		const ac=to_result(inputs);
		for(let i=0;i<res.length;i++){
			expect(res[i],inputs[i].toString()).toBe(ac[i]);
		}
	});
});
