// Created by oportunitas at 2026/09/22 10:42
// leetgo: 1.4.18
// https://leetcode.com/problems/sleep/

// @lc code=begin

async function sleep(millis: number): Promise<void> {
    // we return a promise for a timeout for 'millis' ms
    return new Promise(resolve => setTimeout(resolve, millis));
}

/** 
 * let t = Date.now()
 * sleep(100).then(() => console.log(Date.now() - t)) // 100
 */

// @lc code=end
