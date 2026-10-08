// Created by oportunitas at 2026/10/07 10:34
// leetgo: 1.4.18
// https://leetcode.com/problems/remove-invalid-parentheses/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
    int _max_rem {0};
public:
    /* idea #2 (0ms/100th% | 12.9MB/62th%)
        after reading other accepted solutions, one thing that flew way over my head is 
        how finding an optimal solution for a problem usually means building up from
        an optimized solution for a subset of the problem, and then building up.

        if we're just interested in the _number_ of removals, we can keep track of the
        excess opens in the string, whenever it tries to add a closing bracket to 0 excess,
        we eliminate the current closing bracket, and add 1 to the amount of removals.
        at the end, we add the total amount of removals (from excess closing brackets) to
        the excess open brackets we have. this is already mentioned in the way we find
        the _max_rem variable in previous ideas

            int pointer {0};
            for (const auto& c : s) {
                if (c == '(') {
                    pointer += 1;
                } else if (c == ')') {
                    if (pointer == 0) {
                        _max_rem += 1;
                    } else {
                        pointer -= 1;
                    }
                }
            } _max_rem += pointer;
            // println("max removals: {}", _max_rem);

        if we were to find _any_ string that has the minimum amount removed, we can just
        insert an appending to string logic within the above code block, appending whenever
        we dont get to the case if (c == ')' && pointer == 0).

        a brilliant idea i saw among the other solutions was to do this logic but branch them,
        instead of "removing" the current close bracket to accomodate the (c == ')' && pointer == 0)
        case, we can choose between any close brackets we already traversed through. each of
        them can be used.

        recount how we add _max_rem and pointer at the end of the block. this approach would
        not work if we were to branch the removal options, because just like we can choose
        between available close brackets to pick when we have excess, we should be able to
        choose in the same way (between available open brackets to pick when we have excess)

        a brilliant trick to accomodate this is to rerun the same thing we did but backwards,
        reading from right to left, and this time open brackets reduces pointer by 1, and
        close brackets increases it by 1. after we're done doing this, we essentially get the 
        optimum strings!
    */
    void forward_pass(
        string cur_string, vector<string>& valids, 
        int proc_start, int proc_end
    ) {
        println("forward: {}", cur_string);
        int excess_opens {0};

        // proc_start and proc_end describes the range that we're trying to find out.
        // naturally, proc_start is the same index as the last removed open bracket, and
        // proc_end is the last index that we checked.
        for (int i {proc_end}; i < cur_string.size(); ++i) {
            excess_opens += (cur_string[i] == '(') - (cur_string[i] == ')');
            if (excess_opens >= 0) continue; // string is still valid, add next character.

            // excess opens is < 0, extra close brackets, choose between any close
            // brackets to remove between proc_start and proc_end (proc_start and proc_end)
            // is the range that we're iterating over, before it is confirmed valid (therefore)
            // we cant remove any from that, after that is not checked yet
            for (int j {proc_start}; j <= i; ++j) {
                if (cur_string[j] == ')' && (j == proc_start || cur_string[j - 1] != ')')) {

                    // // we remove the close bracket at the j'th position
                    // cur_string = cur_string.substr(0, j) + cur_string.substr(j + 1);

                    // // then, we set proc_start as j (the removed close bracket position)
                    // // and set proc_end as i. this means that we've concluded our opinion from
                    // // 0 to j, and we shall start over with the calculation but as if the string
                    // // starts at j instead. to remove duplicate calculations, we start calculating
                    // // at i.
                    // proc_start = j;
                    // proc_end = i;

                    // do calculation
                    forward_pass(
                        cur_string.substr(0, j) + cur_string.substr(j + 1), valids, j, i);
                }
            } 
            // we've exhausted all close bracket removal options, we return and let the calculation
            // continue over in the inner calls of forward_pass.
            return;
        }

        // if an instance of forward_pass() gets to this part of the code, it means that it got
        // into the end of the string while excess_opens is >= 0. we've done half the work here,
        // now we pass the same string through but backwards to remove excess open brackets.
        backward_pass(cur_string, valids, cur_string.length() - 1, cur_string.length() - 1);
    }

    void backward_pass(
        string cur_string, vector<string>& valids, 
        int proc_start, int proc_end
    ) {
        int excess_closes {0};
        for (int i {proc_end}; i >= 0; --i) {
            excess_closes += (cur_string[i] == ')') - (cur_string[i] == '(');
            if (excess_closes >= 0) continue;

            for (int j {proc_start}; j >= i; --j) {
                if (cur_string[j] == '(' && (j == proc_start || cur_string[j + 1] != '(')) {
                    // cur_string = cur_string.substr(0, j) + cur_string.substr(j + 1);

                    // // we decrease by 1 since removing at j shifts the indeces by 1 to the left
                    // // unlike the forward pass case where indeces stay intact
                    // proc_start = j - 1;
                    // proc_end = i - 1;

                    backward_pass(
                        cur_string.substr(0, j) + cur_string.substr(j + 1), valids, j - 1, i - 1);
                }
            } return;
        }

        valids.push_back(cur_string);
    }

    void add_to_valids(string& s, vector<string>& valids) {
        forward_pass(s, valids, 0, 0);
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> valids;
        add_to_valids(s, valids);
        return valids;
    }
 
    // /* idea #1 (3ms/91st% | 11.5MB/78th%)
    //     idea #0 gets accepted, but its slow. lets try to optimize a few stuff:
    //         - one thing that flew over my head was i dont need to store cur_string separately
    //           in each iteration. i can push back, then do the iteration when i need it pushed,
    //           and when i'm done, i pop back.
    // */
    // void add_to_valids(
    //     string& s, unordered_set<string>& valids, 
    //     int idx, int rem_count, int excess_opens,
    //     string& cur_string, int open_count, int close_count
    // ) {
    //     if (excess_opens < 0) /*invalid parentheses string, no need to continue*/ {
    //         return;
    //     } else if (idx == s.size()) {
    //         if ((rem_count == _max_rem) && (excess_opens == 0)) {
    //             valids.insert(cur_string);
    //         }
    //         return;
    //     } else {
    //         // skip current character case
    //         // if character is a letter, we must NOT skip
    //         if ((s[idx] == '(' || s[idx] == ')') && (rem_count < _max_rem)) {
    //             add_to_valids(
    //                 s, valids, 
    //                 idx + 1, rem_count + 1, excess_opens, 
    //                 cur_string, open_count, close_count
    //             );
    //         }

    //         // add current character case
    //         if (s[idx] == '(') {
    //             if (open_count < close_count) {
    //                 excess_opens += 1;
    //                 open_count += 1;
    //             } else {
    //                 /*
    //                     no need to check further, we can only skip since there's no leftover
    //                     close brackets
    //                 */
    //                 return;
    //             }
    //         } else if (s[idx] == ')') {
    //             if (excess_opens == 0) {
    //                 return; /* adding close brackets would make the entire string invalid */
    //             } else {
    //                 excess_opens -= 1;
    //             }
    //         }
            
    //         cur_string.push_back(s[idx]);
    //         add_to_valids(
    //             s, valids, 
    //             idx + 1, rem_count, excess_opens, 
    //             cur_string, open_count, close_count
    //         );
    //         cur_string.pop_back();
    //     }
    // }

    // vector<string> removeInvalidParentheses(string s) {
    //     /* initial pass, find out the number of minimum removals needed*/
    //     int pointer {0};
    //     for (const auto& c : s) {
    //         if (c == '(') {
    //             pointer += 1;
    //         } else if (c == ')') {
    //             if (pointer == 0) {
    //                 _max_rem += 1;
    //             } else {
    //                 pointer -= 1;
    //             }
    //         }
    //     } _max_rem += pointer;
    //     // println("max removals: {}", _max_rem);

    //     int test = 1;
    //     unordered_set<string> valids;
    //     int close_count {static_cast<int>(ranges::count(s, ')'))};
    //     string cur_string {""};
    //     add_to_valids(s, valids, 0, 0, 0, cur_string, 0, close_count);
    //     // println("valids: {}", valids);  

    //     if (valids.size() == 0) {
    //         return {""};
    //     } else {
    //         return valids | ranges::to<vector<string>>();
    //     }

    //     // return {"--"};

    //     // for (const auto& [i, row] : valids | views::enumerate) {
    //     //     if (row.size() > 0) {
    //     //         return row | ranges::to<vector<string>>();
    //     //     }
    //     // }

    //     // return {""};
    // }

    // /* idea #0 (135ms/35th% | 24.3MB/25th%)
    //     lets try to approach this via recursion first, see if we can find a 
    //     dp solution afterwards:
    //         - we can have a massive 2d vector that stores the valid parentheses
    //           strings given n many removals (array[0] contains all valid
    //           parentheses given 0 removals)
    //         - the way we populate the array is by using recursion, iterating
    //           through the string and choosing whether to keep or discard
    //           the currrent bracket (and keeping count of the removed bracket
    //           counts)
    //         - then we return the first row of the 2d array that has at least 1
    //           element
    // */
    // void add_to_valids(
    //     string& s, vector<unordered_set<string>>& valids, 
    //     int idx, int rem_count, int excess_opens,
    //     string& cur_string, int open_count, int close_count
    // ) {
    //     // println("idx: {}, rem_count: {}, cur_string: {}", idx, rem_count, cur_string);

    //     if (excess_opens < 0) /*invalid parentheses string, no need to continue*/ {
    //         return;
    //     } else if (idx == s.size()) {
    //         if (excess_opens == 0) {
    //             valids[rem_count].insert(cur_string);
    //             // println("rem_count: {}, cur_string: {}", idx, cur_string);
    //         }
    //         return;
    //     } else {
    //         // if character is a letter, we must NOT skip
    //         if ("()"sv.contains(s[idx])) {
    //             add_to_valids(
    //                 s, valids, 
    //                 idx + 1, rem_count + 1, excess_opens, 
    //                 cur_string, open_count, close_count
    //             );
    //         }

    //         // add current character case
    //         if (s[idx] == '(') {
    //             if (open_count < close_count) {
    //                 excess_opens += 1;
    //                 open_count += 1;
    //             } else {
    //                 return; // no need to check further, we can only skip
    //             }
    //         } else if (s[idx] == ')') {
    //             if (excess_opens == 0) {
    //                 return;
    //             } else {
    //                 excess_opens -= 1;
    //             }
    //         }
            
    //         cur_string.push_back(s[idx]);
    //         add_to_valids(
    //             s, valids, 
    //             idx + 1, rem_count, excess_opens, 
    //             cur_string, open_count, close_count
    //         );
    //         cur_string.pop_back();
    //     }
    // }

    // vector<string> removeInvalidParentheses(string s) {
    //     int test = 1;
    //     // println("test: {}", test);
    //     vector<unordered_set<string>> valids (s.size() + 1, unordered_set<string>());
    //     // println("valids size: {}", valids.size());
    //     int close_count {static_cast<int>(ranges::count(s, ')'))};
    //     string cur_string {""};
    //     add_to_valids(s, valids, 0, 0, 0, cur_string, 0, close_count);

    //     for (const auto& [i, row] : valids | views::enumerate) {
    //         if (row.size() > 0) {
    //             return row | ranges::to<vector<string>>();
    //         }
    //     }

    //     // for (const auto& row : valids) {
    //     //     if (row.size() > 0) {
    //     //         return row;
    //     //     }
    //     // } 
    //     return {""};
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		string s = LeetCodeIO::deserialize<string>(cin);
		Solution obj;
		auto res = obj.removeInvalidParentheses(s);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
