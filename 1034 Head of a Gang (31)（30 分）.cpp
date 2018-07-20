1034 Head of a Gang (30)（30 分）
One way that the police finds the head of a gang is to check people's phone calls. If there is a phone call between A and B, we say that A and B is related. The weight of a relation is defined to be the total time length of all the phone calls made between the two persons. A "Gang" is a cluster of more than 2 persons who are related to each other with total relation weight being greater than a given threshold K. In each gang, the one with maximum total weight is the head. Now given a list of phone calls, you are supposed to find the gangs and the heads.

Input Specification:

Each input file contains one test case. For each case, the first line contains two positive numbers N and K (both less than or equal to 1000), the number of phone calls and the weight threshold, respectively. Then N lines follow, each in the following format:

Name1 Name2 Time

where Name1 and Name2 are the names of people at the two ends of the call, and Time is the length of the call. A name is a string of three capital letters chosen from A-Z. A time length is a positive integer which is no more than 1000 minutes.

Output Specification:

For each test case, first print in a line the total number of gangs. Then for each gang, print in a line the name of the head and the total number of the members. It is guaranteed that the head is unique for each gang. The output must be sorted according to the alphabetical order of the names of the heads.

Sample Input 1:

8 59
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 1:

2
AAA 3
GGG 3
Sample Input 2:

8 70
AAA BBB 10
BBB AAA 20
AAA CCC 40
DDD EEE 5
EEE DDD 70
FFF GGG 30
GGG HHH 20
HHH FFF 10
Sample Output 2:

0
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<string,int> m;
int a[2011][2011], value[2011], vis[2011];
int cnt, teamcnt,  bossid; long long teamsum;
string name[2011];
struct peo{
	int boss_id;
	int group_num;
}; 
bool cmp(peo c, peo d) {
	return name[c.boss_id] < name[d.boss_id];
}
void dfs(int i) {
	for(int j = 1; j <= cnt; j++) {
		if(vis[j] == 0 && a[i][j] == 1) {
			if(value[j] > value[i]) bossid = j;
			teamsum += value[j];
			teamcnt++;
			vis[j] = 1;
			dfs(j);
		}
	}
}
int main(){
	int n, thresold, tel;
	vector<peo> ans;
	cin >> n >> thresold;
	for(int i = 0; i < n; i++) {
		int ta, tb;
		string s1, s2;
		cin >> s1 >> s2 >> tel;
		if(m.count(s1) == 0){
			cnt++;
			ta = m[s1] = cnt;
		} else{
			ta = m[s1];
		}
		name[ta] = s1;
		value[ta] += tel;
		if(m.count(s2) == 0){
			cnt++;
			tb = m[s2] = cnt;
		} else {
			tb = m[s2];
		}
		name[tb] = s2;
		value[tb] += tel;
		a[ta][tb] = a[tb][ta] = 1;
	}
	for(int i = 1; i <= cnt; i++) {
		if(vis[i] == 0) {
			bossid = i;
			teamsum = value[i];
			teamcnt = 1;
			vis[i] = 1;
			dfs(i);
			if(teamsum / 2 > thresold && teamcnt > 2) {
				ans.push_back({bossid,teamcnt});
			} 
		}
	}
	cout << ans.size() << endl; 
	sort(ans.begin(),ans.end(),cmp);
	for(int i = 0; i < ans.size(); i++) {
		cout << name[ans[i].boss_id] << ' ' << ans[i].group_num << endl;
	}
	return 0;
}