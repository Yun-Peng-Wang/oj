#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main(){
    uint64_t n,nTmp;
    while(scanf("%llu",&n)!=EOF){
        nTmp=n;
        uint64_t n2=n*n;
        uint32_t place=0;//n��λ��
        do{
            place++;
            nTmp=nTmp/10;
        }while(nTmp!=0);
        puts(n2%(uint64_t)pow(10, place)==n ? "Yes!":"No!");//���������
    }

    return 0;
}
