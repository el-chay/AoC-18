/*
 * boxid-find
 * program for The Advent of Code 2018
 * Will check for "string proximity" as described for Day 2, part 2.
 * Check sol-2 for more info.
 */
#include <stdio.h>
#include <string.h>
#ifndef SEP
#define SEP " "
#endif

int main(void)
{
    char a[27] = {0}, b[27] = {0}, result[27] = {0}, *p, *q, *r = result;
    while (scanf("%26s" SEP "%26s\n", a, b) == 2) {
        for (p = a, q = b; *p == *q; p++, q++) {
            *r = *p;
            r++;
        }
        for (p += 1, q += 1; *p == *q; p++, q++) {
            *r = *p;
            r++;
        }
        if(strlen(result) == 25){
            puts(result);
            return 0;
        }
        memset(result, 0, sizeof result);
        r = result;
    }
    return 1;
}
