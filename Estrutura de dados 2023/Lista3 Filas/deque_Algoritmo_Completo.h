typedef struct fila Fila;

Fila* create(void);
int full(Fila* f);
void insert(Fila* f, float v);
int empty(Fila* f);
float remove(Fila* f);
void f_free(Fila* f);
