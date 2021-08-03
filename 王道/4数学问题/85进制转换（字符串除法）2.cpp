#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
string numStr;
vector<int> biNum;

void strDivide() {
    int preNum = 0;//高一位对2取余的余数，个位的余数以保存
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
            //biNum.push_back((numStr.back()-'0') & 1);//对2取余，余数看最后一位
            biNum.push_back((numStr.back() - '0') % 2);//对2取余，余数看最后一位
            strDivide();//对字符串做除法，保存商
        }
        for (int i = biNum.size() - 1; i >= 0; i--) {
            cout << biNum[i];
        }
        cout << endl;
        biNum.clear();
    }

    return 0;
}
