// Created by oportunitas at 2026/09/12 17:42
// leetgo: 1.4.18
// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #1 (0ms/100th% | 40.5MB/5th%)
		idea #0 was very elegant. and if I were making a production code, ill use idea #0.
		however, its not very efficient, since we are going to be looping over and visiting
		instances of i which does not append to the result vector. a single empty loop 
		iteration is not much by itself, but on very large iteration counts, adds up 
		eventually.

		lets do a recursive algorithm for better performance
	*/

	void recurse(string& s, int& n, vector<string>& result) {
		if (!s.empty() && s.size() == n) {
			result.push_back(s);
			return;
		} else {
			if (s.empty() || s[s.size() - 1] == '1') {
				s.push_back('0');
				recurse(s, n, result);
				s.pop_back();
			} 
			s.push_back('1');
			recurse(s, n, result);
			s.pop_back();
		}
	}

	vector<string> validStrings(int n) {
		auto result {[] () {vector<string> _; _.reserve(1 << 18); return _;} ()};
		auto s {[] () {string _; _.reserve(2048); return _;} ()};
		recurse(s, n, result);
		return result;
	}


	// /* idea #0
	// 	lets try to create the array in the most straightforward way first,
	// 	then we can see what parts that can be improved

	// 	lets convert the strings to binary representations, perhaps theres a pattern here
	// 	000 0 
	// 	001 1
	// 	010 2 x
	// 	011 3 x
	// 	100 4 
	// 	101 5 x
	// 	110 6 x
	// 	111 7 x

	// 	0 x
	// 	1 x
    //              5 4 3 2 1
	// 	00000 00         x
	// 	00001 01       x x
	// 	00010 02     x x
	// 	00011 03     x x
	// 	00100 04  
	// 	00101 05   x x
	// 	00110 06   x x
	// 	00111 07   x x
	// 	01000 08  
	// 	01001 09   
	// 	01010 10 x x
	// 	01011 11 x x
	// 	01100 12  
	// 	01101 13 x x
	// 	01110 14 x x
	// 	01111 15 x x
	// 	10000 16
	// 	10001 17
	// 	10010 18
	// 	10011 19
	// 	10100 20
	// 	10101 21 x
	// 	10110 22 x
	// 	10111 23 x
	// 	11000 24
	// 	11001 25
	// 	11010 26 x
	// 	11011 27 x
	// 	11100 28
	// 	11101 29 x
	// 	11110 30 x
	// 	11111 31 x

	// 	1, 2  -> 3
	// 	2, 4  -> 6
	// 	4, 8  -> 12
	// 	8, 16 -> 24

	// 	00 -> 11
	// 	01 -> 
	// 	10 ->
	// 	11 ->

	// 	10
	// 	00
	// 	01

	// 	10
	// 	01
	// 	01

	// 	10
	// 	10
	// 	01

	// 	10
	// 	11
	// 	01

	// 	000101001001000100101010010110
	// 	101010101010101010101010101010
	// 	010101010101010101010101010101

	// 	a general rule can be observed here:
	// 		if we were writing the string left to right, when
	// 		the current digit is 0, the next digit must be 1. when the current digit
	// 		is 1, the next one can be either 0 or 1.
	// 	we can use either recursion or bit masking to solve this problem.

	// 	lets use bitmasking first.
	// 	we can use numbers' bit representations here, and 
	// 	we can use bitwise operations here to find out which numbers are valid.
	// 	a number is valid if theres no more than 1 consecutive 0 in its definition.

	// 	we can find out if a number has more than 1 0s by shifting and comparing if the top and 
	// 	bottom number both have 0.:
	// 		0000
	// 		1000|0 : all 3 numbers have 0s on both rows
		
	// 		0101
	// 		1010|1 : no 0 duplicates

	// 		010
	// 		101|0 : no 0 duplicates
			
	// 		0110
	// 		1011|0 : no 0 duplicates

	// 		1001
	// 		1100|1 : one 0 duplicate
	// */
    // vector<string> validStrings(int n) {
	// 	auto result {[] () {vector<string> _; _.reserve(1 << 17); return _;} ()};

	// 	// // we use 18 characters since max n is 18, then cut accordingly
	// 	// int a = (0b010101010101010101) >> (18 - n);
	// 	// int b = (0b101010101010101010) >> (18 - n);
	// 	// // println("{:b}, {:b}", a, b);

	// 	if (n == 1) {
	// 		result.push_back("0");
	// 		result.push_back("1");
	// 		return result;
	// 	}

    //     for (uint32_t i = 0; i < (1 << n); ++i) {
	// 		// println("{:b}: {:b}", i, (~(i | i >> 1)) << (32 - (n - 1)));
	// 		if (((~(i | i >> 1)) << (32 - (n - 1))) == 0) {
	// 			result.push_back(format("{:0{}b}", i, n));
	// 		}
	// 	} return result;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.validStrings(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
