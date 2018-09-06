1126 Eulerian Path（25 分）
In graph theory, an Eulerian path is a path in a graph which visits every edge exactly once. Similarly, an Eulerian circuit is an Eulerian path which starts and ends on the same vertex. They were first discussed by Leonhard Euler while solving the famous Seven Bridges of Konigsberg problem in 1736. It has been proven that connected graphs with all vertices of even degree have an Eulerian circuit, and such graphs are called Eulerian. If there are exactly two vertices of odd degree, all Eulerian paths start at one of them and end at the other. A graph that has an Eulerian path but not an Eulerian circuit is called semi-Eulerian. (Cited from https://en.wikipedia.org/wiki/Eulerian_path)

Given an undirected graph, you are supposed to tell if it is Eulerian, semi-Eulerian, or non-Eulerian.

Input Specification:
Each input file contains one test case. Each case starts with a line containing 2 numbers N (≤ 500), and M, which are the total number of vertices, and the number of edges, respectively. Then M lines follow, each describes an edge by giving the two ends of the edge (the vertices are numbered from 1 to N).

Output Specification:
For each test case, first print in a line the degrees of the vertices in ascending order of their indices. Then in the next line print your conclusion about the graph -- either Eulerian, Semi-Eulerian, or Non-Eulerian. Note that all the numbers in the first line must be separated by exactly 1 space, and there must be no extra space at the beginning or the end of the line.

Sample Input 1:
7 12
5 7
1 2
1 3
2 3
2 4
3 4
5 2
7 6
6 3
4 5
6 4
5 6
Sample Output 1:
2 4 4 4 4 4 2
Eulerian
Sample Input 2:
6 10
1 2
1 3
2 3
2 4
3 4
5 2
6 3
4 5
6 4
5 6
Sample Output 2:
2 4 4 4 3 3
Semi-Eulerian
Sample Input 3:
5 8
1 2
2 5
5 4
4 1
1 3
3 2
3 4
5 3
Sample Output 3:
3 3 4 3 3
Non-Eulerian

判断是不是具有欧拉回路或者是不是具有欧拉路径
之前要判断是不是了连通图

#include <iostream>
#include <vector>
using namespace std;
int sum = 0, vis[505];
vector<int> v[505];
void dfs(int i) {
    if(vis[i] == 0) {
        sum++;
        vis[i] = 1;
        for(int j = 0; j < v[i].size(); j++){
            if(vis[v[i][j]] == 0) dfs(v[i][j]);
        }
    }
}
int main(){
    int n, m, even = 0, odd = 0, cnt[505]= {0};
    scanf("%d%d",&n, &m);
    for(int i = 1; i <= m; i++) {
        int t1, t2;
        scanf("%d%d",&t1, &t2);
        v[t1].push_back(t2);
        v[t2].push_back(t1);
        cnt[t1]++;
        cnt[t2]++;
    }
    dfs(1);
    for(int i = 1; i <= n; i++) {
        if(i != 1) cout << " ";
        cout << cnt[i];
        if(cnt[i] % 2 == 0) even++;
        else odd++;
    }
    if(sum != n) {
        cout << "\nNon-Eulerian";
    }else if(odd == 0) {
        cout << "\nEulerian";
    }else if(odd == 2){
        cout << "\nSemi-Eulerian";
    }else {
        cout << "\nNon-Eulerian";
    }
    return 0;
}
