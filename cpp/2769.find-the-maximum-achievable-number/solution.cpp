// Created by oportunitas at 2026/08/30 17:03
// leetgo: 1.4.18
// https://leetcode.com/problems/find-the-maximum-achievable-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int theMaximumAchievableX(int num, int t) {
        return num + (2 * t);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int num = LeetCodeIO::deserialize<int>(cin);
		int t = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.theMaximumAchievableX(num, t);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
