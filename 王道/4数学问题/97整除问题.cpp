//https://www.nowcoder.com/practice/8e29045de1c84d349b43fdb123ab586a?tpId=40&&tqId=21436&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 1000;
bool markNotPrime[numMax + 1];//默认为false
vector<int> primeVec;//所有素数保存在这
vector<int> nPrimeCount, aPrimeCount;

void initPrime() {
    for (int i = 2; i <= numMax; i++) {
        if (markNotPrime[i] == true)continue;
        primeVec.push_back(i);
        for (int j = i * i; j <= numMax; j += i) {
            markNotPrime[j] = true;
        }
    }
}

int main() {
    int n, a;
    //int nPrimeCount[numMax+1],aPrimeCount[numMax+1];
    initPrime();
    int primeSize = primeVec.size();
    while (cin >> n >> a) {
        nPrimeCount.resize(numMax + 1, 0);
        aPrimeCount.resize(numMax + 1, 0);
        for (int i = 0; i < primeSize; i++) {
            if (n < primeVec[i])break;
            int nTmp = n;
            while (nTmp) {
                nPrimeCount[i] += nTmp / primeVec[i];
                nTmp /= primeVec[i];
            }
        }
        int ans = 1 << 12;//一个题目达不到的倍数
        for (int i = 0; i < primeSize; i++) {
            if (a < primeVec[i])break;
            while (a % primeVec[i] == 0) {
                aPrimeCount[i]++;
                a = a / primeVec[i];
            }
            if (aPrimeCount[i] == 0)continue;
            else if (nPrimeCount[i] / aPrimeCount[i] < ans) {
                ans = nPrimeCount[i] / aPrimeCount[i];
            }
        }
        cout << ans << endl;
        nPrimeCount.clear();
        aPrimeCount.clear();
    }

    return 0;
}
