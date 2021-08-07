//https://www.nowcoder.com/practice/fd972d5d5cf04dd4bb4e5f027d4fc11e?tpId=40&&tqId=21357&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int bitMax = 4000;

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

int main(){
    string tenStr;
    vector<char> biStr;
    while(cin>>tenStr){
        bigInteger bigTenNum,bigReTenNum;
        bigTenNum.intToBigNum(0);
        bigReTenNum.intToBigNum(0);
        int tenStrSize=tenStr.length();
        for(int i=0;i<tenStrSize;i++){//输入的就是10进制
            int tmp=tenStr[i]-'0';
            bigTenNum=bigTenNum*10+tmp;
        }
        do{
            int tmp=bigTenNum%2;
            biStr.push_back(tmp+'0');//此时的二进制串，低位在前，高位在后
            bigTenNum=bigTenNum/2;
        }while(bigTenNum.bigNumSize!=0);
        //只需认为高位在前，低位在后即为反转
        int biStrSize=biStr.size();
        //二进制串转十进制串
        for(int i=0;i<biStrSize;i++){
            int tmp=biStr[i]-'0';
            bigReTenNum=bigReTenNum*2+tmp;
        }
        for(int i=bigReTenNum.bigNumSize-1;i>=0;i--)
            cout<<bigReTenNum.bigNum[i];
        cout<<endl;
    }


    return 0;
}
