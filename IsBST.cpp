//
// Created by sunguoyan on 16/8/4.
// PAT 1043
//

#include<iostream>
#include<vector>

using namespace std;

struct Node{
    Node*left;
    Node*right;
    int value;
    Node(): left(NULL),right(NULL){}
};

//返回二叉搜索树的根节点
int get_root(int*preorder,int*inorder,int len){
    int tmp = preorder[0];
    int i;
    for(i=0;i<len;i++){
        if(inorder[i]==tmp){
            return i;
        }
    }
    return -1;
}

//构建前序二叉搜索树
Node* Bpreorder(int *preorder,int *inorder,int len,int* flag){
    if(len == 0){
        return NULL;
    }
    int root_idx;
    int root_val;
    root_val = preorder[0];
    root_idx = get_root(preorder,inorder,len);
    Node*r = new Node();
    int i;
    for(i=1;i<root_idx;i++){
        if(preorder[i]>root_val ||preorder[i]==root_val){
            *flag = 0;
        }
    }
    for(i = root_idx+1;i<len;i++){
        if(preorder[i]<root_val){
            *flag = 0;
        }
    }
    if(*flag == 0){
        return NULL;
    }
    r->value = root_val;
    r->left = Bpreorder(preorder+1,inorder,root_idx,flag);
    r->right = Bpreorder(preorder+1+root_idx,inorder+1+root_idx,len-root_idx-1,flag);
    return r;
}
//构建镜像二叉搜索树
Node* Spreorder(int *preorder,int *inorder,int len,int* flag){
    if(len == 0){
        return NULL;
    }
    int root_idx;
    int root_val;
    root_val = preorder[0];
    root_idx = get_root(preorder,inorder,len);
    Node*r = new Node();
    int i;
    for(i=1;i<len-root_idx;i++){
        if(preorder[i]<root_val ){
            *flag = 0;
        }
    }
    for(i=len-root_idx;i<len;i++){
        if(preorder[i]>root_val||preorder[i]==root_val){
            *flag = 0;
        }
    }
    if(*flag == 0){
        return NULL;
    }
    r->value = root_val;
    r->left = Spreorder(preorder+1,inorder+1+root_idx,len-root_idx-1,flag);
    r->right = Spreorder(preorder+len-root_idx,inorder,root_idx,flag);
    return r;
}


void postorder(Node*root,vector<int>&v) {
//    if(first){
//        first = false;
//    }else{
//        cout<<" ";
//    }

    if (root->left != NULL) {
        postorder(root->left, v);
    }
    if(root->right!=NULL) {
        postorder(root->right, v);
    }
    v.push_back(root->value);

}

int cmp1(int a,int b)
{
    return b>a;
}
int main(){
    int N,i;
    int array[1005];
    int inorder[1005];
    vector<int>v1,v2;

    cin>>N;
    if(N<=0){
        cout<<"NO"<<endl;
        return 0;
    }
    for(i=0;i<N;i++){
        cin>>array[i];
        inorder[i]= array[i];
    }

    sort(inorder,inorder+N);

    int flag = 1;
    bool first = true;
    Node*root = new Node();
    root = Bpreorder(array,inorder,N,&flag);
    if(flag==0){
        Node*root2 = new Node();
        int flag2 = 1;
        root2 = Spreorder(array,inorder,N,&flag2);
        if(flag2==0){
            cout<<"NO"<<endl;
            return 0;
        }else{
            cout<<"YES"<<endl;
            postorder(root2,v1);
            for(i=0;i<N;i++){
                if(i==0){
                    cout<<v1[i];
                }else {
                    cout << " " << v1[i];
                }
            }
        }
    }else{
        cout<<"YES"<<endl;
        postorder(root,v2);
        for(i=0;i<N;i++){
            if(i==0){
                cout<<v2[i];
            }else {
                cout << " " << v2[i];
            }
        }
    }
    cout<<endl;

    return 0;
}

