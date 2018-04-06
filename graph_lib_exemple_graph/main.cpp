#include "grman/grman.h"
#include <iostream>
#include <allegro.h>
#include "prototype.h"
#include <stdio.h>


#include "graph.h"

int main()
{
    ///INITIALISATION ALLEGRO

     /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();
    // declaration bitmaps

BITMAP *page, *menuf, *menuc;


  /*  set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_FULLSCREEN,1024,768,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    */
//variable menu
int choixmenu=0;

//cr�ation buffer

page=create_bitmap(800,600);
    clear_bitmap(page);



    /// Le nom du r�pertoire o� se trouvent les images � charger
    grman::set_pictures_path("pics");

    /// Un exemple de graphe
    Graph g;
    //g.graphe2();


    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement � des frameworks plus avanc�s )
    while ( !key[KEY_ESC] )
    {


//    show_mouse(screen);

        while (choixmenu!=1)
        {

            chargermenu(menuf,menuc,page,&choixmenu);


        }

        // AFFICHAGE DU BUFFER MIS A JOUR A L'ECRAN
            blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
            /// Il faut appeler les m�thodes d'update des objets qui comportent des widgets
        g.update();

        /// Mise � jour g�n�rale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();

        rest(20);
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


