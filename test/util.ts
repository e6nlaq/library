import { resolve } from "node:path";
import { $ } from "bun";


export const randomCases = 10000;

export async function compile(dir: string, filename: string, out = "a.out") {
	await $`g++-14 ${resolve(dir, filename)} -o ${resolve(dir, out)} --std=c++23 -I ${resolve(import.meta.dir,"../include")}`.quiet();
}

export type Input = (number | string | bigint)[];
export async function run_case(dir: string, input: Input, out = "a.out") {
	return (await run_cases(dir, [input], out))[0];
}

export async function run_cases(dir: string, inputs: Input[], out = "a.out") {
	const res = new Response(`${inputs.length}\n${inputs.map((input) => input.join(" ")).join("\n")}`);
	const ans = await $`${resolve(dir, out)} < ${res}`.text();

	return ans.trim().split("\n").map((line) => line.trim().split(" "));
}
