# Gemini Project: C++ Library with TypeScript Tests

This project is a C++ library that is tested using TypeScript. The library appears to provide various mathematical and algorithmic functionalities.

## Project Structure

- **`include/e6nlaq/`**: Contains the C++ header files for the library.
- **`test/`**: Contains the TypeScript test files.
- **`package.json`**: Defines the project's dependencies and scripts.
- **`bun.lock`**: The lockfile for the Bun package manager.
- **`tsconfig.json`**: The TypeScript configuration file.

## Building and Running

The project uses Bun for package management and testing.

### Running Tests

To run the tests, use the following command:

```bash
bun test
```

The tests will automatically compile the necessary C++ code before running.

## Development Conventions

- **Testing Framework**: The project uses `bun:test` for testing.
- **Test Utilities**: The `test/util.ts` file provides helper functions for compiling and running the C++ code from within the tests.
- **C++ Code**: The C++ source code is organized as a header-only library in the `include` directory.
- **Test Implementation**: Tests are written in TypeScript and are located in the `test` directory. They import the necessary C++ files, compile them, and then run them with various inputs to assert the correctness of the C++ code.
- **Faker.js**: The `@faker-js/faker` library is used to generate random data for testing.
