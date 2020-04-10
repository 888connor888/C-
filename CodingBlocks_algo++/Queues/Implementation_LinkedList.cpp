#include<iostream>
#include<list>
using namespace std;

class Queue{
	int current_size;
	list<int> q;
public:
	Queue(){
		this->current_size = 0;

	}

	bool isEmpty(){
        this->current_size == 0;
	}

	void enqueue(const int data){
        this->q.push_back(data);
        this->current_size += 1;
	}

	void dequeue(){
        if(!isEmpty()){
        	this->current_size -= 1;
        	this->q.pop_front();
        }
	}

	int getFront(){
        return this->q.front()
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