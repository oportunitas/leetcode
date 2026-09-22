// Created by oportunitas at 2026/09/22 11:30
// leetgo: 1.4.18
// https://leetcode.com/problems/truncate-sentence/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea 0 (0ms/100th% | 9MB/41th%)
		we can use the pipe operators with std::views and std::ranges, 
		making the return value look a lot like bash scripting
	*/
    string truncateSentence(string s, int k) {
		// reminds me alot about grep
        return (s 
			| views::split(' ') 
			| views::take(k) 
			| views::join_with(' ') 
			| ranges::to<string>()
		);
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.truncateSentence(s, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
