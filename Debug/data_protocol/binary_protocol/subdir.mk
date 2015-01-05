################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../data_protocol/binary_protocol/BinCMDParser.cpp 

OBJS += \
./data_protocol/binary_protocol/BinCMDParser.o 

CPP_DEPS += \
./data_protocol/binary_protocol/BinCMDParser.d 


# Each subdirectory must supply rules for building sources it contributes
data_protocol/binary_protocol/%.o: ../data_protocol/binary_protocol/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"C:\workspaceLEON\SatProject" -O0 -g3 -Wall -msoft-float -mcpu=v8 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


