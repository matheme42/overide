#include <string.h>
#include <fcntl.h>

# define STDIN 0
char g_username[256];

int verify_user_pass(char *pass)
{
    return (strncmp(pass, "admin", 5));
}

int verify_user_name()
{
    return (strncmp(g_username, "dat_wil", 7));
}

void main(void)
{
    char password[16];

    puts("********* ADMIN LOGIN PROMPT *********");
    puts("Enter Username: ");
    fgets(g_username, 256, STDIN);
    if (verify_user_name(pass))
    {
        puts("nope, incorrect username...\n");
        return (1);
    }

    puts("Enter Password: ");
    fgets(password, 100, STDIN);
    verify_user_pass(password);
    puts("nope, incorrect password...\n");
    return (1);
}
