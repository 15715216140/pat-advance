1056 Mice and Rice (25)（25 分）
Mice and Rice is the name of a programming contest in which each programmer must write a piece of code to control the movements of a mouse in a given map. The goal of each mouse is to eat as much rice as possible in order to become a FatMouse.

First the playing order is randomly decided for N~P~ programmers. Then every N~G~ programmers are grouped in a match. The fattest mouse in a group wins and enters the next turn. All the losers in this turn are ranked the same. Every N~G~ winners are then grouped in the next match until a final winner is determined.

For the sake of simplicity, assume that the weight of each mouse is fixed once the programmer submits his/her code. Given the weights of all the mice and the initial playing order, you are supposed to output the ranks for the programmers.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 positive integers: N~P~ and N~G~ (<= 1000), the number of programmers and the maximum number of mice in a group, respectively. If there are less than N~G~ mice at the end of the player's list, then all the mice left will be put into the last group. The second line contains N~P~ distinct non-negative numbers W~i~ (i=0,...N~P~-1) where each W~i~ is the weight of the i-th mouse respectively. The third line gives the initial playing order which is a permutation of 0,...N~P~-1 (assume that the programmers are numbered from 0 to N~P~-1). All the numbers in a line are separated by a space.

Output Specification:

For each test case, print the final ranks in a line. The i-th number is the rank of the i-th programmer, and all the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:

11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
Sample Output:

5 5 5 2 5 5 5 3 1 3 5

#
把老鼠（编号1-n）,重新排队（排队方式题目给了第i位置站a[i]号老鼠），依次从各个小堆中选出最肥的，进入下一轮选拔，剩最后一只为鼠王，最输后按照老鼠肥胖程度排名（最肥的鼠王排第一）。

法一：
所有老鼠入队列，计算出要晋级的老鼠的数量group(有几个小组就有几个老鼠晋级)，未晋级老鼠们的名次为group+1，晋级的老鼠名次待定，下一次循环开始会计算，本次先留着，然后依次出队，再在此过程中，把每组的最肥老鼠挑出来，进入下一轮，，晋级的老鼠们重新入队列。重复此过程，直到选拔完成。此时鼠王名次未记录，所以给他标记一下名次为1

法二：（第二段代码）
所有老鼠入队列，依次出队，再在此过程中，把每组的最肥老鼠挑出来，进入下一轮，并把每个老鼠进到第几轮标记下来（即老鼠的level++），晋级的老鼠们重新入队列。重复此过程，直到选拔完成。然后根据老鼠到第几轮处理排名输出（用map繁琐的处理不如法一巧妙）；
#
调试过程：把循环中的 k 写成 3 了，忘记换回来，调了好久；结构体处理思考不全面，改来改去；
#
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct mice{
	int id;
	int weight;
	int rank;
};
int main(){
	int n, k, t;
	cin >> n >> k;
	vector<mice> m(n);
	queue<mice> q;
	for(int i = 0; i < n; i++) {
		cin >> t;
		m[i] = {i, t, 0};
	}
	for(int i = 0; i < n; i++) {
		cin >> t;
		q.push(m[t]);
	}
	while(q.size() != 1) {
		int tsize = q.size();
		int group = tsize / k;
		if(tsize % k != 0)	group++;
		for(int j, i = 0; i < tsize; i = j) {
			mice maxn = q.front();
			for(j = i; j < i + k && j < tsize; j++) {
				mice t = q.front();
				m[t.id].rank = group + 1;
				q.pop();
				if(t.weight > maxn.weight) 
					maxn = t;
			}
			q.push(maxn);
		}
	}
	m[q.front().id].rank = 1;
	for(int i = 0; i < m.size(); i++){
		if(i != 0)	cout << ' ';
		cout << m[i].rank; 
	}
	return 0;
}
*******************************************************************************************
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
using namespace std;
struct mice{
	int id;
	int weight;
	int rank;
};
int main(){
	int n, k, t;
	cin >> n >> k;
	vector<mice> m(n);
	queue<mice> q;
	vector<int> ans;
	map<int,int> mp;
	for(int i = 0; i < n; i++) {
		cin >> t;
		m[i] = {i,t,1};
	}
	for(int i = 0; i < n; i++) {
		cin >> t;
		q.push(m[t]);
	}
	while(q.size() != 1) {
		int tsize = q.size();
		for(int j, i = 0; i < tsize; i = j) {
			mice maxn = {-1,-1,-1};
			for(j = i; j < i + k && j < tsize; j++) {
				mice t = q.front();
				q.pop();
				if(t.weight > maxn.weight) 
					maxn = t;
			}
			m[maxn.id].rank++;
			q.push(m[maxn.id]);
		}
	}
	for(int i = 0; i < n; i++) 
		ans.push_back(m[i].rank);
	sort(ans.begin(), ans.end(), greater<int>());
	mp[ans[0]] = 1;
	for(int i = 1; i < ans.size(); i++) {
		if(ans[i] == ans[i-1])	mp[ans[i]] = mp[ans[i-1]];
		else					mp[ans[i]] = i + 1;
	}
	for(int i = 0; i < m.size(); i++){
		if(i != 0)	cout << ' ';
		cout << mp[m[i].rank]; 
	}
	return 0;
}