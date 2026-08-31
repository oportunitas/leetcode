// Created by oportunitas at 2026/08/31 15:49
// leetgo: 1.4.18
// https://leetcode.com/problems/maximum-substrings-with-distinct-start/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	// /*idea #4 (result: 17ms/25.4MB)
	// 	experiment: use idea #2 but pre-reserve the set to 26 items,
	// 	perhaps this might speed things up vs idea #2?	
	// */
	// int maxDistinct(string s) {
	// 	auto set = [] () {unordered_set<char> _; _.reserve(26); return _;} ();
	// 	int char_count = 0;
	// 	for (int i = 0; i < s.size() && char_count < 26; ++i) {
	// 		if (!set.contains(s[i])) {
	// 			set.insert(s[i]);
	// 			char_count += 1;
	// 		}
	// 	}
	// 	return char_count;
	// }

	/*idea #3 (result: 0ms/23.9MB)
		idea #2 got run down to 19ms/25.20MB, lets make this better even more:
		making a custom hash function might work to reduce overhead.
	*/
	int maxDistinct(string s) {
		array<bool, 26> hash {};
		int char_count = 0;
		for (int i = 0; i < s.size() && char_count < 26; ++i) {
			// hash[s[i] - 'a'] * 
			if (hash[s[i] - 'a'] == 0) {
				hash[s[i] - 'a'] = 1;
				char_count += 1;
			}
		}
		return char_count;
	}

	// /*idea #2
	// 	idea #1 is very zen but not very efficient both in time and memory (22ms/25.28MB).
	// 	lets try to do a lower-level approach similar to idea #0
	// */
	// int maxDistinct(string s) {
	// 	unordered_set<char> set;
	// 	int char_count = 0;
	// 	for (int i = 0; i < s.size() && char_count < 26; ++i) {
	// 		if (!set.contains(s[i])) {
	// 			set.insert(s[i]);
	// 			char_count += 1;
	// 		}
	// 	}

	// 	return char_count;
	// }

	// /*idea #1
	// 	we're using cpp23 here, so perhaps we can use ranges::to<unordered_set> on s
	// 	and then immediately calculate its size
	// */
    // int maxDistinct(string s) {
	// 	return ranges::to<unordered_set<char>>(s).size();
    // }

	/*idea #0
		iterate through the string, and put any new/undiscovered letter to a set
		the set is used along the way to check if there's an undiscovered character

		if at any point along the loop, the size of the set is 26 (all distinct letters),
		we exit and return 26 since we've exhaused all possible starting letters
	*/
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.maxDistinct(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
