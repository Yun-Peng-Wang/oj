#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main() {
    int16_t a, b;
    uint64_t tenNum;
    string numStr;
    vector<char> bNumStr;
    while (cin >> a >> numStr >> b) {//没有检查n是否为a进制
        tenNum = 0;
        for (int i = 0; i < numStr.length(); i++) {
           /* switch (numStr[i]) {//switch很耗时间
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                tenNum = tenNum * a + (numStr[i] - '0');
                break;
            case 'a':
            case 'A':
                tenNum = tenNum * a + 10;
                break;
            case 'b':
            case 'B':
                tenNum = tenNum * a + 11;
                break;
            case 'c':
            case 'C':
                tenNum = tenNum * a + 12;
                break;
            case 'd':
            case 'D':
                tenNum = tenNum * a + 13;
                break;
            case 'e':
            case 'E':
                tenNum = tenNum * a + 14;
                break;
            case 'f':
            case 'F':
                tenNum = tenNum * a + 15;
                break;
            default:
                break;
            }*/
            if (numStr[i] >= '0' && numStr[i] <= '9')
                tenNum = tenNum * a + (numStr[i] - '0');
            else if (numStr[i] >= 'a' && numStr[i] <= 'z')
                tenNum = tenNum * a + (numStr[i] - 'a' + 10);
            else if (numStr[i] >= 'A' && numStr[i] <= 'Z')
                tenNum = tenNum * a + (numStr[i] - 'A' + 10);
        }
        do {
            int bTmp = tenNum % b;//计算余数，判断是否大于10
            bNumStr.push_back(bTmp < 10 ? bTmp + '0' : bTmp - 10 + 'A');
            tenNum /= b;
        } while (tenNum != 0);
        for (auto it = bNumStr.end() - 1; it != bNumStr.begin() - 1; it--) {
            cout << *it;
        }

        cout << endl;
        bNumStr.clear();
    }

    return 0;
}
