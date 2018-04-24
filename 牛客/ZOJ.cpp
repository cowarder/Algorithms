#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        int num1,num2,num3;
        num1=num2=num3=0;
        for(int i=0;i<s.length();i++)
            if(s[i]=='Z')
                num1++;
            else if(s[i]=='O')
                num2++;
            else if(s[i]=='J')
                num3++;
            else{
                
            }
        while(num1||num2||num3){
            if(num1){
                cout<<'Z';
                num1--;
            }
            if(num2){
                cout<<'O';
                num2--;
            }
            if(num3){
                cout<<'J';
                num3--;
            }
        }
        cout<<endl;
    }
    return 0;
}