#include<iostream>
using namespace std;

class Queue{
    int *arr;
    int max_size;
    int current_size;
    int front;
    int rear;
public:
    Queue(int default_size = 7){
        this->front = 0;
        this->rear = default_size - 1;  // as we have to calculate % in enqueue/dequeue operations
        this->max_size = default_size;
        this->arr = new int[this->max_size]();
        this->current_size = 0;
    }

    bool isFull(){
        return this->current_size == this->max_size;
    }

    bool isEmpty(){
        return this->current_size == 0;
    }

    void enqueue(const int data){
        if(!isFull()){
            this->rear = (this->rear + 1) % this->max_size;
            this->arr[this->rear] = data;
            this->current_size += 1;
        }
    }

    void dequeue(){
        if(!isEmpty()){
            this->front = (this->front + 1) % this->max_size;
            this->current_size -= 1;
        }
    }

    int getFront(){
        return this->arr[this->front];
    } 

};

int main(int argc, char const *argv[]){
    #ifndef ONLINE_JUDGE
        freopen("Input.txt","r",stdin);
        freopen("Output.txt","w",stdout);
    #endif
    Queue q(10);
    for(int i=1;i<=6;i++)  q.enqueue(i);
    q.dequeue();
    q.enqueue(8);
    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.dequeue();
    }
    return 0;
}