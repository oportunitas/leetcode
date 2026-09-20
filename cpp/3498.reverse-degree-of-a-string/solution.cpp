// Created by oportunitas at 2026/09/20 08:41
// leetgo: 1.4.18
// https://leetcode.com/problems/reverse-degree-of-a-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
#include <execution>
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #0 (0ms/100th% | 9.7MB/78th%)
		lets try to use the most basic loop first, we can optimize later on if its not great enough
	*/
    int reverseDegree(string s) {
        int result {0};
        for (int i {0}; i < s.size(); ++i) {
            // println("{} * {}", (i + 1), ((int)(s[i] - 'z') * -1));
            result += (i + 1) * ((int)(s[i] - 'z' - 1) * -1);
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.reverseDegree(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
