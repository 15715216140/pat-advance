1127 ZigZagging on a Tree（30 分）
Suppose that all the keys in a binary tree are distinct positive integers. A unique binary tree can be determined by a given pair of postorder and inorder traversal sequences. And it is a simple standard routine to print the numbers in level-order. However, if you think the problem is too simple, then you are too naive. This time you are supposed to print the numbers in "zigzagging order" -- that is, starting from the root, print the numbers level-by-level, alternating between left to right and right to left. For example, for the following tree you must output: 1 11 5 8 17 12 20 15.

zigzag.jpg

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤30), the total number of nodes in the binary tree. The second line gives the inorder sequence and the third line gives the postorder sequence. All the numbers in a line are separated by a space.

Output Specification:
For each test case, print the zigzagging sequence of the tree in a line. All the numbers in a line must be separated by exactly one space, and there must be no extra space at the end of the line.

Sample Input:
8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
Sample Output:
1 11 5 8 17 12 20 15

题意：给出中序和后序，蛇形输出层序
题解：用结构体{data,index,level}存储，表示节点的数据，位置，层数。递归把每个节点放入容器v中，然后对容器排序输出。排序方法为：层数小的在前面，如果同层并且是奇数，index大的排在前面，如果同层并且是偶数，index大的排在后面。

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int in[100], post[100];
struct node{
    int data, index, level;
};
bool cmp(node a, node b) {
    if(a.level != b.level) return a.level < b.level;
    if(a.level % 2 == 0) return a.index > b.index;
    return a.index < b.index;
}
vector<node> v;
void dfs(int root, int l, int r, int index, int level) {
    if(l > r) return ;
    int begin = l;
    while(l <= r && post[root] != in[begin]) begin++;
    v.push_back({post[root],index,level});
    dfs(root - 1 - (r - begin), l, begin - 1, index*2+1, level+1);
    dfs(root - 1, begin + 1, r, index*2+2, level+1);
}
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> in[i];
    for(int i = 0; i < n; i++)
        cin >> post[i];
    dfs(n-1,0,n-1,0,0);
    sort(v.begin(),v.end(),cmp);
    for(int i = 0; i < v.size(); i++) {
        if(i != 0) cout << " ";
        cout << v[i].data;
    }
}
