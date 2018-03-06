#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N,M;
    while(cin>>N>>M){
        vector<int>p;
        vector<int>b;
        p.resize(N);//保存每个人喜爱的书
        b.resize(M+1);//保存每本书被喜爱的人数
        for(int i=0;i<N;i++)
            cin>>p[i];
        for(int i=0;i<N;i++)
            b[p[i]]+=1;
        for(int i=0;i<N;i++)
            if(b[p[i]]>1)
                cout<<b[p[i]]-1<<endl;
            else
                cout<<"BeiJu"<<endl;
    }
    return 0;
}