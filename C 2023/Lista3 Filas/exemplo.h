typedef struct fila Fila;

Fila* fila_cria(void);
int fila_cheia (Fila* f);
void fila_insere(Fila* f, float v);
int fila_vazia (Fila* f);
float fila_retira (Fila* f);
