/**-----------------------------------------------------------------------------
 * Release - KallistiOS 1.2.0
 *
 * This class use the liboggvorbisplay library
 * to playback audio data encoded with the wav codec.
 *
 * NOTE:
 * You have to put an wav File into the RAM Disk which should be called
 * like the filename in this sourcecode.
 *
 * wav.cc
 * version - v1.0
 *
 * (c) 2004 DreamTeamCast
 *
 *--------------------=+ Drinving Curse Syndrom : Ignition +=--------------------
*/

#include <kos.h>
#include <oggvorbis/sndoggvorbis.h>
#include "wav.h"

wav::wav(const char *song)
{
    fileWav = snd_sfx_load(song);
}

void wav::play(int vol, int pan)
{
    snd_sfx_play(fileWav, vol, pan);
}

/* Unload a single sample */
void wav::unload() { snd_sfx_unload(fileWav); }

/* Unload all loaded samples and free their SPU RAM */
void wav::unload_all() { snd_sfx_unload_all(); }

void wav::stop()
{
    sndoggvorbis_stop();
}
