#include<iostream>
using namespace std;
# define ll  long long

void swap(ll *xp, ll *yp) 
{ 
	ll temp = *xp; 
	*xp = *yp; 
	*yp = temp; 
} 

// A function to implement bubble sort 
void bubbleSort(ll arr[], ll n) 
{ 
	ll i, j; 
	for (i = 0; i < n-1; i++)	 
	
	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1]) 
			swap(&arr[j], &arr[j+1]); 
} 

/* Function to print an array */
void printArray(ll arr[], ll size) 
{ 
	ll i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] <<endl;  
} 

int main(){
	ll n;
	ll a[1000000];
	cin>>n;
	for(ll i=0;i<n;i++)
		cin>>a[i];
    bubbleSort(a,n);
    printArray(a,n);
    return 0;
}
