CC=g++
CFLAGS=-Wall -g
TARGET=programa

BIN_DIR      = ./bin
SRC_DIR      = ./src
INCLUDE_DIR  = ./include
OBJ_DIR      = ./obj

all: ${BIN_DIR}/${TARGET}

${BIN_DIR}/${TARGET}: ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} -o ${BIN_DIR}/${TARGET} ${OBJ_DIR}/*.o

${OBJ_DIR}/main.o: ${OBJ_DIR}/huffman.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

${OBJ_DIR}/huffman.o: ${OBJ_DIR}/tree.o ${OBJ_DIR}/queue.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/huffman.cpp -o ${OBJ_DIR}/huffman.o

${OBJ_DIR}/tree.o: ${OBJ_DIR}/node.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/tree.cpp -o ${OBJ_DIR}/tree.o

${OBJ_DIR}/node.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/node.cpp -o ${OBJ_DIR}/node.o

${OBJ_DIR}/queue.o: ${OBJ_DIR}/node.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/queue.cpp -o ${OBJ_DIR}/queue.o

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${BIN_DIR}/${TARGET}

run: all
	${BIN_DIR}/${TARGET} 

teste: clean all
	${BIN_DIR}/${TARGET} -c test/input.txt test/output.bin
