CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test logicsim-exe

#-----------------------------------------------------
# Build llrec-test executable
#-----------------------------------------------------
llrec-test: llrec-test.o llrec.o
	$(CXX) $(CXXFLAGS) -o $@ $^

llrec-test.o: llrec-test.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

#-----------------------------------------------------
# Build logicsim executable - 重命名可执行文件
#-----------------------------------------------------
logicsim-exe: logicsim.o circuit.o gate.o wire.o
	$(CXX) $(CXXFLAGS) -o $@ $^

logicsim.o: logicsim/logicsim.cpp logicsim/circuit.h
	$(CXX) $(CXXFLAGS) -c -o $@ logicsim/logicsim.cpp

circuit.o: logicsim/circuit.cpp logicsim/circuit.h heap.h logicsim/event.h logicsim/gate.h
	$(CXX) $(CXXFLAGS) -c -o $@ logicsim/circuit.cpp

gate.o: logicsim/gate.cpp logicsim/gate.h logicsim/event.h logicsim/wire.h
	$(CXX) $(CXXFLAGS) -c -o $@ logicsim/gate.cpp

wire.o: logicsim/wire.cpp logicsim/wire.h
	$(CXX) $(CXXFLAGS) -c -o $@ logicsim/wire.cpp

#-----------------------------------------------------
# Test targets
#-----------------------------------------------------
test-llrec: llrec-test
	./llrec-test llrec-test1.in

test-logicsim: logicsim-exe
	./logicsim-exe logicsim/single_not.txt > my_not.uml
	java -jar logicsim/plantuml.jar my_not.uml

valgrind-llrec: llrec-test
	$(VALGRIND) ./llrec-test llrec-test1.in

valgrind-logicsim: logicsim-exe
	$(VALGRIND) ./logicsim-exe logicsim/single_not.txt

clean:
	rm -f *.o llrec-test logicsim-exe *~ *.uml *.png

.PHONY: clean all test-llrec test-logicsim valgrind-llrec valgrind-logicsim