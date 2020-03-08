#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
bool mycompare(string a,string b)
{
	int i;
	int l1=a.size();
	int l2=b.size();
	int minm=min(l1,l2);
	for( i=0;i<minm;i++)
	{
		//cout<<a[i]<<" "<<b[i]<<endl;
		if(a[i]!=b[i])
			break;
	}
	if(i==minm)
		return a.size()>b.size();
	else
		return a<b;			
}		
int main()
{
	int n;
	cin>>n;
	string A[1000];
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
	}
	
	sort(A,A+n,mycompare);				
	
	for(int i=0;i<n;i++)
	{
		cout<<A[i]<<endl;
	}
	return 0;
}				 		
	