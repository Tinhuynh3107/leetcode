typedef struct{
    int data[100];
    int peek;
} stack;


typedef struct {
    stack s_in;
    stack s_out;
} MyQueue;

void push(stack* s, int x){
    s->data[s->peek++] = x;
}

int pop(stack* s){
    return s->data[--(s->peek)];
}

int stackSize(stack* s){
    return s->peek;
}

void transfer(MyQueue* obj){
    if(stackSize(&obj->s_out) == 0){
        while(stackSize(&obj->s_in) > 0){
            push(&obj->s_out, pop(&obj->s_in));
        }
    }
}

MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->s_in.peek = 0;
    obj->s_out.peek = 0;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    push(&obj->s_in, x);
}

int myQueuePop(MyQueue* obj) {
    transfer(obj);
    return pop(&obj->s_out);
}

int myQueuePeek(MyQueue* obj) {
    transfer(obj);
    return obj->s_out.data[obj->s_out.peek - 1];
}

bool myQueueEmpty(MyQueue* obj) {
    return stackSize(&obj->s_out) == 0 && stackSize(&obj->s_in) == 0;
}

void myQueueFree(MyQueue* obj) {
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/