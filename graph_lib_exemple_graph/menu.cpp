#include <allegro.h>
#include "prototype.h"


void chargermenu (BITMAP * menuc, BITMAP * menuf, BITMAP * page,int *choixmenu)
{
    int couleurcase = 0;

    menuc=load_bitmap("menuc.bmp",NULL);
    if (!menuc)
    {
       /* allegro_message("Menuc.bmp pas trouve");
       */
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    menuf=load_bitmap("Menuf.bmp",NULL);
    if (!menuf)
    {
       // allegro_message("menuf.bmp pas trouve");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    blit(menuf,page,0,0,0,0,SCREEN_W,SCREEN_H);
    blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

    couleurcase = getpixel( menuc, mouse_x,mouse_y);

    //si on clique sur la case bleue
    if (mouse_b&1 && couleurcase == makecol ( 0,0,255))
    {
        *choixmenu=1;
        clear_bitmap(page);


    }
//si on clique sur la case rouge
    if (mouse_b&1 && couleurcase == makecol (255,0,0))
    {
        *choixmenu=2;

    }
//si on clique sur la case verte
    if (mouse_b&1 && couleurcase == makecol (0,255,0))
    {
        *choixmenu=3;
    }

//si on clique sur la case cyan

    if (mouse_b&1 && couleurcase == makecol (0,255,255))
    {
        allegro_exit();
        exit(EXIT_FAILURE);
    }

}

