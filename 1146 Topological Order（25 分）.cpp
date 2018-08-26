1146 Topological Order（25 分）
This is a problem given in the Graduate Entrance Exam in 2018: Which of the following is NOT a topological order obtained from the given directed graph? Now you are supposed to write a program to test each of the options.

gre.jpg

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers N (≤ 1,000), the number of vertices in the graph, and M (≤ 10,000), the number of directed edges. Then M lines follow, each gives the start and the end vertices of an edge. The vertices are numbered from 1 to N. After the graph, there is another positive integer K (≤ 100). Then K lines of query follow, each gives a permutation of all the vertices. All the numbers in a line are separated by a space.

Output Specification:
Print in a line all the indices of queries which correspond to "NOT a topological order". The indices start from zero. All the numbers are separated by a space, and there must no extra space at the beginning or the end of the line. It is graranteed that there is at least one answer.

Sample Input:
6 8
1 2
1 3
5 2
5 4
2 3
2 6
3 4
6 4
5
1 5 2 3 6 4
5 1 2 6 3 4
5 1 2 3 6 4
5 2 1 6 3 4
1 2 3 4 5 6
Sample Output:
3 4

拓扑排序， 从定义入手，依次找到没有前驱的节点加入序列中。
遍历序列，如果某个节点有前驱，那一定不是拓扑序列

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> v(n+1);
    vector<int> ans, in(n+1);
    for(int i = 0; i < m; i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        v[t1].push_back(t2);
        in[t2]++;
    }
    cin >> k;
    for(int j = 0; j < k; j++) {
        vector<int> tin(in);
        int flag = 1;
        for(int i = 1; i <= n; i++){
            int a;
            scanf("%d%", &a);
            if(tin[a] != 0) flag = 0;
            for(int t:v[a]) tin[t]--;
        }
        if(flag == 1) continue;
        ans.push_back(j);
    }
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << ' ';
        cout << ans[i];
    }
    return 0;
}
