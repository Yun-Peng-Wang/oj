#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main(){
    uint64_t a,b;
    while(cin>>a>>b){
        vector<int32_t>aBuff,bBuff;
        int ans=0;
        if(a==0)
            aBuff.push_back(0);
        while(a!=0){
            aBuff.push_back(a%10);
            a=a/10;
        }
        if(b==0)
            bBuff.push_back(0);
        while(b!=0){
            bBuff.push_back(a%10);
            b=b/10;
        }
        for(int i=0;i<aBuff.size();i++){
            for(int j=0;j<bBuff.size();j++){
                ans+=aBuff[i]*bBuff[j];
            }
        }
        aBuff.clear();
        bBuff.clear();
        cout<<ans<<endl;
    }

    return 0;
}
