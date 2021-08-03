//第一步就是设计一个对于字符串的除法 这一点比较难  不多说上代码
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string str;
vector<int>v;
void divide() {//对于字符串的代码 string str是全局的所以不用靠形参传递。
    int remain = 0;  //保留余数
    for (int i = 0; i < str.size(); ++i) {//这一段代码请大家自己演示一遍就懂了
        int temp = remain * 10 + str[i] - '0';
        remain = temp % 2;
        str[i] = temp / 2 + '0';
    }
    while (str[0] == '0') {//对于字符串除***有得到的商最前面有0，必须把0删除
        str.erase(0, 1);
    }
}

int main() {

    while (cin >> str) {
        while (!str.empty()) {
            v.push_back((str.back() - '0') % 2);//字符串最后一位对2取模就能得到余数
            divide();
        }
        for (int i = v.size() - 1; i >= 0; i--) {//用了一个容器逆序输出
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}
