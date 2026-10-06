// Created by oportunitas at 2026/10/06 09:05
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 8.3MB/83th%)
        we can keep track of the excess open brackets with a counter,
        whenever the counter gets to -1, we add 1 to the output, and change the
        output back to 0.

        in the end, if there's still excess open brackets, we add output by the 
        amount of excess.
    */
    int minAddToMakeValid(string s) {
        int excess_opens {0};
        int result {0};
        for (const auto& c : s) {
            if (c == '(') {
                excess_opens += 1;
            } else {
                if (excess_opens == 0) {
                    result += 1;
                } else {
                    excess_opens -= 1;
                }
            }
        }

        return result + excess_opens;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.minAddToMakeValid(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
