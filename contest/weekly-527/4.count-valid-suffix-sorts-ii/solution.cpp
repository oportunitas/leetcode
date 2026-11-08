// Created by oportunitas at 2026/11/08 09:30
// leetgo: 1.4.18
// https://leetcode.com/problems/count-valid-suffix-sorts-ii/
// https://leetcode.com/contest/weekly-contest-527/problems/count-valid-suffix-sorts-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<int> countSuffix(vector<int>& nums, vector<int>& target) {
        
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> target = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.countSuffix(nums, target);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
