#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {//µÝ¹é
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int gcd2(int a, int b) {//·ÇµÝ¹é
    while (b != 0) {
        int tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    int a, b;
    while (cin >> a >> b) {
        //cout<<gcd(a, b);//a<b»á»»Î»ÖÃ
        cout << gcd2(a, b);//a<b»á»»Î»ÖÃ
    }

    return 0;
}
