// Created by oportunitas at 2026/10/01 07:13
// leetgo: 1.4.18
// https://leetcode.com/problems/valid-parentheses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0
        store a stack of the open bracket, then we pop every time we find a matching closing
        bracket. if at any point the closing bracket doesnt match, return false. if
        at the end the open brackets have remained, also return false, else return true
    */
    bool isValid(string s) {
        auto open_stack {[&s] () {vector<char> _; _.reserve(s.size()); return _;} ()};
        unordered_map<char, char> companion {{'}', '{'}, {']', '['}, {')', '('}};

        for (const auto& c : s) {
            if (ranges::contains("{([", c)) {
                open_stack.push_back(c);
            } else if (ranges::contains("})]", c)) {
                if (open_stack.empty() || companion[c] != open_stack.back()) {
                    return false;
                } else {
                    open_stack.pop_back();
                }
            }
        } 

        if (!open_stack.empty()) return false;
        return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.isValid(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
