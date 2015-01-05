################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../logics/CommandExecutor.cpp \
../logics/ModulesOperationRequest.cpp \
../logics/Sampler.cpp \
../logics/negevSat.cpp 

OBJS += \
./logics/CommandExecutor.o \
./logics/ModulesOperationRequest.o \
./logics/Sampler.o \
./logics/negevSat.o 

CPP_DEPS += \
./logics/CommandExecutor.d \
./logics/ModulesOperationRequest.d \
./logics/Sampler.d \
./logics/negevSat.d 


# Each subdirectory must supply rules for building sources it contributes
logics/%.o: ../logics/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"C:\workspaceLEON\SatProject" -O0 -g3 -Wall -msoft-float -mcpu=v8 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


