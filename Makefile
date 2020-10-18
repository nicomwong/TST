CXX = g++

CXXFLAGS = -std=c++11 -Wall

BINARIES = TSTTest

main: #for the final product

testEmpty: TSTTest
	./$^ "empty"

testLinear: TSTTest
	./$^ "linear"

testSmall: TSTTest
	./$^ "small"

testLarge: TSTTest
	./$^ "large"

testHuge: TSTTest
	./$^ "huge"

TSTTest: TSTTest.o TST.o
	${CXX} ${CXXFLAGS} -g $^ -o $@

TSTTest.o: TSTTest.cpp
	${CXX} ${CXXFLAGS} -c $^

TST.o: TST.cpp
	${CXX} ${CXXFLAGS} -c $^

clean:
	/bin/rm -f ${BINARIES} *.o
