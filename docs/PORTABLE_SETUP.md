# 🎒 Portable Setup Guide (No Administrator Rights Required)

> **For Students & Corporate Environments**  
> Complete setup without admin privileges or package managers like Chocolatey

---

## 📋 Overview

This guide helps you set up the Automotive Safety Lab on Windows systems where:
- ❌ You **don't have administrator rights**
- ❌ You **can't install Chocolatey, Scoop, or other package managers**
- ❌ You **can't modify system PATH** permanently
- ✅ You **can download and run portable applications**
- ✅ You **have access to your user directory** (`C:\Users\YourName\`)

**Estimated Setup Time:** 30-45 minutes

---

## 🎯 What We'll Set Up (All Portable)

| Tool | Size | Purpose | Installation Method |
|------|------|---------|---------------------|
| **Bazel** | ~70 MB | Build system | Portable executable |
| **MinGW GCC** | ~350 MB | C/C++ compiler | Portable archive |
| **Git** | ~50 MB | Version control | Portable installer |
| **Git Bash** | Included | Run tutorials | Comes with Git |

**Total Download:** ~470 MB  
**Total Disk Space:** ~800 MB (with extracted files)

---

## 📂 Step 1: Create Your Portable Tools Directory

Create a dedicated folder for all portable tools:

```powershell
# Open PowerShell (no admin needed)
# Create directory structure
New-Item -ItemType Directory -Force -Path "$HOME\PortableTools"
New-Item -ItemType Directory -Force -Path "$HOME\PortableTools\bazel"
New-Item -ItemType Directory -Force -Path "$HOME\PortableTools\mingw64"
New-Item -ItemType Directory -Force -Path "$HOME\PortableTools\git"

# Verify creation
Get-ChildItem "$HOME\PortableTools"
```

**Your structure will look like:**
```
C:\Users\YourName\PortableTools\
├── bazel\
├── mingw64\
└── git\
```

---

## 🔧 Step 2: Install Portable Bazel

### Download Bazel

1. **Visit:** https://github.com/bazelbuild/bazel/releases
2. **Find the latest stable release** (e.g., 7.4.1)
3. **Download:** `bazel-7.4.1-windows-x86_64.exe`
4. **Move to:** `C:\Users\YourName\PortableTools\bazel\`
5. **Rename to:** `bazel.exe`

### Alternative: Using PowerShell (Automated Download)

```powershell
# Download Bazel 7.4.1 (or replace with latest version)
$bazelUrl = "https://github.com/bazelbuild/bazel/releases/download/7.4.1/bazel-7.4.1-windows-x86_64.exe"
$bazelPath = "$HOME\PortableTools\bazel\bazel.exe"

Invoke-WebRequest -Uri $bazelUrl -OutFile $bazelPath
Write-Host "[OK] Bazel downloaded to: $bazelPath"
```

### Verify Installation

```powershell
& "$HOME\PortableTools\bazel\bazel.exe" --version
# Expected: bazel 7.4.1
```

---

## 🔧 Step 3: Install Portable MinGW GCC

### Download MinGW

**Two options available:**

#### Option A: Official MinGW-w64 (Recommended)

1. **Visit:** https://winlibs.com/
2. **Download:** `winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.1-r5.7z`
   - Look for **"GCC 13.2.0 + MinGW-w64 11.0.1 (UCRT) - release 5"**
   - Choose **"Win64 without LLVM/Clang/LLD/LLDB"** (smaller download)
3. **Extract** using 7-Zip or Windows built-in extraction
4. **Move** the extracted `mingw64\` folder to `C:\Users\YourName\PortableTools\mingw64\`

#### Option B: MSYS2 MinGW (Alternative)

1. **Visit:** https://packages.msys2.org/package/mingw-w64-x86_64-gcc
2. **Download:** Latest MinGW GCC package
3. **Extract** to `C:\Users\YourName\PortableTools\mingw64\`

### Alternative: Automated Download (PowerShell)

```powershell
# Download WinLibs MinGW GCC 13.2.0
$mingwUrl = "https://github.com/brechtsanders/winlibs_mingw/releases/download/13.2.0-16.0.6-11.0.0-ucrt-r1/winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64ucrt-11.0.0-r1.7z"
$mingwArchive = "$HOME\Downloads\mingw.7z"
$mingwDest = "$HOME\PortableTools\"

# Note: Requires 7-Zip or Windows 11+ built-in support
Invoke-WebRequest -Uri $mingwUrl -OutFile $mingwArchive
Write-Host "[OK] MinGW downloaded. Extract to: $mingwDest"
Write-Host "[!!] Manual extraction required - use 7-Zip or Windows Explorer"
```

### Verify Installation

```powershell
& "$HOME\PortableTools\mingw64\bin\gcc.exe" --version
# Expected: gcc (GCC) 13.2.0 or similar
```

**Troubleshooting:** If you see "Access Denied" or "Not Found":
- Ensure the path is correct: `mingw64\bin\gcc.exe` should exist
- Check folder permissions (right-click → Properties → Security)

---

## 🔧 Step 4: Install Portable Git with Git Bash

### Download Git Portable

1. **Visit:** https://git-scm.com/download/win
2. **Download:** `PortableGit-2.47.0-64-bit.7z.exe` (self-extracting archive)
3. **Run the executable** (no admin needed)
4. **Extract to:** `C:\Users\YourName\PortableTools\git\`

### Alternative: Direct Download (PowerShell)

```powershell
# Download Git Portable 2.47.0
$gitUrl = "https://github.com/git-for-windows/git/releases/download/v2.47.0.windows.1/PortableGit-2.47.0-64-bit.7z.exe"
$gitInstaller = "$HOME\Downloads\GitPortable.exe"

Invoke-WebRequest -Uri $gitUrl -OutFile $gitInstaller
Write-Host "[OK] Git Portable downloaded to: $gitInstaller"
Write-Host "[!!] Run the installer and extract to: $HOME\PortableTools\git\"
```

### Verify Installation

```powershell
& "$HOME\PortableTools\git\bin\git.exe" --version
# Expected: git version 2.47.0

& "$HOME\PortableTools\git\bin\bash.exe" --version
# Expected: GNU bash, version 5.2.x
```

---

## ⚙️ Step 5: Configure Your Environment (Per Session)

Since you can't modify system PATH permanently, create a **session configuration script**:

### Create `setup_env.ps1`

```powershell
# Create the configuration script
$setupScript = @"
# Automotive Safety Lab - Portable Environment Setup
# Run this script at the start of each PowerShell session

`$env:PORTABLE_TOOLS = "`$HOME\PortableTools"

# Add tools to PATH for this session
`$env:PATH = "`$env:PORTABLE_TOOLS\bazel;" + `$env:PATH
`$env:PATH = "`$env:PORTABLE_TOOLS\mingw64\bin;" + `$env:PATH
`$env:PATH = "`$env:PORTABLE_TOOLS\git\bin;" + `$env:PATH

# Verify setup
Write-Host "`n[PORTABLE ENVIRONMENT]" -ForegroundColor Cyan
Write-Host "Tools directory: `$env:PORTABLE_TOOLS" -ForegroundColor Gray

Write-Host "`nVerifying installations..." -ForegroundColor Yellow
try { 
    `$bazelVer = (bazel --version 2>&1)
    Write-Host "[OK] Bazel: `$bazelVer" -ForegroundColor Green
} catch { 
    Write-Host "[!!] Bazel not found" -ForegroundColor Red 
}

try { 
    `$gccVer = (gcc --version 2>&1 | Select-Object -First 1)
    Write-Host "[OK] GCC: `$gccVer" -ForegroundColor Green
} catch { 
    Write-Host "[!!] GCC not found" -ForegroundColor Red 
}

try { 
    `$gitVer = (git --version 2>&1)
    Write-Host "[OK] Git: `$gitVer" -ForegroundColor Green
} catch { 
    Write-Host "[!!] Git not found" -ForegroundColor Red 
}

try { 
    `$bashVer = (bash --version 2>&1 | Select-Object -First 1)
    Write-Host "[OK] Bash: `$bashVer" -ForegroundColor Green
} catch { 
    Write-Host "[!!] Bash not found" -ForegroundColor Red 
}

Write-Host "`n[READY] Environment configured for Automotive Safety Lab!`n" -ForegroundColor Cyan
"@

# Save the script
$setupScript | Out-File -FilePath "$HOME\PortableTools\setup_env.ps1" -Encoding UTF8
Write-Host "[OK] Environment setup script created: $HOME\PortableTools\setup_env.ps1"
```

### Using the Environment Script

**Every time you open PowerShell to work on the lab:**

```powershell
# Navigate to your portable tools
cd $HOME\PortableTools

# Run the environment setup
.\setup_env.ps1

# Now you can use bazel, gcc, git without full paths
bazel --version
gcc --version
git --version
```

---

## 🚀 Step 6: Clone and Build the Safety Lab

Now that your environment is configured:

```powershell
# 1. Set up environment
cd $HOME\PortableTools
.\setup_env.ps1

# 2. Clone the repository
cd $HOME\Documents
git clone https://github.com/rclakmal/automotive-safety-lab.git
cd automotive-safety-lab

# 3. Verify setup
.\scripts\verify_setup.ps1

# 4. Build first exercise
bazel build //exercises/01_basic_safety:all

# 5. Run violation example (using portable bash)
bash .\exercises\01_basic_safety\tutorial.sh
```

---

## 🎯 Step 7: Create Convenience Shortcuts

### Desktop Shortcut for Quick Start

Create a shortcut that opens PowerShell with the environment already configured:

1. **Right-click Desktop** → New → Shortcut
2. **Target:** 
   ```
   powershell.exe -NoExit -Command "& '$HOME\PortableTools\setup_env.ps1'; cd '$HOME\Documents\automotive-safety-lab'"
   ```
3. **Name:** "Automotive Safety Lab"
4. **Icon:** Browse to `C:\Windows\System32\WindowsPowerShell\v1.0\powershell.exe`

**Double-click this shortcut** to instantly start working on the lab!

### VS Code Integration (Optional)

If you use VS Code (portable version available):

1. **Open VS Code Settings** (JSON)
2. **Add to `settings.json`:**

```json
{
  "terminal.integrated.env.windows": {
    "PATH": "C:\\Users\\YourName\\PortableTools\\bazel;C:\\Users\\YourName\\PortableTools\\mingw64\\bin;C:\\Users\\YourName\\PortableTools\\git\\bin;${env:PATH}"
  }
}
```

Replace `YourName` with your actual username.

---

## 🔧 Troubleshooting Portable Setup

### Issue: "bazel: command not found" after setup

**Cause:** PATH not configured for current session

**Solution:**
```powershell
# Re-run the environment script
& "$HOME\PortableTools\setup_env.ps1"

# Or manually add to PATH
$env:PATH = "$HOME\PortableTools\bazel;$HOME\PortableTools\mingw64\bin;$HOME\PortableTools\git\bin;" + $env:PATH
```

### Issue: "gcc.exe has stopped working"

**Cause:** Incomplete MinGW extraction or missing DLLs

**Solution:**
1. Re-download MinGW from https://winlibs.com/
2. Extract **all files** including subdirectories
3. Verify `mingw64\bin\` contains: `gcc.exe`, `g++.exe`, `libgcc*.dll`
4. Test in fresh PowerShell: `& "$HOME\PortableTools\mingw64\bin\gcc.exe" --version`

### Issue: Git Bash shows "cannot execute binary file"

**Cause:** 32-bit vs 64-bit mismatch

**Solution:**
- Ensure you downloaded **64-bit** versions of all tools
- Check with: `[Environment]::Is64BitOperatingSystem` in PowerShell (should be True)
- Re-download 64-bit Git Portable

### Issue: Bazel fails with "Cannot find Java"

**Cause:** Bazel requires Java for some operations

**Solution:**
```powershell
# Download portable OpenJDK 17
$jdkUrl = "https://download.java.net/java/GA/jdk17.0.2/dfd4a8d0985749f896bed50d7138ee7f/8/GPL/openjdk-17.0.2_windows-x64_bin.zip"
$jdkZip = "$HOME\Downloads\openjdk.zip"

Invoke-WebRequest -Uri $jdkUrl -OutFile $jdkZip
Expand-Archive -Path $jdkZip -DestinationPath "$HOME\PortableTools\jdk17"

# Add to setup_env.ps1
$env:JAVA_HOME = "$HOME\PortableTools\jdk17\jdk-17.0.2"
$env:PATH = "$env:JAVA_HOME\bin;" + $env:PATH
```

### Issue: PowerShell execution policy blocks scripts

**Cause:** Corporate policy restrictions

**Solution (No admin required):**
```powershell
# Bypass for current session only
Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass

# Or run with bypass flag
powershell.exe -ExecutionPolicy Bypass -File "$HOME\PortableTools\setup_env.ps1"
```

---

## 📊 Verification Checklist

Before starting the exercises, verify everything works:

```powershell
# 1. Environment setup
& "$HOME\PortableTools\setup_env.ps1"

# 2. Tool versions
bazel --version       # Should show: bazel 7.4.1
gcc --version         # Should show: gcc (GCC) 13.2.0
git --version         # Should show: git version 2.47.0
bash --version        # Should show: GNU bash, version 5.2.x

# 3. Clone repository (if not done)
cd $HOME\Documents
git clone https://github.com/rclakmal/automotive-safety-lab.git
cd automotive-safety-lab

# 4. Run verification script
.\scripts\verify_setup.ps1

# 5. Build test
bazel build //exercises/01_basic_safety:all

# 6. Run tutorial
bash .\exercises\01_basic_safety\tutorial.sh
```

**Expected output from verify_setup.ps1:**
```
[OK] Bazel installation - version 7.4.1
[OK] GCC compiler - version 13.2.0
[OK] Git installation - version 2.47.0
[OK] Project structure valid
[OK] All 5 exercise directories found
```

---

## 💡 Tips for Portable Setup

### 1. **USB Drive Installation (Maximum Portability)**

You can install everything to a USB drive for complete portability:

```powershell
# Use D:\ (or your USB drive letter) instead of $HOME
$PORTABLE_ROOT = "D:\AutomotiveSafetyLab"
New-Item -ItemType Directory -Force -Path "$PORTABLE_ROOT\PortableTools"
# ... follow same steps, replacing $HOME with $PORTABLE_ROOT
```

### 2. **Offline Installation**

Download all files on a different computer, transfer via USB:
- Bazel: `bazel-7.4.1-windows-x86_64.exe` (~70 MB)
- MinGW: `winlibs-x86_64-posix-seh-gcc-13.2.0.7z` (~350 MB)
- Git Portable: `PortableGit-2.47.0-64-bit.7z.exe` (~50 MB)
- Repository: `git clone` on online machine, zip and transfer

### 3. **Corporate Proxy Configuration**

If behind a corporate proxy:

```powershell
# Add to setup_env.ps1
$env:HTTP_PROXY = "http://proxy.company.com:8080"
$env:HTTPS_PROXY = "http://proxy.company.com:8080"
$env:NO_PROXY = "localhost,127.0.0.1"

# Configure Git proxy
git config --global http.proxy http://proxy.company.com:8080
git config --global https.proxy http://proxy.company.com:8080
```

### 4. **Shared Lab Computers**

For lab environments where multiple users share a computer:

```powershell
# Use user-specific directory
$env:PORTABLE_TOOLS = "$HOME\AppData\Local\AutomotiveSafetyLab"
# This ensures each user has their own isolated environment
```

### 5. **Faster Bazel Builds (Optional)**

Configure Bazel to use local cache:

```powershell
# Create .bazelrc in repository root
@"
# Portable Bazel configuration
startup --output_user_root=$HOME/bazel-cache
build --disk_cache=$HOME/bazel-cache/disk
"@ | Out-File -FilePath "$HOME\Documents\automotive-safety-lab\.bazelrc" -Encoding UTF8
```

---

## 🎓 Quick Reference Card

**Save this for daily use:**

```powershell
# === DAILY WORKFLOW ===

# 1. Open PowerShell
# 2. Set up environment
& "$HOME\PortableTools\setup_env.ps1"

# 3. Navigate to project
cd "$HOME\Documents\automotive-safety-lab"

# 4. Start working
bazel build //exercises/01_basic_safety:all
bash .\exercises\01_basic_safety\tutorial.sh

# === TOOL LOCATIONS ===
# Bazel:  $HOME\PortableTools\bazel\bazel.exe
# GCC:    $HOME\PortableTools\mingw64\bin\gcc.exe
# Git:    $HOME\PortableTools\git\bin\git.exe
# Bash:   $HOME\PortableTools\git\bin\bash.exe

# === TROUBLESHOOTING ===
# Environment issues: Re-run setup_env.ps1
# Build failures:     bazel clean --expunge
# Git issues:         Check proxy configuration
```

---

## 📚 Additional Resources

- **Portable Bazel Docs:** https://bazel.build/install/windows
- **WinLibs MinGW:** https://winlibs.com/ (best for Windows portability)
- **Git Portable:** https://git-scm.com/download/win
- **VS Code Portable:** https://code.visualstudio.com/docs/editor/portable
- **Troubleshooting:** [Full Troubleshooting Guide](./TROUBLESHOOTING.md)

---

## 🆘 Still Having Issues?

If the portable setup doesn't work:

1. **Check [TROUBLESHOOTING.md](./TROUBLESHOOTING.md)** for detailed solutions
2. **Try alternative tools:**
   - Use **MSYS2** instead of WinLibs MinGW
   - Use **Visual Studio Build Tools** (if available without admin)
3. **Ask for help:**
   - [GitHub Issues](https://github.com/rclakmal/automotive-safety-lab/issues)
   - Include: Windows version, error messages, output of `verify_setup.ps1`

---

## ✅ Success!

You now have a **fully portable, admin-free development environment** for the Automotive Safety Lab!

**Next Steps:**
1. ✅ [Start with Exercise 01: Basic Safety](../exercises/01_basic_safety/README.md)
2. 📖 [Read the Getting Started Guide](../GETTING_STARTED.md)
3. 🎯 [Track Your Progress](../scripts/progress.ps1)

**Remember:** Run `setup_env.ps1` every time you open a new PowerShell session!

---

*Happy Learning! 🚗💨*
