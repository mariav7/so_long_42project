#!/bin/bash

# A small script to test different map scenarios, checking minimum requirements and leaks with valgrind

# COLORS
BOLD="\033[1m"
ITALIC="\033[3m"
BLINK="\033[5m"
YELLOW="\e[33m"
RESET="\e[0m"
BLUE="\e[34m"
RED="\e[91m"
GREEN="\e[32m"

# PATHS
NAME="./so_long"
PATH_BADMAPS="./maps/bad_maps/"
FLAGS_VALGRIND="valgrind --leak-check=full --error-exitcode=3"
TEST="$FLAGS_VALGRIND $NAME"

# Function to run tests
run_test() {
    local test_name="$1"
    local test_file="$2"

    echo -e "${BLUE}TESTING: ${test_name}${RESET}\n"
    echo -e "${test_file}\n" && cat "${test_file}"
    echo -e "\n"

    if ${TEST} "${test_file}"; then
        echo -e "\n${BOLD}${RED}[ ✗ ] TEST ${test_name}${RESET}\n\n"
    else
        echo -e "\n${BOLD}${GREEN}[ ✔ ] TEST ${test_name}${RESET}\n\n"
    fi
}

# Check if the program exists, and if not, build it using `make`
if [ ! -e "${NAME}" ]; then
    make
fi

if [ ! -e "${NAME}" ]; then
    echo -e "${RED}Error: Failed to build the program.${RESET}"
    exit 1
fi

# Run error tests
echo -e "\n${YELLOW}. . . RUNNING TESTS . . .${RESET}\n"

run_test "FILE WITH INVALID FILE TYPE" "${PATH_BADMAPS}invalid-file.txt"
run_test "EMPTY MAP" "${PATH_BADMAPS}emptymap.ber"
run_test "MAP WITH INVALID CHARACTERS" "${PATH_BADMAPS}invalid-characters.ber"
run_test "MAP WITH INVALID PATH" "${PATH_BADMAPS}invalid-path.ber"
run_test "MAP TOO LONG TO FIT IN SCREEN" "${PATH_BADMAPS}map_too_long.ber"
run_test "MAP WITHOUT MIN. REQUIREMENTS" "${PATH_BADMAPS}not-min-characters.ber"
run_test "MAP NOT RECTANGULAR" "${PATH_BADMAPS}not-rectangular.ber"
run_test "MAP NOT WALLED" "${PATH_BADMAPS}not-walled.ber"

if [ -e "${NAME}" ]; then
    make fclean
fi