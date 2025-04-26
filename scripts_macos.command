#!/bin/bash

# === FUNCTIONS ===
show_menu() {
echo "---------------------------------"
echo " Scripts "
echo "---------------------------------"
echo "c - Recompile project"
echo "r - Run main executable"
echo "t - Run tests"
echo "q - Quit"
echo "---------------------------------"
}

run_main() {
local exe_path="./build/src/main_exe"

if [[ -x "$exe_path" ]]; then
echo "Running main executable..."
echo ""
"$exe_path"
else
echo "Error: $exe_path not found or not executable."
exit 1
fi
}

run_tests() {
local test_path="./build/tests/tests"
if [[ -x "$test_path" ]]; then
echo "Running tests..."
echo ""
"$test_path"
else
echo "Error: $test_path not found or not executable."
exit 1
fi
}

recompile() {
local build_dir="./build"
echo "Starting recompilation process..."
if [[ ! -d "$build_dir" ]]; then
echo "Build directory does not exist. Creating '$build_dir'..."
mkdir -p "$build_dir"
fi
cd "$build_dir"
echo "Cleaning build directory..."
rm -rf ./*
echo "Ensuring necessary subdirectories exist..."
mkdir -p src tests
echo "Configuring the project with CMake..."
cmake ..
echo "Building the project..."
cmake --build .
cd - >/dev/null
echo "Recompilation completed successfully."
}

quit_program() {
echo ""
exit 0
}

# == MAIN ===
show_menu
read -rp "Enter your choice (r/t/c/q): " choice

case "$choice" in
r|R)
run_main
;;
t|T)
run_tests
;;
c|C)
recompile
;;
q|Q)
quit_program
;;
*)
echo "Invalid option. Exiting."
exit 1
;;
esac

exit 0