// Created by oportunitas at 2026/10/02 10:05
// leetgo: 1.4.18
// https://leetcode.com/problems/generate-parentheses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 15.7MB/36th%)
        we can use recursion to opt between ( and ), only returning whenever
        the resulting string has 3 pairs. the general rule for having closing brackets is only that
        the number of opening brackets before it should be less than the number of closing brackets
        so far. in other words, unlike checking whether a string is valid, to create a valid
        parentheses, we can just choose to pick an opening bracket if the opening bracket count
        is less than n, and can do closing brackets whenever the opening bracket count - closing
        bracket count is 1 or more (there's slot/s for closing bracketS)
    */
    void make_strings(
        vector<string>& result, string current, 
        int open_slot, int close_slot
    ) {
        if (open_slot + close_slot == 0) {
            // println("{}", current);
            result.push_back(current);
            return;
        }

        if (open_slot > 0) make_strings(result, current + '(', open_slot - 1, close_slot);
        if (close_slot > open_slot) make_strings(result, current + ')', open_slot, close_slot - 1);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        make_strings(result, "", n, n);
        return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.generateParenthesis(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
