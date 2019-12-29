#include<iostream>
#include<cstring>
using namespace std;

void rotateString(char * a,int k){
int i=strlen(a);
while(i>=0){
	a[i+k]=a[i];
	i--;
}
i= strlen(a);
int s=0;
int j=i-k;
while(j<i){
	a[s]=a[j];
	s++;
	j++;
}
a[i-k]=a[i];
cout<<a<<endl;
}

int main(){
	char a[1000]="Coding Blocks";
	int k=2;

}