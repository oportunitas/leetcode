// Created by oportunitas at 2026/09/30 08:35
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 8.04MB/22th%)
        the smallest sum between the 4 digits abcd, in increasing order should be ab + cd.
    */
    int minimumSum(int num) {
        auto num_arr {[] () {vector<int> _; _.reserve(1 << 6); return _;} ()};
        for (int i {0}; i < 4; ++i) {
            num_arr.push_back(num % 10);
            num /= 10;
        }
        ranges::sort(num_arr);

        int pair1 = (num_arr[0] * 10) + num_arr[2];
        int pair2 = (num_arr[1] * 10) + num_arr[3];
        return pair1 + pair2;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int num = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.minimumSum(num);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
