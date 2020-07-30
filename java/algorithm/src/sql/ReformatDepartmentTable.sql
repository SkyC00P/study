/* Runtime: 1224 ms, faster than 7.70% of MySQL online submissions for Reformat Department Table.
Memory Usage: 0B, less than 100.00% of MySQL online submissions for Reformat Department Table. */

SELECT
        id,
        MAX(CASE month WHEN 'Jan' THEN revenue ELSE null END) AS 'Jan_Revenue',
        MAX(CASE month WHEN 'Feb' THEN revenue ELSE null END) AS 'Feb_Revenue',
        MAX(CASE month WHEN 'Mar' THEN revenue ELSE null END) AS 'Mar_Revenue',
        MAX(CASE month WHEN 'Apr' THEN revenue ELSE null END) AS 'Apr_Revenue',
        MAX(CASE month WHEN 'May' THEN revenue ELSE null END) AS 'May_Revenue',
        MAX(CASE month WHEN 'Jun' THEN revenue ELSE null END) AS 'Jun_Revenue',
        MAX(CASE month WHEN 'Jul' THEN revenue ELSE null END) AS 'Jul_Revenue',
        MAX(CASE month WHEN 'Aug' THEN revenue ELSE null END) AS 'Aug_Revenue',
        MAX(CASE month WHEN 'Sep' THEN revenue ELSE null END) AS 'Sep_Revenue',
        MAX(CASE month WHEN 'Oct' THEN revenue ELSE null END) AS 'Oct_Revenue',
        MAX(CASE month WHEN 'Nov' THEN revenue ELSE null END) AS 'Nov_Revenue',
        MAX(CASE month WHEN 'Dec' THEN revenue ELSE null END) AS 'Dec_Revenue'
FROM Department
GROUP BY id