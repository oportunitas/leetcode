// Created by oportunitas at 2026/10/11 12:27
// leetgo: 1.4.18
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 7.9MB/79th%)
        we exploit the binary representation of numbers here.

        dividing a number by 2 means shifting right by 1.
        we need to reduce by 1 whenever the number is odd.

        this effectively means, whenever we have the last bit as 1, we need to subtract

        so, recall, we shift right continuously (count this amount),
        then we reduce by 1 whenever the last bit is 1 (also count this amount).

        the amount of shift rights we need is just the width of the number in binary
        and the number of reduce 1 last bits is the number of 1 bits in the number
        already minus 1.
    */
    int numberOfSteps(uint num) {
        return bit_width(num) + max(0, popcount(num) - 1);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int num = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.numberOfSteps(num);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
