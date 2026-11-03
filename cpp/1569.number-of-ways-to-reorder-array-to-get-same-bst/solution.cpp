// Created by oportunitas at 2026/10/18 20:12
// leetgo: 1.4.18
// https://leetcode.com/problems/number-of-ways-to-reorder-array-to-get-same-bst/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/* idea #0 (1ms/97th% | 17.3MB/93th%)
    explanations inside function bodies
*/
using i64 = std::int64_t;
class Solution {
public:
    int numOfWays(vector<int>& nums) {
        const i64 mod = 1e9+7;

        /* store the order of insertion, which acts as a ruleset for which numbers can come
           before which numbers (i.e. in example 1: 3 must come first; 1 must come before 2;
           4 must come before 5) */
        vector<i64> order (nums.size() + 2, -1);
        for (size_t i {0}; i < nums.size(); ++i) order[nums[i]] = i;
        
        // this is the product of subtree sizes in each node. what this essentially stores is
        // the number of constraints in the options. if we disregard any ordering, the number
        // of options in nums is nums.size()!. 
        // 
        // however, say, that if we had a rule that states: 
        //      3 must come before 4.
        // and nothing else; we've essentially cut the number of options by half, because
        // we remove all options where 4 comes before 3, which statistically is half of all
        // the original options.
        // 
        // the denom variable is used to store the denominator of this chain of cutting;
        // further description is inside the for loop.
        i64 denom {1};

        vector<i64> stack {{0}};
        for (size_t i {1}; i <= nums.size() + 1; ++i) {
            // if the current number must come before the last number in the stack,
            // we multiply the denom by the distance from it to the last number in the stack.
            // we multiply by distance, not simply by [2, 3, 4, ...] because the ordering 
            // rule just specifies what must come before what, not that it must _immediately_
            // come before/after what.
            while (order[i] < order[stack.back()]) {
                stack.pop_back();
                denom = denom * ((i - 1) - stack.back()) % mod;
            } stack.push_back(i);
        }

        // the actual function here is ((nums.size()! / denom) - 1).
        // but since we're dealing with large numbers and mod, we're expanding the expression.
        // since (a % p) / (b % p) != (a / b) % p, we need to multiply a with modular inverse of b.
        // ((a % p) * (b^-1 % p)) == (a / b) % p. 
        // we can use fermat's little theorem:
        //      b^-1 = b^(m-2)%m; 
        // *given m is prime.
        return ((_ifac(nums.size()) * _ipow(denom, mod - 2)) - 1) % mod;
    }

private:
    // fast integer power
    i64 _ipow(i64 b, i64 e, i64 m = 1e9+7) {
        i64 n {1}; for (b %= m; e; e >>= 1, b = (b * b) % m) {
            if (e & 1) n = (n * b) % m;
        } return n;
    }

    // factorial/integer version of gamma function
    i64 _ifac(i64 n, i64 m = 1e9+7) {
        for (i64 i = n - 1; i >= 2; --i) {
            n = n * i % m;
        } return n;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> nums = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.numOfWays(nums);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
