// Created by oportunitas at 2026/11/08 11:11
// leetgo: 1.4.18
// https://leetcode.com/problems/count-servers-that-communicate/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (0ms/100th% | 26.6MB/51th%)
        slight mixup on idea #0, we're supposed to check the entire column/row, not just immediate
        neighbors. we count the number of computers in each row and column. instead of 
        keeping tally of servers that can communicate, which would need searching, we just
        keep count of the servers that are lonely, then subtract the total by that.
    */
    int countServers(vector<vector<int>>& grid) {
        int total {0};
        vector<int> in_row (grid.size(), 0);
        vector<int> in_col (grid[0].size(), 0);
        for (size_t i {0}; i < grid.size(); ++i) {
            for (size_t j {0}; j < grid[0].size(); ++j) {
                in_row[i] += grid[i][j];
                in_col[j] += grid[i][j];
                total += grid[i][j];
            }
        }

        int lonely {0};
        for (size_t i {0}; i < grid.size(); ++i) {
            for (size_t j {0}; j < grid[0].size(); ++j) {
                if (grid[i][j] && (in_row[i] == 1 && in_col[j] == 1)) lonely += 1;
            }
        } 
        
        return total - lonely;
    }

    // /* idea #0 (wrong answer)
    //     we essentially just count how many servers have at least one friend/buddy
    // */
    // int countServers(vector<vector<int>>& grid) {
    //     int ans {0}; 
    //     for (int i = 0; i < grid.size(); ++i) {
    //         for (int j = 0; j < grid[0].size(); ++j) {
    //             if (grid[i][j] == 0) continue;

    //             int buddy {0};
    //             buddy += i > 0 && grid[i-1][j] == 1;
    //             buddy += j > 0 && grid[i][j-1] == 1;
    //             buddy += i < grid.size() - 1 && grid[i+1][j] == 1;
    //             buddy += j < grid[0].size() - 1 && grid[i][j+1] == 1;

    //             ans += (buddy > 0);
    //             println("ans: {}", ans);
    //         }
    //     } return ans;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> grid = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.countServers(grid);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
