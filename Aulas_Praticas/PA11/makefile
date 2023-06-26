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

${OBJ_DIR}/main.o: ${OBJ_DIR}/relacao.o ${OBJ_DIR}/conjunto_disjunto.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o

${OBJ_DIR}/relacao.o: 
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/Relacao.cpp -o ${OBJ_DIR}/relacao.o

${OBJ_DIR}/conjunto_disjunto.o: ${OBJ_DIR}/set.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/ConjuntoDisjunto.cpp -o ${OBJ_DIR}/conjunto_disjunto.o

${OBJ_DIR}/set.o: ${OBJ_DIR}/list.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/set.cpp -o ${OBJ_DIR}/set.o

${OBJ_DIR}/list.o: ${OBJ_DIR}/node.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/list.cpp -o ${OBJ_DIR}/list.o

${OBJ_DIR}/node.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/node.cpp -o ${OBJ_DIR}/node.o

run: all
	${BIN_DIR}/${TARGET}
	gnuplot plot.plt

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${BIN_DIR}/${TARGET}
	rm -f ${SRC_DIR}/*.o
	rm -f grafico.pdf
	rm -f data.dat
