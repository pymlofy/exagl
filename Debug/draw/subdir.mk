################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../draw/BGRAn8_alpha_key.cpp \
../draw/BGRAn8_blit.cpp 

OBJS += \
./draw/BGRAn8_alpha_key.o \
./draw/BGRAn8_blit.o 

CPP_DEPS += \
./draw/BGRAn8_alpha_key.d \
./draw/BGRAn8_blit.d 


# Each subdirectory must supply rules for building sources it contributes
draw/%.o: ../draw/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DX86_64 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/include/gtk-2.0 -I/usr/include/librsvg-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/gdk-pixbuf-2.0 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


