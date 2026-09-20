// Created by oportunitas at 2026/09/20 13:33
// leetgo: 1.4.18
// https://leetcode.com/problems/find-missing-elements/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 32.6MB/50th%)
		we can just create an array mapping for each present number, 
		and then in the end loop over that map for each 0 value.
	*/
    vector<int> findMissingElements(vector<int>& nums) {
		bitset<101> present {0};
		int min_num = INT_MAX;
		int max_num = INT_MIN;
		for (auto&& num : nums) { 
			present[num] = 1; 
			min_num = min(min_num, num);
			max_num = max(max_num, num);
		};

		auto result {[] () { vector<int> _; _.reserve(101); return _; } ()};
		for (int i = min_num; i <= max_num; ++i) {
			if (!present[i]) {
				result.push_back(i);
			}
		} return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.findMissingElements(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
