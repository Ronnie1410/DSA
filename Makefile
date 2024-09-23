# Variables
ARCH ?= x86        # Default architecture
BITS ?= 64         # Default to 64-bit; can be overridden with BITS=32
ASM_FLAG ?=        # Assembly flag (empty by default)
CFLAGS = -Wall -Iinclude

# Directories
SRC_DIR = src
APP_DIR = app
BUILD_DIR = build
RUN_DIR = $(BUILD_DIR)/run
ASM_DIR = $(BUILD_DIR)/asm

# Compiler and flags for architectures
CC_x86 = gcc
CC_ARM = arm-linux-gnueabi-gcc

# CFLAGS based on architecture and bitness
ifeq ($(ARCH), x86)
    ifeq ($(BITS), 32)
        CFLAGS += -m32
    else
        CFLAGS += -m64
    endif
else ifeq ($(ARCH), ARM)
    CC = $(CC_ARM)
    CFLAGS += -march=armv7-a
endif

# Object files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
APP_FILES = $(wildcard $(APP_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(RUN_DIR)/%.o,$(SRC_FILES)) \
            $(patsubst $(APP_DIR)/%.c,$(RUN_DIR)/%.o,$(APP_FILES))
ASM_FILES = $(patsubst $(SRC_DIR)/%.c,$(ASM_DIR)/%.s,$(SRC_FILES)) \
            $(patsubst $(APP_DIR)/%.c,$(ASM_DIR)/%.s,$(APP_FILES))

# Choose compiler and flags based on architecture
ifeq ($(ARCH), x86)
    CC = $(CC_x86)
endif

# Targets
.PHONY: all clean asm

all: $(BUILD_DIR) $(RUN_DIR) $(OBJ_FILES)
	@echo "Building for $(ARCH) $(BITS)-bit..."
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(BUILD_DIR)/app_binary
	@echo "Binary created at $(BUILD_DIR)/app_binary"

# Compile C files into object files
$(RUN_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(RUN_DIR)/%.o: $(APP_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create the build directories
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(RUN_DIR):
	@mkdir -p $(RUN_DIR)

# Optional flag for assembly
ifeq ($(ASM_FLAG), --asm)
asm: $(BUILD_DIR) $(ASM_DIR) $(ASM_FILES)
	@echo "Assembly files created at $(ASM_DIR)"
else
asm:
	@echo "To generate assembly files, use: make asm ASM_FLAG=--asm"
endif

# Generate assembly files
$(ASM_DIR):
	@mkdir -p $(ASM_DIR)

$(ASM_DIR)/%.s: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -S $< -o $@

$(ASM_DIR)/%.s: $(APP_DIR)/%.c
	$(CC) $(CFLAGS) -S $< -o $@

# Clean the build directories
clean:
	@echo "Cleaning up..."
	@rm -rf $(BUILD_DIR)
