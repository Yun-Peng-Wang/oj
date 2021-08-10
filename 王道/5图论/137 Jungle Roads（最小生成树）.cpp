//https://www.nowcoder.com/practice/75c19b92d6b942f08989b335afbc73c3?tpId=40&&tqId=21380&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 101;//A-Z
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
    int n;
    while (cin >> n && n != 0) {
        tree.resize(n, -1);
        for (int i = 0; i < n - 1; i++) {
            char villageFrom;
            int roads;
            cin >> villageFrom >> roads;
            for (int j = 0; j < roads; j++) {
                char villageTo;
                int cost;
                cin >> villageTo >> cost;
                Edge edge;
                edge.aNode = villageFrom - 'A';
                edge.bNode = villageTo - 'A';
                edge.cost = cost;
                edges.push_back(edge);
            }
        }
        //将道路按花费排序
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
