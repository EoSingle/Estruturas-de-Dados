CC=g++
CFLAGS=-Wall
TARGET=programa

BIN_DIR    = ./bin
SRC_DIR    = ./src
INCLUDE_DIR  = ./include
OBJ_DIR = ./obj

all: ${BIN_DIR}/${TARGET}

${BIN_DIR}/${TARGET}: ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} -o ${BIN_DIR}/${TARGET} ${OBJ_DIR}/*.o

${OBJ_DIR}/main.o: ${OBJ_DIR}/filacircular.o ${OBJ_DIR}/pilha.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

${OBJ_DIR}/pilha.o: ${OBJ_DIR}/filacircular.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/Pilha.cpp -o ${OBJ_DIR}/pilha.o

${OBJ_DIR}/filacircular.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/FilaCircular.cpp -o ${OBJ_DIR}/filacircular.o

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${BIN_DIR}/${TARGET}

run: all 
	${BIN_DIR}/${TARGET}
