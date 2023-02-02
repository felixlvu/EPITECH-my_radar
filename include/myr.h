/*
** EPITECH PROJECT, 2022
** my.r
** File description:
** my.r
*/

#ifndef MYR_H
    #define MYR_H

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>

typedef struct {
    int count_t;
    int count_p;
    int * rad_t;
    int * xp;
    int * yp;
    int * mxp;
    int * myp;
    int * xt;
    int * yt;
    sfSprite *sprite;
    sfSprite *sprite2;
    sfSprite *sprite3;
    sfTexture *image;
    sfTexture *tower;
    sfTexture *plane;
    sfCircleShape *rad;
    sfRectangleShape *square;
}Radar;


    int main(int arc, char **arv);
    int count_elements(char const *filepath, Radar *radar);
    int find_elements(char const *filepath, int count_t,
                    Radar *radar, int count_p);
    void flag_h(void);
    int start_radar(char const *filepath);
    int print_map(Radar *radar);
    int print_plane(Radar *radar, sfRenderWindow *Window,
    sfSprite *sprite3, sfRectangleShape *square);
    int print_tower(Radar *radar, sfRenderWindow *Window,
    sfSprite *sprite2, sfCircleShape *rad);
#endif
