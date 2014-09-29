/*
#-----------------------------------------------------------------------------
# Release - KallistiOS 1.2.0
#
# Makefile
# version - v1.0
#
# (c) 2004 DreamTeamCast
# 
#--------------------=+ Drinving Curse Syndrom : Ignition +=--------------------
*/

#include <kos.h>
#include <vfdc.h>

#include "video.h"

video::video(char * v) : vid(v) {}

void video::play (int loop) {
  play_mpeg(vid, loop, FrameCB,VMODE_NTSC);
}

int video::FrameCB()
{
  cont_cond_t cond;
  
  if (cont_get_cond(maple_first_controller(), &cond) < 0)
    return FRAMECB_VIDEO_NEXTFRAME;
  if (!(cond.buttons & CONT_START))
    return FRAMECB_VIDEO_STOP;
  
  return FRAMECB_VIDEO_NEXTFRAME;
}
