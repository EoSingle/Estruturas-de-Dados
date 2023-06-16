CC=gcc
CFLAGS=-Wall -g
TARGET=programa

BIN_DIR = ./bin
SRC_DIR = ./src
INCLUDE_DIR = ./include
OBJ_DIR = ./obj


all: ${BIN_DIR}/${TARGET}

${BIN_DIR}/${TARGET}: ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} -o ${BIN_DIR}/${TARGET} ${OBJ_DIR}/*.o 

${OBJ_DIR}/main.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/arvexp.c -o ${OBJ_DIR}/main.o

run: all
	${BIN_DIR}/${TARGET}

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${BIN_DIR}/${TARGET}

teste: clean run