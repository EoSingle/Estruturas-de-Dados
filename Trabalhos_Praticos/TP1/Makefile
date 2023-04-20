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

${OBJ_DIR}/main.o: ${OBJ_DIR}/node.o ${OBJ_DIR}/pilha.o ${OBJ_DIR}/pilhaencadeada.o ${OBJ_DIR}/resolvedor.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o
	
${OBJ_DIR}/node.o: 
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/node.cpp -o ${OBJ_DIR}/node.o

${OBJ_DIR}/pilha.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/pilha.cpp -o ${OBJ_DIR}/pilha.o

${OBJ_DIR}/pilhaencadeada.o: ${OBJ_DIR}/node.o ${OBJ_DIR}/pilha.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/pilhaEncadeada.cpp -o ${OBJ_DIR}/pilhaencadeada.o

${OBJ_DIR}/resolvedor.o: ${OBJ_DIR}/pilhaencadeada.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/resolvedor.cpp -o ${OBJ_DIR}/resolvedor.o

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${BIN_DIR}/${TARGET}

run: all 
	${BIN_DIR}/${TARGET}