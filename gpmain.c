/**********************************************
		World Of Picross

	 a part of the neuneuil project
	 code : rov    gfx : loveMakerz

      * v 1.0.2 *  http://procvor.free.fr
**********************************************/


#include <include.h>
#include <variables.h>
#include <picross.h>


void GpMain(void *arg)
{	
	// init pour les fct d'io
	GpFatInit() ;
	
	// declaration des surfaces d'affichages
	GpLcdSurfaceGet(&gpDraw[0],0);	
	GpLcdSurfaceGet(&gpDraw[1],1);	
		
	// efface l'ecran
	GpRectFill(NULL, &gpDraw[0], 0, 0, gpDraw[0].buf_w, gpDraw[0].buf_h, 0xff);
	
	// on charge l'img de l'addic
	addic = get_gpg("gp:\\gpmm\\picross\\gfx\\addic.gpg") ;
	// on l'affiche
	GpTransBlt(NULL,&gpDraw[0],4,62,315,172,addic,0,0,311,115,0);
	
	// chargement des sons
	zik = get_gpg("gp:\\gpmm\\picross\\snd\\zik.sef") ;
	skap = get_gpg("gp:\\gpmm\\picross\\snd\\win.sef") ;
	rire = get_gpg("gp:\\gpmm\\picross\\snd\\lose.sef") ;
	fouet = get_gpg("gp:\\gpmm\\picross\\snd\\fouet.sef") ;
		
	img[1] = get_gpg("gp:\\gpmm\\picross\\gfx\\cadre.gpg") ;
	GPSTRCPY(theme_name,"standard");
	
	//initialiser() ;		
	charger_options() ;
	initialiser() ;	
	
	charger_menu() ;
	charger_theme() ;

	// efface l'ecran
	GpRectFill(NULL, &gpDraw[0], 0, 0, gpDraw[0].buf_w, gpDraw[0].buf_h, 0xff);	

	// chargement du titre
	img[0] = get_gpg("gp:\\gpmm\\picross\\gfx\\titre.gpg") ;

	img_start = get_gpg("gp:\\gpmm\\picross\\gfx\\start.gpg") ;
	
	perdu = get_gpg("gp:\\gpmm\\picross\\gfx\\gameover.gpg") ;
	
	load_curs1 = get_gpg("gp:\\gpmm\\picross\\gfx\\curs.gpg") ;
	
	load[0] = get_gpg("gp:\\gpmm\\picross\\gfx\\load\\5.gpg") ;
	load[1] = get_gpg("gp:\\gpmm\\picross\\gfx\\load\\5v.gpg") ;
	load[2] = get_gpg("gp:\\gpmm\\picross\\gfx\\load\\10.gpg") ;
	load[3] = get_gpg("gp:\\gpmm\\picross\\gfx\\load\\10v.gpg") ;
	load[4] = get_gpg("gp:\\gpmm\\picross\\gfx\\load\\15.gpg") ;
	load[5] = get_gpg("gp:\\gpmm\\picross\\gfx\\load\\15v.gpg") ;
	
	
	niv.img_haut_gauche_x = 58 ;
	niv.img_haut_gauche_y = 58 ;
	
	lancer_intro() ;

	fic.load=0 ;
	
	// lancement du jeux
	do{
		lancer_menu() ;
	} while(1) ;
}