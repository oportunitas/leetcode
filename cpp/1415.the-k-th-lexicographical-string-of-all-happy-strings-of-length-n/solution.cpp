// Created by oportunitas at 2026/09/22 11:44
// leetgo: 1.4.18
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #0 (0ms/100th% | 7.8MB/96th%)
        lets consider the pattern: 
            n = 1:
                'a', 0
                'b', 1
                'c'  2
            n = 2:
                'ab', 0 0
                'ac', 0 1
                'ba', 1 2
                'bc', 1 3
                'ca', 2 4
                'cb'  2 5
            n = 3:
                'aba',  0 1 0 0
                'abc',  0 1 2 1
                'aca',  0 2 0 2
                'acb',  0 2 1 3
                'bab',  1 0 1 4
                'bac',  1 0 2 5
                'bca',  1 2 0 6
                'bcb',  1 2 1 7
                'cab',  2 0 1 8
                'cac',  2 0 2 9
                'cba',  2 1 0 10
                'cbc'   2 1 2 11
            ....
        
        we can see that each increase in n doubles the set.
        and we can see that at least for the first character only, if a=0, b=2, c=3:
            first character is ((k - 1) // n)
        we can do this down the line:
    */
    string getHappyString(int n, int k) {
        auto result {[&n] () { string _; _.reserve(n + 1); return _; } ()};
        k -= 1;
        int length = (int)pow(2, n - 1);
        int last_char = INT_MAX;
        for (int i {0}; i < n; ++i) {
            int cur_char = k / length;
            if (last_char <= cur_char) {
                cur_char += 1;
            } 
            if (cur_char > 2) {
                break;
            }
            result.push_back(cur_char + 'a');
            k = k % length;
            length /= 2;
            last_char = cur_char;
        } 
        return result;
    }
};

// @lc code=end

int main() {
    ios_base::sync_with_stdio(false);
    try {
        int n = LeetCodeIO::deserialize<int>(cin);
        int k = LeetCodeIO::deserialize<int>(cin);

        Solution obj;
        auto res = obj.getHappyString(n, k);

        stringstream out_stream;
        LeetCodeIO::print(out_stream, res);
        cout << "\noutput: " << out_stream.rdbuf() << '\n';
    } catch (const LeetCodeIO::Error &error) {
        cerr << "LC_IO: " << error.what() << '\n';
        return 2;
    }
    return 0;
}
