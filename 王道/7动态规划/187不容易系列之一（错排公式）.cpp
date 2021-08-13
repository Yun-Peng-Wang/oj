//https://acm.hdu.edu.cn/showproblem.php?pid=1465
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	long long f[21];
	f[1] = 0;
	f[2] = 1;
	for (int i = 3; i <= 20; i++) {
		f[i] = (i - 1) * f[i - 1] + (i - 1) * f[i - 2];
	}

	while (cin >> n) {
		cout << f[n] << endl;

	}

	return 0;
}
