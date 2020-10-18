CXX = g++

CXXFLAGS = -std=c++11 -Wall

BINARIES = TSTTest project1.out

project1.out: TST.o main.o
	${CXX} ${CXXFLAGS} -g $^ -o $@

testEmpty: TSTTest
	./$^ "empty"

testRoot: TSTTest
	./$^ "root"

testLinear: TSTTest
	./$^ "linear"

testSmall: TSTTest
	./$^ "small"

testLarge: TSTTest
	./$^ "large"

testDestructor: TSTTest
	./$^ "destructor"

TSTTest: TSTTest.o TST.o
	${CXX} ${CXXFLAGS} -g $^ -o $@

TSTTest.o: TSTTest.cpp
	${CXX} ${CXXFLAGS} -c $^

TST.o: TST.cpp
	${CXX} ${CXXFLAGS} -c $^

clean:
	/bin/rm -f ${BINARIES} *.o
