CC=g++
CFLAGS=-Wall -g
TARGET=programa

BIN_DIR    = ./bin
SRC_DIR    = ./src
INCLUDE_DIR  = ./include
OBJ_DIR = ./obj

all: ${BIN_DIR}/${TARGET}

${BIN_DIR}/${TARGET}: ${OBJ_DIR}/main.o
	${CC} ${CFLAGS} -o ${BIN_DIR}/${TARGET} ${OBJ_DIR}/*.o

${OBJ_DIR}/main.o: ${OBJ_DIR}/tipono.o ${OBJ_DIR}/node.o ${OBJ_DIR}/pilha.o ${OBJ_DIR}/pilhaencadeada.o ${OBJ_DIR}/arvore.o ${OBJ_DIR}/resolvedor.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/main.cpp -o ${OBJ_DIR}/main.o
	
${OBJ_DIR}/tipono.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/TipoNo.cpp -o ${OBJ_DIR}/tipono.o

${OBJ_DIR}/node.o: ${OBJ_DIR}/tipono.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/node.cpp -o ${OBJ_DIR}/node.o

${OBJ_DIR}/pilha.o: ${OBJ_DIR}/tipono.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/pilha.cpp -o ${OBJ_DIR}/pilha.o

${OBJ_DIR}/pilhaencadeada.o: ${OBJ_DIR}/node.o ${OBJ_DIR}/pilha.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/pilhaEncadeada.cpp -o ${OBJ_DIR}/pilhaencadeada.o

${OBJ_DIR}/nodef.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/nodef.cpp -o ${OBJ_DIR}/nodef.o

${OBJ_DIR}/pilhaf.o:
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/pilhaf.cpp -o ${OBJ_DIR}/pilhaf.o

${OBJ_DIR}/pilhafloat.o: ${OBJ_DIR}/nodef.o ${OBJ_DIR}/pilhaf.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/pilhafloat.cpp -o ${OBJ_DIR}/pilhafloat.o

${OBJ_DIR}/arvore.o: ${OBJ_DIR}/tipono.o ${OBJ_DIR}/node.o ${OBJ_DIR}/pilhaencadeada.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/arvore.cpp -o ${OBJ_DIR}/arvore.o

${OBJ_DIR}/resolvedor.o: ${OBJ_DIR}/pilhaencadeada.o ${OBJ_DIR}/arvore.o ${OBJ_DIR}/pilhafloat.o
	${CC} ${CFLAGS} -I${INCLUDE_DIR} -c ${SRC_DIR}/resolvedor.cpp -o ${OBJ_DIR}/resolvedor.o

clean:
	rm -f ${OBJ_DIR}/*.o
	rm -f ${BIN_DIR}/${TARGET}

run: all 
	${BIN_DIR}/${TARGET}

teste: clean run
