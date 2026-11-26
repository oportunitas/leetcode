// Created by oportunitas at 2026/11/26 14:04
// leetgo: 1.4.18
// https://leetcode.com/problems/stone-removal-game/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1
        among the public solutions, using a bitmask looks the most
        elegant! it precomputes the ranges where alice or bob wins, 
        then bit shifts according to n (which is equivalent to a bunch
        of if else statements)
    */
    bool canAliceWin(int n) {
        int take = 10; bool is_alice = true;
        while (true) {
            if (take > n) {
                if (is_alice) return false;
                return true;
            }

            n -= take; is_alice = !is_alice; take -= 1;
        }        
    }

    // /* idea #0 (0ms/100th% | 7.8MB/38th%)
    //     lets do a more straightforward o(n) solution first
    // */
    // bool canAliceWin(int n) {
    //     int take = 10; bool is_alice = true;
    //     while (true) {
    //         if (take > n) {
    //             if (is_alice) return false;
    //             return true;
    //         }

    //         n -= take; is_alice = !is_alice; take -= 1;
    //     }        
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int n = LeetCodeIO::deserialize<int>(cin);

		Solution obj;
		auto res = obj.canAliceWin(n);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
