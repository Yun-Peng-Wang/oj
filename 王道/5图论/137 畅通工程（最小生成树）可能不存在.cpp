//https://www.nowcoder.com/practice/23c9fe571c1346bb91fdffea8a0b195f?tpId=40&&tqId=21450&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 101;//1��ʼ���
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

int findRoot(int node) {//���Ҵ����ϵ����ĸ����
    if (tree[node] == -1)
        return node;
    else {
        int tmp = findRoot(tree[node]);
        tree[node] = tmp;//��˫�׽������Ϊ���ڵ�
        return tmp;
    }
}

int main() {
    int roadsNum, villagesNum;
    while (scanf("%d%d", &roadsNum, &villagesNum) != EOF && roadsNum != 0) {
        tree.resize(villagesNum + 1, -1);//��1��ʼ���
        for (int i = 0; i < roadsNum; i++) {
            Edge edge;
            scanf("%d%d%d", &edge.aNode, &edge.bNode, &edge.cost);
            edges.push_back(edge);
        }
        //����
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
        for (int i = 1; i <= villagesNum; i++) {//�������д�ׯ�������ͨ����
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
