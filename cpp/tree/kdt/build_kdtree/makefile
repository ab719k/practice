# 'make depend' uses makedepend to automatically generate dependencies 
# (dependencies are added to end of Makefile)
# 'make'	build executable file 'kdt'
# 'make clean'  removes all .o and executable files
#

# C++ compiler to use
CC = g++

# C++ compiler flags (-g -O2 -Wall)
CXXFLAGS = -Wall -g -Wextra -pedantic-errors -std=c++11 -fPIC -static 
#-fPIC -shared 

# define any directories containing header files other than /usr/include
INCLUDES = -I. -I.. -I../common 


# define library paths in addition to /usr/lib
#   if I wanted to include libraries not in /usr/lib I'd specify
#   their path using -Lpath, something like:
LFLAGS = -L../lib 

# libraries to link:
#   if I want to link in libraries (libx.so or libx.a) I use the -llibname 
#   option, something like (this will link in libmylib.so and libm.so:
LIBS = -lm -lkdtree
#LIBS += -l/home/amitbhatia76/c_programming/practice/cpp/tree/kdt/lib

# C++ source files
SRCS = test.cpp 
#SRCS = KDPoint.cpp 

# C object files 
OBJS = $(SRCS:.cpp=.o)

# define the executable file 
TARGET_EXE = build_kdtree 

#
# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above and by
# deleting dependencies appended to the file from 'make depend'
#

.PHONY: depend clean

all:	$(TARGET_EXE)
		@echo  Build process completed. 

$(TARGET_EXE): $(OBJS) 
		$(CC) $(CXXFLAGS) $(INCLUDES) $(OBJS) $(LFLAGS) $(LIBS) -o $(TARGET_EXE)

.c.o:
		$(CC) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@
.cpp.o:
		$(CC) $(CXXFLAGS) $(INCLUDES) -c $<  -o $@ $(LFLAGS) $(LIBS)


clean:
		$(RM) *.o *~ $(TARGET_EXE)

depend: $(SRCS)
		makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- End of File
