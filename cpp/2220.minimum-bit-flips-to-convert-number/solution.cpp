// Created by oportunitas at 2026/09/20 14:01
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 7.9MB/60th%)
		if the start is 10 and the goal is 7:
			1010
			0111
		we can use xor to find:
			1101
		this has 3 ones

		same thing with 3 to 4:
			011
			100
			---xor
			111
		we have 3 ones

		now, we can utilize the popcount() function to find out the number of 1s!
		this is something that is a feature of the hardware of modern cpus, so no
		need to loop.
	*/
    int minBitFlips(int start, int goal) {
		// println("---");
		// println("{:016b}", start);
		// println("{:016b}", goal);
		// println("{:016b}", popcount((uint32_t)(start ^ goal)));
		return popcount((uint32_t)(start ^ goal));
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int start = LeetCodeIO::deserialize<int>(cin);
		int goal = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.minBitFlips(start, goal);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
