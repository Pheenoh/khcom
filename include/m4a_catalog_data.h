#ifndef GUARD_M4A_CATALOG_DATA_H
#define GUARD_M4A_CATALOG_DATA_H

#include "m4a.h"

extern MusicPlayerTrack gMPlayTracks0[];
extern MusicPlayerTrack gMPlayTracks1[];
extern MusicPlayerTrack gMPlayTracks2[];
extern MusicPlayerTrack gMPlayTracks3[];
extern MusicPlayerTrack gMPlayTracks4[];
extern MusicPlayerTrack gMPlayTracks5[];
extern MusicPlayerTrack gMPlayTracks6[];
extern MusicPlayerTrack gMPlayTracks7[];
extern MusicPlayerTrack gMPlayTracks8[];
extern MusicPlayerTrack gMPlayTracks9[];
extern MusicPlayerTrack gMPlayTracks10[];
extern MusicPlayerTrack gMPlayTracks11[];
extern MusicPlayerTrack gMPlayTracks12[];
extern MusicPlayerTrack gMPlayTracks16[];
extern MusicPlayerTrack gMPlayTracks17[];
extern MusicPlayerTrack gMPlayTracks18[];
extern MusicPlayerTrack gMPlayTracks19[];
extern MusicPlayerTrack gMPlayTracks20[];
extern MusicPlayerTrack gMPlayTracks21[];
extern MusicPlayerTrack gMPlayTracks22[];
extern MusicPlayerTrack gMPlayTracks23[];
extern MusicPlayerTrack gMPlayTracks24[];
extern MusicPlayerTrack gMPlayTracks25[];

#ifndef M4A_CATALOG_NO_PLAYER_EXTERNS
extern MusicPlayerInfo gMPlayInfo_BGM;
extern MusicPlayerInfo gUnk_0203D990;
extern MusicPlayerInfo gUnk_0203D9D0;
extern MusicPlayerInfo gUnk_0203DA10;
extern MusicPlayerInfo gUnk_0203DA50;
extern MusicPlayerInfo gUnk_0203DA90;
extern MusicPlayerInfo gUnk_0203DAD0;
extern MusicPlayerInfo gUnk_0203DB50;
extern MusicPlayerInfo gUnk_0203DB90;
extern MusicPlayerInfo gUnk_0203DBD0;
extern MusicPlayerInfo gUnk_0203DC10;
extern MusicPlayerInfo gUnk_0203DC50;
extern MusicPlayerInfo gUnk_0203DC90;
extern MusicPlayerInfo gUnk_0203DCD0;
extern MusicPlayerInfo gUnk_0203DD10;
extern MusicPlayerInfo gUnk_0203DD50;
extern MusicPlayerInfo gUnk_0203DD90;
extern MusicPlayerInfo gUnk_0203DDD0;
extern MusicPlayerInfo gUnk_0203DE10;
extern MusicPlayerInfo gUnk_0203DE50;
extern MusicPlayerInfo gUnk_0203DEA0;
extern MusicPlayerInfo gUnk_0203DEE0;
extern MusicPlayerInfo gUnk_0203DF20;
#endif

void RealClearChain(void* work);
void SoundMainBTM(void* work);
void ply_bend(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_bendr(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_fine(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_goto(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_keysh(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_lfodl(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_modt(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_pan(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_patt(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_pend(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_port(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_prio(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_rept(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_tempo(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_tune(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_voice(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_vol(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_xatta(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_xdeca(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_xiecl(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_xiecv(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_xleng(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_xrele(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_xsust(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_xswee(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_xtype(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_xwave(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);
void ply_xxx(MusicPlayerInfo* mplayInfo, MusicPlayerTrack* track);

#endif
