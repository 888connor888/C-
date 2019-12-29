#include<iostream>
using namespace std;
int main(){
    int **arr= new int*[3]; // create a prymary array in the heap
    for(int i=0;i<3;i++){
        arr[i]= new int[4]; // created secondary arrays
    }
    // read values
    int count=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            arr[i][j]=count;
            count++;
        }
    }
    // print
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<"\t";
        }
    cout<<endl;
    }

    // Delete Operation
    for(int i=0;i<3;i++){
        delete [] arr[i];
    } 
    delete [] arr;

}