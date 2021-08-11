//https://www.nowcoder.com/practice/16212f7d46e44174b5505997ea998538?tpId=40&&tqId=21449&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
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
    int villageNum;
    while (cin >> villageNum && villageNum != 0) {
        //初始化tree
        tree.resize(villageNum + 1, -1);

        int roadNum = villageNum * (villageNum - 1) / 2;
        for (int i = 0; i < roadNum; i++) {
            int aNode, bNode, cost, isBuild;
            cin >> aNode >> bNode >> cost >> isBuild;
            if (isBuild == 1) {//开始连通村庄
                aNode = findRoot(aNode);
                bNode = findRoot(bNode);
                if (aNode != bNode) {
                    tree[aNode] = bNode;
                }
            }
            else {
                Edge edge;
                edge.aNode = aNode;
                edge.bNode = bNode;
                edge.cost = cost;
                edges.push_back(edge);
            }
        }
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
        cout << sumCost << endl;
        tree.clear();
        edges.clear();
    }
    return 0;
}
