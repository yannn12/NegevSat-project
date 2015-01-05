################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../hardware/EnergyModule.cpp \
../hardware/HardwareState.cpp \
../hardware/PayloadModule.cpp \
../hardware/SbandModule.cpp \
../hardware/SolarPanelsModule.cpp \
../hardware/TemperatureModule.cpp \
../hardware/ThermalControlModule.cpp 

OBJS += \
./hardware/EnergyModule.o \
./hardware/HardwareState.o \
./hardware/PayloadModule.o \
./hardware/SbandModule.o \
./hardware/SolarPanelsModule.o \
./hardware/TemperatureModule.o \
./hardware/ThermalControlModule.o 

CPP_DEPS += \
./hardware/EnergyModule.d \
./hardware/HardwareState.d \
./hardware/PayloadModule.d \
./hardware/SbandModule.d \
./hardware/SolarPanelsModule.d \
./hardware/TemperatureModule.d \
./hardware/ThermalControlModule.d 


# Each subdirectory must supply rules for building sources it contributes
hardware/%.o: ../hardware/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: SPARC RTEMS C++ Compiler'
	sparc-rtems-g++ -I"C:\workspaceLEON\SatProject" -O0 -g3 -Wall -msoft-float -mcpu=v8 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


