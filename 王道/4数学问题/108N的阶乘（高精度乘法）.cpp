//https://www.nowcoder.com/practice/f54d8e6de61e4efb8cce3eebfd0e0daa?tpId=40&&tqId=21355&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int bitMax = 3010;

class bigInteger {
private:
    int bigNum[bitMax + 1];
    int bigNumSize;

public:
    bigInteger();//构造函数，初始化
    void intToBigNum(int a);//将int转到bigNum中，低位放前面
    void outPrint();//输出
    friend bigInteger operator * (const bigInteger& a, int b);//友元函数重载*
};

bigInteger::bigInteger() {
    for (int i = 0; i <= bitMax; i++)bigNum[i] = 0;
    bigNumSize = 0;
}

void bigInteger::intToBigNum(int a) {
    while (a) {
        bigNum[bigNumSize++] = a % 10;
        a /= 10;
    }
}

void bigInteger::outPrint() {
    for (int i = bigNumSize - 1; i >= 0; i--)
        cout << bigNum[i];
    cout << endl;
}

bigInteger operator * (const bigInteger& a, int b) {
    bigInteger ans;
    int carry = 0;
    for (int i = 0; i < a.bigNumSize; i++) {
        int tmp = a.bigNum[i] * b + carry;
        carry = tmp / 10;
        ans.bigNum[ans.bigNumSize++] = tmp % 10;
    }
    while (carry) {
        ans.bigNum[ans.bigNumSize++] = carry % 10;
        carry /= 10;
    }
    return ans;
}


int main() {
    int n;
    while (cin >> n) {
        bigInteger a;
        a.intToBigNum(1);
        for (int i = 2; i <= n; i++) {
            a = a * i;
        }
        a.outPrint();
    }

    return 0;
}
