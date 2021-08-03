//https://www.nowcoder.com/practice/7f4be54b37a04fdaa4ee545819151114?tpId=40&&tqId=21514&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 10000;
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
    while (cin >> n) {
        bool isFirst = true;
        for (auto it = primeVec.begin(); it != primeVec.end(); it++) {
            if (*it % 10 == 1) {//��λΪ1
                if (isFirst == true) {//��λ
                    if (*it >= n) {
                        cout << -1 << endl;
                        break;
                    }
                    else {
                        cout << *it;
                        isFirst = false;
                    }
                }
                else if (*it < n) {
                    cout << ' ' << *it;
                }
                else
                    break;
            }
            //cout << endl;
        }
    }
    return 0;
}
