//https://www.nowcoder.com/practice/20426b85f7fc4ba8b0844cc04807fbd9?tpId=40&&tqId=21338&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 100000;
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

int main() {
    int n;
    initPrime();
    int primeSize = primeVec.size();
    while (cin >> n) {
        int primeCount = 0;
        for (int i = 0; i < primeSize; i++) {
            if (n == 1)break;
            while (n % primeVec[i] == 0) {
                primeCount++;
                n = n / primeVec[i];
            }
        }
        if (n != 1) {
            primeCount++;
        }
        cout << primeCount << endl;
    }
    return 0;
}
