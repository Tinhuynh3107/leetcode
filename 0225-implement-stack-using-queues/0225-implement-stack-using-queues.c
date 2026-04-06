typedef struct {
    int data[100];
    int front;
    int rear;
} queue;


typedef struct {
    queue q;
} MyStack;

void enqueue(queue* q, int x){
    q->data[q->rear++] = x;
}

int dequeue(queue* q){
    return q->data[q->front++];
}

int queueSize(queue* q){
    return q->rear - q->front;
}


MyStack* myStackCreate() {
    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
    obj->q.rear = 0;
    obj->q.front = 0;
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    queue* q = &obj->q;
    enqueue(q, x);

    int size = queueSize(q);
    for (int i = 0; i < size - 1; i++){
        enqueue(q, dequeue(q));
    }
}

int myStackPop(MyStack* obj) {
    return dequeue(&obj->q);    
}

int myStackTop(MyStack* obj) {
    return obj->q.data[obj->q.front];    
}

bool myStackEmpty(MyStack* obj) {
    return queueSize(&obj->q) == 0;
}

void myStackFree(MyStack* obj) {
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/