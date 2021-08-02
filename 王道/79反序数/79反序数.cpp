#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    vector<int>aBuff, bBuff;
    for (int i = 1000; i < 1111; i++) {
        a = i;
        int flag = 1;//保持为1则是，否则为0
        b = a * 9;
        while (a != 0) {
            aBuff.push_back(a % 10);
            a /= 10;
        }
        while (b != 0) {
            bBuff.push_back(b % 10);
            b /= 10;
        }
        for (int i = 0; i < 4; i++) {
            if (aBuff[i] != bBuff[3 - i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << i << endl;
        }
        aBuff.clear();
        bBuff.clear();
    }
}
