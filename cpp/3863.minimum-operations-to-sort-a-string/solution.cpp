// Created by oportunitas at 2026/10/21 07:42
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-operations-to-sort-a-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (5ms/88th% | 27.5MB/80th%)
        we're only concerned with sorting at the least (a, b) if
        a, b is the begin and end index of the string. maybe sometimes [a, b)
        or sometimes (a, b]
    */
    int minOperations(string s) {
        char max_c {ranges::max(s)}; 
        char min_c {ranges::min(s)};

        // already sorted
        if (ranges::is_sorted(s)) return 0;

        // not possible to sort
        if (s.size() == 2) return -1;

        // we only need to sort the remaining excluding either s[0] or s[-1] since
        // either of them are already sorted
        if (s[0] == min_c || s[s.size() - 1] == max_c) {
            return 1;
        } 

        // check if the min or max value is "inside"
        for (int i {1}; i < s.size() - 1; ++i) {
            if (s[i] == min_c || s[i] == max_c) return 2;
        }

        // if code gets here, means that the min and max values exact opposites
        return 3;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.minOperations(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
