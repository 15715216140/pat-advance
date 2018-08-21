二叉排序树的
#include <iostream>
#include <queue>
using namespace std;
struct node{
    int data;
    node *left, *right;
};
void insert(node* &root, int data) {
    if(root == NULL) {
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return ;
    }
    if(data < root->data) insert(root->left, data);
    else insert(root->right, data);
}
void pre(node* root){
    if(root != NULL) {
        pre(root->left);
        cout << root->data << ' ';
        pre(root->right);
    }
}
void level(node* root) {
    if(root == NULL) return ;
    queue<node*> q;
    q.push(root);
    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        printf("%d ", temp->data);
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
}
int main() {
    node* root = NULL;
    for(int i = 0; i < 10; i++)
        insert(root, random() / 3282323);
    pre(root);
    cout << endl;
    level(root);
}
