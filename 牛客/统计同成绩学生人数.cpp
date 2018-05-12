#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    int num;
    int target;
    while(cin>>n){
        if(n==0)
            break;
        vector<int>v;
        v.resize(101);
        for(int i=0;i<=100;i++)
            v[i]=0;
        for(int i=1;i<=n;i++){
            cin>>num;
            v[num]++;
        }
        cin>>target;
        cout<<v[target]<<endl;
    }
    return 0;
}