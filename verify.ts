Bun.spawnSync(["oj-verify", "run"], {
    env: { ...process.env },
    stdout: "inherit",
    stderr: "inherit",
});
