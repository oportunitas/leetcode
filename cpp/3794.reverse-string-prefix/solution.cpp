// Created by oportunitas at 2026/09/05 14:56
// leetgo: 1.4.18
// https://leetcode.com/problems/reverse-string-prefix/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #1 (0ms/100th% | 8.8MB/54th%)
		turns out we dont need to create new variables, upon reading modern cpp implementation
		examples, we can just use ranges::reverse(), which does the switching in-place,
		saving memory
	*/
	string reversePrefix(string s, int k) {
		ranges::reverse(s.begin(), s.begin() + k);
		return s;
    }
	
	// /* idea #0 (0ms/100th% | 9.7MB/6th%)
	// 	lets try the most straightforward approach (and hope some parts auto-vectorizes)
	// 	in compilation:
	// 		- create new string, insert twice, return
	// */
    // string reversePrefix(string s, int k) {
	// 	auto result {[&s] () {string _; _.reserve(s.size()); return _;} ()};
	// 	result.insert(result.end(), s.rbegin() + (s.size() - k), s.rend());
	// 	result.insert(result.end(), s.begin() + k, s.end());
	// 	// println("{}", result);
	// 	return result;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);
		int k = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.reversePrefix(s, k);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
