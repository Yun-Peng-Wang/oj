//https://acm.hdu.edu.cn/showproblem.php?pid=1856
//���鼯���ںϲ�������ͬʱ�ϲ������ϵ�Ԫ�ظ���
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int personNumMax = 10000000;
vector<int> tree;//˫�ױ�ʾ��
vector<int> treeNodeSum;//��¼����Ԫ�ظ���

int findRoot(int node) {
    if (tree[node] == -1)
        return node;
    else {
        int tmpRoot = findRoot(tree[node]);
        tree[node] = tmpRoot;//·��ѹ��
        return tmpRoot;
    }
}

int main() {
    int connection;
    while (cin>>connection){
        tree.resize(personNumMax + 1, -1);//��ʼ���н�㶼�Ǹ��ڵ�
        treeNodeSum.resize(personNumMax + 1, 1);
        for (int i = 0; i < connection; i++) {
            int aPerson, bPerson;
            cin >> aPerson >> bPerson;
            aPerson = findRoot(aPerson);//�ں����ڲ��Ҹ��ڵ�
            bPerson = findRoot(bPerson);
            if (aPerson != bPerson) {
                tree[aPerson] = bPerson;//aPerson��ΪbPerson�ĺ���
                treeNodeSum[bPerson] += treeNodeSum[aPerson];
            }
        }
        int ans = 1;
        for (int i = 1; i <= personNumMax; i++) {
            if (tree[i] == -1 && treeNodeSum[i] > ans)
                ans = treeNodeSum[i];
        }
        cout << ans << endl;
        tree.clear();
        treeNodeSum.clear();
    }

    return 0;
}
