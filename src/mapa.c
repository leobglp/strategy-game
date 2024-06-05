#include "bibliotecas.h"

typedef struct _Dimensao
{
    int n, m;
} Dimensao;

Dimensao *mapa_le_dimensao(const char *nome_arquivo)
{
    FILE *arquivo = fopen(nome_arquivo, "r");
    Dimensao *d = (Dimensao*)malloc(sizeof(Dimensao));

    if (!arquivo){
        msg_erro("Nao foi possível abrir o arquivo.", "mapa_le_dimensao");
        free(d);  // Libera a memória alocada
        return NULL;
    }

    // Lê as dimensoes do mapa
    int n, m;
    if (fscanf(arquivo, "%d %d", &n, &m) != 2){
        msg_erro("Erro ao ler a dimensao do mapa", "mapa_inicializa");
        fclose(arquivo);
        free(d);  // Libera a memória alocada
        return NULL;
    }
    fclose(arquivo);
    d->n = n;
    d->m = m;
    return d;
}

Dimensao *seta_dimensao(const int n, const int m)
{
    Dimensao *aux = (Dimensao*)malloc(sizeof(Dimensao));
    aux->n = n;
    aux->m = m;
    return aux;
}

char **mapa_aloca(Dimensao *d)
{
    char **mapa = (char **)malloc(d->n * sizeof(char*));
    if (mapa == NULL){
        msg_erro("Erro na alocação de memoria para linhas", "mapa_aloca");
        return NULL;
    }
    // Aloca memória para cada linha
    for (int i = 0; i < d->n; i++) {
        mapa[i] = (char*)malloc(d->m * sizeof(char));
        if (mapa[i] == NULL){
            msg_erro("Erro na alocação de memoria para coluna", "mapa_aloca");
            // Libera todas as linhas já alocadas
            for (int j = 0; j < i; j++) {
                free(mapa[j]);
            }
            free(mapa);
            return NULL;
        }
    }
    return mapa;
}

void mapa_gera(char **mapa, Dimensao *d)
{
    srand(time(NULL));
   
    for (int i = 0; i < d->n; i++){
        for (int j = 0; j < d->m; j++){
            int tipo = 1 + (rand() % 3);
            switch (tipo){
            case 1:
                mapa[i][j] = 'P';
                break;
            case 2:
                mapa[i][j] = 'F';
                break;
            case 3:
                mapa[i][j] = 'M';
                break;;            
            default:
                break;
            }            
        }
    }
}

void desaloca_mapa(char ***mapa, Dimensao *d)
{
    int i;
    for (i = 0; i < d->n; i++)
        free((*mapa)[i]);
    free(*mapa);
    *mapa = NULL;
}

void desaloca_dimensao(Dimensao **d)
{
    free(*d);
    *d = NULL;
}


// Função para verificar se uma matriz está vazia
int mapa_vazio(char **mapa, Dimensao *dimensao)
{
    if (mapa == NULL) {
        return 1; // Ponteiro da matriz é NULL
    }
    if (dimensao->n == 0 || dimensao->m == 0) {
        return 1; // Número de linhas ou colunas é zero
    }
    for (int i = 0; i < dimensao->n; i++) {
        if (mapa[i] == NULL) {
            return 1; // Linha da matriz é NULL
        }
        for (int j = 0; j < dimensao->m; j++) {
            if (mapa[i][j] != 0) {
                return 0; // Encontrou um elemento diferente de zero
            }
        }
    }
    return 1; // Todos os elementos são zero
}

void mapa_display(char **mapa, Dimensao *d)
{
    if(mapa_vazio(mapa, d))
    {
        msg_erro("Mapa vazio", "mapa_display");
        return;
    }

    for (int i = 0; i < d->n; i++){
        for (int j = 0; j < d->m; j++){
            printf("%c ", mapa[i][j]);
        }
        printf("\n");
    }
}

void mapa_replica(char **mapa_oficial, char **mapa_copia, Dimensao *d)
{
    int i, j;
    for (i = 0; i < d->n; i++){
        for (j = 0; j < d->m; j++){
            mapa_copia[i][j] = mapa_oficial[i][j];
        }
    }
}

