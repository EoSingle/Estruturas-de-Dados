CC=g++
CFLAGS=-Wall -g -std=c++11
TARGET=programa

BIN_DIR    = ./bin
SRC_DIR    = ./src
INCLUDE_DIR  = ./include
OBJ_DIR = ./obj

all: ${BIN_DIR}/${TARGET}

${BIN_DIR}/${TARGET}: ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} -o ${BIN_DIR}/${TARGET} ${OBJ_DIR}/*.o

${OBJ_DIR}/main.o: ${OBJ_DIR}/ponto.o ${OBJ_DIR}/node.o ${OBJ_DIR}/pilha.o ${OBJ_DIR}/graham.o ${OBJ_DIR}/jarvis.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

${OBJ_DIR}/ponto.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/ponto.cpp -o ${OBJ_DIR}/ponto.o

${OBJ_DIR}/node.o: ${OBJ_DIR}/ponto.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/node.cpp -o ${OBJ_DIR}/node.o

${OBJ_DIR}/pilha.o: ${OBJ_DIR}/node.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/pilha.cpp -o ${OBJ_DIR}/pilha.o

${OBJ_DIR}/graham.o: ${OBJ_DIR}/ponto.o ${OBJ_DIR}/node.o ${OBJ_DIR}/pilha.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/graham.cpp -o ${OBJ_DIR}/graham.o

${OBJ_DIR}/jarvis.o: ${OBJ_DIR}/ponto.o ${OBJ_DIR}/node.o ${OBJ_DIR}/pilha.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/jarvis.cpp -o ${OBJ_DIR}/jarvis.o

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${BIN_DIR}/${TARGET}

run: all
	${BIN_DIR}/${TARGET}

teste: clean run
