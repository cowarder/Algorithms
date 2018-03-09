#include<iostream>
using namespace std;
int main(){
    int a,b,k;
    while(cin>>a>>b>>k){
        if(a==0&&b==0)
            break;
        int num;
        int A=a,B=b;
        for(;k>=1;k--){
            if((a%10==b%10)){
                a=a/10;
                b=b/10;
            }else
                break;
        }
        if(k==0)
            cout<<-1<<endl;
        else
            cout<<A+B<<endl;
        
    }
    return 0;
}