//https://www.nowcoder.com/practice/fd972d5d5cf04dd4bb4e5f027d4fc11e?tpId=40&&tqId=21357&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int bitMax = 4000;

class bigInteger {
public:
    int bigNum[bitMax + 1];
    int bigNumSize;

    bigInteger();//���캯������ʼ��
    void intToBigNum(int a);//��intת��bigNum�У���λ��ǰ��
    void outPrint();//���
    friend bigInteger operator * (const bigInteger& a, int b);//��Ԫ��������*
    friend bigInteger operator + (const bigInteger& a, int b);//��Ԫ��������+
    friend bigInteger operator / (const bigInteger& a, int b);//��Ԫ��������/
    friend int operator % (const bigInteger& a, int b);//��Ԫ��������%
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
        int tmp = a.bigNum[i] * b + carry;//�ӵ�λ��ʼ
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
    int carry = b;//��Ϊbһ����С������ֱ�ӷŵ�����
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
    int remainder = 0;//������������������
    for (int i = a.bigNumSize - 1; i >= 0; i--) {//�Ӹ�λ��ʼ
        int tmp = a.bigNum[i] + remainder*10;
        remainder = tmp % b;
        ans.bigNum[i] = tmp / b;//�˴�Ҳ�Ǹ�λ�ں���Ϊ�ǳ���������λ�����ᳬ��a��
    }
    for (int i = a.bigNumSize - 1; i >= 0; i--) {
        if (ans.bigNum[i] != 0) {
            ans.bigNumSize = i + 1;//λ�����±��1
            break;
        }
    }
    return ans;
}

int operator % (const bigInteger& a, int b) {
    int remainder = 0;//�����������������Ƿ��صĽ��
    for (int i = a.bigNumSize - 1; i >= 0; i--) {//�Ӹ�λ��ʼ
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
        for(int i=0;i<tenStrSize;i++){//����ľ���10����
            int tmp=tenStr[i]-'0';
            bigTenNum=bigTenNum*10+tmp;
        }
        do{
            int tmp=bigTenNum%2;
            biStr.push_back(tmp+'0');//��ʱ�Ķ����ƴ�����λ��ǰ����λ�ں�
            bigTenNum=bigTenNum/2;
        }while(bigTenNum.bigNumSize!=0);
        //ֻ����Ϊ��λ��ǰ����λ�ں�Ϊ��ת
        int biStrSize=biStr.size();
        //�����ƴ�תʮ���ƴ�
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
