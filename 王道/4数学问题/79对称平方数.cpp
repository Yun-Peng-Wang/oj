#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    vector<int> bBuff;
    for (int i = 0; i < 256; i++) {
        a = i;
        int flag = 1;//����Ϊ1���ǣ�����Ϊ0
        b = a * a;
        while (b != 0) {
            bBuff.push_back(b % 10);
            b /= 10;
        }
        for (int i = 0; i < bBuff.size(); i++) {
            if (bBuff[i] != bBuff[bBuff.size() - 1 - i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << i << endl;
        }
        bBuff.clear();
    }
}
