CC=gcc
CFLAGS=-Wall
TARGET=programa

BIN_DIR    = ./bin
SRC_DIR    = ./src
INCLUDE_DIR  = ./include
OBJ_DIR = ./obj
OUTPUT_DIR = ./outputs

all: ${BIN_DIR}/${TARGET}

${BIN_DIR}/${TARGET}: ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} -o ${BIN_DIR}/${TARGET} ${OBJ_DIR}/*.o -lm

${OBJ_DIR}/main.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/geraarvbin.c -o ${OBJ_DIR}/main.o

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${BIN_DIR}/${TARGET}
	rm -f ${OUTPUT_DIR}/*.txt

run: all 
	${BIN_DIR}/${TARGET} -o ${OUTPUT_DIR}/seed0.txt -s 0 -n 10
	${BIN_DIR}/${TARGET} -o ${OUTPUT_DIR}/seed1.txt -s 1 -n 10
	${BIN_DIR}/${TARGET} -o ${OUTPUT_DIR}/seed2.txt -s 2 -n 10
	${BIN_DIR}/${TARGET} -o ${OUTPUT_DIR}/seed3.txt -s 3 -n 10
	${BIN_DIR}/${TARGET} -o ${OUTPUT_DIR}/seed4.txt -s 4 -n 10
	${BIN_DIR}/${TARGET} -o ${OUTPUT_DIR}/seed5.txt -s 5 -n 10
	${BIN_DIR}/${TARGET} -o ${OUTPUT_DIR}/seed6.txt -s 6 -n 10
	${BIN_DIR}/${TARGET} -o ${OUTPUT_DIR}/seed7.txt -s 7 -n 10
	${BIN_DIR}/${TARGET} -o ${OUTPUT_DIR}/seed8.txt -s 8 -n 10
	${BIN_DIR}/${TARGET} -o ${OUTPUT_DIR}/seed9.txt -s 9 -n 10
	
