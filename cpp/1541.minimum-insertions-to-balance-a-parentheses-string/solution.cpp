// Created by oportunitas at 2026/10/09 09:04
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (0ms/100th% | 15.6MB/54th%)
        lets try to make the implementation perform better by using integer arithmetic instead
        of floating point arithmetic. this would mean we need to multiply everything by 2 regarding
        balance calculation.
    */
    int minInsertions(string s) {
        int balance {0};
        int toadd {0};
        for (const auto& c : s) {
            // println("balance: {}, toadd: {}", balance, toadd);

            if (c == '(') {
                balance += 2;
                if (balance % 2) {
                    toadd += 1;
                    balance -= 1;
                }
            } else if (c == ')') {
                balance -= 1;
                if (balance < 0) {
                    toadd += 1;
                    balance += 2;
                }
            }
        } 
        // println("final, balance: {}, toadd: {}", balance, toadd);
        return toadd + balance;
    }

    // /* idea #0 (4ms/72th% | 15.5MB/76th%)
    //     instead of adding 1 and subtracting 1 (according to bracket), we can value close bracket
    //     at 0.5 value instead (because we need 2 of them to counterbalance an open bracket)
    // */
    // int minInsertions(string s) {
    //     float balance {0.0};
    //     float toadd {0.0};
    //     for (const auto& c : s) {
    //         // println("balance: {}, toadd: {}", balance, toadd);

    //         if (c == '(') {
    //             balance += 1.0;

    //             if (trunc(balance) != balance) /* extra closing bracket needed */ {
    //                 toadd += 1;
    //                 balance -= 0.5;
    //             }
    //         } else if (c == ')') {
    //             balance -= 0.5;

    //             if (balance < 0.0) /* extra open bracket needed */ {
    //                 toadd += 1;
    //                 balance += 1.0;
    //             }
    //         }
    //     } 
    //     // println("final, balance: {}, toadd: {}", balance, toadd);
    //     return toadd + (2 * balance);
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);

		Solution obj;
		auto res = obj.minInsertions(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
