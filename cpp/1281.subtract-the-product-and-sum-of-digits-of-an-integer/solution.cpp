// Created by oportunitas at 2026/09/25 13:21
// leetgo: 1.4.18
// https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 8MB/21th%)
        lets just do the most straightforward, no tricks solution
    */
    int subtractProductAndSum(int n) {
        int product {1};
        int sum {0};

        while (n > 0) {
            product *= n % 10;
            sum += n % 10;
            n /= 10;
        }

        return product - sum;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.subtractProductAndSum(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
