void sauver_save(char * filename, short num_pz)
{
	char save_name[20] ;
	short i=0,cpt ;
	char url[256] ;
	F_HANDLE hfile;

	
	GPSTRCPY(save_name,filename) ;
	
	while (save_name[i] != '.') { i++; }
	i++ ;
	save_name[i++] = 's' ;
	save_name[i++] = 'a' ;
	save_name[i++] = 'v' ;
	
	save_name[i] = '\0' ;
	
	GPSPRINTF(url,"gp:\\gpmm\\picross\\lvl\\%s",(char*)save_name) ;

	GpFileOpen(url, OPEN_W, &hfile) ;
	//GpFileCreate(url,ALWAYS_CREATE, &hfile);
		
		
	if(num_pz == -1)
	{
		GPSPRINTF(url,"%i",fic.nb_levels) ;
		GpFileWrite(hfile,&url,2);

		for(cpt=0;cpt<fic.nb_levels;cpt++) 	GpFileWrite(hfile,&fic.save[cpt],sizeof(struct pz_save));
	}
	else
	{
		GpFileSeek(hfile,FROM_CURRENT,sizeof(struct pz_save)*(num_pz) + 2,0);
		GpFileWrite(hfile,&fic.save[num_pz],sizeof(struct pz_save));
	}

	GpFileClose(hfile) ;
}




void charger_save(char * filename)
{
	char save_name[20] ;
	short i=0 ;
	char url[256] ;
	F_HANDLE hfile;
	short cw,ch,cx,cy ;
	char buffer[30] ;
	unsigned long m_size=0 ;

	
	GPSTRCPY(save_name,filename) ;
	
	while (save_name[i] != '.') { i++; }
	i++ ;
	save_name[i++] = 's' ;
	save_name[i++] = 'a' ;
	save_name[i++] = 'v' ;
	
	save_name[i] = '\0' ;
	
	GPSPRINTF(url,"gp:\\gpmm\\picross\\lvl\\%s",(char*)save_name) ;

	if (SM_OK != GpFileOpen(url, OPEN_R, &hfile)) // si pas de fichier de save, on le cré
	{
		short cpt=0 ;
		
		GpFileCreate(url,ALWAYS_CREATE, &hfile);
		
		for(cpt=0;cpt<fic.nb_levels;cpt++)
		{
			fic.save[cpt].nb_try = 0 ;
			fic.save[cpt].nb_win = 0 ;
			fic.save[cpt].best_time[0] = 0 ;
			fic.save[cpt].best_time[1] = 0 ;
			
			fic.save[cpt].last_time[0] = 0 ;
			fic.save[cpt].last_time[1] = 0 ;
		} ;
		
		sauver_save(filename,-1) ;
		
			gp_str_func.sprintf((char*)buffer,"new save file created :)");
			  		
			cw = GpTextWidthGet(buffer);
			ch = GpTextHeightGet(buffer);
			cx = (LCD_WIDTH - cw) / 2;
			cy = (LCD_HEIGHT - ch) / 2;
				
			GpRectFill(NULL, &gpDraw[nflip], cx - 7, cy - 5,cw + 27,32,224);
			GpRectFill(NULL, &gpDraw[nflip], cx - 6, cy - 4,cw + 25,30,72);
			GpTextOut(NULL, &gpDraw[nflip], cx, cy, buffer, 212);
			
			while(key_pressed==64) GpKeyGetEx(&key_pressed);
			while(key_pressed!=64) GpKeyGetEx(&key_pressed);
			while(key_pressed==64) GpKeyGetEx(&key_pressed);

	}
	else
	{
		GpFileRead(hfile, buffer,2,&m_size);
		if(atoi(buffer) != fic.nb_levels)
		{
			// mouhouhouhahahaha : error #triso#
			
			gp_str_func.sprintf((char*)buffer,"bad save file :(  %i -> %i",atoi(buffer),fic.nb_levels);
			  		
			cw = GpTextWidthGet(buffer);
			ch = GpTextHeightGet(buffer);
			cx = (LCD_WIDTH - cw) / 2;
			cy = (LCD_HEIGHT - ch) / 2;
				
			GpRectFill(NULL, &gpDraw[nflip], cx - 7, cy - 5,cw + 27,32,224);
			GpRectFill(NULL, &gpDraw[nflip], cx - 6, cy - 4,cw + 25,30,72);
			GpTextOut(NULL, &gpDraw[nflip], cx, cy, buffer, 212);
			
			while(key_pressed==64) GpKeyGetEx(&key_pressed);
			while(key_pressed!=64) GpKeyGetEx(&key_pressed);
			while(key_pressed==64) GpKeyGetEx(&key_pressed);
			
		}
		else
		{
			short cpt=0 ;
			
			for(cpt=0;cpt<fic.nb_levels;cpt++)
			{
				GpFileRead(hfile,&fic.save[cpt],sizeof(struct pz_save),&m_size);
			} ;
			
			/*gp_str_func.sprintf((char*)buffer,"load save file succesfull :)");
			  		
			cw = GpTextWidthGet(buffer);
			ch = GpTextHeightGet(buffer);
			cx = (LCD_WIDTH - cw) / 2;
			cy = (LCD_HEIGHT - ch) / 2;
				
			GpRectFill(NULL, &gpDraw[nflip], cx - 7, cy - 5,cw + 27,32,224);
			GpRectFill(NULL, &gpDraw[nflip], cx - 6, cy - 4,cw + 25,30,72);
			GpTextOut(NULL, &gpDraw[nflip], cx, cy, buffer, 212);
			
			while(key_pressed==64) GpKeyGetEx(&key_pressed);
			while(key_pressed!=64) GpKeyGetEx(&key_pressed);
			while(key_pressed==64) GpKeyGetEx(&key_pressed);*/
		}
		
		GpFileClose(hfile) ;
	}

}


void get_extention(char nom[16],char * extention)
{
	short i=0 ;
//	char output[30] ;
	
	while (nom[i] != '.') { i++; }
	
	i++ ;
	extention[0] = nom[i++] ;
	extention[1] = nom[i++] ;
	extention[2] = nom[i++] ;
	extention[3] = '\0' ;
	
	//GpRectFill(NULL, &gpDraw[0], 0, 0, gpDraw[0].buf_w, gpDraw[0].buf_h, 0xff);
	//GPSPRINTF(output,"fichier : %s  ext : %s",(char*)nom,extention) ;
	//GpTextOut(NULL,&gpDraw[0],10,15,output,15);
	
	//while(key_pressed!=256) GpKeyGetEx(&key_pressed);
   	//while(key_pressed==256) GpKeyGetEx(&key_pressed);
	
	
	//extention[3] = '\0' ;
}

void initialiser(void)
{
	GpKeyInit();
	GpPcmInit(PCM_M11,PCM_8BIT);

	nflip=0;
	key_pressed=0 ;
	//old = 0 ;
	pos_x = 0 ;
	pos_y = 0 ;
	nb_case_restantes = 0 ;
	
	if(difficulte != 2) temps = 1800 ;
	else temps = 3600 ;
	
	temps_en_moins=0 ;
	GpSurfaceSet(&gpDraw[0]);
	srand(GpTickCountGet()) ;
}

//////////////////////////////////////////////////////////

void afficher_terre(short x, short y)
{
	static short num_img = 0 ;	
	num_img++ ;
	if(num_img==25) num_img = 1 ;
	
	if(num_img==1) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre1,0,0,40,40,0);
	if(num_img==2) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre2,0,0,40,40,0);
	if(num_img==3) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre3,0,0,40,40,0);	
	if(num_img==4) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre4,0,0,40,40,0);	
	if(num_img==5) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre5,0,0,40,40,0);	
	if(num_img==6) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre6,0,0,40,40,0);	
	if(num_img==7) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre7,0,0,40,40,0);	
	if(num_img==8) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre8,0,0,40,40,0);	
	if(num_img==9) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre9,0,0,40,40,0);	
	if(num_img==10) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre10,0,0,40,40,0);	
	if(num_img==11) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre11,0,0,40,40,0);	
	if(num_img==12) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre12,0,0,40,40,0);	
	if(num_img==13) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre13,0,0,40,40,0);	
	if(num_img==14) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre14,0,0,40,40,0);	
	if(num_img==15) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre15,0,0,40,40,0);	
	if(num_img==16) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre16,0,0,40,40,0);	
	if(num_img==17) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre17,0,0,40,40,0);	
	if(num_img==18) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre18,0,0,40,40,0);	
	if(num_img==19) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre19,0,0,40,40,0);	
	if(num_img==20) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre20,0,0,40,40,0);	
	if(num_img==21) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre21,0,0,40,40,0);	
	if(num_img==22) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre22,0,0,40,40,0);	
	if(num_img==23) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre23,0,0,40,40,0);	
	if(num_img==24) GpTransBlt(NULL,&gpDraw[nflip],x,y,40,40,(unsigned char*)terre24,0,0,40,40,0);	
}

////////////////////////////////////////////////////////////

void afficher_solution(void)
{
	short cpt_x,cpt_y,couleur, dec_x,dec_y ;//tmp = 0, clr = rand() % 255 ;

	dec_x=(320-(niv.taille_x*15))/2 ;
	dec_y=(240-(niv.taille_y*15))/2 ;

	nflip=0 ;

	GpSurfaceSet(&gpDraw[nflip]);

	GpBitBlt(NULL,&gpDraw[nflip],0,0,320,240,fond_ecran,0,0,320,240);
	
	for(cpt_y=0;(cpt_y < niv.taille_y)&&(cpt_y < MAX_Y - 1);cpt_y++)
	{
		// on affiche la ligne de bmp
		for(cpt_x=0;cpt_x<niv.taille_x;cpt_x++)
		{
			//etat = niv.mat[cpt_ligne][cpt_x].etat ;
			couleur = niv.mat[cpt_y][cpt_x].couleur ;

			if(couleur) GpBitBlt(NULL,&gpDraw[nflip],dec_x + cpt_x*15,dec_y + cpt_y*15,15,15,img[14],0,0,15,15); //bonne
			else GpBitBlt(NULL,&gpDraw[nflip],dec_x + cpt_x*15,dec_y + cpt_y*15,15,15,img[15],0,0,15,15); //mauvaise
		};
	};
	
   // attend l'appui sur 'start'
   while(key_pressed!=256) GpKeyGetEx(&key_pressed);
   while(key_pressed==256) GpKeyGetEx(&key_pressed);
}

unsigned char *get_gpg(char *filename)
{
	unsigned char	*data;
	F_HANDLE		hfile;
	unsigned long	p_read_count;
	unsigned long	fsize;
	hfile = NULL;
	if (SM_OK != GpFileOpen(filename, OPEN_R, &hfile)) { GpSurfaceFlip(&gpDraw[0]); GpRectFill(NULL, &gpDraw[0], 0, 0, gpDraw[0].buf_w, gpDraw[0].buf_h, 0xff); GpTextOut(NULL, &gpDraw[0],5,5,"impossible d'ouvrir",50); GpTextOut(NULL, &gpDraw[0],5,20,filename,50); while(key_pressed!=256) { GpKeyGetEx(&key_pressed); } while(key_pressed==256) { GpKeyGetEx(&key_pressed); } }
	GpFileGetSize(filename, &fsize);
	GpFileSeek(hfile, FROM_BEGIN, 8, 0);
	data = gm_zi_malloc(fsize); //  * sizeof(unsigned short)
	GpFileRead(hfile, data, fsize, &p_read_count);
	GpFileClose(hfile);
	return (data);
}

void charger_fond(void)
{
	short num_fond ;
	static short old_fond = 0 ;
	
	char url[150], fic_name[15] ;

	GPSTRCPY(g_path_curr, "gp:\\gpmm\\picross\\fond\\");
	GpDirEnumList(g_path_curr, 0,30,(GPDIRENTRY*)&liste_fichier, &g_cnt_file);
	
	if(fond_select == 1)
	{
		do {
			num_fond = rand() % (g_cnt_file-2) ; // pour pas prendre . et ..
			num_fond += 2  ;
		} while((num_fond == old_fond)&&(g_cnt_file - 2 > 1)) ;
	}
	else
	{
		num_fond = fond_select ;		
	}
		
	old_fond = num_fond ;
	
	GPSTRCPY(fic_name,liste_fichier[num_fond].name);
	gp_str_func.sprintf(url,"%s%s",g_path_curr,fic_name) ;
	
	//GpTextOut(NULL,&gpDraw[0],5,15,url,15);
	
	//while(key_pressed!=32) GpKeyGetEx(&key_pressed) ;
	
	free(fond_ecran) ;
	fond_ecran = get_gpg(url) ;
}

short afficher_menu_gagne(short end_file)
{

	short select = 2 ;
	short select_max = 3 ;
	short old=0 ;
	long cpt ;
	short debut = 1 ;
	char url[100],buffer[100] ;
	unsigned char* menu[6] ;



	if(langue == 'f')  gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\fr\\menu\\load_win") ;
	else gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\en\\menu\\load_win") ;
	
	gp_str_func.sprintf(url,"%s\\chpuz.gpg",buffer) ;
	menu[0] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\chpuz2.gpg",buffer) ;
	menu[1] = get_gpg(url) ;
	
	gp_str_func.sprintf(url,"%s\\puzsuiv.gpg",buffer) ;
	menu[2] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\puzsuiv2.gpg",buffer) ;
	menu[3] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\quitter.gpg",buffer) ;
	menu[4] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\quitter2.gpg",buffer) ;
	menu[5] = get_gpg(url) ;

	if(end_file) select=1 ;

  do {

		GpKeyGetEx(&key_pressed);
		
		//compteur ++ ;
		
		//if(compteur == 50) { afficher_terre(10,50) ; compteur=0 ; }
		
		// haut
		if((key_pressed == 8)&&(select != 1))
		{
			select-- ;
			
			if((end_file)&&(select == 2)) select=1 ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		// bas
		if((key_pressed == 2)&&(select != select_max))
		{
			select++ ;
			
			if((end_file)&&(select == 2)) select=3 ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		if(debut)
		{
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre	
			
			debut = 0 ;
		}
		
		if(old != select) // aff
		{
			if(langue == 'f')
			{
				// tapette
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],77,63,172,25,menu[0],0,0,172,25);
				else	GpBitBlt(NULL,&gpDraw[nflip],77,63,172,25,menu[1],0,0,172,25);
				
				// humain
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],80,96,169,24,menu[2],0,0,169,24);
				else	GpBitBlt(NULL,&gpDraw[nflip],80,96,169,24,menu[3],0,0,169,24);
				        
				// killer
				if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],107,151,111,27,menu[4],0,0,111,27);
				else	GpBitBlt(NULL,&gpDraw[nflip],107,151,111,27,menu[5],0,0,111,27);
					
			}
			else
			{
				// tapette
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],77,63,172,25,menu[0],0,0,172,25);
				else	GpBitBlt(NULL,&gpDraw[nflip],77,63,172,25,menu[1],0,0,172,25);
				
				// humain
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],94,99,139,27,menu[2],0,0,139,27);
				else	GpBitBlt(NULL,&gpDraw[nflip],94,99,139,27,menu[3],0,0,139,27);
				        
				// killer
				if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],133,153,57,26,menu[4],0,0,57,26);
				else	GpBitBlt(NULL,&gpDraw[nflip],133,153,57,26,menu[5],0,0,57,26);
			}
			old = select ;
			for(cpt=0;cpt!=3500000;cpt++) ;			
		}
		
	} while((key_pressed!=256)&&(key_pressed!=64)&&(key_pressed != 32)) ;

	for(cpt=0;cpt<6;cpt++) free(menu[cpt]) ;

	GpPcmStop() ;
	GpPcmPlay((unsigned short*)start,start_length,0);		

	while ((key_pressed == 64)||(key_pressed == 256)) GpKeyGetEx(&key_pressed);

	
	return select ;	
}

short afficher_menu_lose(void)
{
	
	short select = 1 ;
	short select_max = 2 ;
	short old=0 ;
	long cpt ;
	short debut = 1 ;
	char url[100],buffer[100] ;
	unsigned char* menu[4] ;

	if(langue == 'f')  gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\fr\\menu\\loadlose") ;
	else gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\en\\menu\\loadlose") ;
	
	gp_str_func.sprintf(url,"%s\\quitter.gpg",buffer) ;
	menu[0] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\quitter2.gpg",buffer) ;
	menu[1] = get_gpg(url) ;
	
	gp_str_func.sprintf(url,"%s\\rees.gpg",buffer) ;
	menu[2] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\rees2.gpg",buffer) ;
	menu[3] = get_gpg(url) ;

  do {

		GpKeyGetEx(&key_pressed);
		
		//compteur ++ ;
		
		//if(compteur == 50) { afficher_terre(10,50) ; compteur=0 ; }
		
		// haut
		if((key_pressed == 8)&&(select != 1))
		{
			select-- ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		// bas
		if((key_pressed == 2)&&(select != select_max))
		{
			select++ ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		if(debut)
		{
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre	
			
			debut = 0 ;
		}
		
		if(old != select) // aff
		{
			if(langue == 'f')
			{
				// tapette
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],97,97,128,24,menu[2],0,0,128,24);
				else	GpBitBlt(NULL,&gpDraw[nflip],97,97,128,24,menu[3],0,0,128,24);
				
				// humain
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],116,157,93,23,menu[0],0,0,93,23);
				else	GpBitBlt(NULL,&gpDraw[nflip],116,157,93,23,menu[1],0,0,93,23);
       			}
			else
			{
				// tapette
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],96,96,130,28,menu[2],0,0,130,28);
				else	GpBitBlt(NULL,&gpDraw[nflip],96,96,130,28,menu[3],0,0,130,28);
				
				// humain
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],133,153,57,26,menu[0],0,0,57,26);
				else	GpBitBlt(NULL,&gpDraw[nflip],133,153,57,26,menu[1],0,0,57,26);
			}

			old = select ;
			for(cpt=0;cpt!=3500000;cpt++) ;			
		}
		
	} while((key_pressed!=256)&&(key_pressed!=64)&&(key_pressed != 32)) ;

	for(cpt=0;cpt<4;cpt++) free(menu[cpt]) ;

	GpPcmStop() ;
	GpPcmPlay((unsigned short*)start,start_length,0);		

	while ((key_pressed == 64)||(key_pressed == 256)) GpKeyGetEx(&key_pressed);

	
	return select ;	
}


void afficher_sprite(short couleur,short x,short y)
{
	if(couleur==0)  // case dévoilée noire
	{
		//GpBitBlt(NULL,&gpDraw[nflip],x,y,10,10,(unsigned char*)bleu2,0, 0,10,10);
		GpBitBlt(NULL,&gpDraw[nflip],x,y,10,10,img[12],0, 0,10,10);
	}

	if(couleur==1)  // case dévoilée blanche
	{
		//GpBitBlt(NULL,&gpDraw[nflip],x,y,10,10,(unsigned char*)vert1,0, 0,10,10);
		GpBitBlt(NULL,&gpDraw[nflip],x,y,10,10,img[13],0, 0,10,10);
	}

	if(couleur==2)  // case marquée
	{
		//GpBitBlt(NULL,&gpDraw[nflip],x,y,10,10,(unsigned char*)marque,0, 0,10,10);
		GpBitBlt(NULL,&gpDraw[nflip],x,y,10,10,img[11],0, 0,10,10);
	}

	if(couleur==3)  // case non dévoilée
	{
		//GpBitBlt(NULL,&gpDraw[nflip],x,y,10,10,(unsigned char*)nodevoil,0, 0,10,10);
		GpBitBlt(NULL,&gpDraw[nflip],x,y,10,10,img[10],0, 0,10,10);
	}
	
	if(couleur==4)  // curseur
	{
		GpTransBlt(NULL,&gpDraw[nflip],x,y-24,22,33,(unsigned char*)curseur,0,0,22,33,0);
	}
}

void charger_theme(void)
{
	char url[150] ;
	
	gp_str_func.sprintf(url,"gp:\\gpmm\\picross\\theme\\%s\\nondev.gpg",theme_name) ;
	free(img[10]) ;
	img[10] = get_gpg(url) ;
	
	gp_str_func.sprintf((char*)url,"gp:\\gpmm\\picross\\theme\\%s\\marque.gpg",theme_name) ;
	free(img[11]) ;
	img[11] = get_gpg(url) ;

	gp_str_func.sprintf((char*)url,"gp:\\gpmm\\picross\\theme\\%s\\devbon.gpg",theme_name) ;
	free(img[12]) ;	
	img[12] = get_gpg(url) ;

	gp_str_func.sprintf((char*)url,"gp:\\gpmm\\picross\\theme\\%s\\devpbon.gpg",theme_name) ;
	free(img[13]) ;
	img[13] = get_gpg(url) ;

	gp_str_func.sprintf((char*)url,"gp:\\gpmm\\picross\\theme\\%s\\bigbon.gpg",theme_name) ;
	free(img[14]) ;
	img[14] = get_gpg(url) ;

	gp_str_func.sprintf((char*)url,"gp:\\gpmm\\picross\\theme\\%s\\bigpbon.gpg",theme_name) ;
	free(img[15]) ;
	img[15] = get_gpg(url) ;
}


void choisir_theme(void)
{
	short select=2,cpt=0, old=1 ;
	char  output[20] ;
	long tmp=1 ;
	
	GpSurfaceFlip(&gpDraw[0]);
	
	// on prend la liste des rep contenus ds le rep theme
	
	GPSTRCPY(g_path_curr, "gp:\\gpmm\\picross\\theme\\");
	GpDirEnumList(g_path_curr, 0,20,(GPDIRENTRY*)&liste_fichier, &g_cnt_file);
	
	//gp_str_func.sprintf((char*)buffer,"url : %s (%i)",g_path_curr,g_cnt_file) ;
	//GpTextOut(NULL,&gpDraw[0],5,1,buffer,15);

	do{
		GpKeyGetEx(&key_pressed);
		
		if((key_pressed == 2)&&(select != g_cnt_file-1)) select++ ;
		if((key_pressed == 8)&&(select != 2)) select-- ;
		
		if(select != old)
		{
			old = select ;
			
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre	
			//GpRectFill(NULL, &gpDraw[0], 0, 0, gpDraw[0].buf_w, gpDraw[0].buf_h, 0xff);
			
			for(cpt=2;cpt<g_cnt_file;cpt++)
			{
				//if(cpt-2 > 5) col=90 ;
				//else col = 0 ;
				
				if(select==cpt) GPSPRINTF(output,"-> %s",(char*)liste_fichier[cpt].name) ;
				else GPSPRINTF(output,"    %s",(char*)liste_fichier[cpt].name) ;
				
				if(cpt-2 <= 5) GpTextOut(NULL,&gpDraw[0],50,90 + 10*(cpt - 2),output,15);
				else GpTextOut(NULL,&gpDraw[0],170,90 + 10*(cpt - 8),output,15);
				
			} ;
		
			GPSTRCPY(theme_name,(char*)liste_fichier[select].name);	
			charger_theme() ;
			
			afficher_sprite(3,130,175) ;
			afficher_sprite(2,145,175) ;
			afficher_sprite(1,160,175) ;
			afficher_sprite(0,175,175) ;
		}
		
		for(tmp=1;tmp<2000000;tmp++) ;
		
	} while((key_pressed!=64)&&(key_pressed!=256)) ;
	
	while((key_pressed==64)||(key_pressed==256)) GpKeyGetEx(&key_pressed) ;
	

}

void charger_langue(void)
{
}

void charger_menu(void)
{
	char bufferr[40],urll[50] ;

	if(langue == 'f')  gp_str_func.sprintf(bufferr,"gp:\\gpmm\\picross\\gfx\\fr\\menu\\debut") ;
	else gp_str_func.sprintf(bufferr,"gp:\\gpmm\\picross\\gfx\\en\\menu\\debut") ;

	gp_str_func.sprintf(urll,"%s\\random.gpg",bufferr) ;
	free(img[2]) ;
	img[2] = get_gpg(urll) ;

	gp_str_func.sprintf(urll,"%s\\random2.gpg",bufferr) ;
	free(img[3]) ;
	img[3] = get_gpg(urll) ;

	gp_str_func.sprintf(urll,"%s\\load.gpg",bufferr) ;
	free(img[4]) ;
	img[4] = get_gpg(urll) ;
	
	gp_str_func.sprintf(urll,"%s\\load2.gpg",bufferr) ;
	free(img[5]) ;
	img[5] = get_gpg(urll) ;
	
	gp_str_func.sprintf(urll,"%s\\options.gpg",bufferr) ;
	free(img[6]) ;
	img[6] = get_gpg(urll) ;

	gp_str_func.sprintf(urll,"%s\\options2.gpg",bufferr) ;
	free(img[7]) ;
	img[7] = get_gpg(urll) ;

	gp_str_func.sprintf(urll,"%s\\exit.gpg",bufferr) ;
	free(img2[0]) ;
	img2[0] = get_gpg(urll) ;

	gp_str_func.sprintf(urll,"%s\\exit2.gpg",bufferr) ;
	free(img2[1]) ;
	img2[1] = get_gpg(urll) ;

	gp_str_func.sprintf(urll,"gp:\\gpmm\\picross\\gfx\\pause.gpg") ;
	free(img[8]) ;
	img[8] = get_gpg(urll) ;
	
	gp_str_func.sprintf(urll,"gp:\\gpmm\\picross\\gfx\\win.gpg") ;
	free(img[9]) ;
	img[9] = get_gpg(urll) ;		
}


void lancer_intro(void)
{
	short ancien = 1 ;
	// affichage fond et lecture son d'intro
	
	GpPcmPlay((unsigned short*)intro,intro_length,0);	
	
	while(key_pressed!=256) // temps que 'start' non enfoncé
	{
		long cpt=0, cpt1=0 ;
				
		GpBitBlt(NULL,&gpDraw[nflip],0,0,320,240,img[0],0,0,320,240);
		
		// attente et affichage de la terre
		for(cpt=0;cpt<10;cpt++)
		{
			for(cpt1=0;cpt1<3000;cpt1++) { GpKeyGetEx(&key_pressed); if(key_pressed==256) cpt = 15 ; } ;
			//afficher_terre(10,50) ;
		} ;
		
		ancien = !ancien ;

		//GpBitBlt(NULL,&gpDraw[nflip],0,0,320,240,img[0],0,0,320,240);
		//GpRectFill(NULL, &gpDraw[0],15,15,270,210,99);

		if(!ancien) GpTransBlt(NULL,&gpDraw[nflip],90,188,142,24,img_start,0,0,142,24,0);
		//else GpBitBlt(NULL,&gpDraw[nflip],105,149,110,24,(unsigned char*)fond_sta,0,0,110,24);
		
		nflip = !nflip ;
		GpSurfaceFlip(&gpDraw[!nflip]) ;
		
		//GpKeyGetEx(&key_pressed);
	}
	
	while(key_pressed==256) { GpKeyGetEx(&key_pressed); }

	GpPcmStop() ;	
	// lecture du son 'start' avant d'aller ds le menu
	GpPcmPlay((unsigned short*)start,start_length,0);
	
	
	nflip = 0 ;
	GpSurfaceFlip(&gpDraw[nflip]) ;	
}

///////////////////////////////////////////////////////////

void calculer_ligne(struct case_tab *matrice,short *result,short *nombre)
{
        short pos = 0 ;
        short nb = 0 ;
        short rang = 0 ;
        short taille ;
        short taille_result ;
        short buffer ;

        taille = *nombre ;
        taille_result = taille / sizeof(taille) + 1;
				*nombre = 0 ;

        for(pos=0;pos<taille;pos++)
        {
                buffer = matrice[pos].couleur ;
                if(buffer) nb++ ;
                if((!buffer)&&(nb))
                {
                        result[rang] = nb ;
                        (*nombre) ++ ;
                        rang++ ;
                        nb = 0 ;
                }
        } ;

        if(nb)
        {
                result[rang] = nb ;
                (*nombre) ++ ;
        }
}

////////////////////////////////////////////////////////////////////////////////////

void afficher_niveau(struct niveau *niv) // affiche le jeux
{
	short cpt_x,cpt_y,cpt_ligne,etat,couleur ;

	for(cpt_y=0;(cpt_y < niv->taille_y)&&(cpt_y < MAX_Y - 1);cpt_y++)
	{
		//cpt_ligne = niv->aff_y + niv->scrolling ;
		cpt_ligne=cpt_y + niv->scrolling ;
		// on affiche la ligne de bmp
		for(cpt_x=0;cpt_x<niv->taille_x;cpt_x++)
		{
			etat = niv->mat[cpt_ligne][cpt_x].etat ;
			couleur = niv->mat[cpt_ligne][cpt_x].couleur ;

			if(etat == 0) afficher_sprite(3,niv->dec_x + taille_case*cpt_x + niv->img_haut_gauche_x,niv->dec_y + taille_case*cpt_y + niv->img_haut_gauche_y) ; // case non dévoilée
			if(etat == 1) afficher_sprite(!(short)couleur,niv->dec_x + taille_case*cpt_x + niv->img_haut_gauche_x,niv->dec_y + taille_case*cpt_y + niv->img_haut_gauche_y) ; // case dévoilée
			if(etat == 2) afficher_sprite(2,niv->dec_x + taille_case*cpt_x + niv->img_haut_gauche_x,niv->dec_y + taille_case*cpt_y + niv->img_haut_gauche_y) ; // case marquée
		};
	};	
}

///////////////////////////////////////////////////////////////////

void afficher_info_ligne(struct niveau *niv) // affiche le jeux et les info des lignes
{
	short cpt_x,cpt_y,tmp=1,nb,cpt_ligne ;
	short buffer ;
	char buf[5] ;
	
	for(cpt_y=0;(cpt_y < niv->taille_y)&&(cpt_y < MAX_Y - 1);cpt_y++)
	{
		cpt_ligne=cpt_y + niv->scrolling ;
		tmp=!tmp ;
		if(!tmp) // on alterne les col blanche et noire
		{
			GpBitBlt(NULL,&gpDraw[nflip],niv->dec_x,niv->dec_y + niv->img_haut_gauche_y + cpt_y *10,58,10,(unsigned char*)Horange,0, 0,58,10);
		}
		else
		{
			GpBitBlt(NULL,&gpDraw[nflip],niv->dec_x,niv->dec_y + niv->img_haut_gauche_y + cpt_y *10,58,10,(unsigned char*)Hvert,0, 0,58,10);
		}

		nb = niv->nb_ligne[cpt_ligne]	;

		for(cpt_x=0;cpt_x<nb;cpt_x++)
		{
			buffer = niv->result_ligne[cpt_y][cpt_x] ;						
			gp_str_func.sprintf((char*)buf,"%X",buffer);
			GpTextOut(NULL, &gpDraw[nflip],niv->dec_x + cpt_x*10 + 2,niv->dec_y + niv->img_haut_gauche_y + cpt_y *10 - 5,buf,75);
		};
			// si pas d'info
			
			if(cpt_x==0) GpTextOut(NULL, &gpDraw[nflip],niv->dec_x + cpt_x*10,niv->dec_y + niv->img_haut_gauche_y + cpt_y *10 - 5,"*",75);
	};	
}

void afficher_info_col(struct niveau * niv)
{
				short cpt_y,cpt_x,tmp=1,nb,buffer,aff_y;
				char buf[5] ;
				
				for(cpt_y = 0;cpt_y<niv->taille_x;cpt_y++)
				{
					tmp=!tmp ;
					if(!tmp) // on alterne les col blanche et noire
					{
						GpBitBlt(NULL,&gpDraw[nflip],niv->dec_x + niv->img_haut_gauche_x + cpt_y *10,niv->dec_y, 10,58,(unsigned char*)orange_v,0, 0,10,58);
					}
					else
					{
						GpBitBlt(NULL,&gpDraw[nflip],niv->dec_x + niv->img_haut_gauche_x + cpt_y *10,niv->dec_y, 10,58,(unsigned char*)vert_v,0, 0,10,58);
					}
					
					nb = niv->nb_col[cpt_y]	;
					aff_y=0 ;
					for(cpt_x=niv->scroll_info_col;(cpt_x<nb)/*&&(cpt_x - niv->scroll_info_col < 5)*/;cpt_x++)
					{
						buffer = niv->result_col[cpt_y][cpt_x] ;
						gp_str_func.sprintf((char*)buf,"%X",buffer);
						GpTextOut(NULL, &gpDraw[nflip],niv->dec_x + niv->img_haut_gauche_x + cpt_y *10 + 1,niv->dec_y + cpt_x * 10,buf,70);
						aff_y++ ;
					} ;					
							// si pas d'info
							if(cpt_x==0) GpTextOut(NULL, &gpDraw[nflip],niv->dec_x + niv->img_haut_gauche_x + cpt_y *10 + 1,niv->dec_y + cpt_x * 10,"*",70);
				} ;
}


////////////////////////////////////////////////////////////////////////////////////

void calculer_niveau(struct niveau *niv)
{
				short taille_x = niv->taille_x ;
				short taille_y = niv->taille_y ;
				struct case_tab imat[PZMAX_X][PZMAX_Y] ;
				short nb_y[PZMAX_X] ;
				short cpt_x,cpt_y,nb ;
								
				niv->nb_max_ligne = 0 ;
				niv->nb_max_col = 0 ;
				
				/*  inversion de la matrice  */
				
				for(cpt_x=0;cpt_x<taille_x;cpt_x++)
				{
					for(cpt_y=0;cpt_y<taille_y;cpt_y++)
					{
						imat[cpt_x][cpt_y].couleur = niv->mat[cpt_y][cpt_x].couleur ;
					};				
				};
				
				/*  calcul des collones  */
				
				for(cpt_x=0;cpt_x<taille_x;cpt_x++)
				{
					nb = taille_y ;
					calculer_ligne(imat[cpt_x],niv->result_col[cpt_x],&nb) ;
					
					if(nb>niv->nb_max_col) niv->nb_max_col = nb ;
					nb_y[cpt_x] = nb ;
					niv->nb_col[cpt_x] = nb ;
				};
				
				/*  calcul des lignes  */
				
				for(cpt_y=0;cpt_y<taille_y;cpt_y++)
				{
					nb = taille_x ;
					calculer_ligne(niv->mat[cpt_y],niv->result_ligne[cpt_y],&nb) ;
					if(nb>niv->nb_max_ligne) niv->nb_max_ligne = nb ;
					niv->nb_ligne[cpt_y] = nb ;
				};
				
				niv->scrolling = 0 ; // pas de scrolling au début
				niv->scroll_info_col = 0 ;
				niv->aff_y = 0 ;
				
				//calcul de la taille x et y de l'image haut gauche
				niv->img_haut_gauche_x = (niv->nb_max_ligne) * taille_info - 2 ;
				niv->img_haut_gauche_y = (niv->nb_max_col + 1) * taille_info - 2 ;
				
				// taille mini de l'image : 58x58
				if(niv->img_haut_gauche_x < 58) niv->img_haut_gauche_x = 58 ;
				if(niv->img_haut_gauche_y < 58) niv->img_haut_gauche_y = 58 ;				
				
				// decalage pour centrer le jeux
				niv->dec_x = ((320 - niv->img_haut_gauche_x - (niv->taille_x * taille_case))/2) ;
				niv->dec_y = ((240 - niv->img_haut_gauche_y - (niv->taille_y * taille_case))/2) ;
				
				nb_case_totales = nb_case_restantes ;
}


///////////////////////////////////////////////////////////////////

void afficher_temps(short x, short y)
{
	char buffer[15];
  	short sec, min ;

  	//temps-- ;

  	min = temps / 60 ;
  	sec = temps - 60 * min ;  	

	if((min<10)&&(sec<10))  gp_str_func.sprintf((char*)buffer,"0%i:0%i",min,sec) ;
	if((min<10)&&(sec>=10))	gp_str_func.sprintf((char*)buffer,"0%i:%i",min,sec) ;
	if((min>=10)&&(sec<10))	gp_str_func.sprintf((char*)buffer,"%i:0%i",min,sec) ;
	if((min>=10)&&(sec>=10))gp_str_func.sprintf((char*)buffer,"%i:%i",min,sec) ;

	GpTextOut(NULL, &gpDraw[nflip],x,y,buffer,15);	
}

///////////////////////////////////////////////////////////////////

void afficher_case(struct niveau *niv,short pos_x,short pos_y)
{
   			short etat = niv->mat[pos_y][pos_x].etat ;
    			short x = niv->img_haut_gauche_x  ;
    			short y = niv->img_haut_gauche_y  ;
							
 	  		if(etat == 0) afficher_sprite(3,taille_case*pos_x + x,taille_case*pos_y + y) ; // case non dévoilée
			if(etat == 1) afficher_sprite(!(short)niv->mat[pos_y][pos_x].couleur,taille_case*pos_x + x,taille_case*pos_y + y) ; // case dévoilée
			if(etat == 2) afficher_sprite(2,taille_case*pos_x + x,taille_case*pos_y + y) ; // case marquée
}

///////////////////////////////////////////////////////////////////

void afficher_jeux()
{
		GpSurfaceFlip(&gpDraw[!nflip]);

		//fond
		GpBitBlt(NULL,&gpDraw[nflip],0,0,320,240,(unsigned char*)fond_ecran,0,0,320,240);
		
		// fond terre et temps
		GpBitBlt(NULL,&gpDraw[nflip],niv.dec_x,niv.dec_y,65,65,(unsigned char*)fd_terre,0,0,65,65);
		//GpBitBlt(NULL,&gpDraw[nflip],niv.dec_x,niv.dec_y,niv.img_haut_gauche_x,niv.img_haut_gauche_y,(unsigned char*)fd_terre,0,0,65,65);

		afficher_terre(niv.dec_x + (niv.img_haut_gauche_x/2) - 20,niv.dec_y + (niv.img_haut_gauche_y - 53)/2) ; // -58 + 5
		afficher_temps(niv.dec_x + (niv.img_haut_gauche_x/2) - 19,niv.dec_y + niv.img_haut_gauche_y - 18) ; // -58 + 42

		afficher_niveau(&niv) ;
		afficher_info_col(&niv) ;
		afficher_info_ligne(&niv) ;
		
		afficher_sprite(4,niv.dec_x + taille_case * pos_x + niv.img_haut_gauche_x + 1,niv.dec_y + taille_case * pos_y + niv.img_haut_gauche_y + 1) ;
}

//////////////////////////////////////////////////////////////////

short lire_clavier()
{
		static short marque = 0 ;
		static short nb_tmp = 0 ;
		long temp ;//, old_pad_time = 0 ;		
		short tmp=0 ;				
		
		temp = GpTickCountGet() ;

		//while(GpTickCountGet() < (temp + 100)) ; //GpKeyGetEx(&key_pressed) ; // ralentissement

		if((key_pressed & 4)&&(pos_x != niv.taille_x-1))
		{
			(pos_x)++ ;
			//if(pos_x > niv.taille_x-1) (pos_x)-- ;
			tmp = 1 ;
			marque = 0 ;
			//old_pad_time = GpTickCountGet() ;
		}
		
		if((key_pressed & 1)&&(pos_x != 0))
		{
			(pos_x)-- ;
			//if(pos_x < 0) pos_x = 0 ;
			tmp = 1 ;
			marque = 0 ;
			//old_pad_time = GpTickCountGet() ;
		}
		
		if((key_pressed & 8)&&(pos_y != 0))
		{
			(pos_y)-- ;
			//if(pos_y < 0) pos_y = 0 ;
			tmp = 1 ;
			marque = 0 ;
			//old_pad_time = GpTickCountGet() ;
		}
		
		if((key_pressed & 2)&&(pos_y != niv.taille_y-1))
		{
			(pos_y)++ ;
			//if(pos_y > (niv.taille_y-1)) (pos_y)-- ;
			tmp = 1 ;
			marque = 0 ;
			//old_pad_time = GpTickCountGet() ;
		}
		
		//if(tmp) { temp = GpTickCountGet() ; while(GpTickCountGet() < (temp + 50)) ; }
		
		if(key_pressed & 64)
		{
			char old_etat = niv.mat[pos_y][pos_x].etat ; // état précédent de la case
			char couleur = niv.mat[pos_y][pos_x].couleur ; // couleur de la case
			
			if(old_etat==0) // si pas dévoilé et pas marqué
			{
				niv.mat[pos_y][pos_x].etat = 1 ; // on met l'état de la case dévoilée
		
				if(!couleur)
				{
					short p_t = 2,cw,ch,cx,cy ;
					char buf[20] ;
					
					temps -= temps_en_moins * 60 ;
					
					if((temps_en_moins==1)||(difficulte == 0))
					{
						gp_str_func.sprintf((char*)buf,"- %i minute !",temps_en_moins);
						temps_en_moins ++ ;
						
					}
					else
					{
						gp_str_func.sprintf((char*)buf,"- %i minutes !",temps_en_moins);
						
						if(temps_en_moins<8) temps_en_moins += 2 ;
						
					}
			  		
			  		if(temps<0) temps = 0 ;
			  		if(temps_en_moins<8) p_t = temps_en_moins + 2 ;
			  		else p_t = 8 ;
			  		
			  		afficher_jeux() ;
			  		nflip = !nflip ;
			  		afficher_jeux() ;
			  		nflip = !nflip ;
			  		
					cw = GpTextWidthGet(buf);
					ch = GpTextHeightGet(buf);
					cx = (LCD_WIDTH - cw) / 2;
					cy = (LCD_HEIGHT - ch) / 2;
					
					GpRectFill(NULL, &gpDraw[nflip], cx - 7, cy - 5,cw + 27,32,224);
					GpRectFill(NULL, &gpDraw[nflip], cx - 6, cy - 4,cw + 25,30,72);
					GpTextOut(NULL, &gpDraw[nflip], cx, cy, buf, 212);
					
					GpPcmPlay((unsigned short*)fouet,6894,0);
					temp = GpTickCountGet() ;
					if(temps != 0) while(GpTickCountGet() < (temp + 600)) ;
					
					GpPcmPlay((unsigned short*)fouet,6894,0);
					temp = GpTickCountGet() ;
					if(temps != 0) while(GpTickCountGet() < (temp + 600)) ;
					
									  		
				}
				else
				{
					nb_case_restantes-- ;
				}
				
				//old_pad_time = GpTickCountGet() ;
			}	
		}
		
		if((key_pressed & 32)&&(!marque))
	  	{
				char old_etat = niv.mat[pos_y][pos_x].etat ; // état précédent de la case

				if(old_etat == 0) niv.mat[pos_y][pos_x].etat = 2 ; // si case non dévoilée

				if(old_etat == 2) niv.mat[pos_y][pos_x].etat = 0 ; // si case déjà marquée			

				marque = 1 ;
				nb_tmp=0 ;
	  	}
		
		if(key_pressed == 256) // start -> pause
		{
			static short x=10,y=94,sens=1,sens_x=1,color = 207,txt_color=40 ;
			//long cmpt=0,limit = 20000 ;
			char buffer[40], buf[10] ;
			short sec, min ;

		  	min = temps / 60 ;
		  	sec = temps - 60 * min ; 
			
			
			while(key_pressed==256) GpKeyGetEx(&key_pressed);
			
			do {
				GpSurfaceFlip(&gpDraw[!nflip]);
				
				GpBitBlt(NULL,&gpDraw[nflip],0,0,320,240,fond_ecran,0,0,320,240);			
				
				GpRectFill(NULL, &gpDraw[nflip],15,15,290,40,color);
										
				GpTransBlt(NULL,&gpDraw[nflip],x,y,286,77,img[8],0,0,286,77,0);
				
				if(key_pressed == 2) color-- ;
				if(key_pressed == 8) color++ ;				

				if(key_pressed == 1) txt_color-- ;
				if(key_pressed == 4) txt_color++ ;				
				
				if(sens) y++ ;
				else y-- ;
				
				if(sens_x) x++ ;
				else x-- ;
								
				if(y>=162) sens = 0 ;
				if(y<=1) sens = 1 ;
				
				if(x>=33) sens_x = 0 ;
				if(x<=1) sens_x = 1 ;
				
				if(choix==2) // charger puzzle
				{
					gp_str_func.sprintf((char*)buffer,"puzzle %i/%i : %ix%i",num_puzzle+1,fic.nb_levels,niv.taille_x,niv.taille_y);
					GpTextOut(NULL, &gpDraw[nflip],25,20,buffer,txt_color);					
				}
				else // aleatoire
				{
					if(langue=='f')	gp_str_func.sprintf((char*)buffer,"jeux aleatoire : %ix%i",niv.taille_x,niv.taille_y);
					else gp_str_func.sprintf((char*)buffer,"random game : %ix%i",niv.taille_x,niv.taille_y);
						
					GpTextOut(NULL, &gpDraw[nflip],25,20,buffer,txt_color);
				}				

				if(langue=='f')	GPSTRCPY(buf,"temps") ;
				else GPSTRCPY(buf,"time") ;
						
				if((min<10)&&(sec<10))  gp_str_func.sprintf((char*)buffer,"%s 0%i:0%i",buf,min,sec) ;
				if((min<10)&&(sec>=10))	gp_str_func.sprintf((char*)buffer,"%s 0%i:%i",buf,min,sec) ;
				if((min>=10)&&(sec<10))	gp_str_func.sprintf((char*)buffer,"%s %i:0%i",buf,min,sec) ;
				if((min>=10)&&(sec>=10))gp_str_func.sprintf((char*)buffer,"%s %i:%i",buf,min,sec) ;
				
				//gp_str_func.sprintf((char*)buffer,"temps  %i:%i",min,sec);
				
				GpTextOut(NULL, &gpDraw[nflip],205,20,buffer,txt_color);
				
				if(langue=='f')	gp_str_func.sprintf((char*)buffer,"%i/%i cases restantes",nb_case_restantes,nb_case_totales);
				else gp_str_func.sprintf((char*)buffer,"%i/%i Remaining cells",nb_case_restantes,nb_case_totales);
				
				GpTextOut(NULL, &gpDraw[nflip],50,35,buffer,txt_color);

				if(nflip) GpRectFill(NULL, &gpDraw[0],10,10,295,45,color);
				GpRectFill(NULL, &gpDraw[0],15,15,290,40,color);

				//gp_str_func.sprintf((char*)buffer,"color : %i - %i",color,txt_color);
				//GpTextOut(NULL, &gpDraw[nflip],50,75,buffer,31);
				
				nflip = !nflip ;
				
				GpKeyGetEx(&key_pressed);
				
			} while(key_pressed!=256) ;
			
			while(key_pressed==256) GpKeyGetEx(&key_pressed);
			time = GpTickCountGet() ;
		}
		
		if(nb_tmp>=10)
		{
			marque = 0 ;
			nb_tmp=0 ;
		}

		if(!tmp) nb_tmp++ ;

	return tmp ;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

int lancer_jeux(void)
{
	int cpt,cpt1,limit, temps_copie ;
	unsigned int temps_jeux = 0 ;
		
	GpPcmInit(PCM_S11,PCM_8BIT);
	GpPcmPlay((unsigned short*)zik,291939,1);

	//free(fond_ecran) ;
	
	// on charge un fond aléatoirement et != du precedent
	charger_fond() ;
	
	nflip=0 ;
	
	time = GpTickCountGet() ;
	
	do
	{
		GpKeyGetEx(&key_pressed);
		lire_clavier() ;
		afficher_jeux() ;
		
		if(GpTickCountGet() >= time + 1000)
		{
			temps-- ;
			time += 1000 ;
			temps_jeux++ ;
		}
		
		if(vitesse == 0)
		{
			if((key_pressed != 64)&&(key_pressed & 64)) limit = 900 ;
			else limit = 500 ;
		}
		
		if(vitesse == 1)
		{
			if((key_pressed != 64)&&(key_pressed & 64)) limit = 600 ;
			else limit = 350 ;
		}
		
		if(vitesse == 2)
		{
			if((key_pressed != 64)&&(key_pressed & 64)) limit = 400 ;
			else limit = 200 ;
		}
		
		for(cpt=0;cpt<limit;cpt++)  for(cpt1=0;cpt1<3000;cpt1++) ;
		
		//for(cpt=0;cpt<200;cpt++)  for(cpt1=0;cpt1<3000;cpt1++) ;
		
		nflip = !nflip ;
	
	} while ((nb_case_restantes)&&(temps>0)&&(key_pressed != 144)) ;

	GpPcmStop() ;

	nflip = 0 ;
	afficher_jeux() ;
	nflip = 1 ;
	afficher_jeux() ;
	nflip = 0 ;
	
	GpSurfaceFlip(&gpDraw[nflip]);

	if(key_pressed == 144) { nb_case_restantes=1 ; temps=0 ; }
	
	if((!nb_case_restantes)||((key_pressed & 128)&&(!(key_pressed & 16)))) // si gagné
	{
		GpTransBlt(NULL,&gpDraw[nflip],83,96,154,47,img[9],0,0,154,47,0);
   		GpPcmInit(PCM_M22,PCM_8BIT);
		GpPcmPlay((unsigned short*)skap,291939,1);
		
		while(key_pressed!=256) GpKeyGetEx(&key_pressed);
		while(key_pressed==256) GpKeyGetEx(&key_pressed);

		afficher_solution() ;		
	}

	if((!temps)&&(!(key_pressed & 128))&&(!(key_pressed & 16))) // si perdu
	{
		GpTransBlt(NULL,&gpDraw[nflip],(320-184)/2,(240-53)/2,184,53,(unsigned char*)perdu,0,0,184,53,0);
		GpPcmPlay((unsigned short*)rire,291939,1);
		
		while(key_pressed==256) GpKeyGetEx(&key_pressed);
		while(key_pressed!=256) GpKeyGetEx(&key_pressed);
		while(key_pressed==256) GpKeyGetEx(&key_pressed);
	}
	
	temps_copie = temps ;
	
	GpPcmStop() ;
	initialiser() ;
	
	if(!temps_copie) temps_jeux = -1 ;
	
	return temps_jeux ;
}

short charger_fichier(char filename[255],short pzref,short start_num)
{
	unsigned long m_size=0, total_size=0;
	char buffer[50] = "" ; //, save_name[20], url[255] ;
	unsigned char tmp ;
	short level ;
	unsigned short temp = 0 ;
	unsigned long cmpt=0 ;
	unsigned short ancien=0 ;
	unsigned long pos_fic=0 ;
	//short i=0 ;
	
	F_HANDLE file;
	//F_HANDLE hfile;

	

	GpFileOpen(filename,OPEN_R,&file) ;
	GpFileGetSize(filename,&m_size);
	
	GpFileRead(file, buffer,13,&m_size);
	total_size += m_size;

	if(!GPSTRCMP(buffer,"_picross_lvl_"))
	{
		GPSTRCPY(buffer,"") ;
		
		GpFileRead(file, buffer,20,&m_size);
		total_size += m_size;
		GPSTRCPY(fic.nom,buffer) ;
		fic.nom[20] = '\0' ;
		
		GPSTRCPY(buffer,"") ;
				
		GpFileRead(file, buffer,15,&m_size);
		total_size += m_size;
		GPSTRCPY(fic.auteur,buffer) ;
		fic.auteur[15] = '\0' ;
		
		GPSTRCPY(buffer,"") ;		
		
		GpFileRead(file, buffer,2,&m_size);
		total_size += m_size;
		fic.nb_levels = atoi(buffer) ;

		//fic.tab_taille_x_y = gp_mem_func.calloc(2 * 2,fic.nb_levels) ; // taille short * 2 short (tx et ty) * nb levels
		//GpRectFill(NULL, &gpDraw[0], 0, 0, gpDraw[0].buf_w, gpDraw[0].buf_h, 0xff);
				
		for(cmpt=0;cmpt<fic.nb_levels;cmpt++)
		{
				GpFileRead(file, buffer,2,&m_size);
				total_size += m_size;
				fic.tab_taille_x_y[cmpt][0] = atoi(buffer) ;
					
				GpFileRead(file, buffer,2,&m_size);
				total_size += m_size;
				fic.tab_taille_x_y[cmpt][1] = atoi(buffer) ;
		} ;
	
		level=pzref ;

		if(pzref == -1) // choix du puzzle a charger, si pas specifié
		{
			short lign=0, col=0, cpt ; //, frame_skip=0 ;
		
			if(!(fic.load)) { charger_save(filename) ; fic.load=1 ; }
				
			ancien = !start_num ;
			level = start_num ;
					
			do
			{
				GpKeyGetEx(&key_pressed) ;
		
				if((key_pressed == 4)&&(level!=fic.nb_levels-1)&&(fic.tab_taille_x_y[level + 1][0] * fic.tab_taille_x_y[level + 1][1] != 0)) level++ ;
				if((key_pressed == 1)&&(level)) level-- ;
		
				if((key_pressed == 2)&&(level+15 <= fic.nb_levels-1)) if((fic.tab_taille_x_y[level + 15][0] * fic.tab_taille_x_y[level + 15][1] != 0)) level += 15 ;
				if((key_pressed == 8)&&(level-15 >= 0)) level -= 15 ;		
		
//				if(ancien != level)
				{
					short nb_cases ;
					GpBitBlt(NULL,&gpDraw[nflip],0,0,320,240,img[0],0,0,320,240);
					GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre	
					//GpRectFill(NULL, &gpDraw[0], 0, 0, gpDraw[0].buf_w, gpDraw[0].buf_h, 0xff);
						
					for(cpt=0;cpt<fic.nb_levels;cpt++)
					{
						//frame_skip != frame_skip ;
						//if(level != cpt) GpBitBlt(NULL,&gpDraw[0],45+col*15,45+lign*15,15,15,load_vert,0,0,15,15);						
						//else GpBitBlt(NULL,&gpDraw[0],45+col*15,45+lign*15,15,15,load_jaune,0,0,15,15);
						
						nb_cases = fic.tab_taille_x_y[cpt][0]*fic.tab_taille_x_y[cpt][1] ;

						// l'img de chaque level, depend de la taille de celui ci, et des saves (fini ou non)
						
						if(nb_cases < 100)
						{
							short ref = 0 ;
							if(fic.save[cpt].nb_win != 0) ref++ ;
							
							GpTransBlt(NULL,&gpDraw[nflip],47+col*15,48+lign*15,15,15,load[ref],0,0,15,15,0);
						}
						else
						{
							if(nb_cases < 225)
							{
								short ref = 2 ;
								if(fic.save[cpt].nb_win != 0) ref++ ;

								GpTransBlt(NULL,&gpDraw[nflip],47+col*15,48+lign*15,15,15,load[ref],0,0,15,15,0);
							}
							else
							{
								short ref = 4 ;
								if(fic.save[cpt].nb_win != 0) ref++ ;

								GpTransBlt(NULL,&gpDraw[nflip],47+col*15,48+lign*15,15,15,load[ref],0,0,15,15,0);
							}
						}
						if(cpt==level) GpTransBlt(NULL,&gpDraw[nflip],47+col*15,48+lign*15,15,15,load_curs1,0,0,15,15,0);

						col ++ ;
						if(col==15) { lign ++ ; col=0 ; }
					} ;
						col=lign=0 ;
						
						
						if(langue == 'f') gp_str_func.sprintf((char*)buffer,"nom : %s",fic.nom) ;
						else gp_str_func.sprintf((char*)buffer,"name : %s",fic.nom) ;
						
						GpTextOut(NULL,&gpDraw[nflip],50,130,buffer,25);
			
						if(langue == 'f') gp_str_func.sprintf((char*)buffer,"auteur : %s",fic.auteur) ;
						else gp_str_func.sprintf((char*)buffer,"author : %s",fic.auteur) ;
												
						GpTextOut(NULL,&gpDraw[nflip],50,141,buffer,25);
						
						//gp_str_func.sprintf((char*)buffer,"%i puzzles",fic.nb_levels) ;
						//GpTextOut(NULL,&gpDraw[nflip],50,164,buffer,25);
						
						gp_str_func.sprintf((char*)buffer,"puzzle %i/%i : %ix%i",level+1,fic.nb_levels,fic.tab_taille_x_y[level][0],fic.tab_taille_x_y[level][1]) ;
						GpTextOut(NULL,&gpDraw[nflip],50,152,buffer,15);

						gp_str_func.sprintf((char*)buffer,"play : %i - win : %i",fic.save[level].nb_try,fic.save[level].nb_win) ;
						GpTextOut(NULL,&gpDraw[nflip],50,163,buffer,15);
						
						gp_str_func.sprintf((char*)buffer,"last %i:%i - best %i:%i",fic.save[level].last_time[0],fic.save[level].last_time[1],fic.save[level].best_time[0],fic.save[level].best_time[1]) ;
						GpTextOut(NULL,&gpDraw[nflip],50,175,buffer,15);
						
						ancien = level ;
						
						nflip = !nflip ;
						GpSurfaceFlip(&gpDraw[!nflip]);						
				}	
				
				for(cmpt=0;cmpt<=1000;cmpt++) for(temp=1;temp<=500;temp++) ;	
			
			} while((key_pressed != 256)&&(key_pressed != 64)) ;
					
			while ((key_pressed == 256)||(key_pressed == 64)) GpKeyGetEx(&key_pressed);
		}

		GpKeyGetEx(&key_pressed) ;

		cmpt=0 ; // level actuel = 0
			
		pos_fic = total_size ;
										
			while(cmpt!=level)
			{
				// on avance dans le fichier d'un puzzle
				temp = (fic.tab_taille_x_y[cmpt][0] * fic.tab_taille_x_y[cmpt][1]) ;
				GpFileSeek(file,FROM_CURRENT,temp,0);
				cmpt ++ ;
			} ;
			
		niv.taille_x = fic.tab_taille_x_y[level][0] ; // taille_x = celle chargée
		niv.taille_y = fic.tab_taille_x_y[level][1] ; // taille_y = celle chargée
		
		// on rempli la matrice
		for(cmpt=0;cmpt<niv.taille_y;cmpt++)
		{
			for(tmp=0;tmp<niv.taille_x;tmp++)
			{
				GpFileRead(file, buffer,1,&m_size);
				total_size += m_size;
				niv.mat[cmpt][tmp].couleur = atoi(buffer) ;
				niv.mat[cmpt][tmp].etat = 0 ; // non dévoilé
				if(niv.mat[cmpt][tmp].couleur) nb_case_restantes ++ ;
			};
		};			
        }
	
	GpFileClose(file) ;

	return level ;
}

//////////////////////////////////////////////////////////////////////

void tester_touches(void)
{
	//srand(20);
	short old=0 ;
	while(key_pressed != 144) // l + r        affiche la touche entrée
	{
		char buf[15];
		int tmp1 ;

		//choix_menu = rand() ;

		
		for(tmp1=1;tmp1!=30000;tmp1++) ;
		
		GpKeyGetEx(&key_pressed);
		if((key_pressed && old != key_pressed)||(!key_pressed && old!=0))  GpRectFill(NULL, &gpDraw[nflip], 0, 0, gpDraw[nflip].buf_w, gpDraw[nflip].buf_h, 0xff);		
		
		if(key_pressed)
		{   			
   			gp_str_func.sprintf((char*)buf, "key press  : %d",key_pressed);
			old = key_pressed ;
			GpTextOut(NULL, &gpDraw[nflip], 10, 30, buf,key_pressed);
		}
		else
		{
			gp_str_func.sprintf((char*)buf, "no key press, choix menu = %d",choix);	
			old = 0 ;
			GpTextOut(NULL, &gpDraw[nflip], 10, 30,buf,125);
		}
	}
}

///////////////////////////////////////////////////////////////////////////////

void choisir_langue(void)
{
	short old = 3, select = 1 ;
	unsigned char *gfx[5] ;
	char lang_old = langue ;

	gfx[0] = get_gpg("gp:\\gpmm\\picross\\gfx\\language\\fr.gpg") ;
	gfx[1] = get_gpg("gp:\\gpmm\\picross\\gfx\\language\\fr2.gpg") ;
	gfx[2] = get_gpg("gp:\\gpmm\\picross\\gfx\\language\\usa.gpg") ;
	gfx[3] = get_gpg("gp:\\gpmm\\picross\\gfx\\language\\usa2.gpg") ;
	gfx[4] = get_gpg("gp:\\gpmm\\picross\\gfx\\language\\Language.gpg") ;

	if(langue=='f') select = 0 ;
		
	do
	{		
		GpKeyGetEx(&key_pressed);
		
		// haut
		if((key_pressed == 1)&&(select != 0))
		{
			select-- ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		// bas
		if((key_pressed == 4)&&(select != 1))
		{
			select++ ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
			
		if(old != select) // aff
		{			
		
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre	

			GpBitBlt(NULL,&gpDraw[nflip],96,51,131,41,gfx[4],0,0,131,41);
			
			// français
			if(select==1) GpBitBlt(NULL,&gpDraw[nflip],79,110,56,55,gfx[0],0,0,56,55); // non select
			else	GpBitBlt(NULL,&gpDraw[nflip],63,91,84,83,gfx[1],0,0,84,83); // select
			        
			// anglais
			if(select==0) GpBitBlt(NULL,&gpDraw[nflip],189,110,56,55,gfx[2],0,0,56,55); // non select
			else	GpBitBlt(NULL,&gpDraw[nflip],171,91,84,83,gfx[3],0,0,84,83); // select
			
			old = select ;
		}
		
	} while((key_pressed!=256)&&(key_pressed!=64)) ;

	GpPcmStop() ;
	GpPcmPlay((unsigned short*)start,start_length,0);		

	while ((key_pressed == 64)||(key_pressed == 256)) GpKeyGetEx(&key_pressed);
	
	if(select == 0) langue = 'f' ;
	else langue = 'e' ;
	
	if(lang_old != langue) charger_menu() ;
	
	free(gfx[0]) ;
	free(gfx[1]) ;
	free(gfx[2]) ;
	free(gfx[3]) ;
	free(gfx[4]) ;
}

///////////////////////////////////////////////////////////////////////////////

void jeux_aleatoire(void)
{

	short select = 1 ;
	short select_max = 4 ;
	short old=0 ;
	//short compteur=0 ;
	long cpt ;
	short debut = 1 ;
	short tmp ;
	char url[100],buffer[100] ;
	unsigned char* menu[9] ;

	// chargement des gfx du menu aléatoire
	
	if(langue == 'f')  gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\fr\\menu\\random") ;
	else gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\en\\menu\\random") ;
	
	gp_str_func.sprintf(url,"%s\\rand_fix.gpg",buffer) ;
	menu[0] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\5.gpg",buffer) ;
	menu[1] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\52.gpg",buffer) ;
	menu[2] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\10.gpg",buffer) ;
	menu[3] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\102.gpg",buffer) ;
	menu[4] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\15.gpg",buffer) ;
	menu[5] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\152.gpg",buffer) ;
	menu[6] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\custom.gpg",buffer) ;
	menu[7] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\custom2.gpg",buffer) ;
	menu[8] = get_gpg(url) ;

	do
	{		
		GpKeyGetEx(&key_pressed);
		
		//compteur ++ ;
		
		//if(compteur == 50) { afficher_terre(10,50) ; compteur=0 ; }
		
		// haut
		if((key_pressed == 8)&&(select != 1))
		{
			select-- ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		// bas
		if((key_pressed == 2)&&(select != select_max))
		{
			select++ ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		if(debut)
		{
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre	
			
			if(langue == 'f') GpBitBlt(NULL,&gpDraw[nflip],72,50,185,36,menu[0],0,0,185,36);
			else GpBitBlt(NULL,&gpDraw[nflip],76,50,175,35,menu[0],0,0,175,35);
			
			
			debut = 0 ;
		}
		
		if(old != select) // aff
		{
			// 5x5
			if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],135,88,50,23,menu[1],0,0,50,23);
			else	GpBitBlt(NULL,&gpDraw[nflip],135,88,50,23,menu[2],0,0,50,23);
				        
			// 10x10
			if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],123,115,77,21,menu[3],0,0,77,21);
			else	GpBitBlt(NULL,&gpDraw[nflip],123,115,77,21,menu[4],0,0,77,21);
				
			// 15x15
			if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],122,141,77,23,menu[5],0,0,77,23);
			else	GpBitBlt(NULL,&gpDraw[nflip],122,141,77,23,menu[6],0,0,77,23);
			
			if(langue == 'f')
			{
				// custom
				if(select!=4) GpBitBlt(NULL,&gpDraw[nflip],103,166,117,27,menu[7],0,0,117,27);
				else	GpBitBlt(NULL,&gpDraw[nflip],103,166,117,27,menu[8],0,0,117,27);
			}
			else
			{
				// custom
				if(select!=4) GpBitBlt(NULL,&gpDraw[nflip],124,164,73,29,menu[7],0,0,73,29);
				else	GpBitBlt(NULL,&gpDraw[nflip],124,164,73,29,menu[8],0,0,73,29);
			}
			old = select ;
			for(cpt=0;cpt!=3500000;cpt++) ;			
		}
		
	} while((key_pressed!=256)&&(key_pressed!=64)&&(key_pressed != 32)) ;

	for(cpt=0;cpt<=8;cpt++) free(menu[cpt]) ;

	GpPcmStop() ;
	GpPcmPlay((unsigned short*)start,start_length,0);		

	while ((key_pressed == 64)||(key_pressed == 256)) GpKeyGetEx(&key_pressed);

	if(key_pressed != 32)
	{
		if(select==1) // 5x5
		{
			niv.taille_x = 5 ;
			niv.taille_y = 5 ;
		}
		
		if(select==2) // 10x10
		{
			niv.taille_x = 10 ;
			niv.taille_y = 10 ;
		}
		
		if(select==3) // 15x15
		{
			niv.taille_x = 15 ;
			niv.taille_y = 15 ;
		}

		if(select==4) // custom
		{
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre
			
			if(langue=='f')
			{
				GpTextOut(NULL,&gpDraw[nflip],50,45,"choix de la taille du jeux\0",15);
				GpTextOut(NULL,&gpDraw[nflip],55,60,"utilisez le stick\0",15);
				GpTextOut(NULL,&gpDraw[nflip],50,75,"A : valider  B : annuler\0",15);
			}
			else
			{
				GpTextOut(NULL,&gpDraw[nflip],50,45,"choice of the game length\0",15);
				GpTextOut(NULL,&gpDraw[nflip],50,60,"use the stick\0",15);
				GpTextOut(NULL,&gpDraw[nflip],55,75,"A : ok  B : cancel\0",15);
			}
			

			key_pressed = 0 ;
			
			while((key_pressed!=256)&&(key_pressed!=64)&&(key_pressed != 32)) GpKeyGetEx(&key_pressed);

			niv.taille_x = 15 ;
			niv.taille_y = 15 ;
		}
		
		for(cpt=0;cpt<niv.taille_x;cpt++)
		{
			for(tmp=0;tmp<niv.taille_y;tmp++)
			{
				niv.mat[tmp][cpt].couleur = 0 ;
				niv.mat[tmp][cpt].couleur = rand() % 2 ;
				niv.mat[tmp][cpt].etat = 0 ; // non dévoilé(0)    dévoilé(pour test)(1)
				if(niv.mat[tmp][cpt].couleur) nb_case_restantes ++ ;
			};
		};
	
		calculer_niveau(&niv) ;
		lancer_jeux() ;
	}
	
	while (key_pressed == 32) GpKeyGetEx(&key_pressed);
}

//////////////////////////////////////////////////////////////////////

void charger_jeux(void)
{
	short i ;
	char buffer[50];
	char ext[4];
	short nb_fichiers_lvl = 0 ;
	short fch_lvl_name[20] ; // 20 fichiers max
	short old = -1, pos = 1 ;
	char nom_fichier[16] ;
	unsigned long tmp=0 ;
	short continu = 1 ; //,cmpt=0,temp=0 ;
	unsigned char* img_fixe ;
	short exit = 0 ;
	int temps_zz ;

	num_puzzle = -1 ;
	//GpFatInit();		

	if(langue=='f') img_fixe = get_gpg("gp:\\gpmm\\picross\\gfx\\fr\\menu\\load_fix.gpg") ;
	else img_fixe = get_gpg("gp:\\gpmm\\picross\\gfx\\en\\menu\\load_fix.gpg") ;

	GPSTRCPY(g_path_curr, "gp:\\gpmm\\picross\\lvl\\");
		
	GpRelativePathSet(g_path_curr) ;
	GpDirEnumList(g_path_curr, 0,10,(GPDIRENTRY*)&liste_fichier, &g_cnt_file);

	nb_fichiers_lvl = 0 ;
			
	for(i = 2 ; i < g_cnt_file ; i++)
	{
		get_extention((char*)liste_fichier[i].name,ext) ;
			
		if(!GPSTRCMP("LVL",(char*)ext))
		{
			fch_lvl_name[nb_fichiers_lvl] = i ;
			nb_fichiers_lvl++ ;
		}
	}

	//GpRectFill(NULL, &gpDraw[0], 0, 0, gpDraw[0].buf_w, gpDraw[0].buf_h, 0xff);	
	//gp_str_func.sprintf((char*)buffer,"url : %s (%i,%i)",g_path_curr,g_cnt_file,nb_fichiers_lvl) ;		
	//GpTextOut(NULL,&gpDraw[0],5,2,buffer,25);

	//while (key_pressed != 32) GpKeyGetEx(&key_pressed);


	pos = 0 ; // position actuelle sur le 1er fichier de puzzles
	old = -1 ;

	do
	{
		GpKeyGetEx(&key_pressed);
		
		if((key_pressed == 2)&&(pos != nb_fichiers_lvl-1)) pos++ ;
		if((key_pressed == 8)&&(pos != 0)) pos-- ;
				
		if(old != pos) // actualisation de l'aff
		{
			//GpRectFill(NULL, &gpDraw[0], 0, 0, gpDraw[0].buf_w, gpDraw[0].buf_h, 0xff);		
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259,181,img[1],0,0,259,181,0); // le cadre
			
			if(langue=='f') GpBitBlt(NULL,&gpDraw[nflip],62,53,195,37,img_fixe,0,0,195,37); // l'img fixe
			else GpBitBlt(NULL,&gpDraw[nflip],82,56,156,31,img_fixe,0,0,156,31); // l'img fixe
			
			for(i=0;i<nb_fichiers_lvl;i++)
			{
				if(i==pos) GPSPRINTF((char*)buffer,"-> %s",(char*)liste_fichier[fch_lvl_name[i]].name);
				else GPSPRINTF((char*)buffer,"    %s",(char*)liste_fichier[fch_lvl_name[i]].name);
						
				GpTextOut(NULL,&gpDraw[0],100,(150 - nb_fichiers_lvl * 10) + 10*i,buffer,15);
			} ;
			old = pos ;
			
			for(tmp=1;tmp<2000000;tmp++) ;
		}
				
	} while((key_pressed != 64)&&(key_pressed != 256)&&(key_pressed!=32)) ;
			
	while ((key_pressed == 64)||(key_pressed == 256)) GpKeyGetEx(&key_pressed);

	free(img_fixe) ;

	if(key_pressed != 32)
	{
		short pz_start = 0 ;
		
		short nb_min=0,nb_sec=0 ;
		
		//char buf[20] ;
		
		//short cw,ch,cx,cy ;
		
		GPSTRCPY(nom_fichier,(char*)liste_fichier[fch_lvl_name[pos]].name);
		
		GpTextOut(NULL,&gpDraw[0],5,g_cnt_file * 10 + 30,buffer,25);
		
		// charger_save(nom_fichier) ;
		//pz_start = 1 ;
		
		//charger_save(nom_fichier) ;
		
		fic.load=0 ;
		
		do {
			initialiser() ;
			num_puzzle = charger_fichier(nom_fichier,num_puzzle,pz_start) ;
			calculer_niveau(&niv) ;
			
			//time_start = GpTickCountGet() ;
			
			temps_zz = lancer_jeux() ;

			nb_min = (temps_zz)/60 ;
			nb_sec = (temps_zz - (nb_min * 60)) ;

			fic.save[num_puzzle].nb_try++ ;
			
			if(temps_zz>0) // si gagné
			{
				int best_time = (fic.save[num_puzzle].best_time[0] * 60) + fic.save[num_puzzle].best_time[1] ;
				
				fic.save[num_puzzle].nb_win++ ;
				fic.save[num_puzzle].last_time[0] = nb_min ;
				fic.save[num_puzzle].last_time[1] = nb_sec ;
				
				if((best_time == 0)||(best_time > ((nb_min * 60) + nb_sec))) // new time record
				{
					fic.save[num_puzzle].best_time[0] = nb_min ;
					fic.save[num_puzzle].best_time[1] = nb_sec ;
				}
				
				//sauver_save(nom_fichier,num_puzzle) ;
				sauver_save(nom_fichier,-1) ;
			}
			
			
			old = -2 ; // on force l'affichage
									
			GpSurfaceFlip(&gpDraw[0]);
				
			if(temps_zz) // si gagné
			{
				short end_file = 0 ; // drapeau de fin de fichier
				
				if(num_puzzle == (fic.nb_levels-1)) end_file=1 ; //  on arme le drapeau si dernier pz atteint
				
				continu = afficher_menu_gagne(end_file) ;
				if(continu == 1) num_puzzle = -1 ;
				if(continu == 2) num_puzzle++ ;
				if(continu == 3) exit = 1 ; 
			}
			else // si perdu
			{
				continu = afficher_menu_lose() ;
				if(continu == 2) exit = 1 ;
			}
		
			if(num_puzzle != -1) pz_start = num_puzzle ;
								
		} while(!exit) ;
	}
	
	while (key_pressed == 32) GpKeyGetEx(&key_pressed);
}

//////////////////////////////////////////////////////////////////////

void choisir_fond(void)
{
	short select=fond_select,cpt=0, old=0, old_select=fond_select  ;
	char  output[20] ;
	long tmp=1 ;
	
	GpSurfaceFlip(&gpDraw[0]);
	
	// on prend la liste des fichiers contenus ds le rep fond
	
	GPSTRCPY(g_path_curr, "gp:\\gpmm\\picross\\fond\\");
	g_cnt_file = 0 ;
	GpDirEnumList(g_path_curr, 0,30,(GPDIRENTRY*)&liste_fichier, &g_cnt_file);
	
	//gp_str_func.sprintf((char*)buffer,"url : %s (%i)",g_path_curr,g_cnt_file) ;

	do{
		GpKeyGetEx(&key_pressed);
		
		if((key_pressed == 2)&&(select != g_cnt_file-1)) select++ ;
		if((key_pressed == 8)&&(select != 1)) select-- ;
		
		if(select != old)
		{
			old = select ;
			
			GpRectFill(NULL, &gpDraw[0], 0, 0, gpDraw[0].buf_w, gpDraw[0].buf_h, 255);		
			
			if(langue=='f')
			{
				GpTextOut(NULL,&gpDraw[0],5,1,"choix du fond d'ecran du jeux",15);
				GpTextOut(NULL,&gpDraw[0],5,220,"A : voir   START : ok   B : annuler",15);
				
				if(select == 1) GpTextOut(NULL,&gpDraw[0],10,20,"-> aleatoire",15);
				else GpTextOut(NULL,&gpDraw[0],10,20,"    aleatoire",15);
			}
			else
			{
				GpTextOut(NULL,&gpDraw[0],5,1,"select the game's background",15);
				GpTextOut(NULL,&gpDraw[0],5,220,"A : view   START : ok   B : cancel",15);
				
				if(select == 1) GpTextOut(NULL,&gpDraw[0],10,20,"-> random",15);
				else GpTextOut(NULL,&gpDraw[0],10,20,"    random",15);				
			}
			
			for(cpt=2;cpt<g_cnt_file;cpt++)
			{
				//if(cpt-2 > 13) col=1 ;
				//else col = 0 ;
				
				if(select==cpt) GPSPRINTF(output,"-> %s",(char*)liste_fichier[cpt].name) ;
				else GPSPRINTF(output,"    %s",(char*)liste_fichier[cpt].name) ;
				
				if(cpt-2 <= 14) GpTextOut(NULL,&gpDraw[0],30,35 + 10*(cpt - 2),output,15);
				else GpTextOut(NULL,&gpDraw[0],170,35 + 10*(cpt - 17),output,15);
				
				//GpTextOut(NULL,&gpDraw[0],10 + 80*col,25 + 10*cpt,output,15);
			} ;
		}
		
		for(tmp=1;tmp<2000000;tmp++) ;

		if(key_pressed == 64)
		{
			fond_select = select ;
			charger_fond() ;
			GpBitBlt(NULL,&gpDraw[nflip],0,0,320,240,fond_ecran,0,0,320,240);
			
			while(key_pressed==64) GpKeyGetEx(&key_pressed) ;
			key_pressed = 0 ;
			while(key_pressed == 0) GpKeyGetEx(&key_pressed) ;
			old = 0 ;
			fond_select = old_select ;
			while(key_pressed != 0) GpKeyGetEx(&key_pressed) ;
			key_pressed=0 ;
		}
					
	} while((key_pressed!=256)&&(key_pressed!=32)) ;
	
	if(key_pressed == 256) fond_select = select ;
	
	while((key_pressed==32)||(key_pressed==256)) GpKeyGetEx(&key_pressed) ;
	
	GpBitBlt(NULL,&gpDraw[nflip],0,0,320,240,img[0],0,0,320,240);	
}

//////////////////////////////////////////////////////////////////////

void choisir_difficulte(void)
{
	short select = difficulte ;
	short select_max = 4 ;
	short old=0 ;
	long cpt ;
	short debut = 1 ;
	char url[100],buffer[100] ;
	unsigned char* menu[9] ;

	select++ ;

  do {

	if(langue == 'f')  gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\fr\\menu\\dif") ;
	else gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\en\\menu\\dif") ;
	
	gp_str_func.sprintf(url,"%s\\dif_fixe.gpg",buffer) ;
	menu[0] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\tapette.gpg",buffer) ;
	menu[1] = get_gpg(url) ;
	
	gp_str_func.sprintf(url,"%s\\tapette2.gpg",buffer) ;
	menu[2] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\humain.gpg",buffer) ;
	menu[3] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\humain2.gpg",buffer) ;
	menu[4] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\killer.gpg",buffer) ;
	menu[5] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\killer2.gpg",buffer) ;
	menu[6] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\quitter.gpg",buffer) ;
	menu[7] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\quitter2.gpg",buffer) ;
	menu[8] = get_gpg(url) ;

	do
	{		
		GpKeyGetEx(&key_pressed);
		
		//compteur ++ ;
		
		//if(compteur == 50) { afficher_terre(10,50) ; compteur=0 ; }
		
		// haut
		if((key_pressed == 8)&&(select != 1))
		{
			select-- ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		// bas
		if((key_pressed == 2)&&(select < select_max))
		{
			select++ ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		if(debut)
		{
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre	
			
			if(langue == 'f') GpBitBlt(NULL,&gpDraw[nflip],94,50,138,32,menu[0],0,0,138,32);			
			else GpBitBlt(NULL,&gpDraw[nflip],100,49,123,30,menu[0],0,0,123,30);			
			
			debut = 0 ;
		}
		
		if(old != select) // aff
		{
			if(langue == 'f')
			{
				// tapette
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],113,83,94,24,menu[1],0,0,94,24);
				else	GpBitBlt(NULL,&gpDraw[nflip],113,83,94,24,menu[2],0,0,94,24);
				
				// humain
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],119,112,85,21,menu[3],0,0,85,21);
				else	GpBitBlt(NULL,&gpDraw[nflip],119,112,85,21,menu[4],0,0,85,21);
				        
				// killer
				if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],122,137,81,25,menu[5],0,0,81,25);
				else	GpBitBlt(NULL,&gpDraw[nflip],122,137,81,25,menu[6],0,0,81,25);
					
				// retour
				if(select!=4) GpBitBlt(NULL,&gpDraw[nflip],123,170,79,18,menu[7],0,0,79,18);
				else	GpBitBlt(NULL,&gpDraw[nflip],123,170,79,18,menu[8],0,0,79,18);
			}
			else
			{
				// tapette
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],120,83,79,22,menu[1],0,0,79,22);
				else	GpBitBlt(NULL,&gpDraw[nflip],120,83,79,22,menu[2],0,0,79,22);
				
				// humain
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],121,112,80,21,menu[3],0,0,80,21);
				else	GpBitBlt(NULL,&gpDraw[nflip],121,112,80,21,menu[4],0,0,80,21);
				        
				// killer
				if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],122,137,81,25,menu[5],0,0,81,25);
				else	GpBitBlt(NULL,&gpDraw[nflip],122,137,81,25,menu[6],0,0,81,25);
					
				// retour
				if(select!=4) GpBitBlt(NULL,&gpDraw[nflip],131,167,59,25,menu[7],0,0,59,25);
				else	GpBitBlt(NULL,&gpDraw[nflip],131,167,59,25,menu[8],0,0,59,25);
			}
			old = select ;
			for(cpt=0;cpt!=3500000;cpt++) ;			
		}
		
	} while((key_pressed!=256)&&(key_pressed!=64)&&(key_pressed != 32)) ;

	for(cpt=0;cpt<=8;cpt++) free(menu[cpt]) ;

	GpPcmStop() ;
	GpPcmPlay((unsigned short*)start,start_length,0);		

	while ((key_pressed == 64)||(key_pressed == 256)) GpKeyGetEx(&key_pressed);

	if(key_pressed != 32)
	{
		if(select==1)
		{
			difficulte = 0 ;
		}
		
		if(select==2)
		{
			difficulte = 1 ;
		}
		
		if(select==3)
		{
			difficulte = 2 ;
		}
	}

	debut = 1 ; old=0 ;

} while((select != 4)&&(key_pressed != 32)) ; // tant que l'user n'a pas choisi 'back'
	
	while (key_pressed == 32) GpKeyGetEx(&key_pressed);
	

}

////////////////////////////////////////////////////////////

void choisir_vitesse(void)
{
	short select = vitesse ;
	short select_max = 4 ;
	short old=0 ;
	long cpt ;
	short debut = 1 ;
	char url[100],buffer[100] ;
	unsigned char* menu[9] ;
	
	select++ ;

  do {

	if(langue == 'f')  gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\fr\\menu\\vitesse") ;
	else gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\en\\menu\\vitesse") ;
	
	gp_str_func.sprintf(url,"%s\\vit_fix.gpg",buffer) ;
	menu[0] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\slow.gpg",buffer) ;
	menu[1] = get_gpg(url) ;
	
	gp_str_func.sprintf(url,"%s\\slow2.gpg",buffer) ;
	menu[2] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\normal.gpg",buffer) ;
	menu[3] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\normal2.gpg",buffer) ;
	menu[4] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\fast.gpg",buffer) ;
	menu[5] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\fast2.gpg",buffer) ;
	menu[6] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\quitter.gpg",buffer) ;
	menu[7] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\quitter2.gpg",buffer) ;
	menu[8] = get_gpg(url) ;

	do
	{		
		GpKeyGetEx(&key_pressed);
				
		// haut
		if((key_pressed == 8)&&(select != 1))
		{
			select-- ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		// bas
		if((key_pressed == 2)&&(select != select_max))
		{
			select++ ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		if(debut)
		{
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre	
			
			if(langue == 'f') GpBitBlt(NULL,&gpDraw[nflip],93,48,152,37,menu[0],0,0,152,37);
			else GpBitBlt(NULL,&gpDraw[nflip],93,48,138,37,menu[0],0,0,138,37);
			
			debut = 0 ;
		}
		
		if(old != select) // aff
		{
			if(langue == 'f')
			{
				// slow
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],129,86,65,22,menu[1],0,0,65,22);
				else	GpBitBlt(NULL,&gpDraw[nflip],129,86,65,22,menu[2],0,0,65,22);
				
				// normal
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],125,113,82,21,menu[3],0,0,82,21);
				else	GpBitBlt(NULL,&gpDraw[nflip],125,113,82,21,menu[4],0,0,82,21);
				        
				// fast
				if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],136,140,55,23,menu[5],0,0,55,23);
				else	GpBitBlt(NULL,&gpDraw[nflip],136,140,55,23,menu[6],0,0,55,23);
					
				// retour
				if(select!=4) GpBitBlt(NULL,&gpDraw[nflip],117,169,95,24,menu[7],0,0,95,24);
				else	GpBitBlt(NULL,&gpDraw[nflip],117,169,95,24,menu[8],0,0,95,24);
			}
			else
			{
				// slow
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],129,86,65,22,menu[1],0,0,65,22);
				else	GpBitBlt(NULL,&gpDraw[nflip],129,86,65,22,menu[2],0,0,65,22);
				
				// normal
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],125,113,82,21,menu[3],0,0,82,21);
				else	GpBitBlt(NULL,&gpDraw[nflip],125,113,82,21,menu[4],0,0,82,21);
				        
				// fast
				if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],136,140,55,23,menu[5],0,0,55,23);
				else	GpBitBlt(NULL,&gpDraw[nflip],136,140,55,23,menu[6],0,0,55,23);
					
				// retour
				if(select!=4) GpBitBlt(NULL,&gpDraw[nflip],139,167,48,23,menu[7],0,0,48,23);
				else	GpBitBlt(NULL,&gpDraw[nflip],139,167,48,23,menu[8],0,0,48,23);
			}
			old = select ;
			for(cpt=0;cpt!=3500000;cpt++) ;			
		}
		
	} while((key_pressed!=256)&&(key_pressed!=64)&&(key_pressed != 32)) ;

	for(cpt=0;cpt<=8;cpt++) free(menu[cpt]) ;

	GpPcmStop() ;
	GpPcmPlay((unsigned short*)start,start_length,0);		

	while ((key_pressed == 64)||(key_pressed == 256)) GpKeyGetEx(&key_pressed);

	if(key_pressed != 32)
	{
		if(select==1)
		{
			vitesse = 0 ;
		}
		
		if(select==2)
		{
			vitesse = 1 ;
		}
		
		if(select==3)
		{
			vitesse = 2 ;
		}
	}

	debut = 1 ; old=0 ;

} while((select != 4)&&(key_pressed != 32)) ; // tant que l'user n'a pas choisi 'back'
	
	while (key_pressed == 32) GpKeyGetEx(&key_pressed);
	

}

////////////////////////////////////////////////////////////



void menu_jeux(void)
{
	short select = 1 ;
	short select_max = 5 ;
	short old=0 ;
	long cpt ;
	short debut = 1 ;
	char url[100],buffer[100] ;
	unsigned char* menu[11] ;

  do {

	if(langue == 'f')  gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\fr\\menu\\game") ;
	else gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\en\\menu\\game") ;
	
	gp_str_func.sprintf(url,"%s\\jeu_fixe.gpg",buffer) ;
	menu[0] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\diffic.gpg",buffer) ;
	menu[1] = get_gpg(url) ;
	
	gp_str_func.sprintf(url,"%s\\diffic2.gpg",buffer) ;
	menu[2] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\jouab.gpg",buffer) ;
	menu[3] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\jouab2.gpg",buffer) ;
	menu[4] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\backg.gpg",buffer) ;
	menu[5] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\backg2.gpg",buffer) ;
	menu[6] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\them.gpg",buffer) ;
	menu[7] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\them2.gpg",buffer) ;
	menu[8] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\quitter.gpg",buffer) ;
	menu[9] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\quitter2.gpg",buffer) ;
	menu[10] = get_gpg(url) ;


	do
	{		
		GpKeyGetEx(&key_pressed);
		
		//compteur ++ ;
		
		//if(compteur == 50) { afficher_terre(10,50) ; compteur=0 ; }
		
		// haut
		if((key_pressed == 8)&&(select != 1))
		{
			select-- ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		// bas
		if((key_pressed == 2)&&(select != select_max))
		{
			select++ ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		if(debut)
		{
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre	
			
			if(langue=='f') GpBitBlt(NULL,&gpDraw[nflip],136,48,48,35,menu[0],0,0,48,35);
			else GpBitBlt(NULL,&gpDraw[nflip],118,50,76,30,menu[0],0,0,76,30);
			
			debut = 0 ;
		}
		
		if(old != select) // aff
		{
			if(langue == 'f')
			{
				// difficultée
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],51,89,97,26,menu[1],0,0,97,26);
				else	GpBitBlt(NULL,&gpDraw[nflip],51,89,97,26,menu[2],0,0,97,26);
				
				// jouabilitée
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],161,87,110,34,menu[3],0,0,110,34);
				else	GpBitBlt(NULL,&gpDraw[nflip],161,87,110,34,menu[4],0,0,110,34);
				        
				// arriere plan
				if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],49,131,109,25,menu[5],0,0,109,25);
				else	GpBitBlt(NULL,&gpDraw[nflip],49,131,109,25,menu[6],0,0,109,25);
					
				// theme
				if(select!=4) GpBitBlt(NULL,&gpDraw[nflip],183,128,76,27,menu[7],0,0,76,27);
				else	GpBitBlt(NULL,&gpDraw[nflip],183,128,76,27,menu[8],0,0,76,27);
				
				// quitter
				if(select!=5) GpBitBlt(NULL,&gpDraw[nflip],123,161,79,31,menu[9],0,0,79,31);
				else	GpBitBlt(NULL,&gpDraw[nflip],123,161,79,31,menu[10],0,0,79,31);
			}
			else
			{
				// difficultée
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],56,88,92,29,menu[1],0,0,92,29);
				else	GpBitBlt(NULL,&gpDraw[nflip],56,88,92,29,menu[2],0,0,92,29);
				
				// jouabilitée
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],159,86,103,37,menu[3],0,0,103,37);
				else	GpBitBlt(NULL,&gpDraw[nflip],159,86,103,37,menu[4],0,0,103,37);
				        
				// arriere plan
				if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],49,131,111,33,menu[5],0,0,111,33);
				else	GpBitBlt(NULL,&gpDraw[nflip],49,131,111,33,menu[6],0,0,111,33);
					
				// theme
				if(select!=4) GpBitBlt(NULL,&gpDraw[nflip],173,131,76,27,menu[7],0,0,76,27);
				else	GpBitBlt(NULL,&gpDraw[nflip],173,131,76,27,menu[8],0,0,76,27);
				
				// quitter
				if(select!=5) GpBitBlt(NULL,&gpDraw[nflip],131,163,59,25,menu[9],0,0,59,25);
				else	GpBitBlt(NULL,&gpDraw[nflip],131,163,59,25,menu[10],0,0,59,25);
			}
			old = select ;
			for(cpt=0;cpt!=3500000;cpt++) ;			
		}
		
	} while((key_pressed!=256)&&(key_pressed!=64)&&(key_pressed != 32)) ;

	for(cpt=0;cpt<=8;cpt++) free(menu[cpt]) ;

	GpPcmStop() ;
	GpPcmPlay((unsigned short*)start,start_length,0);		

	while ((key_pressed == 64)||(key_pressed == 256)) GpKeyGetEx(&key_pressed);

	if(key_pressed != 32)
	{
		if(select==1)
		{
			choisir_difficulte() ;
		}
		
		if(select==2)
		{
			choisir_vitesse() ;
		}
		
		if(select==3)
		{
			choisir_fond() ;			
		}

		if(select==4)
		{
			choisir_theme() ;
			charger_theme() ;
		}
	}

	debut = 1 ; old=0 ;

} while((select != 5)&&(key_pressed != 32)) ; // tant que l'user n'a pas choisi 'back'
	
	while (key_pressed == 32) GpKeyGetEx(&key_pressed);



	
}


void sauver_options(void)
{
	F_HANDLE file;
	char buffer[20] ;
	
	GpFileCreate("gp:\\gpmm\\picross\\wop.sav",ALWAYS_CREATE, &file);
	
	GpFileWrite(file,theme_name,20);
	gp_str_func.sprintf(buffer,"%c",langue) ;
	GpFileWrite(file,buffer,1);
	
	if(fond_select < 9)
	{
		gp_str_func.sprintf(buffer,"0%i",fond_select) ;
		GpFileWrite(file,buffer,2);
	}
	else
	{
		gp_str_func.sprintf(buffer,"%i",fond_select) ;
		GpFileWrite(file,buffer,2);
	}

		gp_str_func.sprintf(buffer,"%i",difficulte) ;
		GpFileWrite(file,buffer,1);

		gp_str_func.sprintf(buffer,"%i",vitesse) ;
		GpFileWrite(file,buffer,1);

	GpFileClose(file);
}

void charger_options(void)
{
	F_HANDLE file;
	ERR_CODE err_code;
	char buffer[21], buf ;
	unsigned long m_size=0 ; //, total_size=0;
	
	
	err_code = GpFileOpen("gp:\\gpmm\\picross\\wop.sav",OPEN_R,&file) ;
	
	if (err_code != SM_OK) // fichier de save inexistant
	{
		choisir_langue();
		sauver_options() ;
	}
	else
	{					
		// theme
		GPSTRCPY(theme_name,"") ;
		GpFileRead(file,theme_name,20,&m_size);
		//total_size += m_size;

		// langue
		GpFileRead(file,buffer,1,&m_size);
		//total_size += m_size;
		langue = buffer[0] ;

		// le fond
		GPSTRCPY(buffer,"") ;
		GpFileRead(file,buffer,2,&m_size);
		//total_size += m_size;
		fond_select = atoi(buffer) ;
		
		// la difficulté
		buf='1' ;
		GpFileRead(file,&buf,1,&m_size);
		//total_size += m_size;
		difficulte = atoi(&buf) ;
		 
		// la vitesse
		buf='1' ;
		GpFileRead(file,&buf,1,&m_size);
		//total_size += m_size;
		vitesse = atoi(&buf) ;
		
		GpFileClose(file) ;
	}
}

void sauver_puzzle(char nom_fichier[8])
{
	F_HANDLE file;
	char buffer[20] ;
	
	GpFileCreate("gp:\\gpmm\\picross\\wop.sav",ALWAYS_CREATE, &file);
	
	GpFileWrite(file,theme_name,20);
	gp_str_func.sprintf(buffer,"%c",langue) ;
	GpFileWrite(file,buffer,1);
	
	if(fond_select < 9)
	{
		gp_str_func.sprintf(buffer,"0%i",fond_select) ;
		GpFileWrite(file,buffer,2);
	}
	else
	{
		gp_str_func.sprintf(buffer,"%i",fond_select) ;
		GpFileWrite(file,buffer,2);
	}

		gp_str_func.sprintf(buffer,"%i",difficulte) ;
		GpFileWrite(file,buffer,1);

		gp_str_func.sprintf(buffer,"%i",vitesse) ;
		GpFileWrite(file,buffer,1);

	GpFileClose(file);
}



void lancer_options(void)
{
	short select = 1 ;
	short select_max = 4 ;
	short old=0 ;
	long cpt ;
	short debut = 1 ;
	char url[100],buffer[100] ;
	unsigned char* menu[9] ;

  do {

	if(langue == 'f')  gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\fr\\menu\\options") ;
	else gp_str_func.sprintf(buffer,"gp:\\gpmm\\picross\\gfx\\en\\menu\\options") ;
	
	gp_str_func.sprintf(url,"%s\\opt_fixe.gpg",buffer) ;
	menu[0] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\jeu.gpg",buffer) ;
	menu[1] = get_gpg(url) ;
	
	gp_str_func.sprintf(url,"%s\\jeu2.gpg",buffer) ;
	menu[2] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\languag.gpg",buffer) ;
	menu[3] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\languag2.gpg",buffer) ;
	menu[4] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\regles.gpg",buffer) ;
	menu[5] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\regles2.gpg",buffer) ;
	menu[6] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\retour.gpg",buffer) ;
	menu[7] = get_gpg(url) ;

	gp_str_func.sprintf(url,"%s\\retour2.gpg",buffer) ;
	menu[8] = get_gpg(url) ;

	do
	{		
		GpKeyGetEx(&key_pressed);
		
		//compteur ++ ;
		
		//if(compteur == 50) { afficher_terre(10,50) ; compteur=0 ; }
		
		// haut
		if((key_pressed == 8)&&(select != 1))
		{
			select-- ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		// bas
		if((key_pressed == 2)&&(select != select_max))
		{
			select++ ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		if(debut)
		{
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre	
			
			GpBitBlt(NULL,&gpDraw[nflip],108,49,102,33,menu[0],0,0,102,33);			
			
			debut = 0 ;
		}
		
		if(old != select) // aff
		{
			if(langue == 'f')
			{
				// regles
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],121,90,75,18,menu[5],0,0,75,18);
				else	GpBitBlt(NULL,&gpDraw[nflip],121,90,75,18,menu[6],0,0,75,18);
				
				// jeu
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],135,115,41,18,menu[1],0,0,41,18);
				else	GpBitBlt(NULL,&gpDraw[nflip],135,115,41,18,menu[2],0,0,41,18);
				        
				// language
				if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],111,143,100,18,menu[3],0,0,100,18);
				else	GpBitBlt(NULL,&gpDraw[nflip],111,143,100,18,menu[4],0,0,100,18);
					
				// retour
				if(select!=4) GpBitBlt(NULL,&gpDraw[nflip],122,173,75,19,menu[7],0,0,75,19);
				else	GpBitBlt(NULL,&gpDraw[nflip],122,173,75,19,menu[8],0,0,75,19);
			}
			else
			{
				// regles
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],129,90,60,17,menu[5],0,0,60,17);
				else	GpBitBlt(NULL,&gpDraw[nflip],129,90,60,17,menu[6],0,0,60,17);				
				
				// jeu
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],126,119,62,17,menu[1],0,0,62,17);
				else	GpBitBlt(NULL,&gpDraw[nflip],126,119,62,17,menu[2],0,0,62,17);
				        
				// language
				if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],109,144,98,18,menu[3],0,0,98,18);
				else	GpBitBlt(NULL,&gpDraw[nflip],109,144,98,18,menu[4],0,0,98,18);
					
				// retour
				if(select!=4) GpBitBlt(NULL,&gpDraw[nflip],133,171,52,19,menu[7],0,0,52,19);
				else	GpBitBlt(NULL,&gpDraw[nflip],133,171,52,19,menu[8],0,0,52,19);
			}
			old = select ;
			for(cpt=0;cpt!=3500000;cpt++) ;			
		}
		
	} while((key_pressed!=256)&&(key_pressed!=64)&&(key_pressed != 32)) ;

	for(cpt=0;cpt<=8;cpt++) free(menu[cpt]) ;

	GpPcmStop() ;
	GpPcmPlay((unsigned short*)start,start_length,0);		

	while ((key_pressed == 64)||(key_pressed == 256)) GpKeyGetEx(&key_pressed);

	if(key_pressed != 32)
	{
		if(select==1)
		{
			unsigned char * txt, * fix ;
			
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre
			
			if(langue == 'f')
			{
				txt = get_gpg("gp:\\gpmm\\picross\\gfx\\fr\\rulez\\txt.gpg") ;
				fix = get_gpg("gp:\\gpmm\\picross\\gfx\\fr\\rulez\\fix.gpg") ;
				
				GpBitBlt(NULL,&gpDraw[nflip],129,47,64,32,fix,0,0,64,32);
				GpBitBlt(NULL,&gpDraw[nflip],46,76,228,116,txt,0,0,228,116);
			}
			else
			{
				txt = get_gpg("gp:\\gpmm\\picross\\gfx\\en\\rulez\\txt.gpg") ;
				fix = get_gpg("gp:\\gpmm\\picross\\gfx\\en\\rulez\\fix.gpg") ;	
				
				GpBitBlt(NULL,&gpDraw[nflip],128,46,54,24,fix,0,0,54,24);
				GpBitBlt(NULL,&gpDraw[nflip],46,70,226,123,txt,0,0,226,123);
			}
				
			while((key_pressed!=256)&&(key_pressed!=64)) GpKeyGetEx(&key_pressed);
			
			free(fix) ;
			free(txt) ;
		}
		
		if(select==2)
		{
			menu_jeux() ;
		}
		
		if(select==3)
		{
			choisir_langue() ;
		}

		if(select==4)
		{
		}
	}

	debut = 1 ; old=0 ;

} while((select != 4)&&(key_pressed != 32)) ; // tant que l'user n'a pas choisi 'back'
	
	sauver_options() ;
	
	while (key_pressed == 32) GpKeyGetEx(&key_pressed);

}

//////////////////////////////////////////////////////////////////////

void lancer_menu(void)
{
	short select = 1 ;
	short select_max = 4 ;
	short old=0 ;
	long cpt ;
	short debut = 1 ;
	
	do
	{		
		GpKeyGetEx(&key_pressed);
				
		// haut
		if((key_pressed == 8)&&(select != 1))
		{
			select-- ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		// bas
		if((key_pressed == 2)&&(select != select_max))
		{
			select++ ;
			
			GpPcmStop() ;
			GpPcmPlay((unsigned short*)men_move,men_move_length,0);
		}
		
		if(debut)
		{
			GpBitBlt(NULL,&gpDraw[nflip],0,0,320,240,img[0],0,0,320,240);
			GpTransBlt(NULL,&gpDraw[nflip],30,30,259+30,181+30,img[1],0,0,259,181,0); // le cadre	
			debut = 0 ;
		}
		
		if(old != select) // aff
		{
			
			if(langue == 'f')
			{
				// jeux aléatoire	
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],95,51,135,34,img[2],0,0,135,34);
				else	GpBitBlt(NULL,&gpDraw[nflip],95,51,135,34,img[3],0,0,135,34);
				        
				// charger puzzle
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],87,93,150,35,img[4],0,0,150,35);
				else	GpBitBlt(NULL,&gpDraw[nflip],87,93,150,35,img[5],0,0,150,35);
				
				// options
				if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],123,131,75,27,img[6],0,0,75,27);
				else	GpBitBlt(NULL,&gpDraw[nflip],123,131,75,27,img[7],0,0,75,27);
	
				// exit
				if(select!=4) GpBitBlt(NULL,&gpDraw[nflip],119,163,77,28,img2[0],0,0,77,28);
				else	GpBitBlt(NULL,&gpDraw[nflip],119,163,77,28,img2[1],0,0,77,28);

			}
			else
			{
				// jeux aléatoire	
				if(select!=1) GpBitBlt(NULL,&gpDraw[nflip],98,53,128,33,img[2],0,0,128,33);
				else	GpBitBlt(NULL,&gpDraw[nflip],98,53,128,33,img[3],0,0,128,33);
				        
				// charger puzzle
				if(select!=2) GpBitBlt(NULL,&gpDraw[nflip],104,90,113,29,img[4],0,0,113,29);
				else	GpBitBlt(NULL,&gpDraw[nflip],104,90,113,29,img[5],0,0,113,29);
				
				// options
				if(select!=3) GpBitBlt(NULL,&gpDraw[nflip],124,127,75,27,img[6],0,0,75,27);
				else	GpBitBlt(NULL,&gpDraw[nflip],124,127,75,27,img[7],0,0,75,27);
	
				// exit
				if(select!=4) GpBitBlt(NULL,&gpDraw[nflip],137,163,47,25,img2[0],0,0,47,25);
				else	GpBitBlt(NULL,&gpDraw[nflip],137,163,47,25,img2[1],0,0,47,25);
			}
			old = select ;
			for(cpt=0;cpt!=3500000;cpt++) ;			
		}
		
	} while((key_pressed!=256)&&(key_pressed!=64)&&(key_pressed != 32)) ;

	if(key_pressed != 32)
	{
		GpPcmStop() ;
		GpPcmPlay((unsigned short*)start,start_length,0);		
	
		while ((key_pressed == 64)||(key_pressed == 256)) GpKeyGetEx(&key_pressed);
	
		choix = select ;
	
		if(select == 1) // jeux aleatoire
		{
			jeux_aleatoire() ;
		}
		
		if(select == 2) // charger
		{
			charger_jeux() ;
		}
		
		if(select == 3) // options
		{
			lancer_options() ;
		}
		
		if(select == 4) //reboot
		{
			//confirmation
			
			short cw,ch,cx,cy ;
			char buf[50] ;
			
			temps -= temps_en_moins * 60 ;
			
			if(langue == 'f') gp_str_func.sprintf((char*)buf,"la Gp va redemarrer  A:Ok B:Annuler\0");
			else gp_str_func.sprintf((char*)buf,"this will reboot  A:Ok B:Cancel\0");
	  		
			cw = GpTextWidthGet(buf);
			ch = GpTextHeightGet(buf);
			cx = (LCD_WIDTH - cw) / 2;
			cy = (LCD_HEIGHT - ch) / 2;
			
			GpRectFill(NULL, &gpDraw[nflip], cx - 7, cy - 5,cw + 13,32,37);
			GpRectFill(NULL, &gpDraw[nflip], cx - 6, cy - 4,cw + 11,30,58);
			GpTextOut(NULL, &gpDraw[nflip], cx, cy, buf, 37);
			
			while((key_pressed!=64)&&(key_pressed != 32)) GpKeyGetEx(&key_pressed);
			
			if(key_pressed == 64) GpAppExit();
			
			while(key_pressed == 32) GpKeyGetEx(&key_pressed);
			
			debut=1 ; // pour reafficher le fond
		}
	}
	else lancer_intro() ;
}

////////////////////////////////////////////////////////////



////////////////////////////////////////////////////////////

