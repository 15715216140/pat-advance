1122 Hamiltonian Cycle（25 分）
The "Hamilton cycle problem" is to find a simple cycle that contains every vertex in a graph. Such a cycle is called a "Hamiltonian cycle".

In this problem, you are supposed to tell if a given cycle is a Hamiltonian cycle.

Input Specification:
Each input file contains one test case. For each case, the first line contains 2 positive integers N (2<N≤200), the number of vertices, and M, the number of edges in an undirected graph. Then M lines follow, each describes an edge in the format Vertex1 Vertex2, where the vertices are numbered from 1 to N. The next line gives a positive integer K which is the number of queries, followed by K lines of queries, each in the format:


where n is the number of vertices in the list, and V
​ are the vertices on a path.

Output Specification:
For each query, print in a line YES if the path does form a Hamiltonian cycle, or NO if not.

Sample Input:
6 10
6 2
3 4
1 5
2 5
3 1
4 1
1 6
6 3
1 2
4 5
6
7 5 1 4 3 6 2 5
6 5 1 4 3 6 2
9 6 2 1 6 3 4 5 2 6
4 1 2 5 1
7 6 1 3 4 5 2 6
7 6 1 2 5 4 3 1
Sample Output:
YES
NO
NO
NO
YES
NO


给出一个图，判断给定的路径是不是哈密尔顿路径

1.设置falg1 判断节点是否多走、少走、或走成环
2.设置flag2 判断这条路能不能走通
3.当falg1、flag2都为1时是哈密尔顿路径，否则不是


#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    int n, m, cnt, k, a[210][210] = {0};
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int t1, t2;
        scanf("%d%d", &t1, &t2);
        a[t1][t2] = a[t2][t1] = 1;
    }
    cin >> cnt;
    while(cnt--) {
        cin >> k;
        vector<int> v(k);
        set<int> s;
        int flag1 = 1, flag2 = 1;
        for(int i = 0; i < k; i++) {
            scanf("%d", &v[i]);
            s.insert(v[i]);
        }
        if(s.size() != n || k - 1 != n || v[0] != v[k-1]) flag1 = 0;
        for(int i = 0; i < k - 1; i++)
            if(a[v[i]][v[i+1]] == 0) flag2 = 0;
        printf("%s",flag1 && flag2 ? "YES\n" : "NO\n");
    }
    return 0;
}

