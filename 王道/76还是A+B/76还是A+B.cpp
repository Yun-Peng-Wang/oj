#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main() {
    int64_t a, b, sum;
    int32_t k;
    while (scanf("%lld%lld%d", &a, &b, &k) != EOF && (a != 0 && b != 0)) {
    //while (cin >> a >> b >> k && (a != 0 && b != 0)) {
        int32_t i;
        sum = a + b;//暂时定为a+b
        for (i = 0; i < k; i++) {
            int32_t divisor = 10 * (i + 1);
            if (a % divisor != b % divisor) {//前k位一定不同则终止循环
                break;
            }
        }
        if (i == k)//说明没有终止循环，末尾k位相同
            sum = -1;
        cout << sum << endl;
    }

    return 0;
}
