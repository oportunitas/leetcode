-- Created by oportunitas at 2026/10/02 06:35
-- leetgo: 1.4.18
-- https://leetcode.com/problems/product-sales-analysis-i/

-- @lc code=begin

# Write your MySQL query statement below
select res.product_name, res.year, res.price from (
    select * from sales
    left join product using (product_id)
) as res;

-- @lc code=end
