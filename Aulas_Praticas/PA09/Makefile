CC=g++
CFLAGS=-Wall -g
TARGET=programa

BIN_DIR = ./bin
SRC_DIR = ./src
INCLUDE_DIR = ./include
OBJ_DIR = ./obj


all: ${BIN_DIR}/${TARGET}

${BIN_DIR}/${TARGET}: ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} -o ${BIN_DIR}/${TARGET} ${OBJ_DIR}/*.o 

${OBJ_DIR}/main.o: ${OBJ_DIR}/tree.o 
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

${OBJ_DIR}/tree.o: ${OBJ_DIR}/node.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/tree.cpp -o ${OBJ_DIR}/tree.o

${OBJ_DIR}/node.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/node.cpp -o ${OBJ_DIR}/node.o

run: all
	${BIN_DIR}/${TARGET}

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${BIN_DIR}/${TARGET}

teste: clean run