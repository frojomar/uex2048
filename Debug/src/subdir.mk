################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/entorno.cpp \
../src/juego.cpp \
../src/pruebas.cpp \
../src/tadtablero.cpp \
../src/uex2048.cpp 

OBJS += \
./src/entorno.o \
./src/juego.o \
./src/pruebas.o \
./src/tadtablero.o \
./src/uex2048.o 

CPP_DEPS += \
./src/entorno.d \
./src/juego.d \
./src/pruebas.d \
./src/tadtablero.d \
./src/uex2048.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


