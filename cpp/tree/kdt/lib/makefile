# 'make depend' uses makedepend to automatically generate dependencies 
# (dependencies are added to end of Makefile)
# 'make'	build executable file 'kdt'
# 'make clean'  removes all .o and executable files
#

# C++ compiler to use
CC = g++
AR = ar

# C++ compiler flags (-g -O2 -Wall)
CXXFLAGS = -Wall -g -Wextra -pedantic-errors -std=c++11 -fPIC -static
ARFLAGS = rcs
# define any directories containing header files other than /usr/include
INCLUDES = -I../common -I../../depends -I.  

# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = -L../lib -static
#-shared 

# libraries to link:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lm 

# C++ source files
SRCS =  kdpoint.cpp 
#SRCS +=  KDTree.cpp

# C object files 
OBJS = $(SRCS:.cpp=.o)

# define the executable file 
#MAIN = libKDTree.so 
TARGET_LIB = libkdtree.a
#TARGET_LIB = libKDTree.so


# define the static library 
OUT_DIR= ../lib

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:	$(TARGET_LIB)
		@echo  Build process completed. 

$(TARGET_LIB): $(OBJS)
	$(AR) $(ARFLAGS) $(TARGET_LIB) $(OBJS) 
#	$(CC) $(CXXFLAGS) $(INCLUDES) -o $(TARGET_LIB) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
		$(CC) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@
.cpp.o:
		$(CC) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@

clean:
		$(RM) *.o *~ $(TARGET_LIB)

depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- End of File
