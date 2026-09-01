// Created by oportunitas at 2026/08/31 16:24
// leetgo: 1.4.18
// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/*idea #0
		hmm, we have 2 things we need to attack here:
			- how to efficiently calculate the GCD of 2 numbers
				(and how this might mean that we can somehow reuse stuff for later on)
			- how to insert a node in between linked list nodes
		
		inserting a node should be easy enough, we just replace the next pointer to
		the existing previous node to the current node, and then put the original next
		node as the destination of the new node's next pointer

		as for finding gcd, lets do a scratchpad session:
			any non-negative number can be represented as the positive sum of 
			prime numbers. but this would mean that we would incorporate the sieve of
			eratosthenes here (which might be too complex for this problem)

			as for caching, we can create an unordered_map of pair <int, int> to store
			gcds for existing numbers.

			the pair map can be recursively constructed if needed, ending with prime numbers

			hmm the above sounds very much like the ladder/tree method of finding gcds in
			primary school. 

			lets take an example for the {18, 6} pair:
				18, find smallest prime to divide;
				18 / 2;
				2 | 9, find smallest prime to divide;
				2 | 9 / 3;
				2, 3 | 3, find smallest prime to divide;
				2, 3 | 3 / 3
				2, 3, 3

				6, find smallest prime to divide;
				6 / 2;
				2 | 3; find smallest prime to divide;
				2 | 3 / 3;
				2, 3
			but this is too time-heavy?

			the yardstick approach is better though:
				suppose one has 2 yardsticks of different lengths a and b.

				we need to find out a 3rd yard stick that can in whole measure both the 
				a and b yardsticks (the 3rd yardstick's length is a whole fraction
				of both yardstick a and b's lengths)

				to find out the biggest yardstick that can do this, we can just measure
				how much the smaller of the 2 yardsticks has left over when we stick multiple of
				that smaller yardsticks beside the longer yardstick until it the stack
				of smaller yardsticks gets just 1 stick from extending over the length of the 
				longer one

				we can create another yardstick that's as long as the gap length of the previous
				setup, and then do the same process, but now treat the original shorter stick
				as the long one and use the new yardstick and stack multiple of them together
				besides it. if the new shorter yardstick stack is perfectly the same
				length as the longer one, this means that we can use this shorter 
				yardstick to in whole measure both a and b yardsticks.

				if not, we do this again down the line until we find the stack of yardsticks that
				in whole measure both a and b yardsticks
		lets to the yardstick method for finding gcd via recursion
	*/

	ListNode* insertGreatestCommonDivisors(ListNode* head) {
        auto gcd = [] (this auto self, int a, int b) -> int {
			// here we assume that b is the shorter yardstick.
			// if we're on the cutting-down process, b also means the length of the
			// extra between the longer yardstick and the stack of shorter ones.
			// this means that if we encounter b as 0, the previous step results in 
			// the yardstick we need as the longer one. as such, we return a in this case
			if (b == 0) return a;

			// finding the gap of the a yardstick and the stack of the b ones is the same 
			// as finding the modulus of a and b
			return self(b, a % b);
		};

		auto res = head;

		while (head->next != nullptr) {
			ListNode* new_node = new ListNode {
				gcd(head->val, head->next->val), 
				head->next
			};
			head->next = new_node;

			// print("{} {} ", head->val, head->next->val);
			head = head->next->next;
		}

		return res;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		ListNode* head = LeetCodeIO::deserialize<ListNode*>(cin);

		Solution obj;
		auto res = obj.insertGreatestCommonDivisors(head);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
