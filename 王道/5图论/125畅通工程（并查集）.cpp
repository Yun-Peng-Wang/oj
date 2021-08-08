//https://www.nowcoder.com/practice/4878e6c6a24e443aac5211d194cf3913?tpId=40&&tqId=21457&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
//���鼯���Ҳ�������ļ��ϣ�����ͨ��������ͨ����-1�����ٸ��޵�·
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int cityNumMax = 1000;
vector<int> tree;//˫�ױ�ʾ��

int findRoot(int node) {
    if (tree[node] == -1)
        return node;
    else {
        int tmpRoot = findRoot(tree[node]);
        tree[node] = tmpRoot;
        return tmpRoot;
    }
}

int main() {
    int cityNum, rodeNum;//���д�1��ʼ���
    while (cin >> cityNum && cityNum != 0) {
        cin >> rodeNum;
        tree.resize(cityNum + 1, -1);//�����нڵ�ĸ��ڵ���Ϊ-1
        for (int i = 0; i < rodeNum; i++) {
            int vi, vj;
            cin >> vi >> vj;
            vi = findRoot(vi);
            vj = findRoot(vj);
            if (vi != vj)
                tree[vi] = vj;//vi��Ϊvj�ĺ���
        }
        //��ʣ�µĸ��ڵ�
        int ans = 0;
        for (int i = 1; i <= cityNum; i++) {
            if (tree[i] == -1)
                ans++;
        }
        cout << ans - 1 << endl;
        tree.clear();
    }

    return 0;
}
