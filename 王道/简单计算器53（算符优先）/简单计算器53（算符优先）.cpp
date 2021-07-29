#include<bits/stdc++.h>
using namespace std;

const int maxStr = 202;
char str[maxStr];
stack<int> opStack;
stack<double> numStack;
int opg[][5] = {
    0, -1, -1, -1,  -1,
    1,  1,  1,  -1, -1,
    1,  1,  1,  -1, -1,
    1,  1,  1,  1,  1,
    1,  1,  1,  1,  1,
};
/*
    #   +   -   *   /
#   0,  -1, -1, -1, -1,
+   1,  1,  1,  -1, -1,
-   1,  1,  1,  -1, -1,
*   1,  1,  1,  1,  1,
/   1,  1,  1,  1,  1,
*/

//词法分析
void getSym(bool& isOp, int& wordValue, int &i) {
    char ch = str[i++];
    while (ch == ' ') {
        ch = str[i++];
    }
    if (isdigit(ch)) {
        int numValue = 0;
        numValue = ch - '0';
        ch = str[i++];
        while (isdigit(ch)) {
            numValue = numValue * 10 + (ch - '0');
            ch = str[i++];
        }
        i--;
        isOp = false;
        wordValue = numValue;
        return;
    }
    else if (ch == '+') {
        isOp = true;
        wordValue = 1;
        return;
    }
    else if (ch == '-') {
        isOp = true;
        wordValue = 2;
        return;
    }
    else if (ch == '*') {
        isOp = true;
        wordValue = 3;
        return;
    }
    else if (ch == '/') {
        isOp = true;
        wordValue = 4;
        return;
    }
    else if (ch == '#') {
        isOp = true;
        wordValue = 0;
        return;
    }
}

int main() {
    int i;
    bool isOp;
    int wordValue;
    while (cin.getline(str, maxStr) && !(str[0] == '0' && strlen(str) == 1)) {
        str[strlen(str)] = '#';
        i = 0;
        while (!opStack.empty()) opStack.pop();
        while (!numStack.empty()) numStack.pop();
        //压入一个#（0）
        opStack.push(0);
        do {
            getSym(isOp, wordValue, i);
            if (isOp == false) {
                numStack.push(wordValue);
            }
            else {
                if (opg[opStack.top()][wordValue] == -1) {
                    opStack.push(wordValue);
                }
                else if (opg[opStack.top()][wordValue] == 0) {
                    break;
                }
                else if (opg[opStack.top()][wordValue] == 1) {
                    int num2 = numStack.top();
                    numStack.pop();
                    int num1 = numStack.top();
                    numStack.pop();
                    int op = opStack.top();
                    opStack.pop();
                    i--;
                    double ans;
                    switch (op) {
                    case 1:
                        ans = num1 + num2;
                        numStack.push(ans);
                        break;
                    case 2:
                        ans = num1 - num2;
                        numStack.push(ans);
                        break;
                    case 3:
                        ans = num1 * num2;
                        numStack.push(ans);
                        break;
                    case 4:
                        ans = double(num1) / num2;
                        numStack.push(ans);
                        break;
                    default:
                        break;
                    };
                }
            }
        } while (i < strlen(str));
        cout << numStack.top() << endl;
    }
    return 0;
}
