# ⏱️ Exercise 02: Watchdog Timer Systems (ASIL A)
*Interactive Learning: Timing Supervision and Failure Detection*

## 🚀 **Start Here - Interactive Tutorial**

**Ready for timing safety?** Run the interactive tutorial:

```bash
bazel run //exercises/02_watchdog_timer:interactive_tutorial
```

**Prerequisites**: Complete [Exercise 01](../01_basic_safety/README.md) first.

---

## 🎯 **Learning Objectives**

After completing this **hands-on exercise**, you will master:
- ⏰ **Watchdog Timer Implementation**: Hardware and software supervision
- 🔧 **Timing Failure Detection**: Catching deadline violations  
- 🚨 **Safe State Transitions**: Proper failure response mechanisms
- 🛡️ **ASIL A Requirements**: Basic safety integrity implementation
- 🔄 **Pattern-Based Supervision**: Advanced watchdog techniques

## 🎮 **Interactive Learning Path**

### **Phase 1: Understanding Watchdogs** 📚
Learn why timing supervision is critical in automotive systems:
- What happens when software gets "stuck"?  
- How watchdogs prevent system hangs
- Real automotive failure scenarios

### **Phase 2: Violation Analysis** ❌  
Examine a **dangerous** watchdog implementation:
```bash
bazel run //exercises/02_watchdog_timer:violation_example
```
**Challenge**: Identify 15+ timing safety violations!

### **Phase 3: Compliant Implementation** ✅
Study a **proper** ASIL A watchdog system:
```bash
bazel run //exercises/02_watchdog_timer:compliant_example  
```
**Features**: Pattern validation, timing windows, diagnostic coverage

### **Phase 4: Interactive Debugging** 🐛
Fix timing bugs in broken code:
```bash
bazel run //exercises/02_watchdog_timer:debug_challenge
```
**Skills**: Deadline analysis, timing measurement, failure injection

### **Phase 5: Build Your Own** 🏗️
Implement watchdog for engine control system:
```bash
bazel run //exercises/02_watchdog_timer:build_challenge
```
**Goal**: Create ASIL A compliant timing supervisor

## 📊 **Real-World Context**

### **System Under Development**: Engine Control Module (ECM)
- **Function**: Fuel injection timing control
- **Consequence of Failure**: Engine stall at highway speeds  
- **HARA Analysis**: S2 + E4 + C2 = **ASIL A**
- **Safety Goal**: "Engine control shall not hang or become unresponsive"

### **Watchdog Requirements**:
1. **Timing Deadline**: 10ms maximum cycle time
2. **Detection Time**: 50ms maximum before safe state
3. **Safe State**: Disable fuel injection, enable limp-home mode
4. **Diagnostic Coverage**: 95% of timing faults detected

## 🔧 **Quick Commands**

### **Run Interactive Tutorial** ⭐
```bash
bazel run //exercises/02_watchdog_timer:interactive_tutorial
```

### **Compare Implementations**
```bash
# See dangerous timing violations
bazel run //exercises/02_watchdog_timer:violation_example

# See proper ASIL A implementation
bazel run //exercises/02_watchdog_timer:compliant_example
```

### **Analyze Safety**
```bash
# Static analysis with timing focus
bazel run //exercises/02_watchdog_timer:timing_analysis

# Run unit tests with deadline checking
bazel test //exercises/02_watchdog_timer:all_tests

# Generate timing safety report  
bazel run //exercises/02_watchdog_timer:safety_report
```

### **Interactive Challenges**
```bash
# Debug timing violations
bazel run //exercises/02_watchdog_timer:debug_challenge

# Build your own watchdog
bazel run //exercises/02_watchdog_timer:build_challenge

# Advanced: Pattern-based supervision
bazel run //exercises/02_watchdog_timer:advanced_patterns
```

## 📚 **Background Knowledge**

### **What is a Watchdog Timer?**
A **hardware or software mechanism** that monitors system operation and takes corrective action if the system becomes unresponsive.

**Automotive Examples**:
- Engine control modules monitoring fuel injection timing
- Brake system controllers supervising ABS operation  
- Steering systems ensuring power assist responsiveness

### **ASIL A Requirements** (ISO 26262-6)
- **Single-point fault tolerance**: Basic fault detection
- **Diagnostic coverage**: ≥90% of relevant faults detected
- **Safe state**: Well-defined failure behavior
- **Verification**: Requirements-based testing sufficient

### **Timing Safety Patterns**
1. **Simple Watchdog**: Periodic "kick" to reset timer
2. **Window Watchdog**: Kick only within time window
3. **Pattern Watchdog**: Sequence-based validation
4. **Dual Watchdog**: Independent hardware + software supervision

## 🔗 **Learning Path Navigation**

### **Previous Exercise**
← [Exercise 01: Basic Safety Concepts](../01_basic_safety/README.md)

### **Next Exercise** 
→ [Exercise 03: Memory Protection](../03_memory_protection/README.md) *(unlocked after completion)*

### **Related Documentation**
- 📖 [ISO 26262 Timing Requirements](../../docs/timing_requirements.md)
- 📖 [ASIL Classification Guide](../../docs/asil_classification.md)
- 📖 [Automotive Watchdog Patterns](../../docs/watchdog_patterns.md)

## 🏆 **Completion Criteria**

**Exercise 02 Complete when you can:**
- [ ] Explain why watchdogs are essential in automotive systems
- [ ] Identify common timing safety violations in code
- [ ] Implement basic watchdog supervision (kick, timeout, safe state)
- [ ] Debug timing-related failures using analysis tools
- [ ] Design watchdog architecture for ASIL A requirements

**Estimated Time**: 3-4 hours (including hands-on challenges)

---

## 💡 **Pro Tips**

### **For Safety Engineers**
- Always define **clear timing requirements** before implementation
- Use **diverse supervision** (hardware + software watchdogs)  
- **Test timing failures** extensively with fault injection
- Document **diagnostic coverage** for safety assessment

### **For Developers**
- Implement watchdogs **early** in development cycle
- Use **deterministic timing** patterns (avoid random delays)
- **Monitor real-world timing** in field deployments
- Keep watchdog logic **simple** and **auditable**

---

🚀 **Ready to master automotive timing safety? Start the interactive tutorial!**

```bash
bazel run //exercises/02_watchdog_timer:interactive_tutorial
```