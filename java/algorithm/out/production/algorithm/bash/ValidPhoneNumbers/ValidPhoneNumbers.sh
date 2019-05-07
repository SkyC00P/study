#!/bin/sh
# Runtime: 8 ms, faster than 100.00% of Bash online submissions for Valid Phone Numbers.
# Memory Usage: 3.1 MB, less than 59.79% of Bash online submissions for Valid Phone Numbers
grep -w -E "^[0-9]{3}-[0-9]{3}-[0-9]{4}|^\([0-9]{3}\) [0-9]{3}-[0-9]{4}" file.txt