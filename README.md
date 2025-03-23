# Simple Calculator with Unit Testing and Code Coverage

This project implements a basic calculator in C and uses the **Check** unit testing framework to perform unit tests. It also generates code coverage reports using **lcov** and **genhtml**.

## Project Structure

The project consists of the following files:

- `calculator.c`: Implementation of basic calculator functions.
- `calculator.h`: Header file declaring the calculator functions.
- `main.c`: Main file to run the calculator program.
- `test_calculator.c`: Unit tests for the calculator functions using the Check framework.
- `CMakeLists.txt`: CMake configuration file to build the project and run tests.

## Features

- Basic arithmetic operations: addition, subtraction, multiplication, and division.
- Unit tests using the **Check** framework.
- Code coverage reports using **lcov** and **genhtml**.

## Prerequisites

To build and run this project, you need to have the following installed on your machine:

- **gcc**: GNU Compiler Collection.
- **CMake**: Build system generator.
- **Check**: Unit testing framework for C.
- **lcov** and **genhtml**: Code coverage tools.

You can install the necessary dependencies on Ubuntu using:

```bash
sudo apt update
sudo apt install build-essential cmake check libsubunit-dev lcov
```

**Building the Project**
=========================

### Step 1: Clone or Download the Repository

Clone or download the repository to start building the project.

```bash
    # Clone using Git
git clone https://github.com/your-username/project-repo.git

    # Download directly from GitHub
https://github.com/your-username/project-repo/archive/refs/heads/main.zip
```

### Step 2: Create a Build Directory

Create a build directory to store the project's build files.

```bash
mkdir build
cd build
```

### Step 3: Run CMake to Configure the Project

Run `cmake` to configure the project with the desired build settings.

```bash
cmake ..
```

### Step 4: Compile the Project Using Make

Compile the project using `make`.

```bash
make
```

This will build the executable files for both the calculator program and the unit tests.


**Running Unit Tests**
=====================

To run the unit tests, execute the following command:

```bash
./test_calculator
```

This will run the tests and output the results of each test case to the terminal.




### Step 5: Generate Code Coverage Report

#### Enable Coverage during Build

Configure the project with coverage enabled using `cmake`.

```bash
cmake -DCMAKE_BUILD_TYPE=Coverage ..
```

#### Clean the Build Directory and Rebuild

Clean the build directory and rebuild the project to generate coverage data.

```bash
make clean
make
```

#### Run the Unit Tests: Execute the unit tests to collect coverage data:

Execute the unit tests as usual:


#### Generate Coverage Data

Use `lcov` to capture the coverage information.

```bash
lcov --capture --directory . --output-file coverage.info
```

#### Generate HTML Coverage Report

Use `genhtml` to create an HTML report from the coverage data.


    genhtml coverage.info --output-directory out

Open the `out/index.html` file in a web browser to view the code coverage report.

### Cleaning Up

To clean the build directory and remove any generated files, run:

```bash
make clean
```
