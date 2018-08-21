1058 A+B in Hogwarts (20)（20 分）
If you are a fan of Harry Potter, you would know the world of magic has its own currency system -- as Hagrid explained it to Harry, "Seventeen silver Sickles to a Galleon and twenty-nine Knuts to a Sickle, it's easy enough." Your job is to write a program to compute A+B where A and B are given in the standard form of "Galleon.Sickle.Knut" (Galleon is an integer in [0, 10^7^], Sickle is an integer in [0, 17), and Knut is an integer in [0, 29)).

Input Specification:

Each input file contains one test case which occupies a line with A and B in the standard form, separated by one space.

Output Specification:

For each test case you should output the sum of A and B in one line, with the same format as the input.

Sample Input:

3.2.1 10.16.27
Sample Output:

14.1.28
#进制转换#
#
注意用long long 防止溢出就行了
#
#include <iostream>
using namespace std;
int main() {
  long long  a1, a2, a3, b1, b2, b3, c1, c2, c3, sum;
  scanf("%ld.%ld.%ld %ld.%ld.%ld", &a1, &a2, &a3, &b1, &b2, &b3);
  sum = (a1 + b1) * 17 * 29 + (a2 + b2) * 29 + a3 + b3;
  c1 = sum / (17 * 29);
  c2 = (sum % (17 * 29)) / 29;
  c3 = (sum % (17 * 29)) % 29;
  printf("%ld.%ld.%ld",c1, c2, c3);
}