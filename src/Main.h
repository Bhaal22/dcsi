/**-----------------------------------------------------------------------------
 * Release - KallistiOS 1.2.0
 *
 * Main.h : All header files necessary are declared here
 *
 * 
 * version - v1.0
 *
 * (c) 2004 DreamTeamCast
 * 
 *--------------------=+ Drinving Curse Syndrom : Ignition +=--------------------
*/

#ifndef __MAINH__
#define __MAINH__

/* kos include */
#include <kos.h>

/* OpenGl includes */
#include <GL/gl.h>
#include <GL/glu.h>

/* Math include */
#include <math.h>

/* Png et Pcx includes */
#include <png/png.h>
#include <zlib/zlib.h>
#include <pcx/pcx.h>

/* LibJpeg Includes */
#ifdef __cplusplus      //include the jpeg library as a C file.
extern "C"{
#endif
#include<libjpeg/jpeglib.h>
#include <libjpeg/jerror.h>	
#ifdef __cplusplus
}
#endif
#include <math3d.h>


#define PNG 1
#define PCX 2
#define SIZEMAP 256
#define NJPEG 0
#define JPEG 1 


class myWorld{
 public:
  static void screenShot(){
    printf("shot launch!\n");
    static int count=1;
    char buffer[256];
    sprintf(buffer,"/pc/tmp/shot%4d.ppm", count++);
    vid_screen_shot(buffer);
    printf("shot done!");
  };
  static bool Init(int);
  
};



#endif
