//https://www.nowcoder.com/practice/4c39c984ea3848b48e111b8e71ec1dd4?tpId=40&&tqId=21541&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int bitMax = 1010;

class bigInteger {
private:
    int bigNum[bitMax + 1];
    int bigNumSize;

public:
    bigInteger();//���캯������ʼ��
    void strToBigNum(char str[]);//���ַ���ת��bigNum�У���λ��ǰ��
    void outPrint();//���
    friend bigInteger operator + (const bigInteger& a, const bigInteger& b);//��Ԫ��������+
};

bigInteger::bigInteger() {
    for (int i = 0; i <= bitMax; i++)bigNum[i] = 0;
    bigNumSize = 0;
}

void bigInteger::strToBigNum(char str[]) {
    int strSize = strlen(str);
    for (int i = strSize - 1; i >= 0; i--) {
        bigNum[bigNumSize++] = str[i] - '0';
    }
}

void bigInteger::outPrint() {
    for (int i = bigNumSize - 1; i >= 0; i--)
        cout << bigNum[i];
    cout << endl;
}

bigInteger operator + (const bigInteger& a, const bigInteger& b) {
    bigInteger ans;
    int carry = 0;//��λ
    for (int i = 0; i < a.bigNumSize || i < b.bigNumSize; i++) {
        int tmp = a.bigNum[i] + b.bigNum[i] + carry;//�ǵü��Ͻ�λ��
        carry = tmp / 10;
        ans.bigNum[ans.bigNumSize++] = tmp % 10;
    }
    if (carry != 0) {
        ans.bigNum[ans.bigNumSize++] = carry;
    }
    return ans;
}


int main() {
    char aStr[bitMax + 1], bStr[bitMax + 1];
    while (cin >> aStr >> bStr) {
        bigInteger a, b, c;
        a.strToBigNum(aStr);
        b.strToBigNum(bStr);
        c = a + b;
        c.outPrint();
    }
    return 0;
}
