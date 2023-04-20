CC=g++
CFLAGS=-std=c++11 -Wall -pg
TARGET=programa

BIN_DIR    = ./bin
SRC_DIR    = ./source
INCLUDE_DIR  = ./include

all: ${BIN_DIR}/${TARGET}

${BIN_DIR}/${TARGET}: ${BIN_DIR}/main.o ${BIN_DIR}/fat.o ${BIN_DIR}/fib.o
	${CC} ${CFLAGS} -o ${TARGET} ${BIN_DIR}/*.o

${BIN_DIR}/main.o: ${BIN_DIR}/fat.o ${BIN_DIR}/fib.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${BIN_DIR}/main.o

${BIN_DIR}/fat.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/fatorial.cpp -o ${BIN_DIR}/fat.o

${BIN_DIR}/fib.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/fibonacci.cpp -o ${BIN_DIR}/fib.o

	

	
clean:
	rm -f ${BUILD_DIR}/*.o

run: all 
	$(EXE) -s -x 5 -y 5
	$(EXE) -m -x 5 -y 5
	$(EXE) -t -x 5 -y 5
