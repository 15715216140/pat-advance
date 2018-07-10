#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> v;
int m[105][105] = {0}, w[105] = {0}, out[105] = {0};
int  sum = 0, count = 0, num, n, l;
stack<int> s;
bool cmp(string aa, string bb) {
    string a = aa, b = bb;
    for(int i = 0;i < a.size(); i++)
        if(a[i] == ' ')  a.erase(a.begin() + i);
    for(int i = 0; i < b.size(); i++)
        if(b[i] == ' ')  b.erase(b.begin() + i);
    aa = a; bb = b;
    return aa > bb;
    
}
void dfs(int node) {
    if(sum > num)    return ;
    if(out[node] == 0) {
        if(num == sum) {
            stack<int> t = s;
            string ans = "";
            while(!t.empty()) {
                ans = to_string(t.top()) + " " + ans;
                t.pop();
            }
            v.push_back(ans);
        }
        return ;
    }
    for(int i = 0; i < n; i++) {
        if(m[node][i]) {
            s.push(w[i]);
            sum += w[i];
            dfs(i);
            sum -= w[i];
            s.pop();
        }
    }
    return ;
}
int main() {
    cin >> n >> l >> num;
    for(int i = 0; i < n; i++) {
        cin >> w[i];
    }
    int father, son_num, son;
    for(int j = 0; j < l; j++){
        cin >> father >> son_num;
        out[father] = 1;
        for(int i = 0; i < son_num; i++) {
            cin >> son;
            m[father][son] = 1;
        }
    }
    sum += w[0];
    s.push(w[0]);
    dfs(0);
    sort(v.begin(),v.end(),cmp);
    if(v.size() == 0) {
        cout << endl;
        return 0;
    }
    for(int i = 0; i < v.size(); i++){
        v[i] = v[i].substr(0,v[i].length() - 1);
        cout << v[i] << endl;

    }
    return 0;
}
