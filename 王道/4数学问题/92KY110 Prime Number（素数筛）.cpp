//https://www.nowcoder.com/practice/c5f8688cea8a4a9a88edbd67d1358415?tpId=40&&tqId=21441&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 1000000;//多开点，本题需要10000个素数
bool markNotPrime[numMax + 1];
vector<int> primeVec;//所有素数保存在这

void initPrime() {//初始化素数筛
    for (int i = 1; i <= numMax; i++) {
        markNotPrime[i] = false;
    }
    for (int i = 2; i <= numMax; i++) {
        if (markNotPrime[i] == true) continue;
        primeVec.push_back(i);
        for (int j = i * i; j <= numMax; j = j + i)//j直接从i*i开始，i*k（k<i）的在前面已经标记过了
            markNotPrime[j] = true;
    }
}

int main(){
    int n;
    initPrime();
    while(cin>>n){
        cout<<primeVec[n-1]<<endl;
    }
    return 0;
}
