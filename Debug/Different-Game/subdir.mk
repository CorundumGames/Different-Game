################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Different-Game/main.cpp 

OBJS += \
./Different-Game/main.o 

CPP_DEPS += \
./Different-Game/main.d 


# Each subdirectory must supply rules for building sources it contributes
Different-Game/%.o: ../Different-Game/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/jesse/Desktop/Code/Different Game/Different-Game/include" -O3 -g3 -pedantic -pedantic-errors -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


