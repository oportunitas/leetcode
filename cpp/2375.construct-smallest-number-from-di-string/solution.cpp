// Created by oportunitas at 2026/10/19 12:34
// leetgo: 1.4.18
// https://leetcode.com/problems/construct-smallest-number-from-di-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 8MB/58th%)
        a genius idea is by doing this:
        suppose we choose the 1st example, and map the "levels" of the numbers
        by summing out the d and i values:

        4         d   f
        3       c   e   g
        2     b           h
        1   a               i
            
            0 1 2 3 4 5 6 7 8

        we can do this:


                ^   ^   
        4     ^  \d  \f
        3   ^  \c  \e  \g
        2 ^  \b  \   \   \h
        1  \a  \           \i
             \               \
            0 1 2 3 4 5 6 7 8
        
        (arrows pointing to the northwest) as a guide for selecting which numbers
        gets assigned the lowest available value. this way we prioritize the leftmost
        values first but also preserve the increase-decrease shape of the string.
    */
    string smallestNumber(string pattern) {
        deque<string> list; list.push_back({(char)((pattern.size() + 1) + '0')});
        for (int i = pattern.size() - 1; i >= 0; --i) {
            if (pattern[i] == 'I') {
                list.push_front({});
            } list.front().push_back((i + 1) + '0');
        } 
        string result;
        for (const auto& str: list) {
            result.append(str);
        } return result;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string pattern = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.smallestNumber(pattern);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
