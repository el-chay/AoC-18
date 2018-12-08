#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int eatit(char *b, size_t l)
{
    for (int i = 0; i < (l - 1); i ++)
        if (b[i+1] != 0 && abs(b[i] - b[i+1]) == 32) {
            for(int j = i + 2; j < l; j++)
                b[j-2] = b[j];
            return 1;
        }
    return 0;
}

int main(int argc, char *argv[])
{
    struct stat st;
    if (stat(argv[1], &st)) return 1;
    char *buff = malloc(st.st_size+1);
    if(!buff) return 2;
    memset(buff, 0, st.st_size+1);
    FILE *f = fopen(argv[1], "r");
    fread(buff, 1, st.st_size, f);
    fclose(f);
    buff[st.st_size-1] = 0;
    int count = 0;
    while(eatit(buff, st.st_size - 2*count))
        count++;
    fprintf(stderr, "Iterations: %d\n", count);
    puts(buff);
}
