//https://www.nowcoder.com/practice/c5f8688cea8a4a9a88edbd67d1358415?tpId=40&&tqId=21441&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 1000000;//�࿪�㣬������Ҫ10000������
bool markNotPrime[numMax + 1];
vector<int> primeVec;//����������������

void initPrime() {//��ʼ������ɸ
    for (int i = 1; i <= numMax; i++) {
        markNotPrime[i] = false;
    }
    for (int i = 2; i <= numMax; i++) {
        if (markNotPrime[i] == true) continue;
        primeVec.push_back(i);
        for (int j = i * i; j <= numMax; j = j + i)//jֱ�Ӵ�i*i��ʼ��i*k��k<i������ǰ���Ѿ���ǹ���
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
