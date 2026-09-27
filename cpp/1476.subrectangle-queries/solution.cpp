// Created by oportunitas at 2026/09/27 14:33
// leetgo: 1.4.18
// https://leetcode.com/problems/subrectangle-queries/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class SubrectangleQueries {
/*  idea #0
    i expect huge updateSubrectangle() calls, so instead of storing the values
    literally in the array

    instead, we can just store the values of the dots in a vector, and then 
    check them backwards
*/
private:
    vector<vector<int>> base_rect;
    vector<array<int, 5>> edits;
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        base_rect = rectangle;
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        edits.push_back({row1, col1, row2, col2, newValue});
        edits.reserve(501);
    }
    
    int getValue(int row, int col) {
        for (int i {(int)edits.size() - 1}; i >= 0; --i) {
            const auto& edit = edits[i];
            if (
                row >= edit[0] && row <= edit[2] &&
                col >= edit[1] && col <= edit[3]
            ) {
                return edit[4];
            }
        } return base_rect[row][col];
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		auto method_names = LeetCodeIO::deserialize<vector<string>>(cin);
		auto params = LeetCodeIO::split_array(cin);

		unique_ptr<SubrectangleQueries> obj;
		vector<string> output;
		const unordered_map<string, function<void(const vector<string> &)>> methods = {
			{ "SubrectangleQueries", [&](const vector<string> &method_params) {
				vector<vector<int>> rectangle = LeetCodeIO::deserialize<vector<vector<int>>>(method_params, 0);
				obj = make_unique<SubrectangleQueries>(rectangle);
				output.push_back("null");
			} },
			{ "updateSubrectangle", [&](const vector<string> &method_params) {
				int row1 = LeetCodeIO::deserialize<int>(method_params, 0);
				int col1 = LeetCodeIO::deserialize<int>(method_params, 1);
				int row2 = LeetCodeIO::deserialize<int>(method_params, 2);
				int col2 = LeetCodeIO::deserialize<int>(method_params, 3);
				int newValue = LeetCodeIO::deserialize<int>(method_params, 4);
				obj->updateSubrectangle(row1, col1, row2, col2, newValue);
				output.push_back("null");
			} },
			{ "getValue", [&](const vector<string> &method_params) {
				int row = LeetCodeIO::deserialize<int>(method_params, 0);
				int col = LeetCodeIO::deserialize<int>(method_params, 1);
				output.push_back(LeetCodeIO::serialize(obj->getValue(row, col)));
			} },
		};
		if (method_names.size() != params.size()) {
			throw LeetCodeIO::Error("method and parameter counts differ");
		}
		for (size_t i = 0; i < method_names.size(); ++i) {
			auto method_params = LeetCodeIO::split_array(params[i]);
			methods.at(method_names[i])(method_params);
		}
		cout << "\noutput: " << LeetCodeIO::join_array(output) << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
