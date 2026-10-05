// Created by oportunitas at 2026/10/05 07:08
// leetgo: 1.4.18
// https://leetcode.com/problems/score-of-parentheses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 7.9MB/96th%)
        a brillant trick that we can use is instead of keeping track of the exact
        sequence, we notice that in the end, the sum is the total of all ()s but
        multiplied by 2 for each "parent" they have.

        so we can work this problem sequentially instead, whenever we encounter
        a '()', we add (2^parent_count) to the sum, because at the end the 1 value
        of this () will be multiplied by 2 parent_count amount of times.
    */
    int scoreOfParentheses(string s) {
        int total {0};
        int open_count {0};
        for (int i {0}; i < s.size(); ++i) {
            if (s[i] == '(') /*open bracket case, add*/ {
                open_count += 1;
            } else if (s[i - 1] == '(' && s[i] == ')') /*lowest depth ()*/ {
                total += (1 << (open_count - 1)); 
                open_count -= 1;
            } else if (s[i] == ')') {
                // we separate here to make the code cleaner
                open_count -= 1;
            } 
        } return total;
    }

    // /* idea #0 (0ms/100th% | 8.3MB/8th%)
    //     we can keep score of the levels of parentheses values (based on
    //     how deep they are) using a stack
    // */
    // int scoreOfParentheses(string s) {
    //     auto stk {[&s] () {
    //         vector<int> _; 
    //         _.reserve(s.size()); 
    //         _.push_back(0);
    //         return _;
    //     } ()};

    //     for (const auto& c : s) {
    //         if (c == '(') {
    //             stk.push_back(0);
    //         } else {
    //             int to_add = stk.back();
    //             if (to_add == 0) {
    //                 to_add += 1;
    //             } else {
    //                 to_add *= 2;
    //             }
    //             stk.pop_back();
    //             stk.back() += to_add;
    //         } 
    //     } return stk.back();
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.scoreOfParentheses(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
