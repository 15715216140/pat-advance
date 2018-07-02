1004 Counting Leaves (30)（30 分）
A family hierarchy is usually presented by a pedigree tree. Your job is to count those family members who have no child.

Input

Each input file contains one test case. Each case starts with a line containing 0 < N < 100, the number of nodes in a tree, and M (< N), the number of non-leaf nodes. Then M lines follow, each in the format:

ID K ID[1] ID[2] ... ID[K]
where ID is a two-digit number representing a given non-leaf node, K is the number of its children, followed by a sequence of two-digit ID's of its children. For the sake of simplicity, let us fix the root ID to be 01.

Output

For each test case, you are supposed to count those family members who have no child for every seniority level starting from the root. The numbers must be printed in a line, separated by a space, and there must be no extra space at the end of each line.

The sample case represents a tree with only 2 nodes, where 01 is the root and 02 is its only child. Hence on the root 01 level, there is 0 leaf node; and on the next level, there is 1 leaf node. Then we should output "0 1" in a line.

Sample Input

2 1
01 1 02
Sample Output

0 1

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m, maxc = 0;
int cnt = 0;
int in[1000] = {0}, out[1000] = {0}, map[1000][1000] = {0};
int res[1000] ={0};
bool vis[1000] = {false};
int dfs(int be) {
    if(out[be] == 0) {
        res[cnt]++;
        if(cnt > maxc)
            maxc = cnt;
        return 0;
    }
    else {
        for(int i = 1; i <= n; i++) {
            if(vis[i] == false && map[be][i] == 1) {
                vis[i] == true;
                cnt++;
                dfs(i);
                vis[i] == false;
                cnt--;
            }
        }
    }
    return 0;
}
int main() {
    int r, c ,num;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> r >> num;
        for(int j = 1; j <= num; j++) {
            cin >> c;
            map[r][c] = 1;
            in[c] = 1;
            out[r] = 1;
        }
    }
    dfs(1);
    cout << res[0];
    for(int i = 1; i <= maxc; i++) {
        cout << ' ' << res[i];
    }
    return 0;
}


