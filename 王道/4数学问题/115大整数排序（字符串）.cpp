//https://www.nowcoder.com/practice/b744af632ac4499aa485d7bb048bb0aa?tpId=40&&tqId=21556&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b) {
    if (a.length() < b.length())
        return true;
    if (a.length() > b.length())
        return false;
    if (a.length() == b.length())
        return a < b;
}

int main() {
    int n;
    vector<string> numStrVec;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string sTmp;
        cin >> sTmp;
        numStrVec.push_back(sTmp);
    }
    sort(numStrVec.begin(), numStrVec.end(), cmp);
    for (auto it = numStrVec.begin(); it < numStrVec.end(); it++) {
        cout << *it << endl;
    }
    numStrVec.clear();//这里可以不清，只有一次排序
    return 0;
}
