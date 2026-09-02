// Created by oportunitas at 2026/09/02 08:22
// leetgo: 1.4.18
// https://leetcode.com/problems/partitioning-into-minimum-number-of-deci-binary-numbers/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0 (Runtime: 0ms/100th% | Memory: 16.29MB/96.78th%)
		just find the max digit in the number.
			logic: the minimum amount of deci-binary numbers is always going to be the same
			as whatever the highest digit is (i.e. 990), we need to use 110 9 times,
			no way around it. if the number is instead 1990, we can do 1110 one time and then
			the rest is 110 8 times.
	*/
    int minPartitions(string n) {
        return ranges::max(n) - '0';
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string n = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.minPartitions(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
