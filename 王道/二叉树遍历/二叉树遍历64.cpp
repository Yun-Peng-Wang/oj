#include<bits/stdc++.h>
using namespace std;
char preStr[30], midStr[30];

typedef struct treeNode {
    treeNode* leftChild;
    treeNode* rightChild;
    char c;
}tree;

treeNode* creat() {
    treeNode* node = (treeNode*)malloc(sizeof(treeNode));
    node->leftChild = nullptr;
    node->rightChild = nullptr;
    return node;
}

void postOrder(tree* treeRoot) {//�������
    if (treeRoot == nullptr)//��ָ���򷵻�
        return;
    postOrder(treeRoot->leftChild);
    postOrder(treeRoot->rightChild);
    printf("%c", treeRoot->c);
}

treeNode* buildTree(int preStart, int preEnd, int midStart, int midEnd) {
    treeNode* node = creat();
    node->c = preStr[preStart];
    //���Ҹ��ڵ������������λ��
    int rootNodeInMid;
    for (int i = midStart; i <= midEnd; i++) {
        if (node->c == midStr[i]) {
            rootNodeInMid = i;
            break;
        }
    }
    if (rootNodeInMid != midStart) {//��������Ϊ��
        node->leftChild = buildTree(preStart + 1, preStart + (rootNodeInMid - midStart), midStart, rootNodeInMid - 1);
    }
    if (rootNodeInMid != midEnd) {//��������Ϊ��
        node->rightChild = buildTree(preStart + (rootNodeInMid - midStart) + 1, preEnd, rootNodeInMid + 1, midEnd);
    }
    return node;
}

void freeTree(tree* treeRoot) {
    if (treeRoot == nullptr)
        return;
    freeTree(treeRoot->leftChild);
    freeTree(treeRoot->rightChild);
    free(treeRoot);
    treeRoot = nullptr;
}

int main() {
    while (cin >> preStr) {
        cin >> midStr;
        //�����������
        tree* treeRoot = creat();
        int preStrlen = strlen(preStr);
        int midStrlen = strlen(midStr);
        treeRoot = buildTree(0, preStrlen - 1, 0, midStrlen - 1);
        postOrder(treeRoot);
        printf("\n");
        //�ͷŶ�̬�����Ŀռ�
        freeTree(treeRoot);
    }

    return 0;
}
