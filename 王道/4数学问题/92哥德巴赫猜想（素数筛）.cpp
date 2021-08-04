//https://acm.hdu.edu.cn/showproblem.php?pid=1397
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 1 << 15;
bool markNotPrime[numMax + 1];
vector<int> primeVec;//����������������

void initPrime() {//��ʼ������ɸ
	for (int i = 1; i <= numMax; i++) {
		markNotPrime[i] = false;
	}
	for (int i = 2; i <= numMax; i++) {
		if (markNotPrime[i] == true) continue;
		primeVec.push_back(i);
		for (int j = i * i; j <= numMax; j = j + i)//jֱ�Ӵ�i*i��ʼ��i*k��k<i������ǰ���Ѿ���ǹ���
			markNotPrime[j] = true;
	}
}

int main() {
	int n;
	initPrime();
	//int addPrimeNum[numMax + 1] = { 0 };
	////���
	//int primeSize = primeVec.size();
	//for (int even = 4; even <= numMax; even += 2) {
	//	for (int i = 0; i < primeSize; i++) {
	//		if (primeVec[i] > even)break;
	//		for (int j = i; j < primeSize; j++) {
	//			if (primeVec[i] + primeVec[j] > even)break;
	//			if (primeVec[i] + primeVec[j] == even) {
	//				addPrimeNum[even]++;
	//				continue;
	//			}
	//		}
	//	}
	//}
	//while (cin >> n && n != 0) {
	//	cout << addPrimeNum[n] << endl;
	//}

	while (cin >> n && n != 0) {
		int addPrimeNum = 0;
			int primeSize = primeVec.size();
		for (int i = 0; i < primeSize; i++) {
			if (primeVec[i] > n)break;
			for (int j = i; j < primeSize; j++) {
				if (j > n)break;
				if (primeVec[i] + primeVec[j] == n) {
					addPrimeNum++;
					continue;
				}
			}
		}
		cout << addPrimeNum << endl;
	}

}
