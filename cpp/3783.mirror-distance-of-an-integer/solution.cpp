// Created by oportunitas at 2026/08/30 17:29
// leetgo: 1.4.18
// https://leetcode.com/problems/mirror-distance-of-an-integer/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	// idea #3 implementation
	int mirrorDistance(int n) {
		int a = n; int b = 0;
		while (n > 0) {
			b *= 10;
			b += n % 10;
			n /= 10;
		}
		return abs(a - b);
	}

	// // idea #2 implementation
	// int reverse(int n) {
	// 	int res = 0;
	// 	while (n > 0) {
	// 		res *= 10;
	// 		res += n % 10;
	// 		n /= 10;
	// 	} return res;
	// }

	// int mirrorDistance(int n) {
	// 	return abs(n - reverse(n));
	// }
	
	// idea #1 implementation
    // int mirrorDistance(int n) {
		// // calculates how much memory to allocate if n were to be converted to 
		// // formatted string. convenient way to find the number of digits in n
		// int sizeof_n = formatted_size("{}", n);
		// // println("sizeof_n = {}", sizeof_n);
		// for (
		// 	struct {
		// 		int64_t a, b, a_borrow, b_borrow, res_a, res_b;
		// 	} _this {0, 0, 0, 0, 0, 0};
		// 	int i : views::iota(0, sizeof_n)
		// ) {
		// 	_this.a = (n / static_cast<int64_t>(pow(10, i))) % 10;
		// 	_this.b = (n / static_cast<int64_t>(pow(10, sizeof_n - i - 1))) % 10;
		// 	// println("a: {} \t| b: {}", _this.a, _this.b);

		// 	_this.a = _this.b - _this.a;
		// 	_this.b = _this.a * -1;
		// 	// println("_a: {} \t| _b: {}", _this.a, _this.b);

		// 	if (_this.a_borrow) {_this.a -= 1; _this.a_borrow = 0;}
		// 	if (_this.b_borrow) {_this.b -= 1; _this.b_borrow = 0;}

		// 	if (_this.a < 0) {_this.a = 10 + _this.a; _this.a_borrow = 1;}
		// 	if (_this.b < 0) {_this.b = 10 + _this.b; _this.b_borrow = 1;}

		// 	// println("a: {} \t| b: {}", _this.a, _this.b);
		// 	// println("---");

		// 	_this.res_a += _this.a * pow(10, i);
		// 	_this.res_b += _this.b * pow(10, i);

		// 	if (i == sizeof_n - 1) {

		// 		// both cant be true by nature 
		// 		// (only one is a negative, as such only one still has remainder at the end)
		// 		if (_this.a_borrow) return _this.res_b;
		// 		if (_this.b_borrow) return _this.res_a;
		// 	}
		// }

		// // this line only gets reached when the answer is 0 (single digits or repeating numbers)
		// return 0;
    // }

	/*scratchpad
	idea #3:
		idea 2 is heading to the right direction, a bit of memory improvement would
		be nice though.

	idea #2:
		hmm, idea #0 and #1 is overthinking it.
		instead of doing the calculation along the way, lets just first find the reverse
		number, and then do abs();

	idea #1:
		this:
			+6 +2 +0 +6
			+6 +0 +2 +6
			-----------
			+0 +2 -2 +0

					+0
				-2 +0
				+8 +0 !
			+1 +8 +0 !
			+1 +8 +0
			+0 +1 +8 +0 solved.
			# top number must be bigger ()
		
		we can do this both ways on a single loop!
		whichever number of both is positive is the valid result
		(the negative one is broken arithmetic since you cant use 
		elementary school "borrowing" technique for where the bottom number is bigger)

	idea #0:
		abcd
		dcba -
		----
		wxxw

		+2 +5
		+5 +2
		-----
		-7 +7

		0
		9

		-9 

		+6 +1 +0 +6
		+6 +0 +1 +6
		-----------
		+0 +1 -1 +0
		
				+0
			-1 +0
			+8 +0 !
		+1 +8 +0 !
		+1 +8 +0
		+0 +1 +8 +0 solved.
		# top number must be bigger ()

		+6 +0 +2 +6
		+6 +2 +0 +6
		-----------
		+0 -2 +2 +0

				+0
			+2 +0
			+2 +0 !
		-2 +2 +0 !
		-2 +2 +0
		+0 -2 +8 +0

		+3 +4 +5
		+2 +8 +8
		--------
			-3
			+7 !
		-4 +7 !
		-5 +7 !
		+5 +7 !
		+1 +5 +7 !
		+0 +5 +7 solved

		+2 +8 +8
		+3 +4 +5
	*/
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.mirrorDistance(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
