#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <sys/time.h>
#include <getopt.h>
#include <string.h>
#include <math.h>

// Syntax tree structure
typedef long TipoChave;
typedef struct TipoRegistro {
  TipoChave Chave;
} TipoRegistro;
typedef struct TipoNo * TipoApontador;
typedef struct TipoNo {
  TipoRegistro Reg;
  TipoApontador Esq, Dir;
} TipoNo;

typedef struct prm{
  char nomesaida[200];
  int semente;
  int numno;
  FILE * saida;
  int treesize;
  int numlevel;
} prm_t;

void uso()
// Descricao: imprime as instrucoes de uso do programa
// Entrada:  N/A
// Saida: instrucoes
{
  fprintf(stderr,"geraexp\n");
  fprintf(stderr,"\t-o <arq>\t(arquivo de saida) \n");
  fprintf(stderr,"\t-s <num>\t(semente)\n");
  fprintf(stderr,"\t-n <num>\t(numero de nos)\n");
  fprintf(stderr,"\t-h\t(opcoes de uso)\n");
}

void parse_args(int argc, char ** argv, prm_t * prm)
// Descricao: analisa a linha de comando a inicializa variaveis
// Entrada: argc e argv
// Saida: prm
{
     extern char * optarg;
     extern int optind;
     int c ;
     // valores padrao
     prm->nomesaida[0] = 0;
     prm->semente = 0;
     prm->numno = 3;
     prm->numlevel = 2;
     // percorre a linha de comando buscando identificadores
     while ((c = getopt(argc, argv, "o:s:n:iph")) != EOF){
       switch(c) {
         case 'o':
	          // arquivo de saida
	          strcpy(prm->nomesaida,optarg);
                  break;
         case 's':
	          // semente aleatoria
	          prm->semente = atoi(optarg);
		  srand48((long) prm->semente);
		  break;
         case 'n':
	          // numero de nos
	          prm->numno = atoi(optarg);
		  prm->numlevel = ((int) log2((double) prm->numno))+2;
		  break;
         case 'h':
         default:
                  uso();
                  exit(1);

       }
     }
     // verifica apenas o nome do arquivo de saida
     if (!prm->nomesaida[0]) {
       printf("Arquivo de saida nao definido.");
       exit(1);
     }
}

void dumpTree(TipoApontador * T, int level, prm_t * prm) {
  if ((*T) != NULL) {
    for(int i=0; i<level; i++) fprintf(prm->saida,"    ");
    fprintf(prm->saida," %3ld (%d)\n", (*T)->Reg.Chave,level);
    dumpTree(&(*T)->Esq,level+1,prm);
    dumpTree(&(*T)->Dir,level+1,prm);
  }
}

int createTree(TipoNo ** curr, int level, prm_t * prm){
  // create node
  (*curr) = (TipoNo*) malloc(sizeof(TipoNo));
  (*curr)->Esq = (*curr)->Dir = NULL;
  // set type
  if (drand48()>((8.0*(1<<level)*prm->treesize))/(((1<<prm->numlevel)*prm->numno))){
    (*curr)->Reg.Chave = prm->treesize;
    prm->treesize++;
    if (prm->treesize<prm->numno) createTree(&((*curr)->Esq),level+1,prm);
    if (prm->treesize<prm->numno) createTree(&((*curr)->Dir),level+1,prm);
  } else {
    (*curr)->Reg.Chave = prm->treesize;
    prm->treesize++;
  }
  return prm->treesize;
}

int ancestral(int i, int j, int *preorder, int *inorder, int *postorder, int tamanho) {
  // Encontra a posição dos nós i e j no vetor inorder
  int pos_i = -1, pos_j = -1;
  for (int k = 0; k < tamanho; k++) {
    if (inorder[k] == i) {
      pos_i = k;
    }
    if (inorder[k] == j) {
      pos_j = k;
    }
  }

  // Verifica se o nó i aparece antes do nó j nos três vetores
  int pos_ipre = -1, pos_jpre = -1, pos_ipost = -1, pos_jpost = -1;
  for (int k = 0; k < tamanho; k++) {
    if (preorder[k] == i) {
      pos_ipre = k;
    }
    if (preorder[k] == j) {
      pos_jpre = k;
    }
    if (postorder[k] == i) {
      pos_ipost = k;
    }
    if (postorder[k] == j) {
      pos_jpost = k;
    }
  }

  if (pos_i < pos_j && pos_ipre < pos_jpre && pos_ipost < pos_jpost) {
    return 1;
  } else {
    return 0;
  }
}


void preorder_arvore(TipoApontador T, int *vetor, int *posicao) {
  if (T != NULL) {
    vetor[*posicao] = T->Reg.Chave;
    (*posicao)++;
    preorder_arvore(T->Esq, vetor, posicao);
    preorder_arvore(T->Dir, vetor, posicao);
  }
}

void inorder_arvore(TipoApontador T, int *vetor, int *posicao) {
  if (T != NULL) {
    inorder_arvore(T->Esq, vetor, posicao);
    vetor[*posicao] = T->Reg.Chave;
    (*posicao)++;
    inorder_arvore(T->Dir, vetor, posicao);
  }
}

void postorder_arvore(TipoApontador T, int *vetor, int *posicao) {
  if (T != NULL) {
    postorder_arvore(T->Esq, vetor, posicao);
    postorder_arvore(T->Dir, vetor, posicao);
    vetor[*posicao] = T->Reg.Chave;
    (*posicao)++;
  }
}

int gera_vetores_caminhamento(TipoApontador T, int **preorder, int **inorder, int **postorder) {
  // calcula o tamanho dos vetores
  int tamanho = 0;
  if (T != NULL) {
    // conta o número de nós na árvore
    tamanho = 1 + gera_vetores_caminhamento(T->Esq, preorder, inorder, postorder) +
              gera_vetores_caminhamento(T->Dir, preorder, inorder, postorder);
  }

  // aloca memória para os vetores
  *preorder = (int *)malloc(tamanho * sizeof(int));
  *inorder = (int *)malloc(tamanho * sizeof(int));
  *postorder = (int *)malloc(tamanho * sizeof(int));

  // gera os vetores
  int posicao = 0;
  preorder_arvore(T, *preorder, &posicao);
  posicao = 0;
  inorder_arvore(T, *inorder, &posicao);
  posicao = 0;
  postorder_arvore(T, *postorder, &posicao);

  return tamanho;
}


int main(int argc, char *argv[])
{
  TipoNo *root;
  prm_t prm;
  int i,j;

  parse_args(argc,argv,&prm);
  prm.saida = fopen(prm.nomesaida,"wt");
  prm.treesize = 0;

  createTree(&root,0,&prm);
  dumpTree(&root,0,&prm);

  // gera os vetores de caminhamento
  int *preorder, *inorder, *postorder;
  int tamanho = gera_vetores_caminhamento(root, &preorder, &inorder, &postorder);

  for (int k=0; k<prm.treesize; k++){
    i = j = 0;
    while (i==j){
      i = (int) (drand48()*tamanho);
      j = (int) (drand48()*tamanho);
    }
    fprintf(prm.saida,"%d testando ancestral(%d,%d)\n",k,i,j);
    // verifica se i é ancestral de j usando os vetores de caminhamento
    if (ancestral(i, j, preorder, inorder, postorder, tamanho)) {
      fprintf(prm.saida,"  ancestral(%d,%d) = 1\n",i,j);
    } else {
      fprintf(prm.saida,"  ancestral(%d,%d) = 0\n",i,j);
    }
  }

  fclose(prm.saida);
  return 0;
}

// Lucas Albano - 2022036029
// O código ira gerar as saídas na pasta /outputs
// make run irá gerar as saídas para 10 casos de teste com seeds de 0 a 9 com árvores de tamanho 10