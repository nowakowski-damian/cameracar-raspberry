################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ApiParser.c \
../Error.c \
../Logger.c \
../MovementFunctions.c \
../TcpServer.c \
../main.c 

OBJS += \
./ApiParser.o \
./Error.o \
./Logger.o \
./MovementFunctions.o \
./TcpServer.o \
./main.o 

C_DEPS += \
./ApiParser.d \
./Error.d \
./Logger.d \
./MovementFunctions.d \
./TcpServer.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


