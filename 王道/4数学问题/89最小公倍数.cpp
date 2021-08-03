#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int a, int b) {
    return b != 0 ? gcd(b, a % b) : a;
}

int main() {
    int n1, n2;
    cin >> n1;
    vector<ll> numVec;
    for (int i = 0; i < n1; i++){
        cin >> n2;
        for (int j = 0; j < n2; j++){
            ll tmp;
            cin >> tmp;
            numVec.push_back(tmp);
        }
        while (numVec.size() > 1) {
            ll num1, num2;
            num1 = numVec.back();//要最后一个
            numVec.pop_back();
            num2 = numVec.back();
            numVec.pop_back();
            numVec.push_back(num1 * num2 / gcd(num1, num2));
        }
        cout << numVec.front() << endl;
        numVec.pop_back();
    }


    return 0;
}
