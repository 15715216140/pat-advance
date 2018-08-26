1143 Lowest Common Ancestor（30 分）
The lowest common ancestor (LCA) of two nodes U and V in a tree is the deepest node that has both U and V as descendants.

A binary search tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given any two nodes in a BST, you are supposed to find their LCA.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers: M (≤ 1,000), the number of pairs of nodes to be tested; and N (≤ 10,000), the number of keys in the BST, respectively. In the second line, N distinct integers are given as the preorder traversal sequence of the BST. Then M lines follow, each contains a pair of integer keys U and V. All the keys are in the range of int.

Output Specification:
For each given pair of U and V, print in a line LCA of U and V is A. if the LCA is found and A is the key. But if A is one of U and V, print X is an ancestor of Y. where X is A and Y is the other node. If U or V is not found in the BST, print in a line ERROR: U is not found. or ERROR: V is not found. or ERROR: U and V are not found..

Sample Input:
6 8
6 3 1 2 5 4 8 7
2 5
8 7
1 9
12 -3
0 8
99 99
Sample Output:
LCA of 2 and 5 is 3.
8 is an ancestor of 7.
ERROR: 9 is not found.
ERROR: 12 and -3 are not found.
ERROR: 0 is not found.
ERROR: 99 and 99 are not found.

根据二叉搜索数的性质，两个节点的最近的祖宗一定可以把两个节点大小区分开，即大小夹在两个节点中间。
虽然很多节点可以做到这一功能，但是自定向下，一定是根节点第一个做到

#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main() {
    int m, n;
    map<int,int> vis;
    cin >> m >> n;
    vector<int> pre(n);
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
        vis[pre[i]] = 1;
    }
    while(m--) {
        int a, u, v;
        cin >> u >> v;
        for(int i = 0; i < n; i++) {
            a = pre[i];
            if((a - u) * (a - v) <= 0) break;
        }
        if(vis[u] == 0 && vis[v] == 0) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        }else if(vis[u] == 1 && vis[v] == 0) {
            printf("ERROR: %d is not found.\n",v);
        }else if(vis[u] == 0 && vis[v] == 1) {
            printf("ERROR: %d is not found.\n",u);
        }else if(a == u) {
            printf("%d is an ancestor of %d.\n", u, v);
        }else if(a == v) {
            printf("%d is an ancestor of %d.\n", v, u);
        }else {
            printf("LCA of %d and %d is %d.\n", u, v, a);
        }
    }
    return 0;
}
