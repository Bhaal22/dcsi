#ifndef __MENU2DH__
#define __MENU2DH__

#include <kos.h>
#include <png/png.h>
#include <zlib/zlib.h>
#include <dcplib/fnt.h>
#include "alllcdtex.h"
#include "ogg.h"
#include "wav.h"
#include "perso.h"
#include "video.h"

#define menu 0
#define team 1
#define carlos 2
#define momo 3
#define noel 4
#define select 5
#define one 6
#define two 7
#define three 8
#define go 9
#define fondgris 10
#define fondcolor 11
#define pause 12

class Menu2D {
  
 public:
  /*Constructeur et destructeur*/
  Menu2D();
  ~Menu2D();
  
  /*Methodes graphiques*/
  /*Affiche le nom de la team*/
  void draw_intro(void);
  void draw_perso(void);
  void draw_menu(void);
  void draw_frame(void);
  void draw_game(void);
  void draw_save_init(void);
  void draw_record(void);
  void draw_pause(void);
  void draw_perso_choisi(void);
  void draw_genEric(int);
  void draw_gen_font(int);

  /*Gestion Ecran VMU*/

  void vmu_lcd_update(int);
  void write_on_vmu(void);
  int check_savefile(void);
  char* read_record_on_vmu(void);

  /*ScreenShot*/
  void screenShot(void);

  /*Modificateurs*/
  void Resetall(void);
  void Resetfont(void);
  void Setpos(int newpos){pos=newpos;}
  void Setposcadre(int newposcadre){poscadre=newposcadre;}
  void Setposy(float newval){posy=newval;}
  void Setposcadrex(float newval){poscadrex=newval;}
  void Setpospause(int val){pospause=val;}

  /*Accesseurs*/
  int Getpos(void){return pos;}
  int Getposcadre(void){return poscadre;}
  float Getposy(void){return posy;}
  float Getposcadrex(void){return poscadrex;}
  int Getpospause(void){return pospause;}

  private :
    
    /*Méthodes internes*/
    void draw_alp_tex_box(float x1,float y1,float x2,float y2,float z,int taille,pvr_ptr_t texture,float alpha);
  void drawFont (char * lemot,int taille,int posx,int posy,float r,float g,float b);
  void draw_poly_box(float x1, float y1, float x2, float y2, float z,float a1, float r1, float g1, float b1,float a2, float r2, float g2, float b2);
  void draw_tr_intro(float alpha);
  
   /*Attributs*/
  Perso  *pers_carlos,*pers_momo,*pers_noel;
  fntRenderer * monText;
  pvr_ptr_t * lesTextures;
  fntTexFont * Mesfonts;
  int pos;
  int pospause;
  float posy;
  int poscadre;
  float poscadrex;
  int filter_mode;
};

#endif
