//https://acm.hdu.edu.cn/showproblem.php?pid=2035
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000;

int fastPow(int a, int n) {
	int ans = 1;
	while (n) {
		if (n & 1) {//n与1按位与，相当于对2取模，但快得多
			ans = (ans * a) % mod;
		}
		a = (a * a) % mod;
		n = n >> 1;//右移
	}
	return ans;
}

int main() {
	int a, n;
	while (cin >> a >> n && a != 0 && n != 0) {
		cout << fastPow(a, n) << endl;
	}
	return 0;
}
