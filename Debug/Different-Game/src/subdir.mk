################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Different-Game/src/Entity.cpp 

OBJS += \
./Different-Game/src/Entity.o 

CPP_DEPS += \
./Different-Game/src/Entity.d 


# Each subdirectory must supply rules for building sources it contributes
Different-Game/src/%.o: ../Different-Game/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


