#include <stddef.h>
#include "registration_data.h"
#include "backupstat_data.h"
#include "worldwarp_catalog_assets.h"

BackupStatEntry gUnk_099937E4[6] __attribute__((section(".data_gUnk_099937E4"))) = {
#if defined(VERSION_US)
    {gBackupTextUs_09993864, 2},
    {gBackupTextUs_09993854, 64},
    {gBackupTextUs_09993844, 64},
    {gBackupTextUs_09993834, 512},
    {gBackupTextUs_09993824, 512},
    {gBackupTextUs_09993814, 4},
#elif defined(VERSION_JP)
    {gBackupTextJp_09948378, 2},
    {gBackupTextJp_09948368, 64},
    {gBackupTextJp_09948358, 64},
    {gBackupTextJp_09948348, 512},
    {gBackupTextJp_09948338, 512},
    {gBackupTextJp_09948328, 4},
#elif defined(VERSION_EU)
    {gBackupTextEu_09999B20, 2},
    {gBackupTextEu_09999B10, 64},
    {gBackupTextEu_09999B00, 64},
    {gBackupTextEu_09999AF0, 512},
    {gBackupTextEu_09999AE0, 512},
    {gBackupTextEu_09999AD0, 4},
#endif
};

const char* gUnk_09EF9668[3] __attribute__((section(".data_gUnk_09EF9668"))) = {
#if defined(VERSION_US)
    gBackupTextUs_099937DC,
    gBackupTextUs_099937D4,
    gBackupTextUs_099937CC,
#elif defined(VERSION_JP)
    gBackupTextJp_099482F0,
    gBackupTextJp_099482E8,
    gBackupTextJp_099482E0,
#elif defined(VERSION_EU)
    gBackupTextEu_09999A98,
    gBackupTextEu_09999A90,
    gBackupTextEu_09999A88,
#endif
};
