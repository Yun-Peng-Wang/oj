//https://acm.hdu.edu.cn/showproblem.php?pid=1213
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int NumMax = 1000;
vector<int> tree;

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
    int t;
    int nNode, mEdge;
    scanf("%d", &t);
    for (int j = 0; j < t;j++) {
        scanf("%d%d", &nNode, &mEdge);
        tree.resize(nNode + 1, -1);//赋初值
        for (int i = 0; i < mEdge; i++) {
            int aNode, bNode;
            scanf("%d%d", &aNode, &bNode);
            aNode = findRoot(aNode);
            bNode = findRoot(bNode);
            if (aNode != bNode)
                tree[aNode] = bNode;//aNode为bNode的子树
        }
        int ans = 0;
        //for (const auto& it : tree) {//这个会从头开始
        for (int i = 1; i <= nNode; i++) {
            if (tree[i] == -1)
                ans++;
        }
        printf("%d\n",ans);
        tree.clear();
    }

    return 0;
}
