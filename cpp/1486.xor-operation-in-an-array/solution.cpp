// Created by oportunitas at 2026/09/21 07:16
// leetgo: 1.4.18
// https://leetcode.com/problems/xor-operation-in-an-array/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
	/* idea #0 (0ms/100th% | 7.7MB/78th%)
		lets look at the pattern:
			00000
					00001
			00010
					00011
			00100
					00101
			00110
					00111
			01000
					01001
			01010
					01011
			01100
					01101
			01110
					01111
			10000
					10001
			10010
					10011

		we can see that whether we start with odd or even only dictates the last bit.
		if we remove the last bit, we're left with binary sequence from 1 upwards:
			num  xor 
			00000 00000 0 0
			00001 00001 1 1 
			00010 00011 2 2
			00011 00000 3 3
			00100 00100 4 0
			00101 00001 5 1
			00110 00111 6 2
			00111 00000 7 3
			01000 01000 8 0
			01001 00001 9
			01010 01011 10
			01011 00000 11
			01100 01100 12
			01101 00001 13
			01110 01111 14
			01111 00000 15
			10000 10000 16
			10001 00001 17
			10010 10011 18
			10011 00000 19
			...

		we can find the following pattern:
			1st last bit changes cycles for 1 number at a time
			2nd last bit changes cycles for 2 numbers at a time
			3rd last bit changes cycles for 4 numbers at a time
			4th last bit changes cycles for 8 numbers at a time
		an xor over this range describes the positions in which there are odd number of 1s.

			num  xor 
			00001 00000 1 3
			00010 00010 2 0
			00011 00001 3 1
			00100 00101 4 2
			00101 00000 5 3
			00110 00110 6 0
			00111 00001 7 1
			01000 01001 8 2
			01001 00000 9 3
			...

			num   xor 
			00010 00000 00011 2 
			00011 00011 00000 3 
			00100 00111 00100 4 
			00101 00010 00001 5 
			00110 00100 00111 6 
			00111 00011 00000 7 
			01000 01011 01000 8 
			01001 00010 00001 9 

			xor given start = xor ^ xor at start
			...

		we can utilize this property, a pattern emerges here:
			in i % 4 == 3 the xor is always 0. this is because, everytime we are almost
			at a number that is evenly divisible by 4, every bit that can be 1 has been 1
			for an even number of times. we can use this as an anchor for values around it.

			in i % 4 == 0, the xor is just the number. since we're starting from all 0s

			in i % 4 == 2, the xor is the next number, since the next number should
			cancel out the bits to get the 0s in the i % 4 == 3 condition

			in i % 4 == 1, the xor is always 1, since its only 1 more than the i % 4 == 0
			case, and since the i % 4 == 0 case is a multiply of 4, the only bit that can
			change is the last bit since its always 0 (even)

		nice, now we have a way to represent up to the 2nd last bit of the number
		based solely on their index. now, to incorporate different start positions
		(again lets just consider up to the 2nd last bit):
			looking at the pattran from above, we can just xor the number we get with the
			xor result of the start number from 0.
		
		so, to recap, here's what we can do:
			- find the last number in the sequence
			- store the last bit (by mod 2 is fine i guess)
			- shift the number right by 1
			- do the i % 4 case, for both the last number and start number
			- xor the last number and start number
			- shift the number left by 1, add the last bit
			- return
	*/
private:
	int i4case(int num) {
		switch (num % 4) {
			case 0:
				return num;
			case 1:
				return 1;
			case 2:
				return num + 1;
			case 3:
				return 0;
		} return 0;
	}

public:
    int xorOperation(int n, int start) {
		int last_xor {i4case((start >> 1) + (n - 1))};
		// println("---");

		int start_xor {i4case(start >> 1)};
		// println("start: {:06b}", start_xor);

		last_xor = last_xor ^ start_xor;
		// println("last : {:06b}", last_xor);

		last_xor = ((last_xor << 1) + (((n + 1) % 2) * (start % 2)));
		// println("last : {:06b}", last_xor);

		last_xor = last_xor ^ start;
		// println("last : {:06b}", last_xor);

		return last_xor;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);
		int start = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.xorOperation(n, start);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
