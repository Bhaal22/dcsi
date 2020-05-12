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

class video
{
public:
    video(char *v);

    void play(int loop = 1);

protected:
    char *vid;

private:
    static int FrameCB();
};
