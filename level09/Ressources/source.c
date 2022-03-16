/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matheme <matheme@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:40:20 by matheme           #+#    #+#             */
/*   Updated: 2022/03/16 03:46:04 by matheme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

typedef struct  g_var 
{
    char message[140];
    char username[40];
    long strncpy_n;
}               t_var;

void secret_backdoor(void)
{
    char *string;
    
    fgets(string, 128, stdin);
    system(string);
}

void set_username(t_var *var)
{
    int i;
    char s[128];

    bzero(s, 128);
    puts(">: Enter your username");
    printf(">>: ");
    fgets(s, 128, stdin);
    i = -1;
    while (++i < 41 && s[i])
        var->username[i] = s[i];
    printf(">:Welcome, %s", var->username);
}

void set_message(t_var *var)
{
    char src[1024];

    bzero(src, sizeof(src));
    puts(">: Msg @Unix-Dude");
    printf(">>: ");
    fgets(src, 1024, stdin);
    strncpy(var->message, src, var->strncpy_n);
}

void handle_msg()
{
    t_var var;
    bzero(&var , sizeof(var));
    var.strncpy_n = 140;
    set_username(&var);
    set_message(&var);
    puts(">: Msg sent!");
}

int main(void)
{
    puts("--------------------------------------------");
    puts("|    Welcome to l33t-m$n ~    v1337        |");
    puts("--------------------------------------------");
    handle_msg();
    return (0);
}