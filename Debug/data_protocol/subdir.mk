################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../data_protocol/CMDParser.cpp \
../data_protocol/Sample.cpp \
../data_protocol/TLMParser.cpp \
../data_protocol/TempPacket.cpp \
../data_protocol/ValidatorFactory.cpp \
../data_protocol/WorkDescription.cpp \
../data_protocol/WorkQueue.cpp \
../data_protocol/XMLValidator.cpp 

OBJS += \
./data_protocol/CMDParser.o \
./data_protocol/Sample.o \
./data_protocol/TLMParser.o \
./data_protocol/TempPacket.o \
./data_protocol/ValidatorFactory.o \
./data_protocol/WorkDescription.o \
./data_protocol/WorkQueue.o \
./data_protocol/XMLValidator.o 

CPP_DEPS += \
./data_protocol/CMDParser.d \
./data_protocol/Sample.d \
./data_protocol/TLMParser.d \
./data_protocol/TempPacket.d \
./data_protocol/ValidatorFactory.d \
./data_protocol/WorkDescription.d \
./data_protocol/WorkQueue.d \
./data_protocol/XMLValidator.d 


# Each subdirectory must supply rules for building sources it contributes
data_protocol/%.o: ../data_protocol/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"C:\workspaceLEON\SatProject" -O0 -g3 -Wall -msoft-float -mcpu=v8 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


