1067 Sort with Swap(0, i)（25 分）
Given any permutation of the numbers {0, 1, 2,..., N−1}, it is easy to sort them in increasing order. But what if Swap(0, *) is the ONLY operation that is allowed to use? For example, to sort {4, 0, 2, 1, 3} we may apply the swap operations in the following way:

Swap(0, 1) => {4, 1, 2, 0, 3}
Swap(0, 3) => {4, 1, 2, 3, 0}
Swap(0, 4) => {0, 1, 2, 3, 4}
Now you are asked to find the minimum number of swaps need to sort the given permutation of the first N nonnegative integers.

Input Specification:
Each input file contains one test case, which gives a positive N (≤10
​5
​​ ) followed by a permutation sequence of {0, 1, ..., N−1}. All the numbers in a line are separated by a space.

Output Specification:
For each case, simply print in a line the minimum number of swaps need to sort the given permutation.

Sample Input:
10
3 5 7 2 6 4 9 0 8 1
Sample Output:
9

1.把0号位置称作公交站，每个数字排序后的位置称作家，每个数字回到正确的位置称作回家
2.只需要把1  ～ n - 1 位置上的数字都回家，则排序完成
3.依次遍历每个位置i，如果当前位置不是与之对应的数字，那么我们让这个数字回家
4.数字如何回家：让数字回家前，检查公交站台还有没有人(数字0除外)在公交等待，如果有，让这个人从公交站台直接回家（即交换0号位置和0号数字的家），重复此动作，直到公交站台上的数字为0。然后再次检查i位置上是否等于i这个数字（因为，让公交站台的人回家时，可能会有数字回到此位置），如果不等于，就把此位置的数字放到公交站台等待，为回家做准备
5.在4过程中，如果n-2号位置处理完成后，只剩两种情况，1: 全部有序 ok~ 2: 0号和n-1号互相占着对方的家，把n-1号扔到公交站台就行了（即交换0和n-1号的过程），此过程已经包括在4步骤里了，怕你们不理解，单独说一下～


1.0号为哨兵， 用哨兵与其他数字交换，使其他数字回到有序的位置（最后有序时所处的位置），则排序完成
2.a[t] = i; 表示t数字当前正在占着哪一个位置。 （如果想实时监测每个数字的位置，可以用 b 数组{b[a[i]] = i } 缓存一下数据，输出查看的）
3.依次遍历每个位置i，如果当前位置不是与之对应的数字，那么我们让这哨兵来去该数执行操作回到正确位置
4.数字如何被哨兵执行操作回到序的位置：
                        如果哨兵此时不在自己有序的位置上，那就，先让哨兵去让他占的那个位置上的真正应该放的数字回到此位置，即交换哨兵和此数字，我们swap(a[0],a[a0])，直到哨兵在交换的过程中回到了自己的有序位置。字词再次检查该位置是不是应该放的数字（别的数字回到有序位置的时候即哨兵执行操作的过程中，有可能让此位置该有的数字回到位置）。如果此位置不是当前数字，那哨兵和他交换swap(a[0],a[i])，就是让他先去哨兵的有序位置待一会，等下一轮操作，哨兵会把他交换回来的。如果此位置已经是该数字了，那就什么都不做。
5.当到达最后一个位置时候，两种情况 1）。如果第一个数字和最后一个数字都在自己的有序位置 那ok~ 2）.哨兵和最后一个数字互相占着对方的位置，那最后一个数字就是哨兵，交换一次后，哨兵在交换后的位置等待，就是已经回到自己的有序位置，此时排序也是完成的。此过程包括在4里面了，怕你们不理解，单独说一下～

#include <iostream>
using namespace std;
int main() {
    int n, t, cnt = 0, a[100010];
    cin >> n;
    for(int i = 0; i < n; i++){
    	cin >> t;
    	a[t] = i;
    }
    for(int i = 1; i < n; i++) {
        if(i != a[i]) {
            while(a[0] != 0) {
                swap(a[0],a[a[0]]);
                cnt++;
            }
            if(i != a[i]) {
                swap(a[0],a[i]);
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
