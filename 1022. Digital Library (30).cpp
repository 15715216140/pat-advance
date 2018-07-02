1022 Digital Library (30)（30 分）
A Digital Library contains millions of books, stored according to their titles, authors, key words of their abstracts, publishers, and published years. Each book is assigned an unique 7-digit number as its ID. Given any query from a reader, you are supposed to output the resulting books, sorted in increasing order of their ID's.

Input Specification:

Each input file contains one test case. For each case, the first line contains a positive integer N (<=10000) which is the total number of books. Then N blocks follow, each contains the information of a book in 6 lines:

Line #1: the 7-digit ID number;
Line #2: the book title -- a string of no more than 80 characters;
Line #3: the author -- a string of no more than 80 characters;
Line #4: the key words -- each word is a string of no more than 10 characters without any white space, and the keywords are separated by exactly one space;
Line #5: the publisher -- a string of no more than 80 characters;
Line #6: the published year -- a 4-digit number which is in the range [1000, 3000].
It is assumed that each book belongs to one author only, and contains no more than 5 key words; there are no more than 1000 distinct key words in total; and there are no more than 1000 distinct publishers.

After the book information, there is a line containing a positive integer M (<=1000) which is the number of user's search queries. Then M lines follow, each in one of the formats shown below:

1: a book title
2: name of an author
3: a key word
4: name of a publisher
5: a 4-digit number representing the year
Output Specification:

For each query, first print the original query in a line, then output the resulting book ID's in increasing order, each occupying a line. If no book is found, print "Not Found" instead.

Sample Input:

3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords debug book
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
Sample Output:

1: The Testing Book
1111111
2222222
2: Yue Chen
1111111
3333333
3: keywords
1111111
2222222
3333333
4: ZUCS Print
1111111
5: 2011
1111111
2222222
3: blablabla
Not Found

#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;
map<string,set<int>> mp1, mp2, mp3, mp4, mp5;
void f(map<string,set<int>> &mp, string &t) {//传参用引用，否则会超时
    if(mp.find(t) != mp.end()) {//判断是否查找到
        for(auto it = mp[t].begin(); it != mp[t].end(); it++)
            printf("%07d\n", *it);
    } else
        cout << "Not Found\n";
}
int main() {
    //    freopen("test.txt","r",stdin);
    string t;
    int n , id;
    cin >> n;
    for(int i = 1; i<= n; i++) {
        scanf("%d\n", &id);
        getline(cin,t);
        mp1[t].insert(id);
        getline(cin,t);
        mp2[t].insert(id);
        while (cin >> t) {
            mp3[t].insert(id);
            char c = getchar();
            if(c == '\n')    break;
        }
        getline(cin,t);
        mp4[t].insert(id);
        getline(cin,t);
        mp5[t].insert(id);
    }
    int m;
    cin >> m;
    int num;
    for(int i = 1; i <= m; i++) {
        scanf("%d: ",&num);
        getline(cin,t);
        cout << num << ": " << t << endl;
        if(num == 1)    f(mp1,t);
        if(num == 2)    f(mp2,t);
        if(num == 3)    f(mp3,t);
        if(num == 4)    f(mp4,t);
        if(num == 5)    f(mp5,t);
    }
    return 0;
}


