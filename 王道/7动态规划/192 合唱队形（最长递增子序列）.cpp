//https://www.nowcoder.com/practice/cf209ca9ac994015b8caf5bf2cae5c98?tpId=40&&tqId=21404&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 100;
vector<int> hight, dpUp, dpLow, dp;
int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int k;
    while (cin >> k) {
        hight.resize(k + 1);//1开始编号
        dpUp.resize(k + 1, 0);
        dpLow.resize(k + 1, 0);
        dp.resize(k + 1, 0);
        for (int i = 1; i <= k; i++)
            cin >> hight[i];
        for (int i = 1; i <= k; i++) {//dpUp
            int dpMax = 1;
            for (int j = 1; j < i; j++) {
                if (hight[j] < hight[i])
                    dpMax = max(dpMax, dpUp[j] + 1);
            }
            dpUp[i] = dpMax;
        }
        for (int i = k; i >= 0; i--) {//逆序递增
            int dpMax = 1;
            for (int j = k; j > i; j--) {
                if (hight[j] < hight[i])
                    dpMax = max(dpMax, dpLow[j] + 1);
            }
            dpLow[i] = dpMax;
            dp[i] = dpUp[i] + dpLow[i];
        }
        int ans = 0;
        for (int i = 1; i <= k; i++)
            ans = max(ans, dp[i]);
        cout << k - ans + 1 << endl;//序列中间有一人重复
        hight.clear();
        dpUp.clear();
        dpLow.clear();
    }
}
