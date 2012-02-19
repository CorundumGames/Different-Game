################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Different-Game/src/Block.cpp \
../Different-Game/src/Clickable.cpp \
../Different-Game/src/Movable.cpp \
../Different-Game/src/Visible.cpp 

OBJS += \
./Different-Game/src/Block.o \
./Different-Game/src/Clickable.o \
./Different-Game/src/Movable.o \
./Different-Game/src/Visible.o 

CPP_DEPS += \
./Different-Game/src/Block.d \
./Different-Game/src/Clickable.d \
./Different-Game/src/Movable.d \
./Different-Game/src/Visible.d 


# Each subdirectory must supply rules for building sources it contributes
Different-Game/src/%.o: ../Different-Game/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/jesse/Desktop/Code/Different Game/Different-Game/include" -O3 -g3 -pedantic -pedantic-errors -Wall -c -fmessage-length=0 -v -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


