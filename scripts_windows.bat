@echo off
setlocal ENABLEEXTENSIONS

:menu
echo ---------------------------------
echo           Scripts
echo ---------------------------------
echo c - Recompile project
echo r - Run main executable
:: echo d - Run tests/test_main.cpp
echo t - Run tests via ctest
echo q - Quit
echo ---------------------------------
set /p choice="Enter your choice (r/t/c/q): "

if /I "%choice%"=="r" goto run_main
if /I "%choice%"=="c" goto recompile
if /I "%choice%"=="t" goto ctest_func
if /I "%choice%"=="q" goto quit
echo Invalid option. Exiting.
exit /b 1

:run_main
set exe_path=build\src\main_exe.exe
if exist "%exe_path%" (
    echo Running main executable...
    "%exe_path%"
) else (
    echo Error: "%exe_path%" not found or not executable.
    exit /b 1
)
goto end

:ctest_func
set build_dir=build
if not exist "%build_dir%" (
    echo Build directory does not exist. Creating "%build_dir%"...
    mkdir "%build_dir%"
)
cd "%build_dir%"
ctest .
cd ..
goto end

:recompile
set build_dir=build
echo Starting recompilation process...
if not exist "%build_dir%" (
    echo Build directory does not exist. Creating "%build_dir%"...
    mkdir "%build_dir%"
)
cd "%build_dir%"
echo Cleaning build directory...
rmdir /s /q . >nul 2>nul
mkdir src
mkdir tests
echo Configuring the project with CMake...
cmake ..
echo Building the project...
cmake --build .
cd ..
echo Recompilation completed successfully.
goto end

:quit
exit /b 0

:end
endlocal
