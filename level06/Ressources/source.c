#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int auth(char *login, unsigned int serial)
{
	int				len;

	len = strcspn(login, "\n");
	login[len] = '\0';
	len = strnlen(login, 32);
	if (len < 6)
		return (1);
	return (!(serial == hash(login)));
}

int main(void)
{
    unsigned int	serial;
    char			login[32];

	puts("***********************************");
	puts("*             level06             *");
	puts("***********************************");
    printf("-> Enter Login: ");
    fgets(login, 32, stdin);
    puts("***********************************");
	puts("***** NEW ACCOUNT DETECTED ********");
	puts("***********************************");
   
    printf("-> Enter Serial: ");
    scanf("%u", &serial);
    if (!auth(login, serial)) {
        puts("Authenticated!");
        system("/bin/sh");
    }
    return (1);
}