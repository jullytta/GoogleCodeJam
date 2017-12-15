P=C
CXX=g++
CXXFLAGS=-std=c++11 -Wall
CILKFLAGS=-fcilkplus

${P}: ${P}.cpp
	${CXX} ${P}.cpp -o ${P} ${CXXFLAGS}

run: ${P}
	./${P}

clean:
	rm -f A B C D
