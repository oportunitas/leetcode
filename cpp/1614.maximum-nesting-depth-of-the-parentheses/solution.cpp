// Created by oportunitas at 2026/10/06 10:35
// leetgo: 1.4.18
// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 8.4MB/61th%)
        we can count the number of open brackets (minus 1 whenever there's close
        brackets) and keep count of the running total
    */
    int maxDepth(string s) {
        int max_depth {0};
        for (int cur_depth {0}; const auto& c : s) {
            if (c == '(') {
                cur_depth += 1;
                max_depth = max(max_depth, cur_depth);
            } else if (c == ')') {
                cur_depth -= 1;
            }
        } return max_depth;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.maxDepth(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
