################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/AllTests.cpp \
../tests/CMDParserTests.cpp \
../tests/ReceiveTests.cpp \
../tests/SendReceiveQueueTests.cpp \
../tests/SendTests.cpp \
../tests/TLMParserTests.cpp \
../tests/WorkQueueTests.cpp \
../tests/XMLValidatorTests.cpp 

OBJS += \
./tests/AllTests.o \
./tests/CMDParserTests.o \
./tests/ReceiveTests.o \
./tests/SendReceiveQueueTests.o \
./tests/SendTests.o \
./tests/TLMParserTests.o \
./tests/WorkQueueTests.o \
./tests/XMLValidatorTests.o 

CPP_DEPS += \
./tests/AllTests.d \
./tests/CMDParserTests.d \
./tests/ReceiveTests.d \
./tests/SendReceiveQueueTests.d \
./tests/SendTests.d \
./tests/TLMParserTests.d \
./tests/WorkQueueTests.d \
./tests/XMLValidatorTests.d 


# Each subdirectory must supply rules for building sources it contributes
tests/%.o: ../tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"C:\workspaceLEON\SatProject" -O0 -g3 -Wall -msoft-float -mcpu=v8 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


