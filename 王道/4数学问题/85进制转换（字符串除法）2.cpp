#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
string numStr;
vector<int> biNum;

void strDivide() {
    int preNum = 0;//��һλ��2ȡ�����������λ�������Ա���
    for (int i = 0; i < numStr.size(); i++) {
        int numTmp = preNum * 10 + numStr[i] - '0';
        //preNum=(numStr[i]-'0') & 1;
        preNum = (numStr[i] - '0') % 2;
        numStr[i] = numTmp / 2 + '0';
    }
    if (numStr[0] == '0') {
        numStr.erase(0, 1);
    }
}

int main() {
    while (cin >> numStr) {
        while (!numStr.empty()) {
            //biNum.push_back((numStr.back()-'0') & 1);//��2ȡ�࣬���������һλ
            biNum.push_back((numStr.back() - '0') % 2);//��2ȡ�࣬���������һλ
            strDivide();//���ַ�����������������
        }
        for (int i = biNum.size() - 1; i >= 0; i--) {
            cout << biNum[i];
        }
        cout << endl;
        biNum.clear();
    }

    return 0;
}
