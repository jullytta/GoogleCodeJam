P=A
CXX=g++
CXXFLAGS=-std=c++11 -Wall

${P}: ${P}.cpp
	${CXX} ${P}.cpp -o ${P} ${CXXFLAGS}

run: ${P}
	./${P} < ${P}.in > out

test: run
	diff ${P}.out out

clean:
	rm -f A B C D
