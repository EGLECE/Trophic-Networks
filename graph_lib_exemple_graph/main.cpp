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

//création buffer

    page=create_bitmap(1000,750);
    clear_bitmap(page);



    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");



    /// Un exemple de graphe
    std::string nom_FIC;
    nom_FIC = "graphe_7S.txt";
    Graph g;
    //g.graphe2();





    /// Vous gardez la main sur la "boucle de jeu"
    /// ( contrairement à des frameworks plus avancés )
    while ( !key[KEY_ESC] )
    {



         while (choixmenu==0)
    {

        chargermenu(menuf,menuc,page,&choixmenu,nom_FIC);
        if (choixmenu==1)
        {
            g.graph(nom_FIC);
        }
        if (choixmenu==2)
        {
            nom_FIC="graphe_13S.txt";
            g.graph(nom_FIC);
        }



// AFFICHAGE DU BUFFER MIS A JOUR A L'ECRAN
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

    ///retour menu
        g.retour(&choixmenu);



//    show_mouse(screen);




        /// sauvegarde
        g.save(nom_FIC);



        /// Il faut appeler les méthodes d'update des objets qui comportent des widgets

        g.update();

        /// Mise à jour générale (clavier/souris/buffer etc...)
        grman::mettre_a_jour();

        rest(20);
    }

    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();


