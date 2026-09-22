#include "save.h"

const u8* gSaveSignature = gSaveSignatureText;

const u8 gSaveSignatureText[SAVE_SIGNATURE_SIZE + 1] =
#ifdef VERSION_EU
    "KHCOM_BACKUP_VER00000013";
#else
    "KHCOM_BACKUP_VER00000012";
#endif
