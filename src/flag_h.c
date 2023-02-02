/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_radar
*/

#include "my.h"
#include "myr.h"

void flag_h(void)
{
    my_printf("Air traffic simulation panel\n");
    my_printf("\nUSAGE\n");
    my_printf(" ./my_radar [OPTIONS] path_to_script\n");
    my_printf("   path_to_script    The path to the script file.\n");
    my_printf("\nOPTIONS\n");
    my_printf(" -h          print the usage and quit.\n");
    my_printf("\nUSER INTERACTIONS\n");
    my_printf(" ‘L’    key enable/disable hitboxes and areas.\n");
    my_printf(" ‘S’ key enable/disable sprites.\n");
}
