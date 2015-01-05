################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../communication/CommunicationHandlerFactory.cpp \
../communication/SendReceiveQueue.cpp \
../communication/UartCommunicationHandler.cpp 

OBJS += \
./communication/CommunicationHandlerFactory.o \
./communication/SendReceiveQueue.o \
./communication/UartCommunicationHandler.o 

CPP_DEPS += \
./communication/CommunicationHandlerFactory.d \
./communication/SendReceiveQueue.d \
./communication/UartCommunicationHandler.d 


# Each subdirectory must supply rules for building sources it contributes
communication/%.o: ../communication/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"C:\workspaceLEON\SatProject" -O0 -g3 -Wall -msoft-float -mcpu=v8 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


