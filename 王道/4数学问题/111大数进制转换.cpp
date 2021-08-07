//https://www.nowcoder.com/practice/ae4b3c4a968745618d65b866002bbd32?tpId=60&tqId=31034&tPage=1&rp=1&ru=/ta/tsing-kaoyan
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int bitMax = 3010;

class bigInteger {
public:
    int bigNum[bitMax + 1];
    int bigNumSize;

    bigInteger();//构造函数，初始化
    void intToBigNum(int a);//将int转到bigNum中，低位放前面
    void outPrint();//输出
    friend bigInteger operator * (const bigInteger& a, int b);//友元函数重载*
    friend bigInteger operator + (const bigInteger& a, int b);//友元函数重载+
    friend bigInteger operator / (const bigInteger& a, int b);//友元函数重载/
    friend int operator % (const bigInteger& a, int b);//友元函数重载%
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

}

bigInteger operator * (const bigInteger& a, int b) {
    bigInteger ans;
    int carry = 0;
    for (int i = 0; i < a.bigNumSize; i++) {
        int tmp = a.bigNum[i] * b + carry;//从低位开始
        carry = tmp / 10;
        ans.bigNum[ans.bigNumSize++] = tmp % 10;
    }
    while (carry != 0) {
        ans.bigNum[ans.bigNumSize++] = carry % 10;
        carry /= 10;
    }
    return ans;
}

bigInteger operator + (const bigInteger& a, int b) {
    bigInteger ans;
    int carry = b;//因为b一定是小数所以直接放到余数
    for (int i = 0; i < a.bigNumSize; i++) {
        int tmp = a.bigNum[i] + carry;
        carry = tmp / 10;
        ans.bigNum[ans.bigNumSize++] = tmp % 10;
    }
    while (carry != 0) {
        ans.bigNum[ans.bigNumSize++] = carry % 10;
        carry /= 10;
    }
    return ans;
}

bigInteger operator / (const bigInteger& a, int b) {
    bigInteger ans;
    int remainder = 0;//余数，最后的余数丢弃
    for (int i = a.bigNumSize - 1; i >= 0; i--) {//从高位开始
        int tmp = a.bigNum[i] + remainder*10;
        remainder = tmp % b;
        ans.bigNum[i] = tmp / b;//此处也是高位在后，因为是除法，所以位数不会超过a的
    }
    for (int i = a.bigNumSize - 1; i >= 0; i--) {
        if (ans.bigNum[i] != 0) {
            ans.bigNumSize = i + 1;//位数比下标多1
            break;
        }
    }
    return ans;
}

int operator % (const bigInteger& a, int b) {
    int remainder = 0;//余数，最后的余数就是返回的结果
    for (int i = a.bigNumSize - 1; i >= 0; i--) {//从高位开始
        int tmp = a.bigNum[i] + remainder*10;
        remainder = tmp % b;
    }
    return remainder;
}

int main() {
    char mStr[bitMax + 1];
    vector<char>nStr;
    int m, n;
    while (cin >> m >> n >> mStr) {
        bigInteger tenNum;
        tenNum.intToBigNum(0);
        int strSize = strlen(mStr);
        for (int i = 0; i < strSize; i++) {
            int tmp;
            if (mStr[i] >= '0' && mStr[i] <= '9')
                tmp = mStr[i] - '0';
            else
                tmp = mStr[i] - 'A' + 10;
            tenNum = tenNum * m + tmp;
        }
        do {
            int tmp = tenNum % n;
            if (tmp < 10)
                nStr.push_back(tmp + '0');
            else
                nStr.push_back(tmp - 10 + 'a');
            tenNum = tenNum / n;
        } while (tenNum.bigNumSize != 0);
        int nStrSize = nStr.size();
        for (int i = nStrSize - 1; i >= 0; i--)
            cout << nStr[i];
        cout << endl;
    }

    return 0;
}
