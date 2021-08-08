//https://www.nowcoder.com/practice/4878e6c6a24e443aac5211d194cf3913?tpId=40&&tqId=21457&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
//并查集，找不相连点的集合，即连通分量，连通分量-1即至少改修的路
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int cityNumMax = 1000;
vector<int> tree;//双亲表示法

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
    int cityNum, rodeNum;//城市从1开始编号
    while (cin >> cityNum && cityNum != 0) {
        cin >> rodeNum;
        tree.resize(cityNum + 1, -1);//将所有节点的根节点置为-1
        for (int i = 0; i < rodeNum; i++) {
            int vi, vj;
            cin >> vi >> vj;
            vi = findRoot(vi);
            vj = findRoot(vj);
            if (vi != vj)
                tree[vi] = vj;//vi作为vj的孩子
        }
        //找剩下的根节点
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
