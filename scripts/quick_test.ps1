# Quick Build Test - Verify Bazel build system works (PowerShell)
# ================================================================

Write-Host "`n" -NoNewline
Write-Host "========================================" -ForegroundColor Cyan
Write-Host "  Quick Build Test" -ForegroundColor Cyan
Write-Host "========================================" -ForegroundColor Cyan
Write-Host ""

$projectRoot = Split-Path -Parent $PSScriptRoot
Push-Location $projectRoot

try {
    # Test 1: Build Exercise 01
    Write-Host "📦 Building Exercise 01 (Basic Safety)..." -ForegroundColor Yellow
    $result = bazel build //exercises/01_basic_safety:all 2>&1
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✓ Exercise 01 build successful" -ForegroundColor Green
    } else {
        Write-Host "✗ Exercise 01 build failed" -ForegroundColor Red
        Write-Host $result
        exit 1
    }

    # Test 2: Run violation example
    Write-Host "`n🔍 Testing violation example..." -ForegroundColor Yellow
    $result = bazel run //exercises/01_basic_safety:violation_example 2>&1 | Out-Null
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✓ Violation example runs successfully" -ForegroundColor Green
    } else {
        Write-Host "✗ Violation example failed" -ForegroundColor Red
        exit 1
    }

    # Test 3: Run compliant example
    Write-Host "`n✅ Testing compliant example..." -ForegroundColor Yellow
    $result = bazel run //exercises/01_basic_safety:compliant_example 2>&1 | Out-Null
    if ($LASTEXITCODE -eq 0) {
        Write-Host "✓ Compliant example runs successfully" -ForegroundColor Green
    } else {
        Write-Host "✗ Compliant example failed" -ForegroundColor Red
        exit 1
    }

    # Success
    Write-Host "`n========================================" -ForegroundColor Cyan
    Write-Host "✅ All quick tests passed!" -ForegroundColor Green
    Write-Host "========================================" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "🎉 Your build system is working correctly!" -ForegroundColor Green
    Write-Host ""
    Write-Host "Next steps:" -ForegroundColor Yellow
    Write-Host "  • Run full test suite: bazel test //..."
    Write-Host "  • Start Exercise 01: cd exercises\01_basic_safety"
    Write-Host "  • Read GETTING_STARTED.md for detailed instructions"
    Write-Host ""
    
    exit 0
} finally {
    Pop-Location
}
