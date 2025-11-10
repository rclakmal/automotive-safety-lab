# Learning Progress Dashboard (PowerShell)
# =========================================
# Track your journey through the ISO 26262 Safety Lab

$projectRoot = Split-Path -Parent $PSScriptRoot

Write-Host "`n" -NoNewline
Write-Host "╔════════════════════════════════════════════════╗" -ForegroundColor Cyan
Write-Host "║                                                ║" -ForegroundColor Cyan
Write-Host "║    " -NoNewline -ForegroundColor Cyan
Write-Host "Automotive Safety Lab" -NoNewline -ForegroundColor Yellow
Write-Host "                  ║" -ForegroundColor Cyan
Write-Host "║    " -NoNewline -ForegroundColor Cyan
Write-Host "ISO 26262 Learning Progress" -NoNewline -ForegroundColor Gray
Write-Host "             ║" -ForegroundColor Cyan
Write-Host "║                                                ║" -ForegroundColor Cyan
Write-Host "╚════════════════════════════════════════════════╝" -ForegroundColor Cyan
Write-Host ""

# Function to check if exercise is complete
function Test-ExerciseComplete {
    param($ExerciseId)
    
    $exDir = Join-Path $projectRoot "exercises\$ExerciseId"
    
    if (Test-Path $exDir) {
        Push-Location $projectRoot
        try {
            bazel build "//exercises/${ExerciseId}:all" 2>&1 | Out-Null
            if ($LASTEXITCODE -eq 0) {
                return $true
            }
        } catch {
            # Ignore errors
        } finally {
            Pop-Location
        }
    }
    return $false
}

# Exercise definitions
$exercises = @(
    @{Id="01_basic_safety"; Asil="ASIL QM"; Name="Basic Safety Concepts"; Scenario="Battery Monitoring"},
    @{Id="02_watchdog_timer"; Asil="ASIL A"; Name="Watchdog Timer Systems"; Scenario="Engine Control"},
    @{Id="03_memory_protection"; Asil="ASIL B"; Name="Memory Protection"; Scenario="Electronic Brake System"},
    @{Id="04_redundancy_voting"; Asil="ASIL C"; Name="Redundancy & Voting"; Scenario="Power Steering"},
    @{Id="05_critical_systems"; Asil="ASIL D"; Name="Critical Systems"; Scenario="Autonomous Braking"}
)

$totalExercises = $exercises.Count
$completed = 0
$currentExercise = ""

# Check each exercise
foreach ($ex in $exercises) {
    if (Test-ExerciseComplete $ex.Id) {
        Write-Host "✓ " -ForegroundColor Green -NoNewline
        Write-Host "$($ex.Asil)" -ForegroundColor Blue -NoNewline
        Write-Host " - $($ex.Name) ($($ex.Scenario))"
        $completed++
    } else {
        if ($currentExercise -eq "") {
            Write-Host "→ " -ForegroundColor Yellow -NoNewline
            Write-Host "$($ex.Asil)" -ForegroundColor Blue -NoNewline
            Write-Host " - $($ex.Name) ($($ex.Scenario)) " -NoNewline
            Write-Host "← NEXT" -ForegroundColor Yellow
            $currentExercise = $ex.Id
        } else {
            Write-Host "○ " -ForegroundColor Gray -NoNewline
            Write-Host "$($ex.Asil) - $($ex.Name) ($($ex.Scenario))" -ForegroundColor Gray
        }
    }
}

# Progress bar
Write-Host "`nProgress:" -ForegroundColor Cyan
$progressPercent = [math]::Floor(($completed * 100) / $totalExercises)
$barLength = 40
$filledLength = [math]::Floor(($completed * $barLength) / $totalExercises)
$bar = ""
for ($i = 0; $i -lt $barLength; $i++) {
    if ($i -lt $filledLength) {
        $bar += "█"
    } else {
        $bar += "░"
    }
}
Write-Host "[" -NoNewline
Write-Host $bar -ForegroundColor Green -NoNewline
Write-Host "] $completed/$totalExercises exercises ($progressPercent%)"

# Status message
Write-Host ""
if ($completed -eq 0) {
    Write-Host "🚀 Ready to start your journey!" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "Your first step:"
    Write-Host "  cd exercises\01_basic_safety"
    Write-Host "  type README.md"
    Write-Host ""
} elseif ($completed -eq $totalExercises) {
    Write-Host "🎉 Congratulations! You've completed all exercises!" -ForegroundColor Green
    Write-Host ""
    Write-Host "What's next:" -ForegroundColor Yellow
    Write-Host "  • Review your notes and learnings"
    Write-Host "  • Try the integration test suite: bazel test //tests/integration:all"
    Write-Host "  • Apply for ISO 26262 certification"
    Write-Host "  • Contribute back to the project!"
    Write-Host ""
} else {
    Write-Host "💪 Keep going! You're making great progress!" -ForegroundColor Yellow
    Write-Host ""
    Write-Host "Next exercise:"
    Write-Host "  cd exercises\$currentExercise"
    Write-Host "  type README.md"
    Write-Host ""
}

# Quick stats
$hoursInvested = $completed * 4
$hoursRemaining = ($totalExercises - $completed) * 4
Write-Host "═══════════════════════════════════════════════" -ForegroundColor Cyan
Write-Host "Time invested: ~$hoursInvested hours | Remaining: ~$hoursRemaining hours" -ForegroundColor Gray
Write-Host "═══════════════════════════════════════════════" -ForegroundColor Cyan
Write-Host ""
