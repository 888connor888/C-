/*
using namespace std;

# define R 10
# define C 10

void wavePrint(int a[R][C],int m,int n){
	int i=0,j=0,wave_direction=1;
    while(j<n){
    	if(wave_direction==1){
        for(int i=0;i<m;i++){
        	cout<<a[i][j]<<", ";
        }
        wave_direction=0;
        j++;
    	}
    	if(wave_direction==0){
        for(int i=m-1;i>=0;i--){
        	cout<<a[i][j]<<", ";
        }
        wave_direction=1;
        j++;
    	}
    }
    cout<<"END";
}


int main(){
	int m,n;
	int a[R][C];
	cin>>m>>n;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	wavePrint(a,m,n);
	return 0;
}
*/

#include<iostream>
using namespace std;

# define R 10
# define C 10

void wavePrint(int a[R][C],int m,int n){
    int i=0,j=0,wave_direction=1;
    while(j<n){
        if(wave_direction==1){
        for(int i=0;i<m;i++){
            cout<<a[i][j]<<", ";
        }
        wave_direction=0;
        j++;
        }
        //Modification:
        if(j<n){
            if(wave_direction==0){
            for(int i=m-1;i>=0;i--){
                cout<<a[i][j]<<", ";
            }
            wave_direction=1;
            j++;
            }
        }
    }
    cout<<"END";
}


int main(){
    int m,n;
    int a[R][C];
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    wavePrint(a,m,n);
    return 0;
}