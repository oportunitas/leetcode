// Created by oportunitas at 2026/09/16 12:27
// leetgo: 1.4.18
// https://leetcode.com/problems/count-the-number-of-consistent-strings/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:

	/* idea #2 (19ms/100th% | 33.9MB/82th%)
		idea #1 should use the least amount of computation, at least as far as i know.
		to push performance up, lets try to use the classic competitive programming
		fast i/o header.
	*/
    int countConsistentStrings(string allowed, vector<string>& words) {
		// this is used to significantly reduce i/o time for very long i/o cases
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		bool is_allowed[1 << 5] {{false}};
		for (auto c : allowed) {
			is_allowed[c - 'a'] = true;
		}

        return ranges::count_if(words, [&is_allowed] (string& word) {
			return ranges::all_of(word, [&is_allowed] (char& c) {
				return is_allowed[c - 'a'];
			});
		});
    }

	// /* idea #1 (46ms/49th% | 33.8MB/95th%)
	// 	idea #0 shows to be inefficient the source of this inefficiency is most likely this:
	// 		return allowed.contains(c);
	// 	one call of this runs a linear search. lets use a mapping to do an O(1) time
	// 	implementation for finding if a word contains only the characters in allowed
	// */
    // int countConsistentStrings(string allowed, vector<string>& words) {
	// 	bool is_allowed[1 << 5] {{false}};
	// 	for (auto c : allowed) {
	// 		is_allowed[c - 'a'] = true;
	// 	}

    //     return ranges::count_if(words, [&is_allowed] (string& word) {
	// 		return ranges::all_of(word, [&is_allowed] (char& c) {
	// 			return is_allowed[c - 'a'];
	// 		});
	// 	});
    // }

	// /* idea #0
	// 	we can use cpp's ranges::count_if() to return the count of instances following 
	// 	a specific criteria
	// */
    // int countConsistentStrings(string allowed, vector<string>& words) {
    //     return ranges::count_if(words, [&allowed] (string& word) {
	// 		return ranges::all_of(word, [&allowed] (char& c) {
	// 			return allowed.contains(c);
	// 		});
	// 	});
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string allowed = LeetCodeIO::deserialize<string>(cin);
		vector<string> words = LeetCodeIO::deserialize<vector<string>>(cin);

		Solution obj;
		auto res = obj.countConsistentStrings(allowed, words);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
