1102 Invert a Binary Tree（25 分）
The following is from Max Howell @twitter:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can't invert a binary tree on a whiteboard so fuck off.
Now it's your turn to prove that YOU CAN invert a binary tree!

Input Specification:
Each input file contains one test case. For each case, the first line gives a positive integer N (≤10) which is the total number of nodes in the tree -- and hence the nodes are numbered from 0 to N−1. Then N lines follow, each corresponds to a node from 0 to N−1, and gives the indices of the left and right children of the node. If the child does not exist, a - will be put at the position. Any pair of children are separated by a space.

Output Specification:
For each test case, print in the first line the level-order, and then in the second line the in-order traversal sequences of the inverted tree. There must be exactly one space between any adjacent numbers, and no extra space at the end of the line.

Sample Input:
8
1 -
- -
0 -
2 7
- -
- -
5 -
4 6
Sample Output:
3 7 2 6 4 0 5 1
6 5 7 4 3 2 0 1

1. 反转二叉树就是存储的时候所有左右结点都交换。
2. 二叉树使用{id, l, r, index, level}存储每个结点的id, 左右结点,下标值，和当前层数
3. 根结点是所有左右结点中没有出现的那个结点
4. 已知根结点，用递归的方法可以把中序遍历的结果push_back到数组v1里面,直接输出就是中序，
排序输出就是层序（排序方式，层数小的排前面，相同层数时，index大的排前面）


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    int id, l, r, index, level;
} a[100];
vector<node> v1;
void dfs(int root, int index, int level) {
    if (a[root].r != -1) dfs(a[root].r, index * 2 + 2, level + 1);
    v1.push_back({root, 0, 0, index, level});
    if (a[root].l != -1) dfs(a[root].l, index * 2 + 1, level + 1);
}
bool cmp(node a, node b) {
    if (a.level != b.level) return a.level < b.level;
    return a.index > b.index;
}
int main() {
    int n, have[100] = {0}, root = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a[i].id = i;
        string l, r;
        cin >> l >> r;
        if (l != "-") {
            a[i].l = stoi(l);
            have[stoi(l)] = 1;
        } else {
            a[i].l = -1;
        }
        if (r != "-") {
            a[i].r = stoi(r);
            have[stoi(r)] = 1;
        } else {
            a[i].r = -1;
        }
    }
    while (have[root] == 1) root++;
    dfs(root, 0, 0);
    vector<node> v2(v1);
    sort(v2.begin(), v2.end(), cmp);
    for (int i = 0; i < v2.size(); i++) {
        if (i != 0) cout << " ";
        cout << v2[i].id;
    }
    cout << endl;
    for (int i = 0; i < v1.size(); i++) {
        if (i != 0) cout << " ";
        cout << v1[i].id;
    }
    return 0;
}
