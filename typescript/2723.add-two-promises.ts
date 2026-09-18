// Created by oportunitas at 2026/09/19 06:12
// leetgo: 1.4.18
// https://leetcode.com/problems/add-two-promises/

// @lc code=begin

type P = Promise<number>

/* idea #0
    til: await Promise.all():
        this function can be used to await the promise of an array of values, and
        assign them accordingly
*/
async function addTwoPromises(promise1: P, promise2: P): P {
    const [num1, num2] = await Promise.all([promise1, promise2]);
    return num1 + num2;
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */

// @lc code=end
