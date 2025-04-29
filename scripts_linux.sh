#!/bin/bash

# === FUNCTIONS ===
show_menu() {
echo "---------------------------------"
echo " Scripts Menu "
echo "---------------------------------"
echo "c - Recompile project"
echo "r - Run main executable"
echo "t - Run tests via ctest"
echo "q - Quit"
echo "---------------------------------"
}

run_main() {
local exe_path="./build/src/main_exe"

if [[ -x "$exe_path" ]]; then
echo "Running main executable..."
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

ctest_func() {
local build_dir="./build"
echo "Starting test execution using CTest..."

if [[ ! -d "$build_dir" ]]; then
echo "Build directory does not exist. Creating '$build_dir'..."
mkdir -p "$build_dir"
fi

cd "$build_dir" || { echo "Failed to enter build directory."; exit 1; }
echo "Running CTest..."
ctest
cd - >/dev/null || exit
}

recompile() {
local build_dir="./build"
echo "Starting recompilation process..."

if [[ ! -d "$build_dir" ]]; then
echo "Build directory does not exist. Creating '$build_dir'..."
mkdir -p "$build_dir"
fi

cd "$build_dir" || { echo "Failed to enter build directory."; exit 1; }

echo "Cleaning build directory..."
rm -rf ./*

echo "Ensuring necessary subdirectories exist..."
mkdir -p src tests

echo "Configuring the project with CMake..."
cmake ..

if [[ $? -ne 0 ]]; then
echo "CMake configuration failed."
cd - >/dev/null || exit
exit 1
fi

echo "Building the project..."
cmake --build .

if [[ $? -ne 0 ]]; then
echo "Build failed."
cd - >/dev/null || exit
exit 1
fi

cd - >/dev/null || exit
echo "Recompilation completed successfully."
}

quit_program() {
echo "Exiting the script. Goodbye!"
exit 0
}

# === MAIN ===
while true; do
show_menu
read -rp "Enter your choice (r/t/c/q): " choice

case "$choice" in
r|R)
run_main
;;
t|T)
ctest_func
;;
c|C)
recompile
;;
q|Q)
quit_program
;;
*)
echo "Invalid option. Please try again."
;;
esac

echo ""
done