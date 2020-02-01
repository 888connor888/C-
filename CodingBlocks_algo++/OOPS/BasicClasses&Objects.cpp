#include<iostream>
using namespace std;

class Car{

public:
	int price;
	int model_no;
	char name[20];

};

int main(){
	Car  A;
	cout<<sizeof(A)<<endl; // This is an actual object of 28 bytes.
	cout<<sizeof(Car)<<endl; // This is a user defined datatype.
	return 0;
}