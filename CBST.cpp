//
// Created by sunguoyan on 16/8/1.
// PAT 1064
// 构造完全二叉搜索树，并且层序输出
//

#include <iostream>
#include<cmath>
#include<queue>

using namespace std;

struct Node {
    Node *left;
    Node *right;
    int value;

    Node() : left(NULL), right(NULL) { }
};

//build the complete binary search tree
void buildCBST(int *nodevalue, int len, Node **r) {
    int level = 0;
    int i;
    for (i = 0; i < 100; i++) {
        if ((int) pow(2.0, i) - 1 > len) {
            level = i;    //所要形成的二叉数的层数
            break;
        }
    }
    int remain;//最后一层节点个数
    int left; //左子树节点个数
    int right;//右子树节点个数
    int last; //最后一层最左边节点的编号
    int c;// 满二叉树的节点个数

    c = (int) pow(2.0, level - 1) - 1;
    remain = len - c;
    last = c + 1;
    if (remain > last / 2) {
        left = (c - 1) / 2 + last / 2;
    } else {
        left = (c - 1) / 2 + remain;
    }
    right = len - left - 1;

    Node *root = new Node();
    *r = root;
    root->value = nodevalue[left];

    if (left > 0) {
        buildCBST(nodevalue, left, &root->left);
    }
    if (right > 0) {
        buildCBST(nodevalue + left + 1, right, &root->right);
    }

}

int main() {
    int N;
    int i;
    int nodevalue[1000];
    cin >> N;

    for (i = 0; i < N; i++) {
        cin >> nodevalue[i];
    }

    //排序
    sort(nodevalue, nodevalue + N);

    Node *rootNode = NULL;
    buildCBST(nodevalue, N, &rootNode);
    //利用队列层序输出
    queue<Node *> q;
    q.push(rootNode);
    bool flag = false;
    Node *tmp;

    while (!q.empty()) {
        if (flag) {
            cout << " ";
        } else {
            flag = true;
        }

        tmp = q.front();
        if (tmp) {
            cout << tmp->value;
            if (tmp->left) {
                q.push(tmp->left);
            }
            if (tmp->right) {
                q.push(tmp->right);
            }
        }
        q.pop();
    }
    return 0;

}
