//
// Created by sunguoyan on 16/7/29.
// PAT 1099
// 这题是构建二叉搜索树，给了一些没有顺序的数字，将数字放在二叉数上应该有的位置，然后层序输出这些数字。所以程序的步骤应该是
// 数字排序->中序遍历二叉树并且赋值(因为中序遍历是从值小的到值大的)->层序输出
//

#include <iostream>
using namespace std;

struct Node{
    int left;
    int right;
    int value;
};

Node node[100];
int num[100] = {0};
int K=0;
void inorder(int root){
    if(node[root].left!=-1){
        inorder(node[root].left);
    }
    node[root].value = num[K];
    K++;
    if(node[root].right!=-1){
        inorder(node[root].right);
    }
}

int main(){
    int N;
    int i,j;

    int level[100]={0};

    int k,t;

    cin>>N;
    for(i = 0;i < N;i++){
        cin>>node[i].left;
        cin>>node[i].right;

    }
    for(i=0;i<N;i++){
        cin>>num[i];
    }

    //排序
    for(i=0;i<N;i++){
//        k = num[i];
        for(j=i+1;j<N;j++){
            if(num[j]<num[i]){
                t = num[j];
                num[j] = num[i];
                num[i] = t;
            }
        }
    }

    //中序遍历
    inorder(0);
    //层序输出
    int l,s;
    l=1;s=0;
    while(l){
        if(node[level[s]].left!=-1){
            level[s+l] = node[level[s]].left;
            l++;
        }
        if(node[level[s]].right!=-1){
            level[s+l] = node[level[s]].right;
            l++;
        }

        if(s) {
            cout << " ";
        }
        cout<<node[level[s]].value;
        s++;
        l--;
    }
    return 0;

}
