/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_radar
*/

#include "my.h"
#include "myr.h"

int print_tower(Radar *radar, sfRenderWindow *Window,
                sfSprite *sprite2, sfCircleShape *rad)
{
    for (int i = 0; i != radar->count_t ;i++) {
        sfVector2f pos = {radar->xt[i], radar->yt[i]};
        sfVector2f pos2 = {radar->xt[i] + (radar->rad_t[i] / 2), radar->yt[i]};
        sfSprite_setPosition(sprite2, pos2);
        sfCircleShape_setPosition(rad, pos);
        sfCircleShape_setRadius(rad, radar->rad_t[i]);
        sfCircleShape_setFillColor(rad, sfTransparent);
        sfCircleShape_setOutlineColor(rad, sfBlack);
        sfCircleShape_setOutlineThickness(rad, 5.0);
        sfRenderWindow_drawSprite(Window, sprite2, NULL);
        sfRenderWindow_drawCircleShape(Window, rad, NULL);
    }
}

void move_plane(Radar *radar, int i)
{
    if (radar->xp[i] != radar->mxp[i]) {
        if (radar->xp[i] < radar->mxp[i])
            radar->xp[i] = radar->xp[i] + 1;
        if (radar->xp[i] > radar->mxp[i])
            radar->xp[i] = radar->xp[i] - 1;
    }
    if (radar->yp[i] != radar->myp[i]) {
        if (radar->yp[i] < radar->myp[i])
            radar->yp[i] = radar->yp[i] + 1;
        if (radar->yp[i] > radar->myp[i])
            radar->yp[i] = radar->yp[i] - 1;
    }
}

int print_plane(Radar *radar, sfRenderWindow *Window,
        sfSprite *sprite3, sfRectangleShape *square)
{
    for (int i = 0; i != radar->count_p ;i++) {
        move_plane(radar, i);
        sfVector2f pos = {radar->xp[i], radar->yp[i]};
        sfVector2f size = {20, 20};
        sfRectangleShape_setSize(square, size);
        sfRectangleShape_setPosition(square, pos);
        sfRectangleShape_setFillColor(square, sfTransparent);
        sfRenderWindow_drawRectangleShape(Window, square, NULL);
        sfSprite_setPosition(sprite3, pos);
        sfRectangleShape_setOutlineThickness(square, 1.0);
        sfRenderWindow_drawSprite(Window, sprite3, NULL);
    }
}
