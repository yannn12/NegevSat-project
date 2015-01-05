################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../utils/stringutils.cpp \
../utils/timeutils.cpp 

OBJS += \
./utils/stringutils.o \
./utils/timeutils.o 

CPP_DEPS += \
./utils/stringutils.d \
./utils/timeutils.d 


# Each subdirectory must supply rules for building sources it contributes
utils/%.o: ../utils/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"C:\workspaceLEON\SatProject" -O0 -g3 -Wall -msoft-float -mcpu=v8 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


