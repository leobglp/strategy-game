#ifndef MAPA_H
#define MAPA_H

typedef struct _Dimensao Dimensao;
Dimensao *mapa_le_dimensao(const char *nome_arquivo);
char **mapa_aloca(Dimensao *d);
void mapa_gera(char **mapa, Dimensao *d);
void mapa_display(char **mapa, Dimensao *d);
void desaloca_mapa(char ***mapa, Dimensao *d);
void desaloca_dimensao(Dimensao **d);
int mapa_vazio(char **matriz, int linhas, int colunas);

#endif 