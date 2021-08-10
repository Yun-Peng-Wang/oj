//https://www.nowcoder.com/practice/41b14b4cd0e5448fb071743e504063cf?tpId=40&&tqId=21371&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 101;
vector<int> tree;

struct Edge {
    int aNode;
    int bNode;
    double cost;
    bool operator < (const Edge& b) {
        return cost < b.cost;
    }
};
vector<Edge> edges;

struct Point {
    double x, y;
    double getDistence(Point a) {
        return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y));
    }
};
vector<Point> points;

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
    int pointNum;
    while (cin >> pointNum) {
        tree.resize(pointNum, -1);//0号开始编号
        for (int i = 0; i < pointNum; i++) {
            Point point;
            cin >> point.x >> point.y;
            points.push_back(point);
        }
        for (int i = 0; i < pointNum; i++) {//将所有点两两的距离求出
            for (int j = i + 1; j < pointNum; j++) {
                Edge edge;
                edge.aNode = i;
                edge.bNode = j;
                edge.cost = points[i].getDistence(points[j]);
                edges.push_back(edge);
            }
        }
        double sumDistence = 0;
        sort(edges.begin(), edges.end());
        for (auto it = edges.begin(); it < edges.end(); it++) {
            int aNode, bNode;
            aNode = findRoot(it->aNode);
            bNode = findRoot(it->bNode);
            if (aNode != bNode) {//未连通
                tree[aNode] = bNode;
                sumDistence += it->cost;
            }
        }
        printf("%.2f", sumDistence);

        //清空
        tree.clear();
        edges.clear();
        points.clear();
    }
    return 0;
}
