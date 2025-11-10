# 🚀 Getting Started with Automotive Safety Lab

Welcome! This guide will help you set up the Automotive Safety Lab and complete your first exercise. **No prior ISO 26262 experience required** — we'll guide you every step of the way.

## ⏱️ Time Estimate
- **Setup**: 15-30 minutes
- **First Exercise**: 2-3 hours
- **Total**: 3 hours to your first success! 🎉

---

## 📋 What You'll Learn

By completing this guide, you will:
1. ✅ Set up your development environment
2. ✅ Understand the project structure
3. ✅ Build and run your first safety-critical code
4. ✅ Identify ISO 26262 violations
5. ✅ Fix them using compliant patterns

---

## 🔧 Step 1: Prerequisites Check

Before starting, ensure you have these tools installed:

### Required Tools

| Tool | Version | Purpose | Check Command |
|------|---------|---------|---------------|
| **Bazel** | 6.0+ | Build system | `bazel --version` |
| **GCC/Clang** | GCC 9+ or Clang 10+ | C/C++ compiler | `gcc --version` or `clang --version` |
| **Git** | 2.0+ | Version control | `git --version` |

### Optional But Recommended

| Tool | Purpose |
|------|---------|
| **VS Code** | IDE with excellent C/C++ support |
| **cppcheck** | Static analysis for C/C++ |
| **Python 3.8+** | For analysis scripts |

---

## 🛠️ Step 2: Install Prerequisites

### Windows

```powershell
# Install Bazel using Chocolatey
choco install bazel

# Install MinGW GCC
choco install mingw

# Verify installations
bazel --version
gcc --version
```

### macOS

```bash
# Install Bazel using Homebrew
brew install bazel

# Install GCC (Clang comes with Xcode Command Line Tools)
xcode-select --install
brew install gcc

# Verify installations
bazel --version
gcc --version
```

### Linux (Ubuntu/Debian)

```bash
# Install Bazel
sudo apt install apt-transport-https curl gnupg
curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor > bazel.gpg
sudo mv bazel.gpg /etc/apt/trusted.gpg.d/
echo "deb [arch=amd64] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list
sudo apt update && sudo apt install bazel

# Install GCC
sudo apt install build-essential

# Verify installations
bazel --version
gcc --version
```

**Need help?** See our [Troubleshooting Guide](./docs/TROUBLESHOOTING.md)

---

## 📦 Step 3: Clone the Repository

```bash
# Clone the repository
git clone https://github.com/rclakmal/automotive-safety-lab.git

# Navigate to the project directory
cd automotive-safety-lab

# Verify project structure
ls -la
```

You should see:
```
exercises/    # Your learning exercises
docs/         # Educational materials
tests/        # Integration tests
tools/        # Safety analysis tools
BUILD         # Main build configuration
WORKSPACE     # Bazel workspace
README.md     # Project overview
```

---

## ✅ Step 4: Verify Your Setup

Run our automated verification script:

### Windows (PowerShell)
```powershell
.\scripts\verify_setup.ps1
```

### macOS/Linux (Bash)
```bash
./scripts/verify_setup.sh
```

**Expected output:**
```
✅ Bazel installation verified (version X.X.X)
✅ C/C++ compiler found (GCC X.X.X)
✅ Git installation verified
✅ Project structure valid
✅ Bazel workspace configured correctly

🎉 Your environment is ready!
```

**Seeing errors?** Check the [Troubleshooting Guide](./docs/TROUBLESHOOTING.md)

---

## 🏗️ Step 5: Test the Build System

Let's verify everything compiles:

```bash
# Build all exercises (this may take 1-2 minutes)
bazel build //...

# Expected: All targets build successfully ✅
```

**Quick test** (faster, just the first exercise):
```bash
bazel build //exercises/01_basic_safety:all
```

---

## 🎓 Step 6: Start Your First Exercise

Congratulations! Now for the fun part — let's start learning ISO 26262!

### 6.1 Navigate to Exercise 01

```bash
cd exercises/01_basic_safety
```

### 6.2 Read the Exercise Guide

Open `README.md` in your favorite editor or read it online:

```bash
# VS Code
code README.md

# Or just cat/type it
cat README.md    # macOS/Linux
type README.md   # Windows
```

### 6.3 Understand the Learning Scenario

**Scenario**: Battery monitoring system for an electric vehicle (ASIL QM)

**Your mission**: 
1. Study the `violation.c` file (contains ISO 26262 violations)
2. Compare it with `compliant.c` (proper implementation)
3. Understand what makes code safety-compliant

### 6.4 Build the Violation Example

```bash
# From project root
bazel build //exercises/01_basic_safety:violation_example

# Run it to see the violations in action
bazel run //exercises/01_basic_safety:violation_example
```

**What to observe:**
- Unvalidated inputs ❌
- Lack of error handling ❌
- Missing safety checks ❌

### 6.5 Build the Compliant Example

```bash
bazel build //exercises/01_basic_safety:compliant_example

# Run it to see proper safety implementation
bazel run //exercises/01_basic_safety:compliant_example
```

**What you'll learn:**
- Input validation ✅
- Error handling ✅
- Safe failure modes ✅
- Defensive programming ✅

### 6.6 Compare the Code

Open both files side-by-side:

```bash
# VS Code
code violation.c compliant.c

# Or use diff
diff violation.c compliant.c
```

**Key differences to identify:**
1. How are inputs validated?
2. What happens when errors occur?
3. How are safety-critical values checked?
4. What documentation is provided?

---

## 📊 Step 7: Run the Interactive Tutorial

Each exercise includes an interactive tutorial script:

### Windows
```powershell
.\tutorial.sh  # Uses Git Bash if installed
# Or follow the tutorial manually using the README
```

### macOS/Linux
```bash
chmod +x tutorial.sh
./tutorial.sh
```

The tutorial will:
- ✅ Guide you through the code
- ✅ Explain each violation
- ✅ Show the compliant fix
- ✅ Test your understanding

---

## 🎯 Step 8: Complete the Exercise

### Your Task

1. **Read** `violation.c` thoroughly
2. **Identify** all ISO 26262 violations (hint: there are 5-7)
3. **Study** how `compliant.c` fixes each violation
4. **Document** what you learned

### Self-Assessment Questions

Answer these to verify your understanding:

1. Why is input validation critical in safety-critical systems?
2. What's the difference between fail-safe and fail-operational?
3. How does defensive programming reduce systematic failures?
4. What does ASIL QM mean and what are its requirements?

**Answers** are in the exercise README.md!

---

## ✅ Step 9: Verify Your Progress

Run the test suite to verify your understanding:

```bash
# Run unit tests for Exercise 01
bazel test //exercises/01_basic_safety:all

# Check your progress
./scripts/progress.sh  # Shows completed exercises
```

---

## 🎓 Step 10: What's Next?

Congratulations! You've completed your first ISO 26262 exercise! 🎉

### Your Learning Path

✅ **Exercise 01 (ASIL QM)**: Basic Safety - **COMPLETE!**  
⬜ **Exercise 02 (ASIL A)**: Watchdog Timer Systems  
⬜ **Exercise 03 (ASIL B)**: Memory Protection  
⬜ **Exercise 04 (ASIL C)**: Redundancy & Voting  
⬜ **Exercise 05 (ASIL D)**: Critical Systems  

### Next Steps

1. **Review** your notes from Exercise 01
2. **Read** the [ISO 26262 Guide](./docs/iso26262_guide.md)
3. **Move to** [Exercise 02: Watchdog Timer Systems](./exercises/02_watchdog_timer/README.md)
4. **Join** our community discussions (see main README)

---

## 🆘 Need Help?

### Common Issues

| Problem | Solution |
|---------|----------|
| **Bazel build fails** | Check [Troubleshooting Guide](./docs/TROUBLESHOOTING.md) |
| **Compiler not found** | Verify GCC/Clang installation |
| **Can't run scripts** | Check file permissions (`chmod +x`) |
| **Git clone fails** | Check network and Git installation |

### Resources

- 📖 [Full Documentation](./README.md)
- 🐛 [Troubleshooting Guide](./docs/TROUBLESHOOTING.md)
- 📚 [ISO 26262 Guide](./docs/iso26262_guide.md)
- 💬 [GitHub Issues](https://github.com/rclakmal/automotive-safety-lab/issues)
- 📧 Contact: rclakmal@github

---

## 📝 Checklist for Success

Before moving to Exercise 02, ensure you've:

- [ ] ✅ Verified all prerequisites are installed
- [ ] ✅ Successfully built Exercise 01
- [ ] ✅ Run both violation and compliant examples
- [ ] ✅ Identified all safety violations
- [ ] ✅ Understood the compliant fixes
- [ ] ✅ Passed the unit tests
- [ ] ✅ Answered the self-assessment questions

**All checked?** You're ready for ASIL A! 🚀

---

## 🎓 Learning Tips

### For Best Results

1. **Take Your Time**: Don't rush through the exercises
2. **Hands-On Practice**: Build and run every example
3. **Compare Code**: Always diff violation vs. compliant
4. **Take Notes**: Document your insights
5. **Ask Questions**: Use GitHub Issues for help
6. **Review Standards**: Refer to ISO 26262 guide when confused

### Study Habits

- 📅 **Dedicate 3-5 hours per exercise**
- 🔄 **Review previous exercises before moving forward**
- 📝 **Keep a learning journal**
- 🧑‍🤝‍🧑 **Discuss with peers if possible**
- 🎯 **Focus on understanding, not just completion**

---

**Ready to become an automotive safety engineer? Let's start!** 🚗⚡

[← Back to Main README](./README.md) | [Next: Exercise 01 →](./exercises/01_basic_safety/README.md)
