# Troubleshooting Guide

Common issues and solutions for the Automotive Safety Lab

---

## 🔧 Build System Issues

### Bazel Build Failures

#### Problem: `bazel: command not found`

**Solution:**
```bash
# Verify Bazel installation
which bazel  # Linux/Mac
where bazel  # Windows

# If not found, install Bazel:
# Linux: https://bazel.build/install/ubuntu
# macOS: brew install bazel
# Windows: choco install bazel
```

#### Problem: `ERROR: no such target '//exercises/01_basic_safety:all'`

**Cause:** You're not in the project root directory

**Solution:**
```bash
# Navigate to project root
cd path/to/automotive-safety-lab

# Verify you're in the right place
ls BUILD WORKSPACE  # Should see both files
```

#### Problem: `External dependency error`

**Cause:** Network issues or missing dependencies

**Solution:**
```bash
# Clean and rebuild
bazel clean --expunge
bazel build //exercises/01_basic_safety:all

# If still failing, check your internet connection
# Bazel downloads dependencies from GitHub/Maven
```

#### Problem: `WARNING: ignoring WORKSPACE file as this version uses bzlmod by default`

**Cause:** Bazel 7.0+ uses MODULE.bazel by default

**Solution:**
This is just a warning and can be safely ignored. The project works with both systems. To suppress:
```bash
# Option 1: Use --noenable_bzlmod flag
bazel build --noenable_bzlmod //...

# Option 2: Add to .bazelrc file
echo "build --noenable_bzlmod" >> .bazelrc
```

---

## 🔨 Compiler Issues

### GCC/Clang Not Found

#### Problem: `gcc: command not found` or `clang: command not found`

> **🎒 No Admin Rights?** See [Portable Setup Guide](./PORTABLE_SETUP.md) for installing MinGW GCC without administrator privileges!

**Solution:**

**Linux (Ubuntu/Debian):**
```bash
sudo apt update
sudo apt install build-essential
gcc --version
```

**macOS:**
```bash
# Install Xcode Command Line Tools
xcode-select --install

# Or install via Homebrew
brew install gcc
```

**Windows:**
```powershell
# Option 1: Install MinGW via Chocolatey
choco install mingw

# Option 2: Direct download from SourceForge
# Download from: https://sourceforge.net/projects/mingw-w64/
# Install and add to PATH

# If you don't have Chocolatey, install it first:
# Open PowerShell as Administrator and run:
Set-ExecutionPolicy Bypass -Scope Process -Force; [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072; iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
```

### Compiler Version Too Old

#### Problem: `error: this compiler version is not supported`

**Cause:** GCC < 9.0 or Clang < 10.0

**Solution:**
```bash
# Check current version
gcc --version

# Linux: Update GCC
sudo apt install gcc-11 g++-11
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 100

# macOS: Update via Homebrew
brew upgrade gcc

# Windows: Install newer MinGW
choco upgrade mingw
```

---

## 🐍 Python Issues

### Python Not Found

#### Problem: `python: command not found`

**Solution:**
```bash
# Linux/macOS
sudo apt install python3  # Linux
brew install python3      # macOS

# Windows
choco install python

# Verify installation
python3 --version  # or python --version on Windows
```

### Script Execution Permission Denied

#### Problem: `permission denied: ./scripts/verify_setup.sh`

**Solution:**
```bash
# Make scripts executable
chmod +x scripts/*.sh

# Run the script
./scripts/verify_setup.sh
```

### Bash Not Found on Windows

#### Problem: `bash: command not found` or interactive tutorials fail to run

**Cause:** Windows doesn't include bash by default

**Solution:**
```powershell
# Option 1: Install Git (includes Git Bash) - RECOMMENDED
choco install git

# Option 2: Use Windows Subsystem for Linux (WSL)
wsl --install

# Option 3: Manual Git installation
# Download from: https://git-scm.com/download/win
# Make sure to select "Git Bash" during installation

# Verify installation
bash --version
```

**After installing Git Bash:**
- Use "Git Bash" terminal instead of PowerShell for tutorials
- Or run tutorials with: `bash ./exercises/01_basic_safety/tutorial.sh`

---

## 📂 File and Directory Issues

### Bazel Symlink Warnings

#### Problem: `bazel-*` directories clutter the project

**Explanation:** These are Bazel-generated symlinks to build outputs. They're normal!

**Solution (Optional - to hide them):**
```bash
# Add to .gitignore (already done in this project)
echo "bazel-*" >> .gitignore

# To remove them (they'll be regenerated):
rm -rf bazel-*
```

### Exercise Files Missing

#### Problem: `No such file or directory: exercises/01_basic_safety/violation.c`

**Cause:** Incomplete clone or corrupted files

**Solution:**
```bash
# Re-clone the repository
cd ..
rm -rf automotive-safety-lab
git clone https://github.com/rclakmal/automotive-safety-lab.git
cd automotive-safety-lab

# Verify files exist
ls exercises/01_basic_safety/
```

---

## 🧪 Test Failures

### Unit Tests Fail

#### Problem: `FAILED: //exercises/01_basic_safety:test`

**Cause:** Code changes or build issues

**Solution:**
```bash
# Clean build
bazel clean
bazel test //exercises/01_basic_safety:all

# Run with verbose output
bazel test //exercises/01_basic_safety:all --test_output=all

# Check specific test
bazel test //exercises/01_basic_safety:test --test_output=streamed
```

### Integration Tests Fail

#### Problem: `Integration test suite failed`

**Cause:** One or more exercises not built correctly

**Solution:**
```bash
# Build all exercises first
bazel build //...

# Then run integration tests
bazel test //tests/integration:all

# Run individual test
bazel test //tests/integration:integration_test_suite
```

---

## 🖥️ Platform-Specific Issues

### Windows PowerShell Execution Policy

#### Problem: `script cannot be loaded because running scripts is disabled`

**Solution:**
```powershell
# Check current policy
Get-ExecutionPolicy

# Set to RemoteSigned (recommended)
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser

# Or run with bypass (not recommended for security)
PowerShell -ExecutionPolicy Bypass -File scripts\verify_setup.ps1
```

### Windows Path Length Limit

#### Problem: `The filename or extension is too long`

**Cause:** Windows has a 260-character path limit (older versions)

**Solution:**
```powershell
# Enable long paths (Windows 10 1607+, requires admin)
New-ItemProperty -Path "HKLM:\SYSTEM\CurrentControlSet\Control\FileSystem" `
    -Name "LongPathsEnabled" -Value 1 -PropertyType DWORD -Force

# Or clone to shorter path
cd C:\
git clone https://github.com/rclakmal/automotive-safety-lab.git lab
cd lab
```

### macOS Gatekeeper Warnings

#### Problem: `"bazel" cannot be opened because the developer cannot be verified`

**Solution:**
```bash
# Remove quarantine attribute
xattr -d com.apple.quarantine /path/to/bazel

# Or allow in System Preferences > Security & Privacy
```

### Linux Library Issues

#### Problem: `error while loading shared libraries: libstdc++.so.6`

**Solution:**
```bash
# Install missing libraries
sudo apt install libstdc++6

# For 32-bit support on 64-bit system
sudo apt install lib32stdc++6
```

---

## 📦 Git Issues

### Clone Fails

#### Problem: `fatal: unable to access 'https://github.com/...': Could not resolve host`

**Cause:** Network or DNS issues

**Solution:**
```bash
# Check internet connection
ping github.com

# Try SSH instead of HTTPS
git clone git@github.com:rclakmal/automotive-safety-lab.git

# Or use GitHub CLI
gh repo clone rclakmal/automotive-safety-lab
```

### Large Repository Size

#### Problem: Clone takes too long or fails

**Solution:**
```bash
# Shallow clone (faster, smaller)
git clone --depth 1 https://github.com/rclakmal/automotive-safety-lab.git

# Or single branch
git clone --single-branch --branch master https://github.com/rclakmal/automotive-safety-lab.git
```

---

## 🔍 Debug Mode

### Enable Verbose Output

If you're still having issues, enable verbose logging:

```bash
# Bazel verbose build
bazel build //exercises/01_basic_safety:all --verbose_failures --sandbox_debug

# Bazel with debug output
bazel build //exercises/01_basic_safety:all --subcommands

# Script debug mode
bash -x scripts/verify_setup.sh  # Linux/Mac
```

---

## 💬 Still Need Help?

### Before Asking for Help

1. **Check this guide** - Did you try all solutions above?
2. **Search existing issues** - [GitHub Issues](https://github.com/rclakmal/automotive-safety-lab/issues)
3. **Collect information:**
   ```bash
   # System info
   uname -a          # Linux/Mac
   systeminfo        # Windows
   
   # Tool versions
   bazel --version
   gcc --version
   python3 --version
   git --version
   
   # Project state
   ls -la
   git status
   git log -1
   ```

### Get Support

1. **GitHub Issues**: [Create an issue](https://github.com/rclakmal/automotive-safety-lab/issues/new)
   - Include: OS, tool versions, error messages, steps to reproduce
   
2. **Community Discussions**: [GitHub Discussions](https://github.com/rclakmal/automotive-safety-lab/discussions)
   - Ask questions, share experiences, help others

3. **Documentation**: 
   - [GETTING_STARTED.md](../GETTING_STARTED.md) - Setup guide
   - [README.md](../README.md) - Project overview
   - [ISO 26262 Guide](./iso26262_guide.md) - Standard reference

---

## 📚 Additional Resources

### Bazel Documentation
- [Bazel Installation Guide](https://bazel.build/install)
- [Bazel C++ Tutorial](https://bazel.build/tutorials/cpp)
- [Bazel Troubleshooting](https://bazel.build/docs/troubleshooting)

### Compiler Documentation
- [GCC Documentation](https://gcc.gnu.org/onlinedocs/)
- [Clang Documentation](https://clang.llvm.org/docs/)
- [MSVC Documentation](https://docs.microsoft.com/en-us/cpp/)

### ISO 26262 Resources
- [ISO 26262 Official Site](https://www.iso.org/standard/68383.html)
- [Functional Safety Guide](./iso26262_guide.md)

---

**Last Updated:** November 2025  
**Maintainer:** rclakmal  
**Contributions:** Welcome! Please submit improvements via PR
