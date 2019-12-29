#include<iostream>
using namespace std;

int LinearSearch(int arr[],int key){
	int i=0,x=0;
	while(x==0){
		if(arr[i]==key){
			x=1;
			break;
		}
		else
			x=0
;		i++;
	}
	return i;
}

int main(){
	int a[]={1,6,5,3,8,2,5};
	int n=sizeof(a[])/sizeof(int);
	if(LinearSearch(a,2)==n)
		cout<<"The Element is not Present."<<endl;
	else{
	cout<<"The Index of the number is:";
	cout<<LinearSearch(a,2)<<endl;
    }
	return 0;
}