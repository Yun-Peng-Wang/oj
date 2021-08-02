#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,dRoot;
    string aStr;
    while(cin>>a&&a!=0){
        while(a>=10){
            dRoot=0;
            aStr=to_string(a);
            for(int i=0;i<aStr.length();i++){
                dRoot+=aStr[i]-'0';
            }
            a=dRoot;
        }
        cout<<dRoot<<endl;
    }
    return 0;
}
