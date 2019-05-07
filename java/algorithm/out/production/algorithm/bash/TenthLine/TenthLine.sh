#!/bin/sh
# How to use it?
# sh TenthLine.sh file.txt
# Runtime: 4 ms, faster than 100.00% of Bash online submissions for Tenth Line.
# Memory Usage: 3.6 MB, less than 91.80% of Bash online submissions for Tenth Line.

path=${1}
line=`awk 'END{print NR}' ${path}`
if [ "${line}" -lt 10 ]; then
    echo "";
else
    head -n 10 file.txt | tail -n 1;
fi