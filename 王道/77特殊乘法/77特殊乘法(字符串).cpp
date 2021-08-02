#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main() {
    char aStr[13],bStr[13];
    while(cin>>aStr>>bStr){
        int32_t ans=0;
        for(int32_t i=0;i<strlen(aStr);i++){
            for(int32_t j=0;j<strlen(bStr);j++){
                ans+=(aStr[i]-'0')*(bStr[j]-'0');
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
