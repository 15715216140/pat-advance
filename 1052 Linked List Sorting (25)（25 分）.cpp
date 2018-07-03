1052 Linked List Sorting (25)（25 分）
A linked list consists of a series of structures, which are not necessarily adjacent in memory. We assume that each structure contains an integer key and a Next pointer to the next structure. Now given a linked list, you are supposed to sort the structures according to their key values in increasing order.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive N (< 10^5^) and an address of the head node, where N is the total number of nodes in memory and the address of a node is a 5-digit positive integer. NULL is represented by -1.

Then N lines follow, each describes a node in the format:

Address Key Next

where Address is the address of the node in memory, Key is an integer in [-10^5^, 10^5^], and Next is the address of the next node. It is guaranteed that all the keys are distinct and there is no cycle in the linked list starting from the head node.

Output Specification:

For each test case, the output format is the same as that of the input, where N is the total number of nodes in the list and all the nodes must be sorted order.

Sample Input:

5 00001
11111 100 -1
00001 0 22222
33333 100000 11111
12345 -1 33333
22222 1000 12345
Sample Output:

5 12345
12345 -1 00001
00001 0 11111
11111 100 22222
22222 1000 33333
33333 100000 -1
#
给出链表的节点和地址和键值，要求根据键值从小到大排序，并依次输出节点（包括节点的地址，键值，和下一个地址）。结构体中address，value, next， 和flag依次表示节点地址，键值，下一个地址，是否在内存中存在的地址。把地址遍历，在链表中的节点收进vector中。排序。注意：1.链表中没有元素时候第一行不输出，第二行输出 0 -1。 2.链表元素个数为1也需要特判。
#
#include <iostream>
#include <vector>
using namespace std;
struct node
{
    int address, value, next, flag;
};
bool cmp(node a, node b) {
    return a.value < b.value;
}
int main() {
    int n, begin;
    vector<node> v;
    node a[100001];
    cin >> n >> begin;
    for(int i = 0; i < n; i++) {
        int address, value, next;
        cin >> address >> value >> next;
        a[address] = {address,value,next,1};
    }
    for(int i = begin; i != -1; i = a[i].next){
        if(a[i].flag)
            v.push_back(a[i]);
        else break;
    }
    sort(v.begin(), v.end(),cmp);
    if(v.size() != 0)  printf("%d %05d\n", v.size(), v[0].address);
    if(v.size() == 1)   {
        printf("%05d %d -1\n", v[0].address, v[0].value);
        return 0;
    }else if(v.size() == 0) {
        cout << "0 -1";
        return 0;
    }
    for(int i = 0; i < v.size(); i++) {
        if(i != v.size() - 1)
            printf("%05d %d %05d\n", v[i].address, v[i].value , v[i+1].address);
        else
            printf("%05d %d -1\n", v[i].address, v[i].value);
    }
}
