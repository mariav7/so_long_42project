#!/bin/bash

# A small script to test different map scenarios, checking minimum requirements and leaks with valgrind

NAME="./so_long"
YELLOW="\e[33m"
RESET="\e[0m"
BLUE="\e[34m"
RED="\e[91m"
GREEN="\e[32m"
PATH_BADMAPS="./maps/bad_maps/"
PATH_MAPS="./maps/"
FLAGS_VALGRIND="valgrind --leak-check=full --error-exitcode=3"
TEST="$FLAGS_VALGRIND $NAME $PATH_BADMAPS"
TEST2="$FLAGS_VALGRIND $NAME $PATH_MAPS"

# Function to run tests
run_test() {
    local test_name="$1"
    local test_file="$2"
    local test_command="$3"

    echo -e "${BLUE}TEST: $test_name${YELLOW}\n"
    cat "$test_file"
    echo -e "${RESET}\n"

    if $test_command "$test_file"; then
        echo -e "\n${GREEN}[ ✔ ] TEST $test_name${RESET}\n\n"
    else
        echo -e "\n${RED}[ ✗ ] TEST $test_name${RESET}\n\n"
    fi
}

# Check if the program exists, and if not, build it using `make`
if [ ! -e "$NAME" ]; then
    make
fi

if [ ! -e "$NAME" ]; then
    echo -e "${RED}Error: Failed to build the program.${RESET}"
    exit 1
fi

echo -e "\n${YELLOW}... RUNNING TESTS ...${RESET}\n"

# Run the specific tests
run_test "MAP 1" "${PATH_MAPS}map1.ber" "$TEST2"
run_test "MAP 2" "${PATH_MAPS}map2.ber" "$TEST2"
run_test "MAP 3" "${PATH_MAPS}map3.ber" "$TEST2"

# Run error tests
echo -e "\n${YELLOW}... RUNNING ERROR TESTS ...${RESET}\n"

run_test "INVALID FILE TYPE" "${PATH_BADMAPS}invalid-file.txt" "$TEST"
run_test "EMPTY MAP" "${PATH_BADMAPS}emptymap.ber" "$TEST"
run_test "INVALID CHARACTERS" "${PATH_BADMAPS}invalid-characters.ber" "$TEST"
run_test "MIN. CHARACTERS" "${PATH_BADMAPS}not-min-characters.ber" "$TEST"
run_test "IS NOT RECTANGULAR" "${PATH_BADMAPS}not-rectangular.ber" "$TEST"
run_test "IS NOT WALLED" "${PATH_BADMAPS}not-walled.ber" "$TEST"
run_test "INVALID PATH" "${PATH_BADMAPS}invalid-path.ber" "$TEST"
