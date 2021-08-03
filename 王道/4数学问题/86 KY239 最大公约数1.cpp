#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    int n;
    vector<int> numVec;//一定记住擦pg，要清空
    while (cin >> n) {
        int tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            numVec.push_back(tmp);
        }
        sort(numVec.begin(), numVec.end(), cmp);
        int numMin = numVec[numVec.size() - 1];
        int numMax = numVec[0];
        cout << numMin << ' ' << numMax << ' ' << gcd(numMax, numMin) << endl;
        numVec.clear();
    }
}
