//https://acm.hdu.edu.cn/showproblem.php?pid=1856
//���鼯���ںϲ�������ͬʱ�ϲ������ϵ�Ԫ�ظ���
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int personNumMax = 10000000;
int tree[personNumMax + 1];//˫�ױ�ʾ��
int treeNodeSum[personNumMax + 1];//��¼����Ԫ�ظ���

int findRoot(int node) {
	if (tree[node] == -1)
		return node;
	else {
		int tmpRoot = findRoot(tree[node]);
		tree[node] = tmpRoot;//·��ѹ��
		return tmpRoot;
	}
}

int main() {
	int connection;
	while (scanf("%d", &connection) != EOF) {
		for (int i = 1; i <= personNumMax; i++) {
			tree[i] = -1;
			treeNodeSum[i] = 1;
		}
		for (int i = 0; i < connection; i++) {
			int aPerson, bPerson;
			scanf("%d%d", &aPerson, &bPerson);
			aPerson = findRoot(aPerson);//�ں����ڲ��Ҹ��ڵ�
			bPerson = findRoot(bPerson);
			if (aPerson != bPerson) {
				tree[aPerson] = bPerson;//aPerson��ΪbPerson�ĺ���
				treeNodeSum[bPerson] += treeNodeSum[aPerson];
			}
		}
		int ans = 1;
		for (int i = 1; i <= personNumMax; i++) {
			if (tree[i] == -1 && treeNodeSum[i] > ans)
				ans = treeNodeSum[i];
		}
		printf("%d\n", ans);
	}

	return 0;
}
