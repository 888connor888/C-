#include<iostream>
#include<stack>
using namespace std;

void printSpan(int arr[],int n){
	stack<int> s;
	int ans[100] = {0};
	for(int day = 0;day<n;++day){
		int currentPrice = arr[day];
        while(!s.empty() && currentPrice > arr[s.top()])  s.pop();
        int betterDay = s.empty() ? 0 : s.top();
        int span = day - betterDay;
        ans[day] = span;
        s.push(day);
	}
	// print span
	for(int i=0;i<n;i++)  cout<<ans[i]<<" ";
}

int main(){
	#ifndef ONLINE_JUDGE
	    freopen("Input.txt","r",stdin);
        freopen("Output.txt","w",stdout);
    #endif
    int arr[] = {100,80,60,70,60,75,85};
    int n = 7;
    printSpan(arr,n);
    return 0;
} 