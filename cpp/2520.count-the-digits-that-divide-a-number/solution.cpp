// Created by oportunitas at 2026/10/03 13:27
// leetgo: 1.4.18
// https://leetcode.com/problems/count-the-digits-that-divide-a-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 7.9MB/5th%)
        turn num to string, then count
    */
    int countDigits(int num) {
        return ranges::count_if(to_string(num), [&num] (const auto& c) {
            return (num % (c - '0')) == 0;
        });
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int num = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.countDigits(num);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
