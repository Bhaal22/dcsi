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
 * wav.h
 * version - v1.0
 *
 * (c) 2004 DreamTeamCast
 *
 *--------------------=+ Drinving Curse Syndrom : Ignition +=--------------------
*/
#pragma once

#include <kos.h>

class wav
{
public:
    wav(char *song);

    void play(int vol = 255, int pan = 128);
    /* Unload a single sample */
    void unload();

    /* Unload all loaded samples and free their SPU RAM */
    static void unload_all();

    void stop();

protected:
    sfxhnd_t fileWav;
};

