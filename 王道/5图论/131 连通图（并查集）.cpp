//https://www.nowcoder.com/practice/569e89823a5141fe8a11ab7d4da21edf?tpId=40&&tqId=21506&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
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
    int nNode, mEdge;
    while (scanf("%d%d", &nNode, &mEdge) != EOF && nNode != 0 && mEdge != 0) {
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
        puts(ans == 1 ? "YES" : "NO");
        tree.clear();
    }

    return 0;
}
