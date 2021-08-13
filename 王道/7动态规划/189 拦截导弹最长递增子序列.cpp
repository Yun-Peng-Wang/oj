//https://www.nowcoder.com/practice/dad3aa23d74b4aaea0749042bba2358a?tpId=40&&tqId=21408&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 26;
vector<int>hight, dp;
int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int k;
    while (cin >> k) {
        hight.resize(k);//从0编号
        dp.resize(k, 0);
        for (int i = 0; i < k; i++)
            cin >> hight[i];
        for (int i = 0; i < k; i++) {
            int dpMax = 0;
            for (int j = 0; j <= i; j++) {
                if (hight[j] >= hight[i]) {
                    int tmp = max(1, dp[j] + 1);//高度不增+1
                    if (dpMax < tmp)
                        dpMax = tmp;
                }
            }
            dp[i] = dpMax;
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            ans = max(ans, dp[i]);
        }
        cout << ans << endl;
        hight.clear();
        dp.clear();
    }
    return 0;
}
