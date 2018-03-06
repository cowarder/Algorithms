#include<iostream>
#include<vector>
using namespace std;
int main(){
    int L;
    int M;
    int a,b;
    
    while(cin>>L>>M){
        vector<int>v;
        v.resize(L+1);
        for(int i=0;i<=L;i++)
            v[i]=1;
        for(int i=0;i<M;i++){
            cin>>a>>b;
            for(int j=a;j<=b;j++)
                v[j]=0;
        }
        int sum=0;
        for(int i=0;i<=L;i++)
            sum+=v[i];
        cout<<sum<<endl;
    }
    return 0;
}