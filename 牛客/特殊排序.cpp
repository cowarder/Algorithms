#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    while(cin>>n){
        vector<int>v;
        v.resize(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        cout<<v[v.size()-1]<<endl;
        if(n==1)
            cout<<-1;
        bool first=true;
        for(int i=0;i<(n-1);i++)
            if(first){
                cout<<v[i];
                first=false;
            }else
                cout<<" "<<v[i];
        cout<<endl;
    }
    return 0;
}