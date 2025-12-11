import { expect, test } from "bun:test";
import { parse } from "node:path";
import { Glob } from "bun";
import { compile } from "@/util";

const glob = new Glob("./**/*.cpp");

for await (const file of glob.scan(import.meta.dir)) {
    test.concurrent(parse(file).name, () => {
        expect(async () => {
            await compile(import.meta.dir, parse(file).base);
        }).not.toThrowError();
    });
}
