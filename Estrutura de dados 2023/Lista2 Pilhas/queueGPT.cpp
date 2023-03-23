#include <stdio.h> 
#include <stdlib.h> 

typedef struct queue { 
	int capacity; 
	int size; 
	int front; 
	int rear; 
	int* arr; 
} Queue; 

Queue* queue(int capacity) 
{ 
	Queue* q = (Queue*)malloc(sizeof(Queue)); 
	q->capacity = capacity; 
	q->front = q->size = 0; 
	q->rear = capacity - 1; 
	q->arr = (int*)malloc(q->capacity * sizeof(int)); 
	return q; 
} 

int full(Queue* q) 
{ 
	return (q->size == q->capacity); 
} 

int empty(Queue* q) 
{ 
	return (q->size == 0); 
} 

void enqueue(Queue* q, int item) 
{ 
	if (full(q)) 
		return; 
	q->rear = (q->rear + 1) % q->capacity; 
	q->arr[q->rear] = item; 
	q->size = q->size + 1; 
	printf("%d inserido na fila\n", item); 
} 

int dequeue(Queue* q) 
{ 
	if (empty(q)) 
		return INT_MIN; 
	int item = q->arr[q->front]; 
	q->front = (q->front + 1) % q->capacity; 
	q->size = q->size - 1; 
	return item; 
} 

int main() 
{ 
	Queue* q = queue(4); 
	
	enqueue(q, 23);
	enqueue(q, 81);
	printf("%d removido da fila\n", dequeue(q));
	enqueue(q, 100);
	printf("%d removido da fila\n", dequeue(q));
	enqueue(q, 50);
	enqueue(q, 30);
	enqueue(q, 40);
	enqueue(q, 10);
	enqueue(q, 10);

	return 0; 
}
