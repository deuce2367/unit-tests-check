cmake_minimum_required(VERSION 3.10)
project(Calculator)

set(CMAKE_C_STANDARD 99)

# Add coverage flags for GCC/Clang
option(ENABLE_COVERAGE "Enable coverage reporting" ON)
if(ENABLE_COVERAGE)
    add_compile_options(--coverage)
    add_link_options(--coverage)
endif()

# Create a shared library for calculator logic
add_library(calculator_lib calculator.c)

# Build the calculator application
add_executable(calculator main.c)
target_link_libraries(calculator calculator_lib)

# Build the test executable
add_executable(test_calculator test_calculator.c)
target_link_libraries(test_calculator calculator_lib check m subunit)

# Enable testing
enable_testing()
add_test(NAME CalculatorTests COMMAND test_calculator)

# Add a custom target for coverage
if(ENABLE_COVERAGE)
    find_program(LCOV_EXEC lcov)
    find_program(GENHTML_EXEC genhtml)

    if(LCOV_EXEC AND GENHTML_EXEC)
        add_custom_target(coverage
            COMMAND ${LCOV_EXEC} --directory . --capture --output-file coverage.info
            COMMAND ${LCOV_EXEC} --remove coverage.info "/usr/*" "*/test_*" --output-file coverage_filtered.info
            COMMAND ${GENHTML_EXEC} --no-function-coverage --no-branch-coverage -o coverage_report coverage_filtered.info
            WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
            COMMENT "Generating coverage report"
            VERBATIM
        )
    else()
        message(WARNING "lcov and/or genhtml not found, coverage target will not be available.")
    endif()
endif()




