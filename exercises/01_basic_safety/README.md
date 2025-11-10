# 🎓 Exercise 01: Basic Safety Concepts (ASIL QM)
*Interactive Introduction to ISO 26262 Functional Safety Principles*

## 🚀 **Start Here - Interactive Tutorial**

**New to this exercise?** Run the interactive tutorial:

```bash
bazel run //exercises/01_basic_safety:interactive_tutorial
```

The tutorial will guide you through comparing violation vs. compliant code, running safety analysis, and completing hands-on challenges.

---

## 🎯 **Learning Objectives**

After completing this **interactive exercise**, you will understand:
- ✅ **Functional Safety Fundamentals**: Core ISO 26262 principles
- ✅ **ASIL QM Classification**: Quality-managed automotive systems  
- ✅ **Violation Recognition**: How to spot common safety mistakes
- ✅ **Defensive Programming**: Automotive-grade coding practices
- ✅ **Safety Analysis Tools**: Static analysis and MISRA compliance

## 📚 Background Knowledge

### What is ISO 26262?
ISO 26262 is the international standard for **functional safety** of electrical and electronic systems in road vehicles. It defines methods to:
- Identify hazards in automotive systems
- Assess and classify risks (ASIL ratings)
- Implement appropriate safety measures
- Verify and validate safety requirements

### ASIL QM (Quality Managed)
**ASIL QM** represents systems where there is **no unreasonable risk** associated with hazardous events, or where safety measures outside the scope of ISO 26262 are sufficient.

**Examples of ASIL QM systems:**
- Radio/entertainment systems
- Navigation displays
- Interior lighting
- Non-safety-related diagnostics

## 🔍 Exercise Overview

This exercise introduces a **simple diagnostic system** that monitors vehicle battery voltage. While the diagnostic itself is ASIL QM (non-safety), it demonstrates fundamental safety concepts used in higher ASIL systems.

### System Description
**Function**: Battery voltage monitoring and reporting
**Context**: Dashboard warning system
**Hazard**: Driver unaware of battery condition (non-safety impact)
**ASIL Rating**: QM (Quality Managed)

## 📁 Files in This Exercise

- **`README.md`** - This instruction file
- **`violation.c`** - Code with poor quality practices
- **`compliant.c`** - Proper implementation following good practices  
- **`analysis.md`** - Detailed comparison and explanation
- **`Makefile`** - Build configuration for the exercise

## 🎮 **Interactive Learning Steps**

### **Step 1: Run the Interactive Tutorial** ⭐
```bash
bazel run //exercises/01_basic_safety:interactive_tutorial
```
*This guided experience walks you through everything below with explanations and challenges.*

### **Step 2: Compare Violation vs. Compliant Code**
```bash
# See what NOT to do (violation example)
bazel run //exercises/01_basic_safety:violation_example

# See proper implementation  
bazel run //exercises/01_basic_safety:compliant_example
```

### **Step 3: Run Safety Analysis Tools**
```bash
# Analyze both examples for safety issues
bazel run //exercises/01_basic_safety:safety_check

# Run unit tests on the compliant version
bazel test //exercises/01_basic_safety:compliant_test
```

### **Step 4: Examine Source Code**
- 📄 **[violation.c](./violation.c)** - Poor practices (what NOT to do)
- 📄 **[compliant.c](./compliant.c)** - Good automotive practices
- Compare side-by-side to see the differences

## 🧪 Hands-On Activities

### Activity 1: Code Analysis
1. **Examine `violation.c`**:
   - Identify poor programming practices
   - Note missing error handling
   - Find potential reliability issues

2. **Study `compliant.c`**:
   - Compare error handling approaches
   - Note defensive programming techniques
   - Observe diagnostic information collection

### Activity 2: Modification Exercise
1. **Extend the violation code** to make it even worse:
   - Remove more error checks
   - Add potential buffer overflows
   - Introduce timing issues

2. **Improve the compliant code**:
   - Add more comprehensive validation
   - Implement additional diagnostic features
   - Include self-test capabilities

### Activity 3: ASIL Classification Practice
For each scenario, determine the appropriate ASIL level:

1. **Battery monitoring for electric vehicle**:
   - Loss of battery monitoring could lead to stranding
   - Severity: ? Exposure: ? Controllability: ?
   - ASIL: ?

2. **Fuel level sensor in gasoline vehicle**:
   - Inaccurate fuel reading could cause running out of fuel
   - Severity: ? Exposure: ? Controllability: ?
   - ASIL: ?

3. **Engine temperature gauge**:
   - Failure could lead to engine overheating and loss of power
   - Severity: ? Exposure: ? Controllability: ?
   - ASIL: ?

## 📊 Assessment Questions

### Knowledge Check
1. **What is the difference between functional safety and cybersecurity?**
2. **Why are some automotive systems classified as ASIL QM?**
3. **What are the three factors used to determine ASIL levels?**
4. **Name three examples of safety mechanisms used in automotive systems.**

### Practical Questions
1. **How would you modify the battery monitoring system for an electric vehicle (higher criticality)?**
2. **What additional validation would be needed for ASIL A classification?**
3. **How would you implement redundancy for a critical sensor reading?**

## 🔗 Connections to Higher ASIL Levels

This basic exercise establishes principles used throughout ISO 26262:

### Concepts Applied in ASIL A-D:
- **Error Detection**: Identifying when something goes wrong
- **Error Response**: Taking appropriate action when errors occur
- **Diagnostic Coverage**: Measuring how well faults are detected
- **Safe States**: Defined system behaviors during faults

### Progression Path:
- **Exercise 02 (ASIL A)**: Adds timing supervision and watchdog mechanisms
- **Exercise 03 (ASIL B)**: Introduces memory protection and interference
- **Exercise 04 (ASIL C)**: Implements redundancy and cross-checking
- **Exercise 05 (ASIL D)**: Requires formal verification and diverse implementation

## 💡 Key Takeaways

1. **Quality Matters**: Even QM systems benefit from good engineering practices
2. **Error Handling**: Robust error detection and response is fundamental
3. **Diagnostics**: Information collection enables better system understanding
4. **Documentation**: Clear requirements and traceability support verification
5. **Progressive Complexity**: Safety concepts build upon each other

## 📚 Further Reading

### ISO 26262 References
- **Part 1**: Vocabulary and general principles
- **Part 3**: Concept phase (hazard analysis)
- **Part 6**: Product development at software level
- **Part 8**: Supporting processes

### Automotive Standards
- **MISRA C**: Guidelines for C programming in automotive systems
- **AUTOSAR**: Automotive software architecture standardization
- **ASPICE**: Automotive software process improvement capability determination

---

**Next Exercise**: [02_watchdog_timer](../02_watchdog_timer/) - Introduction to timing supervision (ASIL A)