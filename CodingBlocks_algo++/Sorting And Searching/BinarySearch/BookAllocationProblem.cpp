#include<iostream>
#include<climits>
using namespace std;

bool isPossible(int a[],int n,int m,int current_min){
  int studentUsed = 1;
  int pages_reading = 0;
  for(int i=0;i<n;i++){
  if(pages_reading + a[i]>current_min){
    studentUsed += 1;
    pages_reading = a[i];
    if(studentUsed>m)  return false;
  }
  else pages_reading += a[i];
}
  return true;
}

int main(){
  #ifndef ONLINE_JUDGE
    freopen("Input.txt","r",stdin);
    freopen("Output.txt","w",stdout);
  #endif
  int t,a[1000];
  cin>>t;
  while(t--){
    int m,n;
    cin>>n>>m;
    for(int i=0;i<n;i++)   cin>>a[i];
    int sum=0;
    if(n<m)  cout<<-1<<endl;//if n<m
    for(int i=0;i<n;i++)  sum += a[i];
    // start and end of our search space
    int s = a[n-1],e = sum;
    int ans = INT_MAX;
    while(s<=e){
      int mid = (s+e)/2;
      if(isPossible(a,n,m,mid)){
        ans = min(ans,mid);
        e = mid - 1;
      }
      else s = mid + 1; // when not possible to divide x pages. so, increase the number of pages
    }
    cout<<ans<<endl;
  }
  return 0;
}