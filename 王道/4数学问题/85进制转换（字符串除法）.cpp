//��һ���������һ�������ַ����ĳ��� ��һ��Ƚ���  ����˵�ϴ���
#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string str;
vector<int>v;
void divide() {//�����ַ����Ĵ��� string str��ȫ�ֵ����Բ��ÿ��βδ��ݡ�
    int remain = 0;  //��������
    for (int i = 0; i < str.size(); ++i) {//��һ�δ��������Լ���ʾһ��Ͷ���
        int temp = remain * 10 + str[i] - '0';
        remain = temp % 2;
        str[i] = temp / 2 + '0';
    }
    while (str[0] == '0') {//�����ַ�����***�еõ�������ǰ����0�������0ɾ��
        str.erase(0, 1);
    }
}

int main() {

    while (cin >> str) {
        while (!str.empty()) {
            v.push_back((str.back() - '0') % 2);//�ַ������һλ��2ȡģ���ܵõ�����
            divide();
        }
        for (int i = v.size() - 1; i >= 0; i--) {//����һ�������������
            cout << v[i];
        }
        cout << endl;
    }
    return 0;
}
