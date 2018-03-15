#include<iostream>
#include<vector>
using namespace std;
vector<int>tree;

int findRoot(int x){
    if(tree[x]==-1)
        return x;
    else{
        int temp=findRoot(tree[x]);
        tree[x]=temp;
        return temp;
    }
}

int main(){
    int N,M;
    while(cin>>N){
        if(N==0)
            break;
        cin>>M;
        tree.resize(N+1);
        for(int i=0;i<=N;i++)
            tree[i]=-1;
        int a,b;
        for(int i=0;i<M;i++){
            cin>>a>>b;
            a=findRoot(a);
            b=findRoot(b);
            if(a!=b)tree[a]=b;
        }
        int ans=0;
        for(int i=1;i<=N;i++)
            if(tree[i]==-1)
                ans++;
        cout<<ans-1<<endl;
        
    }
    return 0;
}