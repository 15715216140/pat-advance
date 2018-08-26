#include <cstdio>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
    int k, n;
    cin k;
    vector<int> tree;
    while(k--) {
        cin >> n;
        tree.resize(n);
        for(int i = 0; i <= n; i++) {
            cin >> tree[i];
        }
        if(check(tree, n)) {
            
        }
    }
    return 0;
}