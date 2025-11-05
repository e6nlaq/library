import { resolve } from "node:path";
import { $ } from "bun";

export async function compile(dir: string, filename: string, out = "a.out") {
	await $`g++-14 ${resolve(dir, filename)} -o ${resolve(dir, out)} --std=c++23`.quiet();
}

export type Input = (number | string | bigint)[];
export async function run_case(dir: string, input: Input, out = "a.out") {
	const res = new Response(input.join(" "));
	const ans = await $`${resolve(dir, out)} < ${res}`.text();

	return ans.trim().split(" ");
}
