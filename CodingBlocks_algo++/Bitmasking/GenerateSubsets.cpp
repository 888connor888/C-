/*Find Subsets of a given string
  I/P: abc
  O/P:" ",a,ab,abc,ac,b,bc,c */

#include<iostream>
#include<string.h>
using namespace std;

void filterCharacters(int n,char c[]){
	int j=0;
	while(n>0){
		int last_bit=(n&1);
		if(last_bit){
			cout<<c[j];
		}
		j++;
		n=n>>1;
	}
	cout<<" ";
	return;
}

void printSubsets(char c[]){
	int n = strlen(c);
	for(int i=0;i<(1<<n);i++){
		filterCharacters(i,c);
	}
	return;
}

int main(){
	char c[100];
	cin>>c;
	printSubsets(c);
	return 0;
}
