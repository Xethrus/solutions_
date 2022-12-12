# the compiler: gcc for C program, define as g++ for C++
  CC = g++
 
  # compiler flags:
  #  -g     - this flag adds debugging information to the executable file
  #  -Wall  - this flag is used to turn on most compiler warnings
  CFLAGS  = -g -Wall
 
  # The build target 
  TARGET = problem_1.cpp 
 
  all: $(problem_1)
 
  $(problem_1): $(problem_1).cpp
              $(CC) $(CFLAGS) -o $(problem_1) $(problem_1).cpp
 
  clean:
              $(RM) $(TARGET)
