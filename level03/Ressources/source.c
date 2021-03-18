#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void decrypt(unsigned char nb)
{
	int		len;
	char	*str;
	char	zstr[] = "C}|u`sfg~sf{}|a";

    len = strlen(zstr);
	while(--len) {
		zstr[len] = nb ^ zstr[len];
	}

    if (!strncmp("Congratulations", zstr, 17)) {
        system("/bin/sh");
    } else {
        printf("Invalid Password\n");
    }
    return;
}

void test(int nb, int offset)
{
    offset = offset - nb;
	if ((offset >= 1 && offset <= 9) || (offset >= 16 && offset <= 21))
	{
		decrypt(offset);
		return ;
	}
	decrypt((unsigned char)rand());
}


int main()
{
	int nb;
	printf("***********************************\n");
	printf("*       level03                  **\n");
	printf("***********************************\n");
	printf("Password: ");
	scanf("%d", &nb);

	test(nb, 322424845);
	return (0);
}
