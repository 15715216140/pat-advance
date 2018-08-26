1147 Heaps（30 分）
In computer science, a heap is a specialized tree-based data structure that satisfies the heap property: if P is a parent node of C, then the key (the value) of P is either greater than or equal to (in a max heap) or less than or equal to (in a min heap) the key of C. A common implementation of a heap is the binary heap, in which the tree is a complete binary tree. (Quoted from Wikipedia at https://en.wikipedia.org/wiki/Heap_(data_structure))

Your job is to tell if a given complete binary tree is a heap.

Input Specification:
Each input file contains one test case. For each case, the first line gives two positive integers: M (≤ 100), the number of trees to be tested; and N (1 < N ≤ 1,000), the number of keys in each tree, respectively. Then M lines follow, each contains N distinct integer keys (all in the range of int), which gives the level order traversal sequence of a complete binary tree.

Output Specification:
For each given tree, print in a line Max Heap if it is a max heap, or Min Heap for a min heap, or Not Heap if it is not a heap at all. Then in the next line print the tree‘s postorder traversal sequence. All the numbers are separated by a space, and there must no extra space at the beginning or the end of the line.

Sample Input:
3 8
98 72 86 60 65 12 23 50
8 38 25 58 52 82 70 60
10 28 15 12 34 9 8 56
Sample Output:
Max Heap
50 60 65 72 12 23 86 98
Min Heap
60 58 52 38 82 70 25 8
Not Heap
56 12 34 28 9 8 15 10

检查大还是小顶堆，根据下表，静态后续遍历树即可


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int k, n, a[20000] = {0};
vector<int> ans;
void check(){
    int big = 1, small = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] > a[i/2]) {
            big = 0;
            break;
        }
    }
    for(int i = 2; i <= n; i++) {
        if(a[i] < a[i/2]) {
            small = 0;
            break;
        }
    }
    if(big == 1) cout << "Max Heap\n";
    else if(small == 1) cout << "Min Heap\n";
    else cout << "Not Heap\n";
}
void post(int root) {
    if(root > n) return ;
    post(2 * root);
    post(2 * root + 1);
    ans.push_back(a[root]);
}
int main(){
    cin >> k >> n;
    while(k--) {
        ans.clear();
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        check();
        post(1);
        if(n != ans.size()) while(1);
        for(int i = 0; i < n; i++) {
            if(i != 0) cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
