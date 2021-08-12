//https://www.nowcoder.com/practice/c978e3375b404d598f1808e4f89ac551?tpId=40&&tqId=21557&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int NumMax=90;
int fNum[NumMax+1];

int SumUp(int n){//n化为n-1和n-2两种情况，斐波那契数列
    if(n==1||n==0)
        return 1;
    return SumUp(n-1)+SumUp(n-2);

}

int SumUp2(int n){
    int n1=1,n2=1;
    for(int i=2;i<=n;i++){
        int tmp=n1+n2;
        n2=n1;
        n1=tmp;
    }
    return n1;
}

void initFNum(){
    fNum[0]=fNum[1]=1;
    for(int i=2;i<=NumMax;i++)
        fNum[i]=fNum[i-1]+fNum[i-2];
}

int main(){
    int n;
    initFNum();
    while(scanf("%d",&n)!=EOF){
        int ans=0;
        //ans=SumUp2(n);
        //printf("%d\n",ans);

        printf("%d\n",fNum[n]);
    }
}
