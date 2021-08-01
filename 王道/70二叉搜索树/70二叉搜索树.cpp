#include<bits/stdc++.h>
using namespace std;

typedef struct treeNode {
    treeNode* leftChild;
    treeNode* rightChild;
    int num;
}tree;

char originStr[25], compStr[25];
int originSize, compSize;
char* curStr = nullptr;//指向一个字符串，用统一的格式操控不同字符串
int* curSize = nullptr;

treeNode* creat() {
    treeNode* node = (treeNode*)malloc(sizeof(treeNode));
    node->leftChild = nullptr;
    node->rightChild = nullptr;
    return node;
}

void preOrder(tree* treeRoot) {//先序遍历
    if (treeRoot == nullptr)
        return;
    curStr[(*curSize)++] = treeRoot->num + '0';
    preOrder(treeRoot->leftChild);
    preOrder(treeRoot->rightChild);
}

void midOrder(tree* treeRoot) {//中序遍历
    if (treeRoot == nullptr)
        return;
    midOrder(treeRoot->leftChild);
    curStr[(*curSize)++] = treeRoot->num + '0';
    midOrder(treeRoot->rightChild);
}

treeNode* insert(treeNode* node, int numTmp) {//二叉排序树的插入
    if (node == nullptr) {
        node = creat();
        node->num = numTmp;
        return node;
    }
    else if (numTmp < node->num) {//小于插入左子树
        node->leftChild = insert(node->leftChild, numTmp);
    }
    else if (numTmp > node->num) {//大于插入右子树
        node->rightChild = insert(node->rightChild, numTmp);
    }
    //等于不处理
    return node;
}

void freeTree(tree* treeRoot) {//释放动态申请的空间
    if (treeRoot == nullptr)
        return;
    freeTree(treeRoot->leftChild);
    freeTree(treeRoot->rightChild);
    free(treeRoot);
    treeRoot = nullptr;
}

int main() {
    int n;
    char strTmp[13];
    while (cin >> n && n != 0) {
        tree* treeRoot = nullptr;
        cin >> strTmp;
        for (int i = 0; strTmp[i] != '\0'; i++) {
            treeRoot = insert(treeRoot, strTmp[i] - '0');
        }
        originSize = 0;
        curStr = originStr;
        curSize = &originSize;

        preOrder(treeRoot);
        midOrder(treeRoot);

        originStr[originSize] = '\0';
        while (n--) {
            tree* treeRoot2 = nullptr;
            cin >> strTmp;
            for (int i = 0; strTmp[i] != '\0'; i++) {
                treeRoot2 = insert(treeRoot2, strTmp[i] - '0');
            }
            compSize = 0;
            curStr = compStr;
            curSize = &compSize;

            preOrder(treeRoot2);
            midOrder(treeRoot2);

            compStr[compSize] = '\0';
            puts(strcmp(originStr, compStr) == 0 ? "YES" : "NO");
            freeTree(treeRoot2);
        }
        freeTree(treeRoot);
    }


    return 0;
}
