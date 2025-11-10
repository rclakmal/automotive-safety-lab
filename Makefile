# ISO 26262 Educational Platform Makefile
# ======================================
# 
# Build system for automotive safety training examples
# Includes safety-critical compiler flags and analysis tools

CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic
SAFETY_FLAGS = -O2 -fstack-protector-strong -D_FORTIFY_SOURCE=2
DEBUG_FLAGS = -g -fsanitize=address -fsanitize=undefined
INCLUDE_DIRS = -I./src -I./components

# Safety analysis tools (if available)
MISRA_CHECKER = pc-lint
STATIC_ANALYZER = cppcheck

# Build directories
BUILD_DIR = build
SRC_DIR = src
COMPONENTS_DIR = components

# Default target
all: watchdog_examples

# Create build directory
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Watchdog examples
watchdog_examples: $(BUILD_DIR) $(BUILD_DIR)/watchdog_violation $(BUILD_DIR)/watchdog_compliant

$(BUILD_DIR)/watchdog_violation: $(SRC_DIR)/watchdog/watchdog_violation.c
	@echo "Building watchdog violation example..."
	$(CC) $(CFLAGS) $(INCLUDE_DIRS) -o $@ $<

$(BUILD_DIR)/watchdog_compliant: $(SRC_DIR)/watchdog/watchdog_compliant.c
	@echo "Building watchdog compliant example..."
	$(CC) $(CFLAGS) $(SAFETY_FLAGS) $(INCLUDE_DIRS) -o $@ $<

# Debug builds with sanitizers
debug: $(BUILD_DIR)
	@echo "Building debug versions with sanitizers..."
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(INCLUDE_DIRS) \
		-o $(BUILD_DIR)/watchdog_violation_debug $(SRC_DIR)/watchdog/watchdog_violation.c
	$(CC) $(CFLAGS) $(SAFETY_FLAGS) $(DEBUG_FLAGS) $(INCLUDE_DIRS) \
		-o $(BUILD_DIR)/watchdog_compliant_debug $(SRC_DIR)/watchdog/watchdog_compliant.c

# Run examples
run_violation: $(BUILD_DIR)/watchdog_violation
	@echo "Running watchdog violation example..."
	@echo "======================================"
	./$(BUILD_DIR)/watchdog_violation

run_compliant: $(BUILD_DIR)/watchdog_compliant
	@echo "Running watchdog compliant example..."
	@echo "====================================="
	./$(BUILD_DIR)/watchdog_compliant

run_all: run_violation run_compliant

# Static analysis (if tools are available)
analyze:
	@echo "Running static analysis..."
	@if command -v cppcheck > /dev/null 2>&1; then \
		cppcheck --enable=all --std=c99 --platform=unix32 \
			--suppress=missingIncludeSystem $(SRC_DIR)/ ; \
	else \
		echo "cppcheck not found, skipping static analysis"; \
	fi

# MISRA compliance check (if pc-lint is available)
misra:
	@echo "Checking MISRA C compliance..."
	@if command -v pc-lint > /dev/null 2>&1; then \
		pc-lint +v -w3 -misra(2012) $(SRC_DIR)/watchdog/*.c ; \
	else \
		echo "pc-lint not found, skipping MISRA analysis"; \
	fi

# Safety report generation
safety_report:
	@echo "Generating safety analysis report..."
	@echo "ISO 26262 Educational Platform - Safety Analysis" > safety_report.txt
	@echo "================================================" >> safety_report.txt
	@echo "Build timestamp: $$(date)" >> safety_report.txt
	@echo "" >> safety_report.txt
	@echo "Compiler flags: $(CFLAGS) $(SAFETY_FLAGS)" >> safety_report.txt
	@echo "Static analysis: make analyze" >> safety_report.txt
	@echo "MISRA check: make misra" >> safety_report.txt
	@echo "" >> safety_report.txt
	@echo "Examples built:" >> safety_report.txt
	@ls -la $(BUILD_DIR)/ >> safety_report.txt 2>/dev/null || echo "No build artifacts found" >> safety_report.txt
	@echo "Safety report generated: safety_report.txt"

# Clean build artifacts
clean:
	@echo "Cleaning build artifacts..."
	rm -rf $(BUILD_DIR)
	rm -f safety_report.txt

# Install development dependencies (Ubuntu/Debian)
install_deps:
	@echo "Installing development dependencies..."
	@if command -v apt-get > /dev/null 2>&1; then \
		sudo apt-get update && \
		sudo apt-get install -y build-essential cppcheck valgrind gdb; \
	elif command -v yum > /dev/null 2>&1; then \
		sudo yum groupinstall -y "Development Tools" && \
		sudo yum install -y cppcheck valgrind gdb; \
	else \
		echo "Package manager not recognized. Please install manually:"; \
		echo "- build-essential/Development Tools"; \
		echo "- cppcheck (static analysis)"; \
		echo "- valgrind (memory debugging)"; \
		echo "- gdb (debugging)"; \
	fi

# Help target
help:
	@echo "ISO 26262 Educational Platform Build System"
	@echo "=========================================="
	@echo ""
	@echo "Available targets:"
	@echo "  all              - Build all examples"
	@echo "  watchdog_examples - Build watchdog examples"
	@echo "  debug            - Build debug versions with sanitizers"
	@echo "  run_violation    - Run watchdog violation example"
	@echo "  run_compliant    - Run watchdog compliant example"
	@echo "  run_all          - Run all examples"
	@echo "  analyze          - Run static analysis (cppcheck)"
	@echo "  misra            - Check MISRA C compliance (pc-lint)"
	@echo "  safety_report    - Generate safety analysis report"
	@echo "  clean            - Clean build artifacts"
	@echo "  install_deps     - Install development dependencies"
	@echo "  help             - Show this help message"
	@echo ""
	@echo "Educational Usage:"
	@echo "  make run_violation  # See safety violations in action"
	@echo "  make run_compliant  # See proper ISO 26262 implementation"
	@echo "  make analyze        # Learn about static analysis"
	@echo "  make safety_report  # Generate compliance documentation"

# Prevent make from treating these as file targets
.PHONY: all watchdog_examples debug run_violation run_compliant run_all analyze misra safety_report clean install_deps help