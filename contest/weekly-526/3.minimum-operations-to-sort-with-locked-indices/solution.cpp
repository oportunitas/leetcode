// Created by oportunitas at 2026/11/01 09:42
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-operations-to-sort-with-locked-indices/
// https://leetcode.com/contest/weekly-contest-526/problems/minimum-operations-to-sort-with-locked-indices/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        
        vector<bool> req(n, false);
        int max_val = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            max_val = max(max_val, nums[i]);
            if (max_val > i + 1) {
                req[i] = true;
                req[i + 1] = true;
            }
        }
        
        int unlocks_needed = 0;
        for (int i = 0; i < n; ++i) {
            if (req[i] && locked[i] == 1) {
                unlocks_needed++;
            }
        }
        
        if (unlocks_needed > k) {
            return -1;
        }
        
        int inversions = 0;
        vector<int> tree(n + 1, 0);
        
        auto add = [&](int i, int delta) {
            for (; i <= n; i += i & -i) {
                tree[i] += delta;
            }
        };
        
        auto query = [&](int i) {
            int sum = 0;
            for (; i > 0; i -= i & -i) {
                sum += tree[i];
            }
            return sum;
        };
        
        for (int i = n - 1; i >= 0; --i) {
            inversions += query(nums[i] - 1);
            add(nums[i], 1);
        }
        
        return inversions + unlocks_needed;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> locked = LeetCodeIO::deserialize<vector<int>>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.minOperations(nums, locked, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
