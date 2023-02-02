/*
** EPITECH PROJECT, 2022
** my_radar
** File description:
** my_radar
*/

#include "my.h"
#include "myr.h"

void create_texture(Radar *radar)
{
    radar->image = sfTexture_createFromFile("src/map.jpg", NULL);
    radar->tower = sfTexture_createFromFile("src/tower.png", NULL);
    radar->plane = sfTexture_createFromFile("src/plane.png", NULL);
    radar->sprite = sfSprite_create();
    radar->sprite2 = sfSprite_create();
    radar->sprite3 = sfSprite_create();
    radar->rad = sfCircleShape_create();
    radar->square = sfRectangleShape_create();
}

void set_texture(Radar *radar)
{
    sfSprite_setTexture(radar->sprite, radar->image, sfFalse);
    sfSprite_setTexture(radar->sprite2, radar->tower, sfFalse);
    sfSprite_setTexture(radar->sprite3, radar->plane, sfFalse);
}

void close_window(sfEvent event, sfRenderWindow *Window)
{
    while (sfRenderWindow_pollEvent(Window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(Window);
    }
}

int print_map(Radar *radar)
{
    sfRenderWindow *Window;
    sfVideoMode video_mode = {1920, 1080, 32};
    sfEvent event;
    create_texture(radar);

    for (int i = 0; i != 1 ; i++) {
        Window = sfRenderWindow_create(video_mode,
        "myradar", sfClose | sfResize, NULL);
        set_texture(radar);
        sfRenderWindow_setFramerateLimit(Window, 60);
    }
    while (sfRenderWindow_isOpen(Window)){
        sfRenderWindow_drawSprite(Window, radar->sprite, NULL);
        print_tower(radar, Window, radar->sprite2, radar->rad);
        print_plane(radar, Window, radar->sprite3, radar->square);
        sfRenderWindow_display(Window);
        close_window(event, Window);
    }
}

int main(int arc, char **arv)
{
    if (arc > 2)
        return 84;
    if (arc == 2 && my_strcmp(arv[1], "-h") == 0)
        flag_h();
    else
        start_radar(arv[1]);
    return 0;
}
