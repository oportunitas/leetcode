// Created by oportunitas at 2026/09/27 14:23
// leetgo: 1.4.18
// https://leetcode.com/problems/reverse-prefix-of-word/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 8.3MB/90th%)
        just store the string so far, at first occurence, reverse, append, exit
    */
    string reversePrefix(string word, char ch) {
        ranges::reverse( word | 
            views::take(
                ((ranges::find(word, ch) - word.begin()) % word.size()) + 1
            )
        );
        return word;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string word = LeetCodeIO::deserialize<string>(cin);
		char ch = LeetCodeIO::deserialize<char>(cin);

		Solution obj;
		auto res = obj.reversePrefix(word, ch);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
