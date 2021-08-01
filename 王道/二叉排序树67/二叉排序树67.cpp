#include<bits/stdc++.h>
using namespace std;

typedef struct treeNode {
    treeNode* leftChild;
    treeNode* rightChild;
    int num;
}tree;

treeNode* creat() {
    treeNode* node = (treeNode*)malloc(sizeof(treeNode));
    node->leftChild = nullptr;
    node->rightChild = nullptr;
    return node;
}

void preOrder(tree* treeRoot){//�������
    if (treeRoot == nullptr)
        return;
    printf("%d ", treeRoot->num);
    preOrder(treeRoot->leftChild);
    preOrder(treeRoot->rightChild);
}

void midOrder(tree* treeRoot){//�������
    if (treeRoot == nullptr)
        return;
    midOrder(treeRoot->leftChild);
    printf("%d ", treeRoot->num);
    midOrder(treeRoot->rightChild);
}

void postOrder(tree* treeRoot){//�������
    if (treeRoot == nullptr)
        return;
    postOrder(treeRoot->leftChild);
    postOrder(treeRoot->rightChild);
    printf("%d ", treeRoot->num);
}

treeNode* insert(treeNode* node,int numTmp){
    if(node==nullptr){
        node=creat();
        node->num=numTmp;
        return node;
    }
    else if(numTmp<node->num){//С�ڲ���������
        node->leftChild=insert(node->leftChild,numTmp);
    }
    else if(numTmp>node->num){//���ڲ���������
        node->rightChild=insert(node->rightChild,numTmp);
    }
    //���ڲ�����
    return node;
}

void freeTree(tree* treeRoot) {//�ͷŶ�̬����Ŀռ�
    if (treeRoot == nullptr)
        return;
    freeTree(treeRoot->leftChild);
    freeTree(treeRoot->rightChild);
    free(treeRoot);
    treeRoot = nullptr;
}

int main(){
    int n;
    while(cin>>n){
        tree* treeRoot=nullptr;
        int numTmp;
        for(int i=0;i<n;i++){
            cin>>numTmp;
            treeRoot=insert(treeRoot,numTmp);
        }
        preOrder(treeRoot);
        cout<<endl;
        midOrder(treeRoot);
        cout<<endl;
        postOrder(treeRoot);
        cout<<endl;

        freeTree(treeRoot);
    }
    return 0;
}

