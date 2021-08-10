//https://www.nowcoder.com/practice/23c9fe571c1346bb91fdffea8a0b195f?tpId=40&&tqId=21450&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 101;//1开始编号
vector<int> tree;

struct Edge {
    int aNode;
    int bNode;
    int cost;
    bool operator < (const Edge& b) {
        return cost < b.cost;
    }
};
vector<Edge> edges;

int findRoot(int node) {//查找代表集合的树的根结点
    if (tree[node] == -1)
        return node;
    else {
        int tmp = findRoot(tree[node]);
        tree[node] = tmp;//将双亲结点设置为根节点
        return tmp;
    }
}

int main() {
    int roadsNum, villagesNum;
    while (scanf("%d%d", &roadsNum, &villagesNum) != EOF && roadsNum != 0) {
        tree.resize(villagesNum + 1, -1);//从1开始编号
        for (int i = 0; i < roadsNum; i++) {
            Edge edge;
            scanf("%d%d%d", &edge.aNode, &edge.bNode, &edge.cost);
            edges.push_back(edge);
        }
        //排序
        sort(edges.begin(), edges.end());
        int sumCost = 0;
        for (auto it = edges.begin(); it < edges.end(); it++) {
            int aNode, bNode;
            aNode = findRoot(it->aNode);
            bNode = findRoot(it->bNode);
            if (aNode != bNode) {
                tree[aNode] = bNode;
                sumCost += it->cost;
            }
        }
        int flag = 0;
        for (int i = 1; i <= villagesNum; i++) {//遍历所有村庄，检查连通分量
            if (tree[i] == -1)
                flag++;
        }
        if (flag == 1)
            printf("%d\n", sumCost);
        else
            printf("?\n");
        tree.clear();
        edges.clear();
    }
    return 0;
}
