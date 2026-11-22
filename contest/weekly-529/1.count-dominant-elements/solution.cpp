// Created by oportunitas at 2026/11/22 09:32
// leetgo: 1.4.18
// https://leetcode.com/problems/count-dominant-elements/
// https://leetcode.com/contest/weekly-contest-529/problems/count-dominant-elements/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int countDominantElements(vector<int>& nums) {
        int n = ssize(nums); if (n == 1) return 1;

        int ans = 0;
        if (nums[0] >= nums[1]) ans += 1;
        for (int i = 1; i < n - 1; ++i) {
            ans += (nums[i] * 2 >= (nums[i-1] + nums[i+1]) ? 1 : 0);
        } if (nums[n-1] >= nums[n-2]) ans += 1;
        
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.countDominantElements(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
