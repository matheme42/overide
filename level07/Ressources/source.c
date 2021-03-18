#include <stdio.h>
#include <string.h>

void clear_stdin(void)
{
    char c;
    
    do {
        c = getchar();
        if (c == '\n') {
            return;
        }
    } while (c != -1);
}

int32_t get_unum(void)
{
    int32_t val;
    
    val = 0;
    fflush(stdout);
    scanf("%u", &val);
    clear_stdin();
    return val;
}


int store_number(int32_t buffer)
{
	int32_t num;
    int32_t id;

    printf(" Number: ");
    num = get_unum();
    printf(" Index: ");
    id = get_unum();
    if ((id % 3 == 0) || (num >> 24 == 183)) {
        puts(" *** ERROR! ***");
        puts("   This index is reserved for wil!");
        puts(" *** ERROR! ***");
        return (1);
    } else {
        *(int32_t *)(id * 4 + buffer) = num;
       	return (0);
    }
}

int read_number(int32_t buffer)
{
    int32_t id;
    int32_t var_ch;
    
    printf(" Index: ");
    id = get_unum();
    printf(" Number at data[%u] is %u\n", id, *(unsigned int *)(id * 4 + buffer));
    return 0;
}


int main(int ac, char **av, char **env)
{
    char fbuffer[100];
    int		ret;
	int		len;
    char	buffer[20];

	bzero(buffer, sizeof(buffer));
	bzero(av, sizeof(av));
	bzero(env, sizeof(env));

    puts("\
----------------------------------------------------\n\
   Welcome to wil\'s crappy number storage service!   \n\
----------------------------------------------------\n\
  Commands:                                          \n\
   store - store a number into the data storage    \n\
   read  - read a number from the data storage     \n\
   quit  - exit the program                        \n\
----------------------------------------------------\n\
  wil has reserved some storage :>                 \n\
----------------------------------------------------\n"
	);

    while(1) {
		ret = 1;
        printf("Input command: ");
        fgets(buffer, 20, stdin);
		len = strcspn(buffer, "\n");
		buffer[len] = '\0';

		if (strnstr(buffer, "store", 5)) {
			ret = store_number(*(int32_t*)fbuffer);
		} else if (strnstr(buffer, "read", 4)) {
			ret = read_number(*(int32_t*)fbuffer);
		} else if (strnstr(buffer, "quit", 4))
			return (0);
	
        if (ret == 0) {
            printf(" Completed %s command successfully\n", buffer);
        } else {
            printf(" Failed to do %s command\n", buffer);
        }
        bzero(buffer, sizeof(buffer));
    }
}
