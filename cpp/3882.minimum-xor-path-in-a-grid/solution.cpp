// Created by oportunitas at 2026/10/28 15:29
// leetgo: 1.4.18
// https://leetcode.com/problems/minimum-xor-path-in-a-grid/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

/* idea #4 (69ms/99th% | 40.1MB/96th%)
    lets optimize one more time.

    we can use gcc/clang's _Find_first() and _Find_next() methods from bitsets to 
    speed up iterations over sparse bit sets.
*/
class Solution {
public: 
    int minCost(vector<vector<int>>& grid) {
        int height = grid.size();
        int width = grid[0].size();

        vector<bitset<1024>> exists_in_row (width); 
        exists_in_row[0].set(grid[0][0]); //set grid[0][0]th bit to 1

        for (int row {0}; row < height; ++row) {
            for (int col {0}; col < width; ++col) {
                if (row == 0 && col == 0) continue;
                int cur {grid[row][col]};

                bitset<1024> options;
                if (row > 0) options |= exists_in_row[col];
                if (col > 0) options |= exists_in_row[col-1];
                /*options should now contain all numbers that we need to xor with grid[row][col]*/

                exists_in_row[col].reset(); //set to all 0
                for (auto opt {options._Find_first()}; opt < 1024; opt = options._Find_next(opt)) {
                    if (options[opt] == true) exists_in_row[col].set(opt^cur);
                }
            }
        }

        return exists_in_row[width-1]._Find_first();
    }
};

// /* idea #3 (73ms/99th% | 40.2MB/96th%)
//     lets optimize even further.

//     we can use a bitset instead of a vector of uint8_t for the exists_in_row data
//     so that we dont need to iterate over options (1024 times), which also eliminates
//     lots of heap allocations from the next_state declaration in each loop.
// */
// class Solution {
// public: 
//     int minCost(vector<vector<int>>& grid) {
//         int height = grid.size();
//         int width = grid[0].size();

//         vector<bitset<1024>> exists_in_row (width); 
//         exists_in_row[0].set(grid[0][0]); //set grid[0][0]th bit to 1

//         for (int row {0}; row < height; ++row) {
//             for (int col {0}; col < width; ++col) {
//                 if (row == 0 && col == 0) continue;
//                 int cur {grid[row][col]};

//                 bitset<1024> options;
//                 if (row > 0) options |= exists_in_row[col];
//                 if (col > 0) options |= exists_in_row[col-1];
//                 /*options should now contain all numbers that we need to xor with grid[row][col]*/

//                 exists_in_row[col].reset(); //set to all 0
//                 for (int option {0}; option < 1024; ++option) {
//                     if (options[option] == true) exists_in_row[col].set(option^cur);
//                 }
//             }
//         }

//         for (int option {0}; option < 1024; ++option) {
//             if (exists_in_row[width-1][option]) {
//                 // print("[{}]", option);
//                 return option;
//             }
//         }

//         return -1;
//     }
// };

// /* idea #2 (331ms/71th% | 160.2MB/52th%)
//     lets optimize even further. we can reduce the "exists" set to a 1d array of set.
//     this is possible because at any row, the values of a tile is the xors of the values
//     above it and to its left. this means that we can reduce heap allocation and pointer indirection
//     by just considering a row at a time.

//     also, since vector<bool> is a special data type that uses a bitset-esque system under the hood,
//     we would change the data type to uint8_t but still consider it as a boolean.
// */
// class Solution {
// public: 
//     int minCost(vector<vector<int>>& grid) {
//         int height = grid.size();
//         int width = grid[0].size();

//         vector<vector<uint8_t>> exists_in_row (
//             width, vector<uint8_t> (
//                 1024, false
//             )
//         ); exists_in_row[0][grid[0][0]] = true;


//         for (int row {0}; row < height; ++row) {
//             for (int col {0}; col < width; ++col) {
//                 if (row == 0 && col == 0) continue;
//                 int cur {grid[row][col]};

//                 vector<uint8_t> next_state (1024, false);
//                 for (int option {0}; option < 1024; ++option) {
//                     if (
//                         (row > 0 && exists_in_row[col][option]) ||
//                         (col > 0 && exists_in_row[col-1][option])
//                     ) {
//                         next_state[option^cur] = true;
//                     }
//                 } exists_in_row[col] = next_state;
//             }
//         }

        

//         for (int option {0}; option < 1024; ++option) {
//             if (exists_in_row[width-1][option]) {
//                 // print("[{}]", option);
//                 return option;
//             }
//         }

//         return -1;
//     }
// };

// /* idea #1 (384ms/64th% | 62MB/66th%)
//     for any bit, it can choose between 2 options (both can be either 0 or 1).
//     the end goal is for this bit to have the resulting value of 0 (encountered 1 an 
//     even number of times)

//     we can optimize the pass by creating a stack of numbers in each grid position, that denotes
//     the option of numbers

//      0110    0111
//     (0110)  (0001)

//      0101    1000
//     (0011)  (1001 | 1011)
// */
// class Solution {
// public: 
//     int minCost(vector<vector<int>>& grid) {
//         int height = grid.size();
//         int width = grid[0].size();

//         vector<vector<vector<bool>>> exists (
//             height, vector<vector<bool>> (
//                 width, vector<bool> (
//                     1024, false
//                 )
//             )
//         ); exists[0][0][grid[0][0]] = true;


//         for (int col {0}; col < width; ++col) {
//             for (int row {0}; row < height; ++row) {
//                 int cur {grid[row][col]};
//                 for (int option {0}; option < 1024; ++option) {
//                     if (
//                         (row > 0 && exists[row-1][col][option]) ||
//                         (col > 0 && exists[row][col-1][option])
//                     ) {
//                         exists[row][col][option^cur] = true;
//                     }
//                 }
//             }
//         }

//         for (int option {0}; option < 1024; ++option) {
//             if (exists[height-1][width-1][option]) {
//                 return option;
//             }
//         }

//         return -1;
//     }
// };

// /* idea #0 (time limit exceeded)
//     the xor value of any bit in a binary number is equal to whether the number of 1s
//     in the sequence is odd.

//         001
//         010
//         011
//         110
//         ---xor
//         110

//     so essentially, this problem asks for the least amount of columns with odd number
//     of 1s.

//     lets try to do a more straightforward solution: bfs; and see where we can optimize 
//     later on.

//         1 2
//         3 4
// */
// class Solution {
// public: 
//     uint dfs(vector<vector<int>>& grid, uint run, int i, int j) {
//         if (i >= grid.size() || j >= grid[0].size()) {
//             return UINT_MAX;
//         }

//         // println("{},{}: {}", i, j, run);

//         run ^= grid[i][j];
//         if (i == grid.size() - 1 && j == grid[0].size() - 1) {
//             // println("returning {}", run);
//             return run;
//         } 

//         uint down {dfs(grid,run,i+1,j)};
//         uint rght {dfs(grid,run,i,j+1)};

//         return min(down, rght);
//     }

//     int minCost(vector<vector<int>>& grid) {
//         return dfs(grid, 0, 0, 0);
//     }
// };

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> grid = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.minCost(grid);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
