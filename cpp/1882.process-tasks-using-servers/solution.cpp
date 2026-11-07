// Created by oportunitas at 2026/11/07 07:06
// leetgo: 1.4.18
// https://leetcode.com/problems/process-tasks-using-servers/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    /* idea #1 (144ms/81th% | 139.4MB/94th%)
        lets optimize

        1. convert the servers-vacant data to a single minheap `available_servers`.
           this way, the heap is ordered by the ordering the problem requests, while simultaneously
           allowing us to access the best server immediately via top() and check how many servers
           are vacant by size()
        2. iterate over j and periodically jump t instead. this way the general code direction is
           cleaner. this also includes changin the comparison from < to <= (offset by 1)
    */
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using i64 = std::int64_t; using pii = std::pair<i64, i64>; 
        using minheap = priority_queue<pii, vector<pii>, greater<>>;

        vector<pii> tmp (servers.size());
        for (i64 i {0}; i < servers.size(); ++i) {
            tmp[i] = {servers[i], i};
        } minheap available_servers (greater<>{}, move(tmp));

        // {last second, true server index}
        minheap ongoing_tasks;

        vector<int> ans (tasks.size(), -1); 
        i64 t {0};

        for (i64 j {0}; j < tasks.size(); ++j) {
            t = max(t, j);
            if (available_servers.empty()) t = max(t, ongoing_tasks.top().first);

            while (!ongoing_tasks.empty() && ongoing_tasks.top().first <= t) {
                i64 i = ongoing_tasks.top().second;
                ongoing_tasks.pop();
                available_servers.push({servers[i], i});
            }

            i64 last_second = t + tasks[j];
            i64 i = available_servers.top().second;

            ongoing_tasks.push({last_second, i});
            available_servers.pop();
            ans[j] = i;
        }
        return ans;
    }

    // /* idea #0 (398ms/18th% | 204.9MB/17th%)
    //     first we change the servers to a 2d array sorted by the problem's ordering (weight first,
    //     then index). this eliminates the need to sort in each iteration of task insertion.

    //     we store a priority queue of the ongoing tasks to keep track on when to free them.
    //     iterating over the tasks, we vacate any servers which have completed the tasks, then
    //     inserted any backlogged tasks, and afterwards insert the current task.
    // */
    // vector<int> assignTasks(vector<int>& _servers, vector<int>& tasks) {
    //     // convert to 2d array of enumerated servers, then sort by weights first then if tie by idx
    //     auto servers {_servers | views::enumerate | views::transform([] (const auto& e) {
    //         const auto& [i, v] = e;
    //         return array<int, 2> {(int)i, v};
    //     }) | ranges::to<vector>()};
    //     ranges::sort(servers, [] (const auto& row1, const auto& row2) {
    //         // this is a fancy way to state:
    //         //      if (row1[1] != row2[1]) return row1[1] < row2[1];
    //         //      return row1[0] < row2[0]
    //         // since comparing tuple made with std::tie() will compare the first pair first,
    //         // then the second pair, then so on.
    //         return tie(row1[1], row1[0]) < tie(row2[1], row2[0]);
    //     });
    //     // println("{}", servers);

    //     // {last second, `servers` index}
    //     using pii = std::pair<int, int>;
    //     priority_queue<pii, vector<pii>, greater<pii>> ongoing_tasks;

    //     // {j, time}
    //     deque<pii> pending_tasks;

    //     set<int> vacant; for (size_t i {0}; i < servers.size(); ++i) { vacant.insert(i); }
    //     vector<int> ans (tasks.size(), -1); 
    //     size_t j {0};
    //     size_t t {0};

    //     while (j < tasks.size()) {
    //         // println("oloop: j: {}, t: {}", j, t);

    //         // clear out all completed tasks, if there's any currently ongoing
    //         while (!ongoing_tasks.empty() && ongoing_tasks.top().first < t) {
    //             // println("  vacating server {}", servers[ongoing_tasks.top().second][0]);

    //             vacant.insert(ongoing_tasks.top().second);
    //             ongoing_tasks.pop();
    //         }

    //         // // flush pending tasks until no servers are vacant
    //         // while (!vacant.empty() && pending_tasks.size() > 0) {
    //         //     auto [task_i, task_duration] = pending_tasks.front();

    //         //     int last_second = t + task_duration;
    //         //     int server_indx = *vacant.begin();

    //         //     println(
    //         //         "  inserting pending task {} to server {}", 
    //         //         task_i, servers[server_indx][0]
    //         //     );

    //         //     ongoing_tasks.push({last_second, server_indx});
    //         //     vacant.erase(server_indx);

    //         //     ans[task_i] = servers[server_indx][0];
    //         // }

    //         // // insert current task if possible, else put into pending tasks
    //         // if (!vacant.empty()) {
    //         //     int last_second = t + tasks[j] - 1;
    //         //     int server_indx = *vacant.begin();

    //         //     ongoing_tasks.push({last_second, server_indx});
    //         //     vacant.erase(server_indx);

    //         //     ans[j] = servers[server_indx][0];
    //         // } else {
    //         //     pending_tasks.push_back({j, tasks[j]});
    //         // }
            
    //         // insert new task
    //         while (j < tasks.size() && j <= t && !vacant.empty()) {
    //             int last_second = t + tasks[j] - 1;
    //             int server_indx = *vacant.begin();
    //             // println("  inserting task {} to server {}", j, servers[server_indx][0]);
    //             ongoing_tasks.push({last_second, server_indx});
    //             vacant.erase(server_indx);

    //             ans[j] = servers[server_indx][0];
    //             j += 1;
    //         }

    //         // if theres no vacant server, jump in time to the end of the nearest task
    //         if (vacant.empty()) {
    //             t = ongoing_tasks.top().first + 1;
    //         } else {
    //             t += 1;
    //         }
    //     }

    //     return ans;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		vector<int> servers = LeetCodeIO::deserialize<vector<int>>(cin);
		vector<int> tasks = LeetCodeIO::deserialize<vector<int>>(cin);

		Solution obj;
		auto res = obj.assignTasks(servers, tasks);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
