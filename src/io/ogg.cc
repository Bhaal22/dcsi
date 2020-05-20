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

#ifdef __cplusplus //include the jpeg library as a C file.
extern "C"
{
#endif
#include <oggvorbis/sndoggvorbis.h>
#ifdef __cplusplus
}
#endif

#include <kos.h>
#include "ogg.h"

ogg::ogg(const char *s)
    : song(s)
{
}

void ogg::init()
{
}

void ogg::play(int loop)
{
    sndoggvorbis_start(song, loop);
}

char *ogg::getArtist()
{
    sndoggvorbis_getartist();
}

char *ogg::getTitle()
{
    return sndoggvorbis_gettitle();
}

char *ogg::getGenre()
{
    return sndoggvorbis_getgenre();
}

void ogg::setVolume(int vol)
{
    sndoggvorbis_volume(vol);
}

void ogg::stop()
{
    sndoggvorbis_stop();
}

void ogg::shutDown()
{
    sndoggvorbis_shutdown();
}
