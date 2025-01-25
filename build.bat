@echo off

REM Set environment variables
set OpenCV_DIR=C:\opencv\build
set Qt6_DIR=C:\Qt\6.5.3\msvc2019_64\lib\cmake\Qt6

REM Clean build directory
if exist build (
    echo Cleaning build directory...
    cmake --build build --target clean
) else (
    echo Build directory does not exist. Skipping clean.
)

REM Configure and generate build files
echo Configuring project...
cmake -DCMAKE_PREFIX_PATH=%Qt6_DIR%;%OpenCV_DIR% -S . -B build

REM Build the project
echo Building project...
cmake --build build --config Debug

echo Build completed.