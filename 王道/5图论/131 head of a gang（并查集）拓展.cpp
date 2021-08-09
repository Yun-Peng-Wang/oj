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
    int weightOfTeam;//����ֻά�����ų���Ȩ��
    int personOfTeam;
    personNode() {
        name = "";
        index = -1;
        parent = -1;
        weightOfPerson = 0;
        weightOfTeam = 0;
        personOfTeam = 1;//����ʱ�϶�����һ��
    }
};
vector<personNode> treeOfTeam;

personNode findRoot(personNode node) {
    if (node.parent == -1)
        return node;
    else {
        personNode tmp = findRoot(treeOfTeam[node.parent]);
        treeOfTeam[node.index].parent = tmp.index;//����ֻ��Ҫ�ĸ���㣬˫��Ϊ���ڵ�ı��
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
            if (aFlag == -1) {//û�ҵ��½�
                aNode.index = treeOfTeam.size();
                aNode.name = aTmp;
                aNode.weightOfPerson = num;
                //�����ڹ��캯����
                treeOfTeam.push_back(aNode);
            }
            else {//�ҵ����޸�Ȩ�أ��ҵ�֮��Ҫ������ʱ����
                treeOfTeam[aFlag].weightOfPerson += num;
                aNode = treeOfTeam[aFlag];
            }
            if (bFlag == -1) {
                bNode.index = treeOfTeam.size();
                bNode.name = bTmp;
                bNode.weightOfPerson = num;
                treeOfTeam.push_back(bNode);
            }
            else {//�ҵ����޸�Ȩ��
                treeOfTeam[bFlag].weightOfPerson += num;
                bNode = treeOfTeam[bFlag];
            }
            aNode = findRoot(aNode);//�Ҹ����
            bNode = findRoot(bNode);
            //����Ȩ��Ҫ�ҵ�������ټ�
            //treeOfTeam[aNode.index].weightOfTeam += num;
            //treeOfTeam[bNode.index].weightOfTeam += num;
            if (aNode.index != bNode.index) {//a��Ȩ�ش���b����ʱ�Ǹ����
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
        //�ҵ��ų�
        vector<personNode> ans;
        int treeOfTeamSize = treeOfTeam.size();
        for (int i = 0; i < treeOfTeamSize; i++) {
            personNode tmpMax;
            int wightOfPerson = -1;
            if (treeOfTeam[i].parent == -1 && treeOfTeam[i].weightOfTeam > k && treeOfTeam[i].personOfTeam > 2) {
                for (int j = 0; j < treeOfTeamSize; j++) {
                    personNode tmp = findRoot(treeOfTeam[j]);
                    //ͬһ���ţ�����Ȩ�����
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
