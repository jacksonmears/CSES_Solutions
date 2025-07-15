@echo off

g++ -std=c++20 -O2 -o out.exe %1

if %errorlevel% equ 0 (
	echo.
	echo === Program Output ===
	out.exe
)