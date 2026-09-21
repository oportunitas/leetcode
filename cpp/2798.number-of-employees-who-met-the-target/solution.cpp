// Created by oportunitas at 2026/09/21 09:35
// leetgo: 1.4.18
// https://leetcode.com/problems/number-of-employees-who-met-the-target/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 24.6MB/13th%)
		we can just do a for loop
	*/
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int result {0};
		for (auto hour : hours) {
			result += hour >= target;
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> hours = LeetCodeIO::deserialize<vector<int>>(cin);
		int target = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.numberOfEmployeesWhoMetTarget(hours, target);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
