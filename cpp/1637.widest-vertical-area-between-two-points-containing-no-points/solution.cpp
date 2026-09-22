// Created by oportunitas at 2026/09/22 12:29
// leetgo: 1.4.18
// https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #1 (0ms/100th% | 72.4MB/46th%)
		instead of sorting the array, we can use the following approach:
			we can create an array of x-s, which stores whether there's a point
			in that x location

			we can then iterate through this array only once, keeping record of the 
			biggest differences between indexes with value 1. the biggest gap
			is the answer.

			this approach changes the time complexity from O(N log(N)) by sorting, to just
			O(N + (max_x - min_x)), essentially O(N), which is faster as input gets larger.

		however. there's a problem with this approach, which is that the size of the 
		array that stores x can be huge. and as we learned from house robber, 
		the act of iterating over a huge array, even though without any operations, does
		take some time away.

		lets take the absolute worst scenario: x is between 0 and 10^9. the problem specifies
		that the length of the array is at most 10^5, so there's no way that the increment of 
		the x values are all 1. 

		instead of making this huge x-storing array directly from the x values of each point,
		we can instead "bin" the array, so instead of storing the status of whether a point
		exists in a single x position, the array contains bins that each describe:
			between the range x of a to b, what is the minimum and maximum x value?

		if we know beforehand, that the max vertical area, is, say, 5. we can set the bin
		size to 5, in this way, we effectively can do the approach above 
		(iterate through x array, keeping record of the biggest
		differences) with way fewer amount of iterations.

		this case instead of just comparing the difference in x values, we compare the difference
		between the maximum of one bin with the minimum of another (and vice versa):

		|   bin 1   |   bin 2   |   bin 3   |   bin 4   |
		| x     x   |       x  x|   x   x   |         xx|  
		
		x marks the max and min values in each bin in the visualization above.
		remember here that it doesnt matter if there's numbers in between the x's, since
		we're searching for a gap bigger than the bin size.

		we can traverse the bins, keep record of whichever is the largest:
			current_min - last_max, or current_max - current_min.
		then we can return the value

		now, another catch: we assumed that we know the max gap is 5, so we use 5 to always find the gap. however, we don't know the max number beforehand.

		so, instead of bothering with the maximum value and trying to find that number,
		we think in reverse, find the bin size that guarantees that whatever the max gap is,
		the bin will always be at the biggest its value, can be lower, but cant be larger, since
		that would mean that we might cancel out one of the 2 points in the max gap for the min
		max per bin value counting.

		the above statement is the definition of the *average* of the gap sizes. the maximum
		gap is always bigger or equal than the average. as such, we can use the average of the 
		gap sizes as the bin size. we dont need to loop over the array to find this. we can just
		find the difference between the absolute maximum and minimum of the value, then divide
		it by the number of points!
	*/
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		int max_x {INT_MIN};
		int min_x {INT_MAX};
		for (const auto& point: points) {
			max_x = max(max_x, point[0]);
			min_x = min(min_x, point[0]);
		}

		// bin size is the average gap size
		int bin_size {(int)((max_x - min_x) / points.size())};
		if (bin_size < 1) bin_size = 1; // in this case we essentially just do direct mapping

		// +1 just for safety
		int bin_count {(max_x - min_x) / bin_size + 1};
		// each bin contains {min, max}
		vector<array<int, 2>> bins(bin_count, {INT_MAX, INT_MIN});

		// put each point to appropriate bins
		for (const auto& point: points) {
			// assign the bin that this point belongs to
			int which_bin = (point[0] - min_x) / bin_size;

			bins[which_bin][0] = min(bins[which_bin][0], point[0]);
			bins[which_bin][1] = max(bins[which_bin][1], point[0]);
		}

		int max_gap {0};
		int last_max {bins[0][0]}; // initially set to the very first x

		for (const auto& bin : bins) {
			if (bin[0] != INT_MAX && bin[1] != INT_MIN) {
				max_gap = max(max_gap, bin[0] - last_max);
				last_max = bin[1];
			}
		}

		return max_gap;
    }

	// /* idea #0 (24ms/69th% | 70.5MB/52th%)
	// 	we sort the array, then go forwards one by one and record the biggest gap
	// */
    // int maxWidthOfVerticalArea(vector<vector<int>>& points) {
	// 	// sort the points vector based on points[i][0] vs points[j][0]
	// 	sort(
	// 		points.begin(), 
	// 		points.end(), 
	// 		[] (const auto& a, const auto&b) {
	// 			return a[0] < b[0];
	// 		}
	// 	);

	// 	int min_i {points[0][0]};
	// 	int max_i {0};
	// 	int result {0};

	// 	// println("{}", points);
	// 	for (int i {0}; i < points.size(); ++i) {
	// 		max_i = points[i][0];
	// 		// println("{} - {}", min_i, max_i);
	// 		result = max(result, (max_i - min_i));
	// 		min_i = points[i][0];
	// 	} return result;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<vector<int>> points = LeetCodeIO::deserialize<vector<vector<int>>>(cin);

		Solution obj;
		auto res = obj.maxWidthOfVerticalArea(points);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
