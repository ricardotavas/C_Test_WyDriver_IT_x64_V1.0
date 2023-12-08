################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := Test_Wydriver_IT_V1
BUILD_ARTIFACT_EXTENSION :=
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: main-build

# Main-build Target
main-build: Test_Wydriver_IT_V1

# Tool invocations
Test_Wydriver_IT_V1: $(OBJS) $(USER_OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C Linker'
	gcc -L"/home/wymauser/Documents/Projetos Linux/Test_Wydriver_IT/Test_Wydriver_IT_V1/WyDriver_IT" -o "Test_Wydriver_IT_V1" $(OBJS) $(USER_OBJS) $(LIBS) -lWyDriver_IT_V1
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) Test_Wydriver_IT_V1
	-@echo ' '

.PHONY: all clean dependents main-build

-include ../makefile.targets
