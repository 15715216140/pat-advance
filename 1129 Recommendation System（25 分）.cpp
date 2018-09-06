1129 Recommendation System（25 分）
Recommendation system predicts the preference that a user would give to an item. Now you are asked to program a very simple recommendation system that rates the user‘s preference by the number of times that an item has been accessed by this user.

Input Specification:
Each input file contains one test case. For each test case, the first line contains two positive integers: N (≤ 50,000), the total number of queries, and K (≤ 10), the maximum number of recommendations the system must show to the user. Then given in the second line are the indices of items that the user is accessing -- for the sake of simplicity, all the items are indexed from 1 to N. All the numbers in a line are separated by a space.

Output Specification:
For each case, process the queries one by one. Output the recommendations for each query in a line in the format:

query: rec[1] rec[2] ... rec[K]
where query is the item that the user is accessing, and rec[i] (i=1, ... K) is the i-th item that the system recommends to the user. The first K items that have been accessed most frequently are supposed to be recommended in non-increasing order of their frequencies. If there is a tie, the items will be ordered by their indices in increasing order.

Note: there is no output for the first item since it is impossible to give any recommendation at the time. It is guaranteed to have the output for at least one query.

Sample Input:
12 3
3 5 7 5 5 3 2 1 8 3 8 12
Sample Output:
5: 3
7: 3 5
5: 3 5 7
5: 5 3 7
3: 5 3 7
2: 5 3 7
1: 5 3 2
8: 5 3 1
3: 5 3 1
8: 3 5 1
12: 3 5 8

每次打印前m明推荐，然后更新推荐列表，可以手动写，也可以用set写， 结构体node要重载operator方法

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int cnt[50005];
bool cmp(int a, int b) {
    if(cnt[a] != cnt[b]) return cnt[a] > cnt[b];
    return a < b;
}
int main() {
    int n, m, t;
    scanf("%d%d", &n, &m);
    vector<int> v;
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        int size = min(m,(int)v.size());
        sort(v.begin(), v.end(), cmp);
        if(size != 0) {
            printf("%d:",t);
            for(int j = 0; j < size; j++) {
                printf(" %d",v[j]);
            }
            printf("\n");
        }
        cnt[t]++;
        int flag = 0;
        for(int j = 0; j < v.size(); j++) {
            if(v[j] == t) flag = 1;
        }
        if(flag) {
            cnt[t]++;
        }else {
            cnt[t]++;
            if(v.size() < m) {
                v.push_back(t);
            }else{
                int maxid = -1, mindata = 9999999, value = 999999999;
                for(int j = 0; j < v.size(); j++) {
                    if(cnt[v[j]] < mindata || (cnt[v[j]] == mindata && v[j] > value)) {
                        value = v[j];
                        maxid = j;
                        mindata = cnt[v[j]];
                    }
                }
                if(cnt[t] > mindata || (cnt[t] == mindata && t < value))
                    v[maxid] = t;
            }
        }
    }
    return 0;
}

法二

#include <iostream>
#include <set>
using namespace std;
int cnt[50005];
struct node{
    int value, cnt;
    bool operator < (const node a) const{
        if(value != a.value) return value > a.value;
        return cnt != a.cnt;
    }
};
int main() {
    int n, m, t;
    scanf("%d%d", &n, &m);
    set<node> s;
    for(int i = 0; i < n; i++) {
        scanf("%d", &t);
        if(i != 0) {
            printf("%d:",t);
            int j = 0;
            for(auto it = s.begin(); j < m && it != s.end(); it++) {
                printf(" %d",it->value);
                j++;
            }
            printf("\n");
        }
        auto it = s.find({t,cnt[t]});
        if(it != s.end()) s.erase(it);
        cnt[t]++;
        s.insert({t,cnt[t]});
    }
    return 0;
}
