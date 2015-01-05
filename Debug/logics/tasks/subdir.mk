################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../logics/tasks/CMDTask.cpp \
../logics/tasks/LifeCycleTask.cpp \
../logics/tasks/MPTask.cpp \
../logics/tasks/ReceiveTask.cpp \
../logics/tasks/SendTask.cpp \
../logics/tasks/StateMachineTask.cpp 

OBJS += \
./logics/tasks/CMDTask.o \
./logics/tasks/LifeCycleTask.o \
./logics/tasks/MPTask.o \
./logics/tasks/ReceiveTask.o \
./logics/tasks/SendTask.o \
./logics/tasks/StateMachineTask.o 

CPP_DEPS += \
./logics/tasks/CMDTask.d \
./logics/tasks/LifeCycleTask.d \
./logics/tasks/MPTask.d \
./logics/tasks/ReceiveTask.d \
./logics/tasks/SendTask.d \
./logics/tasks/StateMachineTask.d 


# Each subdirectory must supply rules for building sources it contributes
logics/tasks/%.o: ../logics/tasks/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"C:\workspaceLEON\SatProject" -O0 -g3 -Wall -msoft-float -mcpu=v8 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


