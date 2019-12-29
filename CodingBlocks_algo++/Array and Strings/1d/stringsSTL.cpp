
// For more reffer to cplusplus.com



#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool compare( string a, string b){
    return a.length()>b.length();
}

int main() {
    string s("Hello World!");
    cout<<s<<endl;
    string s2 = "Another way!";
    cout<<s2<<endl;
    cout<<s2.length()<<endl;
    // Iterate through the string
    for(int j=0;j<s2.length();j++){
        cout<<s2[j]<<"-";
    }
    cout<<endl;
    string s3;
    getline(cin,s3);
    cout<<s3<<endl;
    // Array of Strings
    string arr[]={"Apples","Bannanas","Mangos","Pineapples","Guavas"};
    sort(arr,arr+4,compare);
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    



}
