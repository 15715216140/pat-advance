1057 Stack (30)（30 分）
Stack is one of the most fundamental data structures, which is based on the principle of Last In First Out (LIFO). The basic operations include Push (inserting an element onto the top position) and Pop (deleting the top element). Now you are supposed to implement a stack with an extra operation: PeekMedian -- return the median value of all the elements in the stack. With N elements, the median value is defined to be the (N/2)-th smallest element if N is even, or ((N+1)/2)-th if N is odd.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<= 10^5^). Then N lines follow, each contains a command in one of the following 3 formats:

Push key\ Pop\ PeekMedian

where key is a positive integer no more than 10^5^.

Output Specification:

For each Push command, insert key into the stack and output nothing. For each Pop or PeekMedian command, print in a line the corresponding returned value. If the command is invalid, print "Invalid" instead.

Sample Input:

17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
Sample Output:

Invalid
Invalid
3
2
2
1
2
4
4
5
3
Invalid
要求实现一个特殊的桟，除了正常出桟入栈，还要能查询排名在中间的那个数。
普通实现会超时，用树状数组解决，查询更新都是logn
如果入栈就对应的数+1，如果出桟，就-1，最后求他们的和，就是对应的名次，输出即可
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int c[maxn];
stack<int> s;
int lowbit(int x) {
    return x & -x;
}
void update (int index, int value) {
    for(int i = index; i < maxn; i += lowbit(i))
        c[i] += value;
}
int getsum (int index) {
    int sum = 0;
    for(int i = index; i >= 1; i -= lowbit(i))
        sum += c[i];
    return sum;
}
void peekmedian() {
    int l = 1, r = maxn - 1, k = (s.size() + 1) / 2;
    while(l < r) {
        int mid = (l + r) / 2;
        if(getsum(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }
    printf("%d\n",l);
}
int main() {
    int n;
    char str[15];
    cin >> n;
    while(n--) {
        scanf("%s", str);
        if(str[1] == 'u') {
            int num;
            cin >> num;
            s.push(num);
            update(num, 1);
        }else if(str[1] == 'o') {
            if(!s.empty()){
                printf("%d\n", s.top());
                update(s.top(), -1);
                s.pop();
            }else {
                printf("Invalid\n");
            }
        }else if(str[1] == 'e') {
            if(s.empty())
                printf("Invalid\n");
            else
                peekmedian();
        }
    }
    return 0;
}
