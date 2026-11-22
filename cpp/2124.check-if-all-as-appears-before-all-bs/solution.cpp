// Created by oportunitas at 2026/11/22 11:08
// leetgo: 1.4.18
// https://leetcode.com/problems/check-if-all-as-appears-before-all-bs/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 8.2MB/82th%)
        this problem is pretty trivial, we just keep track of the index of last occurence of a and b
        and then return false whenever the last b is before the last a. we use sentinels to pre
        init the values 
    */
    bool checkString(string s) {
        int lbi = numeric_limits<int>::max(); 
        int lai = numeric_limits<int>::min();
        for (const auto& [i, c] : s | views::enumerate) {
            if (c == 'b') lbi = i; if (c == 'a') lai = i;
            if (lbi < lai) return false;
        } return true;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.checkString(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
