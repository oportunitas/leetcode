// Created by oportunitas at 2026/11/09 07:59
// leetgo: 1.4.18
// https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (63ms/99th% | 96.5MB/98th%)
        instead of using a set for the available server, we can use a minheap also instead.

        this reduces runtime quite significantly, from ~190 ms to ~60 ms
    */
    template <class t> using minheap = priority_queue<t, vector<t>, greater<>>;

    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        minheap<pair<int,int>> ongoing; 
        
        vector<int> tmp; for (int i {0}; i < k; ++i) tmp.push_back(i);
        minheap<int> available (greater<>{}, move(tmp));

        vector<int> task_count (k, 0);

        int time {0};
        for (int ri = 0; ri < arrival.size(); ++ri) {
            time = max(time, arrival[ri]);
            while (!ongoing.empty() && ongoing.top().first <= time) {
                available.push(ri + (ongoing.top().second + k - (ri % k)) % k);
                ongoing.pop();
            }

            if (available.empty()) continue;

            ongoing.push({time + load[ri], available.top() % k});
            task_count[available.top() % k] += 1;
            available.pop();
        }

        int max_task_count {ranges::max(task_count)};
        vector<int> ans;
        for (const auto& [i, c] : task_count | views::enumerate) {
            if (c == max_task_count) {
                ans.push_back(i);
            }
        }

        return ans;
    }

    // /* idea #0 (188ms/24th% | 125.1MB/41th%)
    //     use a minheap to store the ongoing tasks by end second, and a set to store the available
    //     servers, then iterate.
    // */
    // vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
    //     // what servers are vacant, we use set to preserve ordering
    //     set<int> available; for (int i {0}; i < k; ++i) available.insert(i);

    //     using minheap = priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>;
    //     minheap ongoing; // {last second, server index}

    //     // {count, index}
    //     vector<pair<int,int>> server; for (int i {0}; i < k; ++i) server.push_back({0, i});

    //     int time {0};
    //     // println("--");
    //     for (int ri = 0; ri < arrival.size(); ++ri) {
    //         time = max(time, arrival[ri]);
    //         // println("time: {}", time);

    //         // println("ongoing: {}", ongoing);
    //         // println("vacating servers...");
    //         while (!ongoing.empty() && ongoing.top().first <= time) {
    //             available.insert(ongoing.top().second);
    //             ongoing.pop();
    //         }
    //         // println("ongoing: {}", ongoing);

    //         // println("trying to insert task of load {} to server {}", load[ri], ri % k);

    //         if (available.empty()) continue;

    //         int si = ri % k;
    //         auto it = available.lower_bound(si);
    //         if (it == available.end()) it = available.lower_bound(0);

    //         server[*it].first += 1;
    //         ongoing.push({time + load[ri], *it});
    //         available.erase(*it);
            
    //         // println("--");
    //     }

    //     ranges::sort(server, greater{});
    //     // println("{}", server);

    //     vector<int> ans; int maxc {server[0].first};
    //     for (const auto& [c, i] : server) {
    //         if (c < maxc) break;
    //         ans.push_back(i);
    //     }

    //     return ans;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		int k = LeetCodeIO::deserialize<int>(cin);
		vector<int> arrival = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> load = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.busiestServers(k, arrival, load);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
