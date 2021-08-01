#include<bits/stdc++.h>
using namespace std;
char preStr[30],midStr[30];

typedef struct treeNode{
    treeNode* leftChild;
    treeNode* rightChild;
    char c;
}tree;

treeNode* creat(){
    treeNode* node=(treeNode*)malloc(sizeof(treeNode));
    node->leftChild=nullptr;
    node->rightChild=nullptr;
    return node;
}

void postOrder(tree* treeRoot){//后序遍历
    if(treeRoot=nullptr)
        return;
    postOrder(treeRoot->leftChild);
    postOrder(treeRoot->rightChild);
    printf("%c",treeRoot->c);
}

void buildTree(int preStart,int preEnd,int midStart,int midEnd){
    treeNode* node=creat();
    node->c=preStr[preStart];
    //查找根节点在中序遍历的位置
    int rootNodeInMid;
    for(int i=midStart;i<=midEnd;i++){
        if(node->c==midStr[i]){
            rootNodeInMid=i;
            break;
        }
    }
    if(rootNodeInMid!=midStart){//左子树不为空
        buildTree(preStart+1,preStart+(rootNodeInMid-midStart),midStart,rootNodeInMid-1);
    }
    if(rootNodeInMid!=midEnd){//右子树不为空
        buildTree(preStart+(rootNodeInMid-midStart)+1,preEnd,rootNodeInMid+1,midEnd);
    }
}

int main(){


    return 0;
}
