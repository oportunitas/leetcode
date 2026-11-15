// Created by oportunitas at 2026/11/15 10:10
// leetgo: 1.4.18
// https://leetcode.com/problems/count-consistent-subarrays-ii/
// https://leetcode.com/contest/weekly-contest-528/problems/count-consistent-subarrays-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0
        we can slightly optimize the trivial brute force solution which compares like this:
            x
            x

            x
             x
            
            x
              x
            
            ...

             x
             x

             x
              x
             
             x
               x

            ...
            ...
                  x
                  x
        by noticing that in each iteration of the top x, the and value is going to be the same
        for a lot of contiguous sequences. instead of checking one-by-one, we can just jump
        across these blocks
    */
    long long countConsistent(vector<int>& nums) {
        using i64 = std::int64_t;

        array<i64, 1000001> last; last.fill(-1);

        struct block_t {
            i64 and_val;
            i64 l; i64 r;
        }; 
        
        vector<block_t> blocks;
        vector<block_t> next;

        auto push = [&](block_t block) {
            if (!next.empty() && next.back().and_val == block.and_val) {
                next.back().r = block.r;
            } else {
                next.push_back(block);
            }
        };

        i64 count {0};

        for (i64 r = 0; r < ssize(nums); ++r) {
            i64 num = nums[r];
            last[num] = r;

            // update all blocks' and_val to consider num (merge if some gets the same, look at
            // the push() function definition above)
            next.clear();
            for (const auto& [and_val, l, r] : blocks) {
                push({and_val & num, l, r});
            } push({num, r, r}); 
            swap(blocks, next);

            // batch add
            for (const auto& [and_val, l, r] : blocks) {
                count += max<i64>(0, min(r, last[and_val]) - l + 1);
            }
        }

        return count;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.countConsistent(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
