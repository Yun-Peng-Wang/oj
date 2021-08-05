//https://acm.hdu.edu.cn/showproblem.php?pid=2817
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 200907;

ll fastPow(ll a, ll n) {
	ll ans = 1;
	while (n) {
		if (n & 1)//��λ��Ϊ1�����
			ans = (ans * a) % mod;
		a = (a * a) % mod;
		n = n >> 1;
	}
	return ans;
}

int main() {
	ll a, b, c, k, n;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll kTerm;
		cin >> a >> b >> c >> k;
		if (2 * b == a + c) {//�Ȳ����У�����+��k-1��*�Ȳ�
			kTerm = ((a % mod) + ((k - 1) * (b - a) % mod)) % mod;
		}
		else {//�ȱ�����
			kTerm = ((a % mod) * fastPow((b / a) % mod, k - 1)) % mod;
		}
		cout << kTerm << endl;
	}

	return 0;
}
