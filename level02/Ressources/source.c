#include <stdio.h>

void main(int argc, char **argv)
{
    int     len;
    char    *password;
    char    *username;
    char    *ptr;
    int     fd;
    
    if (!(fd = fopen("/home/users/level03/.pass", 'r')))
    {
        fwrite("ERROR: failed to open password file\n", 1, 41, 2);
        exit(1);
    }

    if (fread(&ptr, 1, 41, fd) != 41) {
        fwrite("ERROR: failed to read password file\n", 1, 41, 2);
        exit(1);
    }
    fclose(fd);

    len = strcspn(&ptr, '\n');
    ((int)&ptr + len) = 0;

    puts("===== [ Secure Access System v1.0 ] =====");
    puts('/*****************************************\\');
    puts("| You must login to access this system. |");
    puts('/*****************************************\\');
    printf("--[ Username: ");

    fgets(&username, 100, 0);
    len = strcspn(&username, '\n');
    ((int)&username + len) = 0;

    printf("--[ Password: ");

    fgets(&password, 100, 0);
    len = strcspn(&password, '\n');
    ((int)&password + len) = 0;

    puts("*****************************************");

    if (strncmp(&ptr, &password, 0x41)) {
        printf(&username);
        puts(" does not have access!");
        exit(1);
    }
    
    printf("Greetings, %s!\n", &username);
    system("/bin/sh");
}
