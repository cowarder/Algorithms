#include<iostream>
using namespace std;
int main(){
    int N;
    while(cin>>N){
        int d=N*N;
        bool found=false;
        while(d>0&&N>0){
            if((d%10)==(N%10)){
                d/=10;
                N/=10;
            }
            else
                break;
        }
        if(N==0)
            found=true;
        if(found)
            cout<<"Yes!"<<endl;
        else
            cout<<"No!"<<endl;
    }
    return 0;
}