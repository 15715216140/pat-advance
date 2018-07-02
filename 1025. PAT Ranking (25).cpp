1025. PAT Ranking (25)

Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive number N (<=100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (<=300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:

For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct stu {
    string id;
    int sco, frank, gro, rank;
};
bool cmp(stu x, stu y) {
    if(x.sco == y.sco )    return x.id < y.id ;
    else                return x.sco > y.sco ;
}
int main() {
    vector<stu> ans;
    int n, m, tsco;
    string tid;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        vector<stu> v;
        cin >> m;
        for(int j = 0; j < m; j++) {
            cin >> tid >>  tsco;
            v.push_back(stu {tid,tsco,0,i,0});
        }
        sort(v.begin(),v.end(),cmp);
        v[0].rank = 1;
        ans.push_back(v[0]);
        for(int j = 1; j < v.size(); j++) {
            if(v[j].sco == v[j-1].sco)    v[j].rank = v[j-1].rank;
            else                        v[j].rank = j+1;
            ans.push_back(v[j]);
        }
    }
    sort(ans.begin(),ans.end(),cmp);
    ans[0].frank = 1;
    for(int j = 1; j < ans.size(); j++) {
        if(ans[j].sco == ans[j-1].sco)    ans[j].frank = ans[j-1].frank;
        else                            ans[j].frank = j+1;
    }
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].id << ' ' << ans[i].frank << ' ' << ans[i].gro << ' ' << ans[i].rank << endl;
    return 0;
}

