1134 Vertex Cover（25 分）
A vertex cover of a graph is a set of vertices such that each edge of the graph is incident to at least one vertex of the set. Now given a graph with several vertex sets, you are supposed to tell if each of them is a vertex cover or not.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers N and M (both no more than 10
​4
​​ ), being the total numbers of vertices and the edges, respectively. Then M lines follow, each describes an edge by giving the indices (from 0 to N−1) of the two ends of the edge.

After the graph, a positive integer K (≤ 100) is given, which is the number of queries. Then K lines of queries follow, each in the format:
​​  is the number of vertices in the set, and v[i]'s are the indices of the vertices.

Output Specification:
For each query, print in a line Yes if the set is a vertex cover, or No if not.

Sample Input:
10 11
8 7
6 8
4 5
8 4
8 1
1 2
1 4
9 8
9 1
1 0
2 4
5
4 0 3 8 4
6 6 1 7 5 4 9
3 1 8 4
2 2 8
7 9 8 7 6 5 4 2
Sample Output:
No
Yes
Yes
No
No


给出一个图，和一组点，判断这些点是否覆盖了所有的边
把边存在一个vector中，让后把点用vis数组编辑是否出现，遍历每个边，如果出现有一条边的左右节点都没有被标记，判断出结果为不符合

#include <iostream>
#include <vector>
using namespace std;
struct edge{
    int s, e;
};
int main() {
    int n, m, k;
    scanf("%d%d", &n, &m);
    vector<edge> v(m);
    for(int i = 0; i < m; i++) 
        scanf("%d%d",&v[i].s, &v[i].e);
    scanf("%d",&k);
    while(k--){
        int cnt, num, flag = 1, vis[10010] = {0};
        scanf("%d",&cnt);
        for(int i = 0; i < cnt; i++) {
            scanf("%d",&num);
            vis[num] = 1;
        }
        for(int i = 0; i < v.size(); i++) 
            if(vis[v[i].s] == 0  && vis[v[i].e] == 0) 
                flag = 0;
        if(flag)  cout << "Yes\n";
        else      cout << "No\n";
    }
    return 0;
}

