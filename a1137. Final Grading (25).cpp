1137. Final Grading (25)
时间限制
100 ms
内存限制
65536 kB
代码长度限制
16000 B
判题程序
Standard
作者
CHEN, Yue
For a student taking the online course "Data Structures" on China University MOOC (http://www.icourse163.org/), to be qualified for a certificate, he/she must first obtain no less than 200 points from the online programming assignments, and then receive a final grade no less than 60 out of 100. The final grade is calculated by G = (Gmid-termx 40% + Gfinalx 60%) if Gmid-term > Gfinal, or Gfinal will be taken as the final grade G. Here Gmid-term and Gfinal are the student's scores of the mid-term and the final exams, respectively.

The problem is that different exams have different grading sheets. Your job is to write a program to merge all the grading sheets into one.

Input Specification:

Each input file contains one test case. For each case, the first line gives three positive integers: P , the number of students having done the online programming assignments; M, the number of students on the mid-term list; and N, the number of students on the final exam list. All the numbers are no more than 10,000.

Then three blocks follow. The first block contains P online programming scores Gp's; the second one contains M mid-term scores Gmid-term's; and the last one contains N final exam scores Gfinal's. Each score occupies a line with the format: StudentID Score, where StudentID is a string of no more than 20 English letters and digits, and Score is a nonnegative integer (the maximum score of the online programming is 900, and that of the mid-term and final exams is 100).

Output Specification:

For each case, print the list of students who are qualified for certificates. Each student occupies a line with the format:

StudentID Gp Gmid-term Gfinal G

If some score does not exist, output "-1" instead. The output must be sorted in descending order of their final grades (G must be rounded up to an integer). If there is a tie, output in ascending order of their StudentID's. It is guaranteed that the StudentID's are all distinct, and there is at least one qualified student.

Sample Input:
6 6 7
01234 880
a1903 199
ydjh2 200
wehu8 300
dx86w 220
missing 400
ydhfu77 99
wehu8 55
ydjh2 98
dx86w 88
a1903 86
01234 39
ydhfu77 88
a1903 66
01234 58
wehu8 84
ydjh2 82
missing 99
dx86w 81
Sample Output:
missing 400 -1 99 99
ydjh2 200 98 82 88
dx86w 220 88 81 84
wehu8 300 55 84 84
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
using namespace std;
struct stu{
	string name;
	int mooc, mid, end, fin;
};
bool com(stu a, stu b) {
	if(a.fin == b.fin ) return a.name  < b.name ;
	else				return a.fin  > b.fin ;
}
int main() {
	map<string,int> mp;
	int m, n, t, sco, cnt = 0, res = 0;
	vector<stu> a, ans;
	cin >> n >> m >> t;
	string s;
	for(int i = 1; i <= n; i++) {
		cin >> s >> sco;
		if(sco >= 200) {
			mp[s] = cnt++;
			a.push_back(stu{s,sco,-1,-1,0});
		}
	}
	for(int i = 1; i <= m; i++) {
		cin >> s >> sco;
		if(mp.count(s) == 1) {
			a[mp[s]].mid = sco;
		}
	}
	for(int i = 1; i <= t; i++) {
		cin >> s >> sco;
		if(mp.count(s) == 1) {
			a[mp[s]].end = sco;
			if(a[mp[s]].mid > a[mp[s]].end)		a[mp[s]].fin = a[mp[s]].mid*0.4+a[mp[s]].end*0.6 + 0.5;
			else 									a[mp[s]].fin = a[mp[s]].end;
			if(a[mp[s]].fin >=60)	 ans.push_back(a[mp[s]]);
		}
	}
	sort(ans.begin(), ans.end(),com);
	for(int i = 0; i < ans.size(); i++) {
		cout << ans[i].name << ' ' << ans[i].mooc << ' ' << ans[i].mid << ' '<< ans[i].end << ' ' << ans[i].fin << endl;
	}
	return 0;
}

 
