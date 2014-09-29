/**-----------------------------------------------------------------------------
 * Release - KallistiOS 1.2.0
 *
 * This class use the liboggvorbisplay library
 * to playback audio data encoded with the Vorbis codec (.ogg).
 *
 * NOTE:
 * You have to put an Ogg File into the RAM Disk which should be called
 * like the filename in this sourcecode.
 *
 * ogg.cc
 * version - v1.0
 *
 * (c) 2004 DreamTeamCast
 * 
 *--------------------=+ Drinving Curse Syndrom : Ignition +=--------------------
*/
#ifndef __OGGH__
#define __OGGH__

#include <oggvorbis/sndoggvorbis.h>

class ogg{
 public :
 ogg(char * song);
 
 static void init();
 
 void play (int loop);
 
 char * getArtist();
 char * getTitle();
 char * getGenre();   
 
 void setVolume(int vol);
   
 void stop();
 static void shutDown();
 
 protected:
 char *song;
};

//#include "ogg.cc"


#endif
