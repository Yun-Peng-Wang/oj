//https://www.nowcoder.com/practice/04c8a5ea209d41798d23b59f053fa4d6?tpId=40&&tqId=21334&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
//https://www.nowcoder.com/practice/04c8a5ea209d41798d23b59f053fa4d6?tpId=40&&tqId=21334&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 100000;
bool markNotPrime[numMax + 1];//默认为false
vector<int> primeVec;//所有素数保存在这
int primeSize;
//vector<int> factorCount;


void initPrime() {
    for (int i = 2; i <= numMax; i++) {
        if (markNotPrime[i] == true)continue;
        primeVec.push_back(i);
        for (int j = i * i; j <= numMax; j += i) {
            markNotPrime[j] = true;
        }
    }
}

int sumFactorCount(int n) {//每个素因数的指数加1，再相乘就是约数个数，意思是每个素因数取0..n（n表示指数）
    int ans;
    vector<int> exponent;
    for (int i = 0; i < primeSize; i++) {
        int factor = primeVec[i];
        if (n < factor)break;
        if (n % factor == 0) {
            int num = 0;//本题只要个数，不需要知道其他
            while (n % factor == 0) {
                num++;
                n /= factor;
            }
            exponent.push_back(num);
        }
    }
    if (n > 1) {
        exponent.push_back(1);
    }
    ans = 1;
    for (auto it = exponent.begin(); it != exponent.end(); it++) {
        ans *= *it + 1;
    }

    return ans;
}

int main() {
    int n;
    initPrime();
    primeSize = primeVec.size();
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        cout << sumFactorCount(num) << endl;
    }

    return 0;
}
