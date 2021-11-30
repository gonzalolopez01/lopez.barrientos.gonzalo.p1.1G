################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/2PLab.c \
../src/Controller.c \
../src/LinkedList.c \
../src/emergencia.c \
../src/inputs.c \
../src/parser.c 

OBJS += \
./src/2PLab.o \
./src/Controller.o \
./src/LinkedList.o \
./src/emergencia.o \
./src/inputs.o \
./src/parser.o 

C_DEPS += \
./src/2PLab.d \
./src/Controller.d \
./src/LinkedList.d \
./src/emergencia.d \
./src/inputs.d \
./src/parser.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


