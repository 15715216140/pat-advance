1142 Maximal Clique（25 分）
A clique is a subset of vertices of an undirected graph such that every two distinct vertices in the clique are adjacent. A maximal clique is a clique that cannot be extended by including one more adjacent vertex. (Quoted from https://en.wikipedia.org/wiki/Clique_(graph_theory))

Now it is your job to judge if a given subset of vertices can form a maximal clique.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers Nv (≤ 200), the number of vertices in the graph, and Ne, the number of undirected edges. Then Ne lines follow, each gives a pair of vertices of an edge. The vertices are numbered from 1 to Nv.

After the graph, there is another positive integer M (≤ 100). Then M lines of query follow, each first gives a positive number K (≤ Nv), then followed by a sequence of K distinct vertices. All the numbers in a line are separated by a space.

Output Specification:
For each of the M queries, print in a line Yes if the given subset of vertices can form a maximal clique; or if it is a clique but not a maximal clique, print Not Maximal; or if it is not a clique at all, print Not a Clique.

Sample Input:
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1
Sample Output:
Yes
Yes
Yes
Yes
Not Maximal
Not a Clique

判断给出的子图，是不是强联通子图，并且是不是最大强联通子图

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int m[210][210],vis[210];
int n ,mm, cnt;
vector<int> v;
bool check() {
    for(int i = 0; i < v.size(); i++)
        for(int j= 0; j < v.size(); j++)
            if(i != j && m[v[i]][v[j]] == 0)
                return false;
    return true;
}
bool checkmax() {
    for(int i = 1; i <= n; i++) {
        if(vis[i] == 0) {
            int flag = 1;
            for(int j = 0; j < v.size(); j++)
                if(m[i][v[j]] == 0) flag = 0;
            if (flag == 1)   return false;
        }
    }
    return true;
}
int main() {
    cin >> n >> mm;
    for(int i = 0; i < mm; i++) {
        int t1, t2;
        scanf("%d%d", &t1 ,&t2);
        m[t1][t2] = m[t2][t1] = 1;
    }
    cin >> cnt;
    while(cnt--) {
        int k, vis[210] = {0};
        cin >> k;
        memset(vis,0,sizeof(vis));
        v.resize(k);
        for(int i = 0; i < k; i++) {
            cin >> v[i];
            vis[i] = 1;
        }
        if(check() == false) cout << "Not a Clique\n";
        else {
            if(checkmax() == true)  cout << "Yes\n";
            else  cout << "Not Maximal\n";
        }
    }
    return 0;
}
