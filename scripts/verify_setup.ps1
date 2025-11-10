# Automotive Safety Lab - Setup Verification Script (PowerShell)
# ================================================================
# This script verifies that your development environment is properly
# configured for the ISO 26262 Safety Lab exercises.

Write-Host "`n" -NoNewline
Write-Host "================================================" -ForegroundColor Cyan
Write-Host "  Automotive Safety Lab - Setup Verification" -ForegroundColor Cyan
Write-Host "================================================" -ForegroundColor Cyan
Write-Host ""

$allChecksPass = $true

# Function to check if a command exists
function Test-Command {
    param($Command)
    try {
        if (Get-Command $Command -ErrorAction Stop) {
            return $true
        }
    } catch {
        return $false
    }
}

# Function to print check result
function Write-CheckResult {
    param(
        [string]$Name,
        [bool]$Success,
        [string]$Details = ""
    )
    
    if ($Success) {
        Write-Host "[" -NoNewline
        Write-Host "OK" -ForegroundColor Green -NoNewline
        Write-Host "] $Name" -NoNewline
        if ($Details) {
            Write-Host " - " -NoNewline -ForegroundColor Gray
            Write-Host "$Details" -ForegroundColor Gray
        } else {
            Write-Host ""
        }
    } else {
        Write-Host "[" -NoNewline
        Write-Host "!!" -ForegroundColor Red -NoNewline
        Write-Host "] $Name" -NoNewline
        if ($Details) {
            Write-Host " - " -NoNewline -ForegroundColor Red
            Write-Host "$Details" -ForegroundColor Red
        } else {
            Write-Host ""
        }
        $script:allChecksPass = $false
    }
}

# Check 1: Bazel
Write-Host "`n[BUILD SYSTEM CHECK]" -ForegroundColor Yellow
if (Test-Command "bazel") {
    $bazelVersion = (bazel --version 2>&1) -replace 'bazel ', ''
    Write-CheckResult "Bazel installation" $true "version $bazelVersion"
} else {
    Write-CheckResult "Bazel installation" $false "Not found. Install from https://bazel.build/install"
}

# Check 2: C/C++ Compiler
Write-Host "`n[COMPILER CHECK]" -ForegroundColor Yellow
$compilerFound = $false
$compilerDetails = ""

if (Test-Command "gcc") {
    $gccVersion = (gcc --version 2>&1 | Select-Object -First 1) -replace 'gcc ', '' -replace '\(.*', ''
    Write-CheckResult "GCC compiler" $true "version $gccVersion"
    $compilerFound = $true
} elseif (Test-Command "clang") {
    $clangVersion = (clang --version 2>&1 | Select-Object -First 1) -replace 'clang version ', '' -replace ' .*', ''
    Write-CheckResult "Clang compiler" $true "version $clangVersion"
    $compilerFound = $true
} else {
    Write-CheckResult "C/C++ compiler" $false "Neither GCC nor Clang found. Install MinGW or MSVC"
}

# Check 3: Git
Write-Host "`n[VERSION CONTROL CHECK]" -ForegroundColor Yellow
if (Test-Command "git") {
    $gitVersion = (git --version 2>&1) -replace 'git version ', ''
    Write-CheckResult "Git installation" $true "version $gitVersion"
} else {
    Write-CheckResult "Git installation" $false "Not found. Install from https://git-scm.com/"
}

# Check 4: Project Structure
Write-Host "`n[PROJECT STRUCTURE CHECK]" -ForegroundColor Yellow
$requiredDirs = @("exercises", "docs", "tests", "tools")
$projectRoot = Split-Path -Parent $PSScriptRoot

foreach ($dir in $requiredDirs) {
    $dirPath = Join-Path $projectRoot $dir
    if (Test-Path $dirPath) {
        Write-CheckResult "Directory: $dir" $true
    } else {
        Write-CheckResult "Directory: $dir" $false "Missing"
    }
}

# Check 5: Bazel Configuration
Write-Host "`n[BAZEL CONFIG CHECK]" -ForegroundColor Yellow
$workspaceFile = Join-Path $projectRoot "WORKSPACE"
$buildFile = Join-Path $projectRoot "BUILD"

if (Test-Path $workspaceFile) {
    Write-CheckResult "WORKSPACE file" $true
} else {
    Write-CheckResult "WORKSPACE file" $false "Missing"
}

if (Test-Path $buildFile) {
    Write-CheckResult "BUILD file" $true
} else {
    Write-CheckResult "BUILD file" $false "Missing"
}

# Check 6: Exercise Files
Write-Host "`n[EXERCISE FILES CHECK]" -ForegroundColor Yellow
$exerciseDirs = @(
    "exercises/01_basic_safety",
    "exercises/02_watchdog_timer",
    "exercises/03_memory_protection",
    "exercises/04_redundancy_voting",
    "exercises/05_critical_systems"
)

$exerciseCount = 0
foreach ($exDir in $exerciseDirs) {
    $exPath = Join-Path $projectRoot $exDir
    if (Test-Path $exPath) {
        $exerciseCount++
    }
}

Write-CheckResult "Exercise directories" ($exerciseCount -eq 5) "Found $exerciseCount/5"

# Check 7: Optional Tools
Write-Host "`n[OPTIONAL TOOLS CHECK]" -ForegroundColor Yellow
if (Test-Command "python") {
    $pythonVersion = (python --version 2>&1) -replace 'Python ', ''
    Write-Host "[" -NoNewline
    Write-Host "i" -ForegroundColor Blue -NoNewline
    Write-Host "] Python (optional) - version $pythonVersion" -ForegroundColor Gray
} else {
    Write-Host "[" -NoNewline
    Write-Host "i" -ForegroundColor Blue -NoNewline
    Write-Host "] Python (optional) - Not found (recommended for analysis tools)" -ForegroundColor Gray
}

if (Test-Command "cppcheck") {
    Write-Host "[" -NoNewline
    Write-Host "i" -ForegroundColor Blue -NoNewline
    Write-Host "] cppcheck (optional) - Found (great for static analysis!)" -ForegroundColor Gray
} else {
    Write-Host "[" -NoNewline
    Write-Host "i" -ForegroundColor Blue -NoNewline
    Write-Host "] cppcheck (optional) - Not found (recommended for code quality)" -ForegroundColor Gray
}

# Final Summary
Write-Host "`n================================================" -ForegroundColor Cyan
if ($allChecksPass) {
    Write-Host "  >> Setup Verification: " -NoNewline -ForegroundColor Green
    Write-Host "PASSED" -ForegroundColor Green
    Write-Host "================================================" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "SUCCESS: Your environment is ready!" -ForegroundColor Green
    Write-Host ""
    Write-Host "Next Steps:" -ForegroundColor Yellow
    Write-Host "  1. Read GETTING_STARTED.md for detailed instructions" -ForegroundColor White
    Write-Host "  2. Run: " -NoNewline -ForegroundColor White
    Write-Host "bazel build //exercises/01_basic_safety:all" -ForegroundColor Cyan
    Write-Host "  3. Start learning with Exercise 01!" -ForegroundColor White
    Write-Host ""
    exit 0
} else {
    Write-Host "  >> Setup Verification: " -NoNewline -ForegroundColor Red
    Write-Host "FAILED" -ForegroundColor Red
    Write-Host "================================================" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "WARNING: Some checks failed. Please review the errors above." -ForegroundColor Red
    Write-Host ""
    Write-Host "Need help? Check:" -ForegroundColor Yellow
    Write-Host "  • GETTING_STARTED.md - Installation instructions" -ForegroundColor White
    Write-Host "  • docs/TROUBLESHOOTING.md - Common issues and solutions" -ForegroundColor White
    Write-Host "  • GitHub Issues: https://github.com/rclakmal/automotive-safety-lab/issues" -ForegroundColor White
    Write-Host ""
    exit 1
}
