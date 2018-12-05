#!/usr/bin/perl -n
# tosqlite
# Parse AoC 18, problem 3 data into sqlite friendly format.
BEGIN { $\ = "\n"; $, = "|"; }
($elf, $x, $y, $maxi, $maxj) = /(#\d+)\s@\s(\d+),(\d+):\s(\d+)x(\d+)/;
print @$_ foreach (map { $i = $_; map { [ $elf, $x+$i, $y+$_ ] } (0..$maxj-1) } (0..$maxi-1));
