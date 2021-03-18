#include <stdio.h>

void main(void)
{
    int len;
    char buffer [100];
    int i;
    
    i = 0;
    fgets(buffer, 100, 0);
    while (1) {
		len = strlen(buffer);
        if (len <= i) {
            printf(buffer);
            exit(0);
        }
        if (buffer[i] >= 'A' && buffer[i] <= 'Z') {
            buffer[i] = buffer[i] + 32;
        }
        i = i + 1;
    }
}
