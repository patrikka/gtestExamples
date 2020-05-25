TEST = testAll
CXX = g++
CXXFLAGS = -Wall -g -std=c++11 -L/usr/local/lib -lgtest -lgmock -lpthread
VALGRINDFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
INCS = -I./ -I../ -I/usr/local/include
OBJS = ../AbstractInterfaceUser.o \
	../TemplateInterfaceUser.o \
    FloatTester.o \
	DoubleTester.o \
	OutputTester.o \
	AbstractInterfaceUserTester.o \
	TemplateInterfaceUserTester.o

all: test

$(TEST): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) $(INCS) -o $@ testAll.cpp

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@ $(INCS)

test:	$(TEST)
		@echo "Test	$(TEST)"
		@./$(TEST)

memcheck: $(TEST)
		@valgrind $(VALGRINDFLAGS) ./$(TEST)

clean:
	rm testAll *.o ../*.o

.PHONY: all clean test memcheck
