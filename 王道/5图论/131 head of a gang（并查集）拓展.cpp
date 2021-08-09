//https://www.nowcoder.com/practice/a31b1ea6c87647bc86e382acaf21c53b?tpId=40&&tqId=21469&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int numMax = 26 * 26 * 26;
struct personNode {
    string name;
    int index;
    int parent;
    int weightOfPerson;
    int weightOfTeam;//本题只维护了团长的权重
    int personOfTeam;
    personNode() {
        name = "";
        index = -1;
        parent = -1;
        weightOfPerson = 0;
        weightOfTeam = 0;
        personOfTeam = 1;//创建时肯定至少一个
    }
};
vector<personNode> treeOfTeam;

personNode findRoot(personNode node) {
    if (node.parent == -1)
        return node;
    else {
        personNode tmp = findRoot(treeOfTeam[node.parent]);
        treeOfTeam[node.index].parent = tmp.index;//这里只需要改父结点，双亲为父节点的编号
        return tmp;
    }
}

bool cmp(personNode a, personNode b) {
    return a.name < b.name;
}

int main() {
    int n, k;
    while (cin >> n >> k) {
        for (int i = 0; i < n; i++) {
            string aTmp, bTmp;
            int num, aFlag = -1, bFlag = -1;
            personNode aNode, bNode;
            cin >> aTmp >> bTmp >> num;
            for (int j = 0; j < treeOfTeam.size(); j++) {
                if (aTmp == treeOfTeam[j].name)
                    aFlag = j;
                else if (bTmp == treeOfTeam[j].name)
                    bFlag = j;
            }
            if (aFlag == -1) {//没找到新建
                aNode.index = treeOfTeam.size();
                aNode.name = aTmp;
                aNode.weightOfPerson = num;
                //其余在构造函数里
                treeOfTeam.push_back(aNode);
            }
            else {//找到了修改权重，找到之后还要赋给临时变量
                treeOfTeam[aFlag].weightOfPerson += num;
                aNode = treeOfTeam[aFlag];
            }
            if (bFlag == -1) {
                bNode.index = treeOfTeam.size();
                bNode.name = bTmp;
                bNode.weightOfPerson = num;
                treeOfTeam.push_back(bNode);
            }
            else {//找到了修改权重
                treeOfTeam[bFlag].weightOfPerson += num;
                bNode = treeOfTeam[bFlag];
            }
            aNode = findRoot(aNode);//找根结点
            bNode = findRoot(bNode);
            //团体权重要找到根结点再加
            //treeOfTeam[aNode.index].weightOfTeam += num;
            //treeOfTeam[bNode.index].weightOfTeam += num;
            if (aNode.index != bNode.index) {//a的权重大于b，此时是根结点
                if (aNode.weightOfPerson > bNode.weightOfPerson) {
                    treeOfTeam[bNode.index].parent = aNode.index;
                    treeOfTeam[aNode.index].weightOfTeam += treeOfTeam[bNode.index].weightOfTeam + num;
                    treeOfTeam[aNode.index].personOfTeam += treeOfTeam[bNode.index].personOfTeam;
                }
                else {
                    treeOfTeam[aNode.index].parent = bNode.index;
                    treeOfTeam[bNode.index].weightOfTeam += treeOfTeam[aNode.index].weightOfTeam + num;
                    treeOfTeam[bNode.index].personOfTeam += treeOfTeam[aNode.index].personOfTeam;
                }
            }
            else {
                treeOfTeam[aNode.index].weightOfTeam += num;
            }
        }
        //找到团长
        vector<personNode> ans;
        int treeOfTeamSize = treeOfTeam.size();
        for (int i = 0; i < treeOfTeamSize; i++) {
            personNode tmpMax;
            int wightOfPerson = -1;
            if (treeOfTeam[i].parent == -1 && treeOfTeam[i].weightOfTeam > k && treeOfTeam[i].personOfTeam > 2) {
                for (int j = 0; j < treeOfTeamSize; j++) {
                    personNode tmp = findRoot(treeOfTeam[j]);
                    //同一个团，并且权重最大
                    if (tmp.name == treeOfTeam[i].name && wightOfPerson < treeOfTeam[j].weightOfPerson) {
                        treeOfTeam[j].personOfTeam = tmp.personOfTeam;
                        tmpMax = treeOfTeam[j];
                        wightOfPerson = treeOfTeam[j].weightOfPerson;
                    }
                }
                ans.push_back(tmpMax);
            }
        }
        if (ans.size() == 0) {
            cout << 0 << endl;
        }
        else {
            sort(ans.begin(), ans.end(), cmp);
            cout << ans.size() << endl;
            for (auto it = ans.begin(); it < ans.end(); it++)
                cout << it->name << ' ' << it->personOfTeam << endl;
        }
        treeOfTeam.clear();
    }


    return 0;
}
