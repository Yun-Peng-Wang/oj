//https://www.nowcoder.com/practice/d6bd75dbb36e410995f8673a6a2e2229?tpId=40&&tqId=21479&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 100;
vector<int> tree;

struct Edges {
    int aNode;
    int bNode;
    int cost;
    bool operator < (const Edges& b) {
        return cost < b.cost;
    }
};
vector<Edges> edges;

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
        int edgeNum = n * (n - 1) / 2;
        tree.resize(n + 1, -1);
        for (int i = 0; i < edgeNum; i++) {
            Edges edge;
            cin >> edge.aNode >> edge.bNode >> edge.cost;
            edges.push_back(edge);
        }
        sort(edges.begin(), edges.end());//默认升序排列
        int ans = 0;
        for (auto it = edges.begin(); it < edges.end(); it++) {
            int aNode, bNode;
            aNode = findRoot(it->aNode);
            bNode = findRoot(it->bNode);
            if (aNode != bNode) {
                tree[aNode] = bNode;//a的双亲设置为b
                ans += it->cost;
            }
        }
        cout << ans << endl;
        tree.clear();
        edges.clear();
    }
    return 0;
}
