#ifndef FACCAO_H
#define FACCAO_H

typedef struct _faccao TFaccao;
typedef struct _cfaccao CFaccao;

#include "mapa.h"

TFaccao *Tfaccao_aloca(const char *nome, const int x, const int y);
CFaccao *Cfaccao_cria(void);
void cfaccao_desaloca(CFaccao **cabeca);
void tfaccao_desaloca(CFaccao *cabeca, char *nome_faccao);

int Cfaccao_vazia(const CFaccao *cabeca);
int faccao_existe(const CFaccao *cabeca, const char *nome);
int faccao_verifica_posicao(CFaccao *cabeca, const int x, const int y);
void faccao_inserir(CFaccao *cabeca, const char *nome, const int x, const int y);
void faccoes_converte_txt_lista(CFaccao *cabeca, const char *nome_arquivo);
void faccoes_display(const CFaccao *cabeca);
void faccoes_posicionar_mapa(const CFaccao *cabeca, char **mapa);
TFaccao *faccao_buscar(CFaccao *cabeca, char *nome);
void faccao_coleta(CFaccao *cabeca, const char identificador, const int tipo, const int qtd);
void faccao_combate(CFaccao *cabeca, char *f1, char *f2);
void faccao_teste(CFaccao *cabeca);
void faccao_alianca(CFaccao *cabeca, char *f1, char *f2);
void mapa_faccao_atualiza(CFaccao *cabeca, char **mapa_faccao, Dimensao *dimensao);

#endif