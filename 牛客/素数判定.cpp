#include<iostream>
#include<cmath>
using namespace std;

bool judge(int num) {
	if (num <= 1)
		return false;
	int bound = sqrt(num) + 1;
	for (int i = 2; i < bound; i++)
		if (num%i == 0)
			return false;
	return true;
}

int main() {
    int num;
    while(cin>>num){
        if(judge(num))
            cout<<"yes"<<endl;
        else
            cout<<"no"<<endl;
    }
	return 0;
}