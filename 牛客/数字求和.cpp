#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        vector<int>v;
        int m;
        int sum=0;
        for(int i=1;i<=5;i++){
            cin>>m;
            if(m<n)
                sum+=m;
        }
        cout<<sum<<endl;
    }
}