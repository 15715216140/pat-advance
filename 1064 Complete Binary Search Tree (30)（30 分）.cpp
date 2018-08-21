1064 Complete Binary Search Tree (30)（30 分）
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
A Complete Binary Tree (CBT) is a tree that is completely filled, with the possible exception of the bottom level, which is filled from left to right.

Now given a sequence of distinct non-negative integer keys, a unique BST can be constructed if it is required that the tree must also be a CBT. You are supposed to output the level order traversal sequence of this BST.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=1000). Then N distinct non-negative integer keys are given in the next line. All the numbers in a line are separated by a space and are no greater than 2000.

Output Specification:

For each test case, print in one line the level order traversal sequence of the corresponding complete binary search tree. All the numbers in a line must be separated by a space, and there must be no extra space at the end of the line.

Sample Input:

10
1 2 3 4 5 6 7 8 9 0
Sample Output:

6 3 8 1 5 7 9 0 2 4
#
完全二叉树求根节点+递归
#
对所有节点排序，可得中序序列。有 n 个节点，则：
最后一层满的层数 :
level = ( log(n+1) / log(2) ) (换底公式)
最后一层不满的节点（即叶节点个数 :
leaf = n - ( pow(2, level) - 1 )
根节点在中序中的下标 :
root = l + 左子树的节点个数
     = l + 左子树满的层数节点 + 叶节点(树的最后一层叶节点 和 左子树的最后一层节点个数的最小值)
     = l + pow(2,level - 1) - 1 + min(leaf , pow(2, level - 1))
把次根节点放入正确的树的节点下标
然后根据次下标继续递归左右子树
#
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> v, ans;
void dfs(int l, int r, int index) {
    if(l > r) return ;
    int n = r - l + 1;
    int level = log(n+1) / log(2);
    int leaf = n - (pow(2,level) - 1);
    int root = l + pow(2,level-1) - 1 + min(leaf,(int)pow(2,level-1));
    ans[index] = v[root];
    dfs(l, root-1, index * 2 + 1);
    dfs(root+1, r, index * 2 + 2);
}
int main() {
    int n;
    cin >> n;
    v.resize(n);
    ans.resize(n);
    for(int i = 0; i < n; i++)
        scanf("%d", &v[i]);
    sort(v.begin(), v.end());
    dfs(0,n-1,0);
    cout << ans[0];
    for(int i = 1; i < n; i++)
        printf(" %d",ans[i]);
}
