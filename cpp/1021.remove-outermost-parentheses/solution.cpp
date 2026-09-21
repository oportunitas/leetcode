// Created by oportunitas at 2026/09/21 12:15
// leetgo: 1.4.18
// https://leetcode.com/problems/remove-outermost-parentheses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 8.7MB/97th%)
		we store the "depth" of the parenthesees by using a counter, and append to 
		string whenever the counter is greater than 1.
	*/
    string removeOuterParentheses(string s) {
        string result {[&s] () { string _; _.reserve(s.size()); return _; } ()};
		int depth = 0;

		for (auto&& c: s) {
			if (c == ')') {
				depth -= 1;
			}
			if (depth > 0) {
				result.push_back(c);
			}
			if (c == '(') {
				depth += 1;
			} 
		}

		return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.removeOuterParentheses(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
