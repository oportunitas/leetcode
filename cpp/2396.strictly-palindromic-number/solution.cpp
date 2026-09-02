// Created by oportunitas at 2026/09/02 08:31
// leetgo: 1.4.18
// https://leetcode.com/problems/strictly-palindromic-number/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0 (Runtime: 0ms/100.00th% | Memory: 7.90MB/26.94th%)
		lets use base 1 (tally counting) to visualize how the numbers are grouped
		9:
			base 1: - | - | - | - | - | - | - | - | -
			base 2: -------- | | | -
			base 3: --------- | | 
		hmm this isnt getting any insights...

		the obvious way to do this is to manually create the numbers in other bases, but
		this is very runtime-heavy, so lets put this idea aside for now. but lets breakdown the
		process to gain insights:
		9:
			base 2 representation process:
				do modulus down powers of 2 until resulting is less than original:
				9 mod 8 = 1;
				then repeat
				...
				1 mod 1 = 0;
				as such: 8 + 1: 1001
		this is wayy too much calculation for a medium problem. there must be a trick

		n is strictly palindromic if for every base between 2 and n - 2, the string rep of b
		is palindromic.

		n in base n-1 is obviously always palindromic, since:
			9 in base 8: 11
			4 in base 3: 11
			8 in base 7: 11
			11 in base 10: 11 (trivial case)
			12 in base 11: 11
			17 in hex: 11
		
		hmm, but this would mean that the exact opposite always happens in base n - 2
		(there would always be one extra from the '11' equivalent):
			9 in base 7: 12
			4 in base 2: 110
			8 in base 6: 12
			11 in base 9: 12
			12 in base 10: 12 (trivial case)
			17 in base 15: 12
			18 in hex: 12
		this would mean that EVERY number cant be strictly palindromic, since base n - 2 always
		fails. 

		excellent!
	*/
    bool isStrictlyPalindromic(int n) {
        return false;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.isStrictlyPalindromic(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
