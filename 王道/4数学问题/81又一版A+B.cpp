#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main(){
    uint64_t a,b,sum;
    uint32_t m;
    vector<uint32_t> mSum;
    while(cin>>m && m!=0){
        cin>>a>>b;
        sum=a+b;
        if(sum==0)
            mSum.push_back(0);//���У�sumΪ0ʱ������ֵ���´���
        while(sum>0){
            mSum.push_back(sum%m);
            sum/=m;
        }
        for(auto it=mSum.end()-1;it!=mSum.begin()-1;it--){
            cout<<*it;
        }
        cout<<endl;
        mSum.clear();
    }

    return 0;
}
