# Complete Exercise Workflow Example

**A step-by-step walkthrough of Exercise 01 from start to finish**

This guide shows you exactly what to expect when completing an exercise in the Automotive Safety Lab. We'll walk through Exercise 01 (Basic Safety Concepts - ASIL QM) as a complete example.

---

## 📋 Overview

**Exercise:** 01 - Basic Safety Concepts  
**ASIL Level:** QM (Quality Management)  
**Time Required:** 2-3 hours  
**Difficulty:** Beginner  
**Scenario:** Battery monitoring system for electric vehicle

**What You'll Learn:**
- Defensive programming principles
- Input validation and error handling
- Safe failure modes
- ISO 26262 basic concepts

---

## 🚀 Step 1: Navigate to the Exercise

```bash
# From project root
cd exercises/01_basic_safety

# List the files
ls -la
```

**Expected files:**
```
BUILD           # Bazel build configuration
README.md       # Exercise instructions
violation.c     # Code with violations (BAD)
compliant.c     # Compliant code (GOOD)
tutorial.sh     # Interactive tutorial script
```

---

## 📖 Step 2: Read the Exercise README

```bash
# Read the instructions
cat README.md  # Linux/Mac
type README.md # Windows
```

**Key sections to focus on:**
1. **Learning Objectives** - What you'll master
2. **Scenario Description** - The real-world context
3. **Safety Requirements** - What ISO 26262 demands
4. **Your Tasks** - What you need to do

**Take notes!** Write down:
- The safety requirements
- The system hazards
- The acceptance criteria

---

## 🔍 Step 3: Study the Violation Code

```bash
# Open violation.c in your editor
code violation.c  # VS Code
vim violation.c   # Vim
nano violation.c  # Nano
```

**What to look for:**

### ❌ Violation #1: No Input Validation
```c
// BAD: No validation!
void update_battery_voltage(float voltage) {
    battery.voltage = voltage;  // What if voltage is negative or too high?
}
```

**Problem:** Accepts invalid inputs that could cause hazards

### ❌ Violation #2: No Error Handling
```c
// BAD: Ignores errors!
void read_sensor(void) {
    float value = sensor_read();  // What if sensor fails?
    battery.temperature = value;
}
```

**Problem:** No response to sensor failures

### ❌ Violation #3: No Range Checking
```c
// BAD: No bounds checking!
void set_charge_current(float current) {
    battery.charge_current = current;  // Could exceed safe limits!
}
```

**Problem:** Could allow dangerous charging currents

**Your Task:** Identify ALL violations (usually 5-7 in each exercise)

---

## ✅ Step 4: Study the Compliant Code

```bash
# Open compliant.c
code compliant.c
```

**See how violations are fixed:**

### ✅ Fix #1: Input Validation
```c
// GOOD: Validates inputs!
safety_status_t update_battery_voltage(float voltage) {
    // Check range
    if (voltage < BATTERY_VOLTAGE_MIN || voltage > BATTERY_VOLTAGE_MAX) {
        return SAFETY_ERROR_OUT_OF_RANGE;
    }
    
    // Check for plausibility
    if (fabsf(voltage - battery.voltage) > MAX_VOLTAGE_CHANGE_RATE) {
        return SAFETY_ERROR_IMPLAUSIBLE;
    }
    
    battery.voltage = voltage;
    return SAFETY_OK;
}
```

**Benefits:**
- Range validation prevents impossible values
- Rate checking catches sensor faults
- Error codes enable proper error handling

### ✅ Fix #2: Error Handling
```c
// GOOD: Handles errors!
safety_status_t read_sensor(void) {
    float value;
    sensor_status_t status = sensor_read(&value);
    
    if (status != SENSOR_OK) {
        log_error("Sensor failure");
        enter_safe_state();
        return SAFETY_ERROR_SENSOR_FAULT;
    }
    
    battery.temperature = value;
    return SAFETY_OK;
}
```

**Benefits:**
- Detects sensor failures
- Enters safe state on error
- Logs for diagnostics

### ✅ Fix #3: Defensive Programming
```c
// GOOD: Defensive checks!
safety_status_t set_charge_current(float current) {
    // Null pointer check
    if (!battery_initialized) {
        return SAFETY_ERROR_NOT_INITIALIZED;
    }
    
    // Range check
    if (current < 0.0f || current > BATTERY_MAX_CHARGE_CURRENT) {
        return SAFETY_ERROR_OUT_OF_RANGE;
    }
    
    // Safety interlock check
    if (battery.temperature > BATTERY_OVERTEMP_THRESHOLD) {
        return SAFETY_ERROR_SAFETY_CONDITION;
    }
    
    battery.charge_current = current;
    return SAFETY_OK;
}
```

**Benefits:**
- Multiple layers of safety checks
- State validation
- Thermal protection

**Your Task:** Understand HOW each violation is fixed

---

## 🏗️ Step 5: Build the Examples

```bash
# Return to project root
cd ../..

# Build violation example
bazel build //exercises/01_basic_safety:violation_example

# Build compliant example
bazel build //exercises/01_basic_safety:compliant_example
```

**Expected output:**
```
INFO: Analyzed target //exercises/01_basic_safety:violation_example (0 packages loaded, 0 targets configured).
INFO: Found 1 target...
Target //exercises/01_basic_safety:violation_example up-to-date:
  bazel-bin/exercises/01_basic_safety/violation_example
INFO: Build completed successfully, 1 total action
```

✅ **Success!** Both examples should build without errors

---

## 🎯 Step 6: Run and Compare

### Run Violation Example

```bash
bazel run //exercises/01_basic_safety:violation_example
```

**Expected output (BAD behavior):**
```
=== Battery Monitoring System - Violation Example ===

Initializing battery system...
Battery voltage: 0.00V (invalid, but not caught!)
Setting charge current: -10.00A (negative! should be rejected!)
Battery temperature: 999.00°C (impossible! not validated!)

CRASH: Segmentation fault (system failed due to invalid state)
```

**Observe:** 
- Invalid values accepted
- No error handling
- System crashes or behaves incorrectly

### Run Compliant Example

```bash
bazel run //exercises/01_basic_safety:compliant_example
```

**Expected output (GOOD behavior):**
```
=== Battery Monitoring System - Compliant Example ===

Initializing battery system... OK
Setting voltage to 12.5V... OK
Setting voltage to -5.0V... ERROR: Out of range (rejected safely)
Setting charge current to 50.0A... OK
Setting charge current to 200.0A... ERROR: Exceeds maximum (rejected safely)
Reading temperature: 25.3°C... OK
Reading temperature: SENSOR_FAULT... ERROR: Entering safe state

System entered safe state successfully. Battery disconnected.
```

**Observe:**
- Invalid values rejected
- Errors handled gracefully
- System enters safe state
- No crashes!

---

## 📝 Step 7: Document Your Learning

Create a learning journal entry:

```markdown
# Exercise 01 - Battery Monitoring System

## Date: [Today's date]

## Key Violations Identified:
1. No input validation - allows invalid voltage values
2. No error handling - ignores sensor failures
3. No range checking - accepts dangerous charge currents
4. No state validation - allows operations when not initialized
5. No rate limiting - accepts implausible value changes

## Solutions Applied:
1. Input validation with min/max bounds
2. Error return codes and checking
3. Safe state entry on faults
4. Defensive programming with null checks
5. Plausibility analysis for sensor data

## Key Takeaways:
- Always validate inputs before use
- Check error codes from all operations
- Have a defined safe state and enter it on faults
- Use defensive programming (assume the worst)
- Log errors for diagnostics

## ISO 26262 Concepts:
- ASIL QM: Quality Management requirements
- Defensive programming: Assume all inputs are hostile
- Safe failure mode: Predictable behavior on errors
- Error detection: Validate all inputs and states

## Time Spent: 2.5 hours
## Difficulty: 3/10
## Status: ✓ Complete
```

---

## 🧪 Step 8: Run the Tests

```bash
# Run unit tests
bazel test //exercises/01_basic_safety:all

# Run with detailed output
bazel test //exercises/01_basic_safety:all --test_output=all
```

**Expected output:**
```
//exercises/01_basic_safety:compliant_test       PASSED in 0.1s
//exercises/01_basic_safety:violation_test       PASSED in 0.1s

Executed 2 out of 2 tests: 2 tests pass.
```

✅ **All tests pass!**

---

## 📊 Step 9: Check Your Progress

```bash
# Run progress tracker
./scripts/progress.sh  # Linux/Mac
.\scripts\progress.ps1 # Windows
```

**Expected output:**
```
╔════════════════════════════════════════════════╗
║                                                ║
║    Automotive Safety Lab                       ║
║    ISO 26262 Learning Progress                 ║
║                                                ║
╚════════════════════════════════════════════════╝

✓ ASIL QM - Basic Safety Concepts (Battery Monitoring)
→ ASIL A - Watchdog Timer Systems (Engine Control) ← NEXT
○ ASIL B - Memory Protection (Electronic Brake System)
○ ASIL C - Redundancy & Voting (Power Steering)
○ ASIL D - Critical Systems (Autonomous Braking)

Progress:
[████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░] 1/5 exercises (20%)

💪 Keep going! You're making great progress!

Next exercise:
  cd exercises/02_watchdog_timer
  cat README.md
```

✅ **Exercise 01 complete!**

---

## 🎓 Step 10: Self-Assessment Quiz

Before moving on, answer these questions:

### Question 1: Why is input validation critical?
**Answer:** Invalid inputs can cause:
- System crashes
- Unsafe behavior
- Component damage
- Hazardous situations

### Question 2: What is a safe state?
**Answer:** A predictable, low-risk state the system enters when:
- Errors are detected
- Unsafe conditions occur
- Normal operation can't continue

For a battery: Disconnect charging, alert user, log fault

### Question 3: What's the difference between ASIL QM and ASIL D?
**Answer:**
- **ASIL QM**: Quality Management, lowest safety requirements
- **ASIL D**: Highest safety requirements, most stringent

### Question 4: Why use return codes instead of exceptions?
**Answer:** 
- More predictable in safety-critical systems
- Explicit error handling (can't be ignored)
- Better for embedded systems
- Required by MISRA C guidelines

### Question 5: What is defensive programming?
**Answer:** 
- Assume all inputs are invalid until proven otherwise
- Check all preconditions before operations
- Validate state before taking actions
- Handle all possible error cases

---

## ✅ Exercise Completion Checklist

Before moving to Exercise 02, ensure:

- [x] Read Exercise 01 README thoroughly
- [x] Identified all violations in violation.c
- [x] Understood all fixes in compliant.c
- [x] Built both violation and compliant examples
- [x] Ran both examples and observed behavior
- [x] Documented learning in journal
- [x] Passed all unit tests
- [x] Answered self-assessment questions
- [x] Updated progress tracker

---

## 🚀 Next Steps

### You're Ready For Exercise 02 When You Can:
1. ✅ Explain the 5+ violations in Exercise 01
2. ✅ Describe how each was fixed
3. ✅ Implement input validation from scratch
4. ✅ Handle errors with return codes
5. ✅ Design a safe state for a system

### Moving Forward

```bash
# Go to Exercise 02
cd exercises/02_watchdog_timer

# Read the README
cat README.md

# Start learning!
```

**Exercise 02 Preview:**
- ASIL A (higher than QM)
- Watchdog timer systems
- Timing supervision
- Engine control scenario
- 3-4 hours

---

## 💡 Tips for Success

### Do's ✅
- Take breaks every 45-60 minutes
- Write notes as you learn
- Compare code side-by-side
- Run examples multiple times
- Ask questions if stuck
- Review previous exercises

### Don'ts ❌
- Don't rush through
- Don't skip the README
- Don't just read code (run it!)
- Don't ignore the tests
- Don't move forward if confused
- Don't skip documentation

---

## 📚 Additional Resources

### For Exercise 01
- [ISO 26262-6: Software Development](https://www.iso.org/standard/68383.html)
- [MISRA C:2012 Guidelines](https://misra.org.uk/)
- [Defensive Programming Patterns](../docs/iso26262_guide.md)

### For Next Exercise
- [Watchdog Timer Theory](https://en.wikipedia.org/wiki/Watchdog_timer)
- [ASIL A Requirements](../docs/iso26262_guide.md#asil-a)

---

## 🎉 Congratulations!

You've completed your first ISO 26262 exercise! You now understand:
- ✅ Basic functional safety concepts
- ✅ Input validation techniques
- ✅ Error handling patterns
- ✅ Defensive programming principles
- ✅ Safe failure modes

**Time invested:** ~2-3 hours  
**Progress:** 20% complete  
**Next milestone:** ASIL A (Watchdog Timers)

**Keep going!** Each exercise builds on the previous one. 🚀

---

[← Back to Main README](../README.md) | [Next: Exercise 02 →](../exercises/02_watchdog_timer/README.md)

