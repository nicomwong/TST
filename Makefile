CXX = g++

CXXFLAGS = -std=c++11

BINARIES = TSTTest

test: TSTTest
	./$^

TSTTest: main.o TST.o
	${CXX} ${CXXFLAGS} $^ -o $@

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c $^

TST.o: TST.cpp
	${CXX} ${CXXFLAGS} -c $^

clean:
	/bin/rm -f ${BINARIES} *.o
