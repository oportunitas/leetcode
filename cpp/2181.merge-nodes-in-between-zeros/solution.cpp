// Created by oportunitas at 2026/09/05 13:39
// leetgo: 1.4.18
// https://leetcode.com/problems/merge-nodes-in-between-zeros/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
	/* idea #1 (0ms/100th% | 263.6MB/82th%)
		perhaps the delete step is time expensive? lets try without delete.

		>> yes, it seems like removing the delete step results in better runtime.
	*/
    ListNode* mergeNodes(ListNode* head) {
		auto result = head;
		// auto printnodes {[result] () {
		// 	auto _ = result;
		// 	print("[");
		// 	while (_->next != nullptr) {
		// 		print("{}, ", _->val);
		// 		_ = _->next;
		// 	} print("{}]\n", _->val);
		// }};

		head = head->next;
        while (head->next != nullptr) {
			// printnodes();
			if (head->next->next == nullptr) {
				// println("enter last case");
				// delete head->next;
				head->next = nullptr;
				continue;
			}
			if (head->next->val == 0) {
				head = head->next;
				continue;
			}

			head->val += head->next->val;
			// auto to_delete = head->next;
			head->next = head->next->next;
			// delete to_delete;
		} 
		
		return result->next;
    }

	// /* idea #0 (76ms/5th% | 273MB/59th%)
	// 	we can iterate through the linked list and add. 
	// 	this is time-intensive though
	// */
    // ListNode* mergeNodes(ListNode* head) {
	// 	auto result = head;
	// 	// auto printnodes {[result] () {
	// 	// 	auto _ = result;
	// 	// 	print("[");
	// 	// 	while (_->next != nullptr) {
	// 	// 		print("{}, ", _->val);
	// 	// 		_ = _->next;
	// 	// 	} print("{}]\n", _->val);
	// 	// }};

	// 	head = head->next;
    //     while (head->next != nullptr) {
	// 		// printnodes();
	// 		if (head->next->next == nullptr) {
	// 			// println("enter last case");
	// 			delete head->next;
	// 			head->next = nullptr;
	// 			continue;
	// 		}
	// 		if (head->next->val == 0) {
	// 			head = head->next;
	// 			continue;
	// 		}

	// 		head->val += head->next->val;
	// 		auto to_delete = head->next;
	// 		head->next = to_delete->next;
	// 		delete to_delete;
	// 	} 
		
	// 	return result->next;
    // }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	try {
		ListNode* head = LeetCodeIO::deserialize<ListNode*>(cin);

		Solution obj;
		auto res = obj.mergeNodes(head);

		stringstream out_stream;
		LeetCodeIO::print(out_stream, res);
		cout << "\noutput: " << out_stream.rdbuf() << '\n';
	} catch (const LeetCodeIO::Error &error) {
		cerr << "LC_IO: " << error.what() << '\n';
		return 2;
	}
	return 0;
}
