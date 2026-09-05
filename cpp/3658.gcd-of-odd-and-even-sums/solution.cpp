// Created by oportunitas at 2026/09/05 13:30
// leetgo: 1.4.18
// https://leetcode.com/problems/gcd-of-odd-and-even-sums/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0 (0ms/100th% | 8.6MB/10th%)
		the obvious solution would be using the yardstick gcd / euclidean gcd.
		but lets find ways to make this even more efficient.

		A = 1 + 3 + 5 + 7 + ....
		B = 1 + 1 + 1 + 1 + ....
		C = 2 + 4 + 6 + 8 + ....

		A + B = 2 + 4 + 6 + 8 + ....
		A + B = C

		we notice that the difference between A and C is B. in finite lengths, 
		B = n.
		A + n = C

		and we know that C / 2 is 1 + 2 + 3 + 4 + ...:
			n * (n - 1) / 2

		A + n = n (n - 1)
		A + n = n^2 - n
		A = n^2 + 2n

		A = n (n + 2)
		C = n (n - 1)

		we arrived at an analytical comparison between A and C. naturally, we found that
		since A and C both share n as their common multiplier. we can deduce that the
		gcd of A and C is n!
	*/
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.gcdOfOddEvenSums(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
