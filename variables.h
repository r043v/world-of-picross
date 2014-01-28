#define taille_max_x 10
#define taille_max_y 10
#define	LCD_WIDTH	320	//width of LCD
#define	LCD_HEIGHT	240	//height of LCD
#define	BG_WIDTH	320	//width of background image
#define	BG_HEIGHT	240	//height of background image
#define MAX_Y 20
#define MAX_X 20
#define PZMAX_X 15
#define PZMAX_Y 15
#define MAX_COUNT_FILE 30

#define	GPSPRINTF	(gp_str_func.sprintf)
#define	GPSTRLEN	(gp_str_func.gpstrlen)
#define	GPSTRCPY	(gp_str_func.strcpy)
#define	GPSTRCMP	(gp_str_func.compare)
#define	GPSTRCAT	(gp_str_func.strcat)
#define	GPSTRRCHR	(gp_strrchr)

struct case_tab
{
	unsigned char couleur ;
	unsigned char etat ;
} ;

struct pz_save
{
	short nb_try ;
	short nb_win ;
	char best_time[2] ;
	char last_time[2] ;
} ;

struct fichier
{
	struct pz_save save[256] ;
	char nom[21] ; // nom des niveaux
	char auteur[16] ; // auteur
	unsigned short nb_levels ; // le nombre de niveaux contenus dans le fichier
	unsigned short tab_taille_x_y[256][2] ; // les tableaux contenant les taille x et y des niveaux
	char *level ; // les niveaux
	short load ;
} ;

struct niveau
{
	unsigned short id ;	
	unsigned char taille_x ;	
	unsigned char taille_y ;
	unsigned char nb_max_col ;
	unsigned char nb_max_ligne ;
	short scrolling ;
	short scroll_info_col ;
	unsigned char nb_ligne[PZMAX_Y] ;
	unsigned char nb_col[PZMAX_X] ;
	short result_ligne[15][8] ;
	short result_col[15][8] ;
	short aff_y ;
	short pos_y ;
  	struct case_tab mat[PZMAX_Y][PZMAX_X]	;
	short dec_x,dec_y ; // decalage pour centrer
	
	short img_haut_gauche_x ;
	short img_haut_gauche_y ;
} ;


//ERR_CODE err ;
//F_HANDLE fichier ;

char*	filename;

GPDRAWSURFACE	gpDraw[2] ;
GPDIRENTRY	liste_fichier[MAX_COUNT_FILE];
char		g_path_curr[256];
ulong		g_cnt_file = 0;			// nb de fichiers

int nflip=0;
int key_pressed=0 ;
short choix ;
struct niveau niv ;
struct fichier fic ;
short pos_x = 0,pos_y = 0 ;
short nb_case_restantes = 0 ;
short nb_case_totales = 0 ;
int temps = 1800 ;
int temps_jeux = 0 ;
short temps_en_moins=1 ;

short taille_case = 10 ;
short taille_info = 10 ;

short num_puzzle = -1 ;


unsigned char *img[30] ; // les gfx du jeux
unsigned char *img2[10] ; // les gfx du jeux
unsigned char *load_vert, *load_jaune, *load_vide, *load_curs1, *load_curs2 ;
unsigned char *load[6] ;

unsigned char *zik, *addic, *rire, *skap, *fond_ecran, *fouet, *img_start, *perdu ;

int time=0 ;


// les options

short vitesse = 1 ;
short difficulte = 1 ;
char theme_name[20] ;
short fond_select = 1 ;
char langue = 'f' ;