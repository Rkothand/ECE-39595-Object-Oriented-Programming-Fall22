# suffix rules don't allow pre-requisites to be used and are deprecated for
# this reason.  The right way to do this is to use patterns.  The "%" pattern
# allows any file to be matched.
OBJS = HW1.o Automobile.o
GPP = g++
# INCLUDE = 
# LIBS = 
CFLAGS = -Wall -Wextra _Werror -std=c++11
EXECUTABLE = HW1
#COMMANDLINE =


$(EXECUTABLE): $(OBJS) 
	$(GPP) $(OBJS) -o $(EXECUTABLE) 
	./$(EXECUTABLE)


run : $(EXECUTABLE)
	./$(EXECUTABLE) 


clean :
	rm -f $(OBJS) $(EXECUTABLE)  *.o