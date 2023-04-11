typedef struct pilha Pilha;

Pilha* create();
int full(Pilha* p);
void push(Pilha* p, int v);
int empty(Pilha* p);
int pop(Pilha* p);
void free_p(Pilha* p)
