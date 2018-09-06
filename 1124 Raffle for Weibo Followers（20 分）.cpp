1124 Raffle for Weibo Followers（20 分）
John got a full mark on PAT. He was so happy that he decided to hold a raffle（抽奖） for his followers on Weibo -- that is, he would select winners from every N followers who forwarded his post, and give away gifts. Now you are supposed to help him generate the list of winners.

Input Specification:
Each input file contains one test case. For each case, the first line gives three positive integers M (≤ 1000), N and S, being the total number of forwards, the skip number of winners, and the index of the first winner (the indices start from 1). Then M lines follow, each gives the nickname (a nonempty string of no more than 20 characters, with no white space or return) of a follower who has forwarded John‘s post.

Note: it is possible that someone would forward more than once, but no one can win more than once. Hence if the current candidate of a winner has won before, we must skip him/her and consider the next one.

Output Specification:
For each case, print the list of winners in the same order as in the input, each nickname occupies a line. If there is no winner yet, print Keep going... instead.

Sample Input 1:
9 3 2
Imgonnawin!
PickMe
PickMeMeMeee
LookHere
Imgonnawin!
TryAgainAgain
TryAgainAgain
Imgonnawin!
TryAgainAgain
Sample Output 1:
PickMe
Imgonnawin!
TryAgainAgain
Sample Input 2:
2 3 5
Imgonnawin!
PickMe
Sample Output 2:
Keep going...

从begin位置的人才开始统计,如果遇到中过奖的或者还没到第一个检索的位置，就continue。
cnt++表示当前有效的人的位置，根据位置判断是否中奖。注意题目k的可能取1

#include <iostream>
#include <map>
using namespace std;
int main() {
    map<string,int> m;
    int n, k, begin, cnt = 0, flag = 0;
    cin >> n >> k >> begin;
    for(int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        if(i < begin) continue;
        if(m[name] == 0) {
            cnt++;
            if((cnt - 1) % k == 0) {
                cout << name << endl;
                m[name] = 1;
                flag = 1;
            }
        }
    }
    if(flag == 0) cout << "Keep going...";
}

