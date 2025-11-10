#!/usr/bin/env pwsh

[System.String] $TestsDirectory = "./tests" ;
[System.String] $BuildDirectory = "./bin" ;

[System.String] $TestFiles = "$TestsDirectory/test_add.c" ;

# Create build directory if non-existent
if (-not (Test-Path $BuildDirectory)) {
    New-Item -ItemType Directory -Path $BuildDirectory | Out-Null ;
}

Write-Host "Building test runner with Clang.";

clang -Wall -Wextra -Werror "$TestsDirectory/run_tests.c" $TestFiles -o "$BuildDirectory/run_tests.exe" ;

Write-Host "Build completed.";

# Run tests
Write-Host "Running tests...";

& "$BuildDirectory/run_tests.exe"

if ($LASTEXITCODE -ne 0) {
    Write-Error "Some tests failed ❌" ;
    exit 1 ;
}

Write-Host "All tests passed ✅" ;
exit 0 ;
