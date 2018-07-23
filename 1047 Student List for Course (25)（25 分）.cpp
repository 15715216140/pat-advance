1047 Student List for Course (25)（25 分）
Zhejiang University has 40000 students and provides 2500 courses. Now given the registered course list of each student, you are supposed to output the student name lists of all the courses.

Input Specification:

Each input file contains one test case. For each case, the first line contains 2 numbers: N (<=40000), the total number of students, and K (<=2500), the total number of courses. Then N lines follow, each contains a student's name (3 capital English letters plus a one-digit number), a positive number C (<=20) which is the number of courses that this student has registered, and then followed by C course numbers. For the sake of simplicity, the courses are numbered from 1 to K.

Output Specification:

For each test case, print the student name lists of all the courses in increasing order of the course numbers. For each course, first print in one line the course number and the number of registered students, separated by a space. Then output the students' names in alphabetical order. Each name occupies a line.

Sample Input:

10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
Sample Output:

1 4
ANN0
BOB5
JAY9
LOR6
2 7
ANN0
BOB5
FRA8
JAY9
JOE4
KAT3
LOR6
3 1
BOB5
4 7
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
5 9
AMY7
ANN0
BOB5
DON2
FRA8
JAY9
KAT3
LOR6
ZOE1
#
最后一个测试点bug
#

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
struct order {
	int id;
	string name;
};
struct cases {
	string name;
	vector<int> choice;
};
bool cmp(order a, order b) {
	return a.name < b.name;
}
vector<vector<int>> ans;
vector<string> id_name;
int main() {
	int n, k, i, j, id;
	cin >> n >> k;

	ans.resize(k+1);
	id_name.resize(n+1);
	vector<order> vo(n);
	vector<vector<int>> v(n);
	string s;
	int cnt, tnum;
	char tt[5];
	string ts;
	for(i = 0; i < n; i++) {
		scanf("%s",&tt);
		ts = tt;
		vo[i] = {i, ts};
		id_name[i] = ts;
		scanf("%d",&cnt);
		for(j = 0; j < cnt; j++) {
			scanf("%d",&tnum);
			v[i].push_back(tnum);
		}
	}
	sort(vo.begin(), vo.end(), cmp);
	for(int i = 0; i < vo.size(); i++) {
		id = vo[i].id;
		for(j = 0; j < v[id].size(); j++) {
			ans[v[id][j]].push_back(id);
		}
	}
	for( i = 1; i <= k; i++) {
		printf("%d %d\n", i, ans[i].size());
		for(j = 0; j < ans[i].size(); j++)
			printf("%s\n", id_name[ans[i][j]].c_str());
	}
	return 0;
}