################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../cairo_frame.cpp \
../character_generator.cpp \
../condition.cpp \
../cpu_dispatch.cpp \
../exagl.cpp \
../mutex.cpp \
../posix_util.cpp \
../raw_frame.cpp \
../rsvg_frame.cpp \
../svg_subprocess_character_generator.cpp \
../thread.cpp \
../xmalloc.cpp 

OBJS += \
./cairo_frame.o \
./character_generator.o \
./condition.o \
./cpu_dispatch.o \
./exagl.o \
./mutex.o \
./posix_util.o \
./raw_frame.o \
./rsvg_frame.o \
./svg_subprocess_character_generator.o \
./thread.o \
./xmalloc.o 

CPP_DEPS += \
./cairo_frame.d \
./character_generator.d \
./condition.d \
./cpu_dispatch.d \
./exagl.d \
./mutex.d \
./posix_util.d \
./raw_frame.d \
./rsvg_frame.d \
./svg_subprocess_character_generator.d \
./thread.d \
./xmalloc.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -DX86_64 -I/usr/include/cairo -I/usr/include/glib-2.0 -I/usr/include/gtk-2.0 -I/usr/include/librsvg-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/gdk-pixbuf-2.0 -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


