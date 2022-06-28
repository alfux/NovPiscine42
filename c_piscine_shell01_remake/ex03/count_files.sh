A=$(find . -type f 2>/dev/null| wc -l) && B=$(find . -type d 2>/dev/null | wc -l) && echo "$A+$B" | bc -l
