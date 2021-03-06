1065. A+B and C (64bit) (20)
Given three integers A, B and C in [-263, 263], you are supposed to tell whether A+B > C.
Input Specification:
The first line of the input gives the positive number of test cases, T (<=10). Then T test cases follow, each consists of a single line containing three integers A, B and C, separated by single spaces.
Output Specification:
For each test case, output in one line "Case #X: true" if A+B>C, or "Case #X: false" otherwise, where X is the case number (starting from 1)."
Sample Input:
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0

import java.math.BigInteger;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        BigInteger a, b, c;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i = 1; i <= n; i++){
            a = sc.nextBigInteger();
            b = sc.nextBigInteger();
            c = sc.nextBigInteger();
            if(a.add(b).compareTo(c) == 1)
                System.out.println("Case #" + i + ": true");
            else
                System.out.println("Case #" + i + ": false");
        }
    }
}
