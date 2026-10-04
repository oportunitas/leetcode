// Created by oportunitas at 2026/10/04 11:10
// leetgo: 1.4.18
// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 35MB/15th%)
        an interesting pattern we can find is that, we can assign the numbers into
        the resulting vector by just finding out its occurence:
            - 1st 1 goes to the 1st result vector
            - 2nd 1 goes to the 2nd result vector
            - 3rd 1 goes to the 3rd result vector
        and so on.
    */
    vector<vector<int>> findMatrix(vector<int>& nums) {
        // we'll use 0-indexing here, so the moment we found a number, that's the 0th occurence
        array<int, 1 << 9> occurence;
        occurence.fill(-1);

        vector<vector<int>> result;
        for (const auto& num : nums) {
            occurence[num] += 1;
            if (occurence[num] >= result.size()) result.push_back({});
            result[occurence[num]].push_back(num);
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.findMatrix(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
