//https://acm.hdu.edu.cn/showproblem.php?pid=1856
//并查集，在合并过程中同时合并两集合的元素个数
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int personNumMax = 10000000;
vector<int> tree;//双亲表示法
vector<int> treeNodeSum;//记录集合元素个数

int findRoot(int node) {
    if (tree[node] == -1)
        return node;
    else {
        int tmpRoot = findRoot(tree[node]);
        tree[node] = tmpRoot;//路径压缩
        return tmpRoot;
    }
}

int main() {
    int connection;
    while (cin>>connection){
        tree.resize(personNumMax + 1, -1);//初始所有结点都是根节点
        treeNodeSum.resize(personNumMax + 1, 1);
        for (int i = 0; i < connection; i++) {
            int aPerson, bPerson;
            cin >> aPerson >> bPerson;
            aPerson = findRoot(aPerson);//在函数内部找根节点
            bPerson = findRoot(bPerson);
            if (aPerson != bPerson) {
                tree[aPerson] = bPerson;//aPerson作为bPerson的孩子
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
