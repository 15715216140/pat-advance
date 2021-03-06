1036 Boys vs Girls (25)（25 分）
This time you are asked to tell the difference between the lowest grade of all the male students and the highest grade of all the female students.

Input Specification:

Each input file contains one test case. Each case contains a positive integer N, followed by N lines of student information. Each line contains a student's name, gender, ID and grade, separated by a space, where name and ID are strings of no more than 10 characters with no space, gender is either F (female) or M (male), and grade is an integer between 0 and 100. It is guaranteed that all the grades are distinct.

Output Specification:

For each test case, output in 3 lines. The first line gives the name and ID of the female student with the highest grade, and the second line gives that of the male student with the lowest grade. The third line gives the difference grade~F~-grade~M~. If one such kind of student is missing, output "Absent" in the corresponding line, and output "NA" in the third line instead.

Sample Input 1:

3
Joe M Math990112 89
Mike M CS991301 100
Mary F EE990830 95
Sample Output 1:

Mary EE990830
Joe Math990112
6
Sample Input 2:

1
Jean M AA980920 60
Sample Output 2:

Absent
Jean AA980920
NA

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct stu{
    string name;
    char c;
    string id;
    int sco;
};
int main() {
    int n ;
    stu a[10000];
    cin >> n;
    int mins = 100, maxs = 0, minbe = 0, maxbe = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].name >> a[i].c >> a[i].id >> a[i].sco ;
        if(a[i].c == 'M') {
            if(a[i].sco < mins) {
                mins = a[i].sco ;
                minbe = i;
            }
        }
        if(a[i].c == 'F') {
            if(a[i].sco > maxs) {
                maxs = a[i].sco ;
                maxbe = i;
            }
        }
    }
    if(maxbe == 0)     cout << "Absent\n";
    else             cout << a[maxbe].name  << ' ' << a[maxbe].id << endl;
    
    if(minbe == 0)     cout << "Absent\n";
    else            cout << a[minbe].name  << ' ' << a[minbe].id << endl;
    
    if(maxbe != 0 && minbe != 0)    cout << a[maxbe].sco - a[minbe].sco  << endl;
    else                            cout << "NA\n";
    return 0;
}


