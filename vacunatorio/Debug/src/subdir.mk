################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/datawarehouse.c \
../src/fecha.c \
../src/inoculacion.c \
../src/inputs.c \
../src/laboratorio.c \
../src/paciente.c \
../src/provincia.c \
../src/vacuna.c \
../src/vacunatorio.c 

OBJS += \
./src/datawarehouse.o \
./src/fecha.o \
./src/inoculacion.o \
./src/inputs.o \
./src/laboratorio.o \
./src/paciente.o \
./src/provincia.o \
./src/vacuna.o \
./src/vacunatorio.o 

C_DEPS += \
./src/datawarehouse.d \
./src/fecha.d \
./src/inoculacion.d \
./src/inputs.d \
./src/laboratorio.d \
./src/paciente.d \
./src/provincia.d \
./src/vacuna.d \
./src/vacunatorio.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


