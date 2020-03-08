// we consider that all the characters are lowercase

#include<iostream>
using namespace std;

int main(){
	char ch[1001];
	int freq[26] = {0};
	cin>>ch;
	int i = 0; 
	while(ch[i] != '\0'){
		int idx = ch[i] - 'a';
		freq[idx]++;
		i++;
	}
    int maxidx = 0;
	for(int i=0;i<26;i++){
		if(freq[i]>freq[maxidx]){
			maxidx = i;
		}
	}
    char cha = 'a' + maxidx;
	cout<<cha<<endl;
	return 0;
}