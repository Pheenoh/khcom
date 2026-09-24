#include "jiminy_data.h"
#include "jiminy_text_assets.h"
#include "map_runtime.h"
#include "map_index_assets.h"
#include "map_text_data.h"
#include "map_text_assets.h"

#ifdef VERSION_EU

const JiminyTextChar gUnkEu_0888E4D4[17] = { 'O', 'l', 'y', 'm', 'p', 'u', 's', ' ', 'C', 'o', 'l', 'i', 's', 'e', 'u', 'm', 0 };

const JiminyTextChar gUnkEu_0888E4E5[20] = { 'C', 'o', 'l', 'i', 's', 0xe9, 'e', ' ', 'd', 'e', ' ', 'l', '\'', 'O', 'l', 'y', 'm', 'p', 'e', 0 };

const JiminyTextChar gUnkEu_0888E4F9[17] = { 'A', 'r', 'e', 'n', 'a', ' ', 'd', 'e', 's', ' ', 'O', 'l', 'y', 'm', 'p', 's', 0 };

const JiminyTextChar gUnkEu_0888E50A[16] = { 'I', 'l', ' ', 'M', 'o', 'n', 't', 'e', ' ', 'O', 'l', 'i', 'm', 'p', 'o', 0 };

const JiminyTextChar gUnkEu_0888E51A[19] = { 'C', 'o', 'l', 'i', 's', 'e', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'i', 'm', 'p', 'o', 0 };

asm(".align 2, 0\n.include \"asm/eu/jiminy_eu_localized_name_data.inc\"");

const u8 gMapWorldNameTextEu_08892680[22] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'H', 'a', 'l', 'l', 0 };

const u8 gMapWorldNameTextEu_08892696[22] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'h', 'a', 'l', 'l', 0 };

const u8 gMapWorldNameTextEu_088926AC[29] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', '.', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', 'H', 'a', 'l', 'l', 'e', 0 };

const u8 gMapWorldNameTextEu_088926C9[23] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', 'a', 't', 'r', 'i', 'o', 0 };

const u8 gMapWorldNameTextEu_088926E0[26] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'h', 'a', 'l', 'l', 0 };

const LocalizedText gMapWorldNameEu_088926FC = { {
    gMapWorldNameTextEu_08892680,
    gMapWorldNameTextEu_08892696,
    gMapWorldNameTextEu_088926AC,
    gMapWorldNameTextEu_088926C9,
    gMapWorldNameTextEu_088926E0,
} };

asm(".include \"asm/eu/jiminy_eu_room_name_data.inc\"");

const u8 gMapNameTextEu_08893324[14] = { 'U', 'n', 'k', 'n', 'o', 'w', 'n', ' ', 'P', 'l', 'a', 'c', 'e', 0 };

const u8 gMapNameTextEu_08893332[16] = { 'S', 'e', 'c', 't', 'e', 'u', 'r', ' ', 'i', 'n', 'c', 'o', 'n', 'n', 'u', 0 };

const u8 gMapNameTextEu_08893342[16] = { 'U', 'n', 'b', 'e', 'k', 'a', 'n', 'n', 't', 'e', 'r', ' ', 'O', 'r', 't', 0 };

const u8 gMapNameTextEu_08893352[13] = { 'L', 'u', 'o', 'g', 'o', ' ', 'I', 'g', 'n', 'o', 't', 'o', 0 };

const u8 gMapNameTextEu_0889335F[16] = { 'T', 'i', 'e', 'r', 'r', 'a', ' ', 'd', 'e', ' ', 'n', 'a', 'd', 'i', 'e', 0 };

const LocalizedText gMapNameEu_08893370 = { {
    gMapNameTextEu_08893324,
    gMapNameTextEu_08893332,
    gMapNameTextEu_08893342,
    gMapNameTextEu_08893352,
    gMapNameTextEu_0889335F,
} };

const u8 gMapNameTextEu_08893384[12] = { 'H', 'i', 'd', 'd', 'e', 'n', ' ', 'R', 'o', 'o', 'm', 0 };

const u8 gMapNameTextEu_08893390[14] = { 'S', 'a', 'l', 'l', 'e', ' ', 's', 'e', 'c', 'r', 0xe8, 't', 'e', 0 };

const u8 gMapNameTextEu_0889339E[17] = { 'V', 'e', 'r', 's', 't', 'e', 'c', 'k', 't', 'e', 'r', ' ', 'R', 'a', 'u', 'm', 0 };

const u8 gMapNameTextEu_088933AF[16] = { 'S', 't', 'a', 'n', 'z', 'a', ' ', 'N', 'a', 's', 'c', 'o', 's', 't', 'a', 0 };

const u8 gMapNameTextEu_088933BF[18] = { 'H', 'a', 'b', 'i', 't', 'a', 'c', 'i', 0xf3, 'n', ' ', 'o', 'c', 'u', 'l', 't', 'a', 0 };

const LocalizedText gMapNameEu_088933D4 = { {
    gMapNameTextEu_08893384,
    gMapNameTextEu_08893390,
    gMapNameTextEu_0889339E,
    gMapNameTextEu_088933AF,
    gMapNameTextEu_088933BF,
} };

const u8 gMapNameTextEu_088933E8[29] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'F', 'i', 'r', 's', 't', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_08893405[26] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '1', 0 };

const u8 gMapNameTextEu_0889341F[33] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '1', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_08893440[27] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '1', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_0889345B[36] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 'p', 'r', 'i', 'm', 'e', 'r', 'a', 0 };

const LocalizedText gMapNameEu_08893480 = { {
    gMapNameTextEu_088933E8,
    gMapNameTextEu_08893405,
    gMapNameTextEu_0889341F,
    gMapNameTextEu_08893440,
    gMapNameTextEu_0889345B,
} };

const u8 gMapNameTextEu_08893494[30] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'S', 'e', 'c', 'o', 'n', 'd', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_088934B2[26] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '2', 0 };

const u8 gMapNameTextEu_088934CC[33] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '2', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_088934ED[27] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '2', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_08893508[36] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 's', 'e', 'g', 'u', 'n', 'd', 'a', 0 };

const LocalizedText gMapNameEu_0889352C = { {
    gMapNameTextEu_08893494,
    gMapNameTextEu_088934B2,
    gMapNameTextEu_088934CC,
    gMapNameTextEu_088934ED,
    gMapNameTextEu_08893508,
} };

const u8 gMapNameTextEu_08893540[29] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'T', 'h', 'i', 'r', 'd', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_0889355D[26] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '3', 0 };

const u8 gMapNameTextEu_08893577[33] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '3', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_08893598[27] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '3', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_088935B3[36] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 't', 'e', 'r', 'c', 'e', 'r', 'a', 0 };

const LocalizedText gMapNameEu_088935D8 = { {
    gMapNameTextEu_08893540,
    gMapNameTextEu_0889355D,
    gMapNameTextEu_08893577,
    gMapNameTextEu_08893598,
    gMapNameTextEu_088935B3,
} };

const u8 gMapNameTextEu_088935EC[30] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'F', 'o', 'u', 'r', 't', 'h', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_0889360A[26] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '4', 0 };

const u8 gMapNameTextEu_08893624[33] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '4', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_08893645[27] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '4', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_08893660[35] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 'c', 'u', 'a', 'r', 't', 'a', 0 };

const LocalizedText gMapNameEu_08893684 = { {
    gMapNameTextEu_088935EC,
    gMapNameTextEu_0889360A,
    gMapNameTextEu_08893624,
    gMapNameTextEu_08893645,
    gMapNameTextEu_08893660,
} };

const u8 gMapNameTextEu_08893698[29] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'F', 'i', 'f', 't', 'h', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_088936B5[26] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '5', 0 };

const u8 gMapNameTextEu_088936CF[33] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '5', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_088936F0[27] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '5', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_0889370B[35] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 'q', 'u', 'i', 'n', 't', 'a', 0 };

const LocalizedText gMapNameEu_08893730 = { {
    gMapNameTextEu_08893698,
    gMapNameTextEu_088936B5,
    gMapNameTextEu_088936CF,
    gMapNameTextEu_088936F0,
    gMapNameTextEu_0889370B,
} };

const u8 gMapNameTextEu_08893744[29] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'S', 'i', 'x', 't', 'h', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_08893761[26] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '6', 0 };

const u8 gMapNameTextEu_0889377B[33] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '6', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_0889379C[27] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '6', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_088937B7[34] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 's', 'e', 'x', 't', 'a', 0 };

const LocalizedText gMapNameEu_088937DC = { {
    gMapNameTextEu_08893744,
    gMapNameTextEu_08893761,
    gMapNameTextEu_0889377B,
    gMapNameTextEu_0889379C,
    gMapNameTextEu_088937B7,
} };

const u8 gMapNameTextEu_088937F0[31] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'S', 'e', 'v', 'e', 'n', 't', 'h', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_0889380F[26] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '7', 0 };

const u8 gMapNameTextEu_08893829[33] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '7', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_0889384A[27] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '7', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_08893865[36] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 's', 0xe9, 'p', 't', 'i', 'm', 'a', 0 };

const LocalizedText gMapNameEu_0889388C = { {
    gMapNameTextEu_088937F0,
    gMapNameTextEu_0889380F,
    gMapNameTextEu_08893829,
    gMapNameTextEu_0889384A,
    gMapNameTextEu_08893865,
} };

const u8 gMapNameTextEu_088938A0[30] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'E', 'i', 'g', 'h', 't', 'h', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_088938BE[26] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '8', 0 };

const u8 gMapNameTextEu_088938D8[33] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '8', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_088938F9[27] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '8', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_08893914[35] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 'o', 'c', 't', 'a', 'v', 'a', 0 };

const LocalizedText gMapNameEu_08893938 = { {
    gMapNameTextEu_088938A0,
    gMapNameTextEu_088938BE,
    gMapNameTextEu_088938D8,
    gMapNameTextEu_088938F9,
    gMapNameTextEu_08893914,
} };

const u8 gMapNameTextEu_0889394C[29] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'N', 'i', 'n', 't', 'h', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_08893969[26] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '9', 0 };

const u8 gMapNameTextEu_08893983[33] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '9', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_088939A4[27] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '9', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_088939BF[35] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 'n', 'o', 'v', 'e', 'n', 'a', 0 };

const LocalizedText gMapNameEu_088939E4 = { {
    gMapNameTextEu_0889394C,
    gMapNameTextEu_08893969,
    gMapNameTextEu_08893983,
    gMapNameTextEu_088939A4,
    gMapNameTextEu_088939BF,
} };

const u8 gMapNameTextEu_088939F8[29] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'T', 'e', 'n', 't', 'h', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_08893A15[27] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '1', '0', 0 };

const u8 gMapNameTextEu_08893A30[34] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '1', '0', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_08893A52[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '1', '0', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_08893A6E[35] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 'd', 0xe9, 'c', 'i', 'm', 'a', 0 };

const LocalizedText gMapNameEu_08893A94 = { {
    gMapNameTextEu_088939F8,
    gMapNameTextEu_08893A15,
    gMapNameTextEu_08893A30,
    gMapNameTextEu_08893A52,
    gMapNameTextEu_08893A6E,
} };

const u8 gMapNameTextEu_08893AA8[32] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'E', 'l', 'e', 'v', 'e', 'n', 't', 'h', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_08893AC8[27] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '1', '1', 0 };

const u8 gMapNameTextEu_08893AE3[34] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '1', '1', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_08893B05[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '1', '1', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_08893B21[37] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 'u', 'n', 'd', 0xe9, 'c', 'i', 'm', 'a', 0 };

const LocalizedText gMapNameEu_08893B48 = { {
    gMapNameTextEu_08893AA8,
    gMapNameTextEu_08893AC8,
    gMapNameTextEu_08893AE3,
    gMapNameTextEu_08893B05,
    gMapNameTextEu_08893B21,
} };

const u8 gMapNameTextEu_08893B5C[31] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'T', 'w', 'e', 'l', 'f', 't', 'h', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_08893B7B[27] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '1', '2', 0 };

const u8 gMapNameTextEu_08893B96[34] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '1', '2', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_08893BB8[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '1', '2', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_08893BD4[38] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 'd', 'u', 'o', 'd', 0xe9, 'c', 'i', 'm', 'a', 0 };

const LocalizedText gMapNameEu_08893BFC = { {
    gMapNameTextEu_08893B5C,
    gMapNameTextEu_08893B7B,
    gMapNameTextEu_08893B96,
    gMapNameTextEu_08893BB8,
    gMapNameTextEu_08893BD4,
} };

const u8 gMapNameTextEu_08893C10[34] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'T', 'h', 'i', 'r', 't', 'e', 'e', 'n', 't', 'h', ' ', 'F', 'l', 'o', 'o', 'r', 0 };

const u8 gMapNameTextEu_08893C32[27] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'p', 'a', 'l', 'i', 'e', 'r', ' ', '1', '3', 0 };

const u8 gMapNameTextEu_08893C4D[34] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '1', '3', '.', ' ', 'S', 't', 'o', 'c', 'k', 0 };

const u8 gMapNameTextEu_08893C6F[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '1', '3', 0xb0, ' ', 'P', 0 };

const u8 gMapNameTextEu_08893C8B[43] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 'p', 'l', 'a', 'n', 't', 'a', ' ', 'd', 'e', 'c', 'i', 'm', 'o', 't', 'e', 'r', 'c', 'e', 'r', 'a', ' ', 0 };

const LocalizedText gMapNameEu_08893CB8 = { {
    gMapNameTextEu_08893C10,
    gMapNameTextEu_08893C32,
    gMapNameTextEu_08893C4D,
    gMapNameTextEu_08893C6F,
    gMapNameTextEu_08893C8B,
} };

const u8 gMapNameTextEu_08893CCC[33] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'B', 'a', 's', 'e', 'm', 'e', 'n', 't', ' ', 'T', 'w', 'e', 'l', 'v', 'e', 0 };

const u8 gMapNameTextEu_08893CED[29] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 's', 'o', 'u', 's', '-', 's', 'o', 'l', ' ', '1', '2', 0 };

const u8 gMapNameTextEu_08893D0A[43] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '1', '2', '.', ' ', 'K', 'e', 'l', 'l', 'e', 'r', 'g', 'e', 's', 'c', 'h', 'o', 's', 's', 0 };

const u8 gMapNameTextEu_08893D35[29] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '1', '2', 0xb0, ' ', 'P', 'I', 0 };

const u8 gMapNameTextEu_08893D52[38] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 's', 0xf3, 't', 'a', 'n', 'o', ' ', 'd', 'u', 'o', 'd', 0xe9, 'c', 'i', 'm', 'o', 0 };

const LocalizedText gMapNameEu_08893D78 = { {
    gMapNameTextEu_08893CCC,
    gMapNameTextEu_08893CED,
    gMapNameTextEu_08893D0A,
    gMapNameTextEu_08893D35,
    gMapNameTextEu_08893D52,
} };

const u8 gMapNameTextEu_08893D8C[33] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'B', 'a', 's', 'e', 'm', 'e', 'n', 't', ' ', 'E', 'l', 'e', 'v', 'e', 'n', 0 };

const u8 gMapNameTextEu_08893DAD[29] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 's', 'o', 'u', 's', '-', 's', 'o', 'l', ' ', '1', '1', 0 };

const u8 gMapNameTextEu_08893DCA[43] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '1', '1', '.', ' ', 'K', 'e', 'l', 'l', 'e', 'r', 'g', 'e', 's', 'c', 'h', 'o', 's', 's', 0 };

const u8 gMapNameTextEu_08893DF5[29] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '1', '1', 0xb0, ' ', 'P', 'I', 0 };

const u8 gMapNameTextEu_08893E12[37] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 's', 0xf3, 't', 'a', 'n', 'o', ' ', 'u', 'n', 'd', 0xe9, 'c', 'i', 'm', 'o', 0 };

const LocalizedText gMapNameEu_08893E38 = { {
    gMapNameTextEu_08893D8C,
    gMapNameTextEu_08893DAD,
    gMapNameTextEu_08893DCA,
    gMapNameTextEu_08893DF5,
    gMapNameTextEu_08893E12,
} };

const u8 gMapNameTextEu_08893E4C[30] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'B', 'a', 's', 'e', 'm', 'e', 'n', 't', ' ', 'T', 'e', 'n', 0 };

const u8 gMapNameTextEu_08893E6A[29] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 's', 'o', 'u', 's', '-', 's', 'o', 'l', ' ', '1', '0', 0 };

const u8 gMapNameTextEu_08893E87[43] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '1', '0', '.', ' ', 'K', 'e', 'l', 'l', 'e', 'r', 'g', 'e', 's', 'c', 'h', 'o', 's', 's', 0 };

const u8 gMapNameTextEu_08893EB2[29] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '1', '0', 0xb0, ' ', 'P', 'I', 0 };

const u8 gMapNameTextEu_08893ECF[35] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 's', 0xf3, 't', 'a', 'n', 'o', ' ', 'd', 0xe9, 'c', 'i', 'm', 'o', 0 };

const LocalizedText gMapNameEu_08893EF4 = { {
    gMapNameTextEu_08893E4C,
    gMapNameTextEu_08893E6A,
    gMapNameTextEu_08893E87,
    gMapNameTextEu_08893EB2,
    gMapNameTextEu_08893ECF,
} };

const u8 gMapNameTextEu_08893F08[31] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'B', 'a', 's', 'e', 'm', 'e', 'n', 't', ' ', 'N', 'i', 'n', 'e', 0 };

const u8 gMapNameTextEu_08893F27[28] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 's', 'o', 'u', 's', '-', 's', 'o', 'l', ' ', '9', 0 };

const u8 gMapNameTextEu_08893F43[42] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '9', '.', ' ', 'K', 'e', 'l', 'l', 'e', 'r', 'g', 'e', 's', 'c', 'h', 'o', 's', 's', 0 };

const u8 gMapNameTextEu_08893F6D[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '9', 0xb0, ' ', 'P', 'I', 0 };

const u8 gMapNameTextEu_08893F89[35] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 's', 0xf3, 't', 'a', 'n', 'o', ' ', 'n', 'o', 'v', 'e', 'n', 'o', 0 };

const LocalizedText gMapNameEu_08893FAC = { {
    gMapNameTextEu_08893F08,
    gMapNameTextEu_08893F27,
    gMapNameTextEu_08893F43,
    gMapNameTextEu_08893F6D,
    gMapNameTextEu_08893F89,
} };

const u8 gMapNameTextEu_08893FC0[32] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'B', 'a', 's', 'e', 'm', 'e', 'n', 't', ' ', 'E', 'i', 'g', 'h', 't', 0 };

const u8 gMapNameTextEu_08893FE0[28] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 's', 'o', 'u', 's', '-', 's', 'o', 'l', ' ', '8', 0 };

const u8 gMapNameTextEu_08893FFC[42] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '8', '.', ' ', 'K', 'e', 'l', 'l', 'e', 'r', 'g', 'e', 's', 'c', 'h', 'o', 's', 's', 0 };

const u8 gMapNameTextEu_08894026[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '8', 0xb0, ' ', 'P', 'I', 0 };

const u8 gMapNameTextEu_08894042[35] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 's', 0xf3, 't', 'a', 'n', 'o', ' ', 'o', 'c', 't', 'a', 'v', 'o', 0 };

const LocalizedText gMapNameEu_08894068 = { {
    gMapNameTextEu_08893FC0,
    gMapNameTextEu_08893FE0,
    gMapNameTextEu_08893FFC,
    gMapNameTextEu_08894026,
    gMapNameTextEu_08894042,
} };

const u8 gMapNameTextEu_0889407C[32] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'B', 'a', 's', 'e', 'm', 'e', 'n', 't', ' ', 'S', 'e', 'v', 'e', 'n', 0 };

const u8 gMapNameTextEu_0889409C[28] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 's', 'o', 'u', 's', '-', 's', 'o', 'l', ' ', '7', 0 };

const u8 gMapNameTextEu_088940B8[42] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '7', '.', ' ', 'K', 'e', 'l', 'l', 'e', 'r', 'g', 'e', 's', 'c', 'h', 'o', 's', 's', 0 };

const u8 gMapNameTextEu_088940E2[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '7', 0xb0, ' ', 'P', 'I', 0 };

const u8 gMapNameTextEu_088940FE[36] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 's', 0xf3, 't', 'a', 'n', 'o', ' ', 's', 0xe9, 'p', 't', 'i', 'm', 'o', 0 };

const LocalizedText gMapNameEu_08894124 = { {
    gMapNameTextEu_0889407C,
    gMapNameTextEu_0889409C,
    gMapNameTextEu_088940B8,
    gMapNameTextEu_088940E2,
    gMapNameTextEu_088940FE,
} };

const u8 gMapNameTextEu_08894138[30] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'B', 'a', 's', 'e', 'm', 'e', 'n', 't', ' ', 'S', 'i', 'x', 0 };

const u8 gMapNameTextEu_08894156[28] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 's', 'o', 'u', 's', '-', 's', 'o', 'l', ' ', '6', 0 };

const u8 gMapNameTextEu_08894172[42] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '6', '.', ' ', 'K', 'e', 'l', 'l', 'e', 'r', 'g', 'e', 's', 'c', 'h', 'o', 's', 's', 0 };

const u8 gMapNameTextEu_0889419C[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '6', 0xb0, ' ', 'P', 'I', 0 };

const u8 gMapNameTextEu_088941B8[34] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 's', 0xf3, 't', 'a', 'n', 'o', ' ', 's', 'e', 'x', 't', 'o', 0 };

const LocalizedText gMapNameEu_088941DC = { {
    gMapNameTextEu_08894138,
    gMapNameTextEu_08894156,
    gMapNameTextEu_08894172,
    gMapNameTextEu_0889419C,
    gMapNameTextEu_088941B8,
} };

const u8 gMapNameTextEu_088941F0[31] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'B', 'a', 's', 'e', 'm', 'e', 'n', 't', ' ', 'F', 'i', 'v', 'e', 0 };

const u8 gMapNameTextEu_0889420F[28] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 's', 'o', 'u', 's', '-', 's', 'o', 'l', ' ', '5', 0 };

const u8 gMapNameTextEu_0889422B[42] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '5', '.', ' ', 'K', 'e', 'l', 'l', 'e', 'r', 'g', 'e', 's', 'c', 'h', 'o', 's', 's', 0 };

const u8 gMapNameTextEu_08894255[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '5', 0xb0, ' ', 'P', 'I', 0 };

const u8 gMapNameTextEu_08894271[35] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 's', 0xf3, 't', 'a', 'n', 'o', ' ', 'q', 'u', 'i', 'n', 't', 'o', 0 };

const LocalizedText gMapNameEu_08894294 = { {
    gMapNameTextEu_088941F0,
    gMapNameTextEu_0889420F,
    gMapNameTextEu_0889422B,
    gMapNameTextEu_08894255,
    gMapNameTextEu_08894271,
} };

const u8 gMapNameTextEu_088942A8[31] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'B', 'a', 's', 'e', 'm', 'e', 'n', 't', ' ', 'F', 'o', 'u', 'r', 0 };

const u8 gMapNameTextEu_088942C7[28] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 's', 'o', 'u', 's', '-', 's', 'o', 'l', ' ', '4', 0 };

const u8 gMapNameTextEu_088942E3[42] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '4', '.', ' ', 'K', 'e', 'l', 'l', 'e', 'r', 'g', 'e', 's', 'c', 'h', 'o', 's', 's', 0 };

const u8 gMapNameTextEu_0889430D[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '4', 0xb0, ' ', 'P', 'I', 0 };

const u8 gMapNameTextEu_08894329[35] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 's', 0xf3, 't', 'a', 'n', 'o', ' ', 'c', 'u', 'a', 'r', 't', 'o', 0 };

const LocalizedText gMapNameEu_0889434C = { {
    gMapNameTextEu_088942A8,
    gMapNameTextEu_088942C7,
    gMapNameTextEu_088942E3,
    gMapNameTextEu_0889430D,
    gMapNameTextEu_08894329,
} };

const u8 gMapNameTextEu_08894360[32] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'B', 'a', 's', 'e', 'm', 'e', 'n', 't', ' ', 'T', 'h', 'r', 'e', 'e', 0 };

const u8 gMapNameTextEu_08894380[28] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 's', 'o', 'u', 's', '-', 's', 'o', 'l', ' ', '3', 0 };

const u8 gMapNameTextEu_0889439C[42] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '3', '.', ' ', 'K', 'e', 'l', 'l', 'e', 'r', 'g', 'e', 's', 'c', 'h', 'o', 's', 's', 0 };

const u8 gMapNameTextEu_088943C6[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '3', 0xb0, ' ', 'P', 'I', 0 };

const u8 gMapNameTextEu_088943E2[36] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 's', 0xf3, 't', 'a', 'n', 'o', ' ', 't', 'e', 'r', 'c', 'e', 'r', 'o', 0 };

const LocalizedText gMapNameEu_08894408 = { {
    gMapNameTextEu_08894360,
    gMapNameTextEu_08894380,
    gMapNameTextEu_0889439C,
    gMapNameTextEu_088943C6,
    gMapNameTextEu_088943E2,
} };

const u8 gMapNameTextEu_0889441C[30] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'B', 'a', 's', 'e', 'm', 'e', 'n', 't', ' ', 'T', 'w', 'o', 0 };

const u8 gMapNameTextEu_0889443A[28] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 's', 'o', 'u', 's', '-', 's', 'o', 'l', ' ', '2', 0 };

const u8 gMapNameTextEu_08894456[42] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '2', '.', ' ', 'K', 'e', 'l', 'l', 'e', 'r', 'g', 'e', 's', 'c', 'h', 'o', 's', 's', 0 };

const u8 gMapNameTextEu_08894480[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '2', 0xb0, ' ', 'P', 'I', 0 };

const u8 gMapNameTextEu_0889449C[36] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 's', 0xf3, 't', 'a', 'n', 'o', ' ', 's', 'e', 'g', 'u', 'n', 'd', 'o', 0 };

const LocalizedText gMapNameEu_088944C0 = { {
    gMapNameTextEu_0889441C,
    gMapNameTextEu_0889443A,
    gMapNameTextEu_08894456,
    gMapNameTextEu_08894480,
    gMapNameTextEu_0889449C,
} };

const u8 gMapNameTextEu_088944D4[30] = { 'C', 'a', 's', 't', 'l', 'e', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 'B', 'a', 's', 'e', 'm', 'e', 'n', 't', ' ', 'O', 'n', 'e', 0 };

const u8 gMapNameTextEu_088944F2[28] = { 'M', 'a', 'n', 'o', 'i', 'r', ' ', 'O', 'b', 'l', 'i', 'v', 'i', 'o', 'n', ',', ' ', 's', 'o', 'u', 's', '-', 's', 'o', 'l', ' ', '1', 0 };

const u8 gMapNameTextEu_0889450E[42] = { 'S', 'c', 'h', 'l', 'o', 's', 's', ' ', 'd', 'e', 's', ' ', 'E', 'n', 't', 'f', 'a', 'l', 'l', 'e', 'n', 's', ',', ' ', '1', '.', ' ', 'K', 'e', 'l', 'l', 'e', 'r', 'g', 'e', 's', 'c', 'h', 'o', 's', 's', 0 };

const u8 gMapNameTextEu_08894538[28] = { 'C', 'a', 's', 't', 'e', 'l', 'l', 'o', ' ', 'd', 'e', 'l', 'l', '\'', 'O', 'b', 'l', 'i', 'o', ' ', '-', ' ', '1', 0xb0, ' ', 'P', 'I', 0 };

const u8 gMapNameTextEu_08894554[36] = { 'C', 'a', 's', 't', 'i', 'l', 'l', 'o', ' ', 'd', 'e', 'l', ' ', 'O', 'l', 'v', 'i', 'd', 'o', ',', ' ', 's', 0xf3, 't', 'a', 'n', 'o', ' ', 'p', 'r', 'i', 'm', 'e', 'r', 'o', 0 };

const LocalizedText gMapNameEu_08894578 = { {
    gMapNameTextEu_088944D4,
    gMapNameTextEu_088944F2,
    gMapNameTextEu_0889450E,
    gMapNameTextEu_08894538,
    gMapNameTextEu_08894554,
} };

const JiminyTextChar gUnkEu_0889458C[12] = { 'I', 'n', 'c', 'r', 'e', 'm', 'e', 'n', 't', 'o', 'r', 0 };

const JiminyTextChar gUnkEu_08894598[13] = { 'A', 'm', 0xe9, 'l', 'i', 'o', 'r', 'a', 't', 'i', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_088945A5[12] = { 'B', 'o', 'n', 'i', 'f', 'i', 'k', 'a', 't', 'o', 'r', 0 };

const JiminyTextChar gUnkEu_088945B1[12] = { 'A', 'u', 'm', 'e', 'n', 't', 'u', 'n', 'i', 't', 0xe0, 0 };

const JiminyTextChar gUnkEu_088945BD[12] = { 'P', 'o', 't', 'e', 'n', 'c', 'i', 'a', 'd', 'o', 'r', 0 };

const JiminyLocalizedName gUnkEu_088945CC = { {
    gUnkEu_0889458C,
    gUnkEu_08894598,
    gUnkEu_088945A5,
    gUnkEu_088945B1,
    gUnkEu_088945BD,
} };

const JiminyTextChar gUnkEu_088945E0[11] = { 'C', 'o', 'm', 'b', 'o', ' ', 'P', 'l', 'u', 's', 0 };

const JiminyTextChar gUnkEu_088945EB[11] = { 'C', 'o', 'm', 'b', 'o', ' ', 'P', 'l', 'u', 's', 0 };

const JiminyTextChar gUnkEu_088945F6[8] = { 'C', 'o', 'm', 'b', 'o', ' ', '+', 0 };

const JiminyTextChar gUnkEu_088945FE[11] = { 'C', 'o', 'm', 'b', 'o', ' ', 'P', 'l', 'u', 's', 0 };

const JiminyTextChar gUnkEu_08894609[9] = { 'C', 'o', 'm', 'b', 'i', ' ', '+', '1', 0 };

const JiminyLocalizedName gUnkEu_08894614 = { {
    gUnkEu_088945E0,
    gUnkEu_088945EB,
    gUnkEu_088945F6,
    gUnkEu_088945FE,
    gUnkEu_08894609,
} };

const JiminyTextChar gUnkEu_08894628[11] = { 'R', 'e', 't', 'r', 'o', 'g', 'r', 'a', 'd', 'e', 0 };

const JiminyTextChar gUnkEu_08894633[10] = { 'I', 'n', 'v', 'e', 'r', 's', 'i', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_0889463D[17] = { 'W', 'e', 'r', 't', 'e', '-', 'R', 'e', 'v', 'e', 'r', 's', 'a', 't', 'o', 'r', 0 };

const JiminyTextChar gUnkEu_0889464E[12] = { 'I', 'n', 'v', 'e', 'r', 't', 'u', 'n', 'i', 't', 0xe0, 0 };

const JiminyTextChar gUnkEu_0889465A[10] = { 'I', 'n', 'v', 'e', 'r', 's', 'i', 0xf3, 'n', 0 };

const JiminyLocalizedName gUnkEu_08894664 = { {
    gUnkEu_08894628,
    gUnkEu_08894633,
    gUnkEu_0889463D,
    gUnkEu_0889464E,
    gUnkEu_0889465A,
} };

const JiminyTextChar gUnkEu_08894678[5] = { 'D', 'r', 'a', 'w', 0 };

const JiminyTextChar gUnkEu_0889467D[7] = { 'A', 'i', 'm', 'a', 'n', 't', 0 };

const JiminyTextChar gUnkEu_08894684[9] = { 'C', 'h', 'a', 'r', 'm', 'e', 'u', 'r', 0 };

const JiminyTextChar gUnkEu_0889468D[9] = { 'A', 's', 's', 'i', 'm', 'i', 'l', 'a', 0 };

const JiminyTextChar gUnkEu_08894696[5] = { 'I', 'm', 0xe1, 'n', 0 };

const JiminyLocalizedName gUnkEu_0889469C = { {
    gUnkEu_08894678,
    gUnkEu_0889467D,
    gUnkEu_08894684,
    gUnkEu_0889468D,
    gUnkEu_08894696,
} };

const JiminyTextChar gUnkEu_088946B0[12] = { 'B', 'a', 'c', 'k', ' ', 'A', 't', 't', 'a', 'c', 'k', 0 };

const JiminyTextChar gUnkEu_088946BC[9] = { 'B', 'a', 'c', 'k', 'l', 'a', 's', 'h', 0 };

const JiminyTextChar gUnkEu_088946C5[14] = { 'R', 0xfc, 'c', 'k', 'e', 'n', 'a', 'n', 'g', 'r', 'i', 'f', 'f', 0 };

const JiminyTextChar gUnkEu_088946D3[12] = { 'R', 'e', 't', 'r', 'a', 't', 't', 'a', 'c', 'c', 'o', 0 };

const JiminyTextChar gUnkEu_088946DF[16] = { 'A', 't', 'a', 'q', 'u', 'e', ' ', 's', 'o', 'r', 'p', 'r', 'e', 's', 'a', 0 };

const JiminyLocalizedName gUnkEu_088946F0 = { {
    gUnkEu_088946B0,
    gUnkEu_088946BC,
    gUnkEu_088946C5,
    gUnkEu_088946D3,
    gUnkEu_088946DF,
} };

const JiminyTextChar gUnkEu_08894704[6] = { 'G', 'u', 'a', 'r', 'd', 0 };

const JiminyTextChar gUnkEu_0889470A[7] = { 'P', 'a', 'r', 'a', 'd', 'e', 0 };

const JiminyTextChar gUnkEu_08894711[10] = { 'R', 'e', 'f', 'l', 'e', 'k', 't', 'o', 'r', 0 };

const JiminyTextChar gUnkEu_0889471B[12] = { 'I', 'p', 'e', 'r', 'g', 'u', 'a', 'r', 'd', 'i', 'a', 0 };

const JiminyTextChar gUnkEu_08894727[8] = { 'B', 'l', 'o', 'q', 'u', 'e', 'o', 0 };

const JiminyLocalizedName gUnkEu_08894730 = { {
    gUnkEu_08894704,
    gUnkEu_0889470A,
    gUnkEu_08894711,
    gUnkEu_0889471B,
    gUnkEu_08894727,
} };

const JiminyTextChar gUnkEu_08894744[14] = { 'R', 'a', 'n', 'd', 'o', 'm', ' ', 'V', 'a', 'l', 'u', 'e', 's', 0 };

const JiminyTextChar gUnkEu_08894752[13] = { 'V', 'a', 'l', 'e', 'u', 'r', ' ', 'a', 'l', 0xe9, 'a', '.', 0 };

const JiminyTextChar gUnkEu_0889475F[13] = { 'Z', 'u', 'f', 'a', 'l', 'l', 's', 'w', 'e', 'r', 't', 'e', 0 };

const JiminyTextChar gUnkEu_0889476C[11] = { 'S', 'l', 'o', 't', ' ', 'U', 'n', 'i', 't', 0xe0, 0 };

const JiminyTextChar gUnkEu_08894777[7] = { 'R', 'u', 'l', 'e', 't', 'a', 0 };

const JiminyLocalizedName gUnkEu_08894780 = { {
    gUnkEu_08894744,
    gUnkEu_08894752,
    gUnkEu_0889475F,
    gUnkEu_0889476C,
    gUnkEu_08894777,
} };

const JiminyTextChar gUnkEu_08894794[13] = { 'C', 'o', 'm', 'b', 'o', ' ', 'F', 'i', 'n', 'i', 's', 'h', 0 };

const JiminyTextChar gUnkEu_088947A1[9] = { 'C', 'o', 'm', 'b', 'o', ' ', 'S', 'P', 0 };

const JiminyTextChar gUnkEu_088947AA[16] = { 'C', 'o', 'm', 'b', 'o', '-', 'A', 'b', 's', 'c', 'h', 'l', 'u', 's', 's', 0 };

const JiminyTextChar gUnkEu_088947BA[13] = { 'C', 'o', 'm', 'b', 'o', ' ', 'F', 'i', 'n', 'a', 'l', 'e', 0 };

const JiminyTextChar gUnkEu_088947C7[12] = { 'C', 'o', 'm', 'b', 'o', ' ', 'f', 'i', 'n', 'a', 'l', 0 };

const JiminyLocalizedName gUnkEu_088947D4 = { {
    gUnkEu_08894794,
    gUnkEu_088947A1,
    gUnkEu_088947AA,
    gUnkEu_088947BA,
    gUnkEu_088947C7,
} };

const JiminyTextChar gUnkEu_088947E8[10] = { 'A', 'l', 'l', ' ', 'Z', 'e', 'r', 'o', 's', 0 };

const JiminyTextChar gUnkEu_088947F2[14] = { 'N', 'u', 'l', 'l', 'i', 'f', 'i', 'c', 'a', 't', 'i', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_08894800[13] = { 'A', 'l', 'l', 'e', 's', ' ', 'N', 'u', 'l', 'l', 'e', 'n', 0 };

const JiminyTextChar gUnkEu_0889480D[11] = { 'T', 'u', 't', 't', 'i', ' ', 'Z', 'e', 'r', 'o', 0 };

const JiminyTextChar gUnkEu_08894818[11] = { 'C', 'e', 'r', 'o', ' ', 't', 'o', 't', 'a', 'l', 0 };

const JiminyLocalizedName gUnkEu_08894824 = { {
    gUnkEu_088947E8,
    gUnkEu_088947F2,
    gUnkEu_08894800,
    gUnkEu_0889480D,
    gUnkEu_08894818,
} };

const JiminyTextChar gUnkEu_08894838[11] = { 'F', 'i', 'r', 'e', ' ', 'B', 'o', 'o', 's', 't', 0 };

const JiminyTextChar gUnkEu_08894843[12] = { 'B', 'o', 'o', 's', 't', 'e', 'r', ' ', 'F', 'e', 'u', 0 };

const JiminyTextChar gUnkEu_0889484F[9] = { 'P', 'y', 'r', 'o', 'm', 'a', 'n', 'e', 0 };

const JiminyTextChar gUnkEu_08894858[8] = { 'F', 'u', 'o', 'c', 'o', ' ', '+', 0 };

const JiminyTextChar gUnkEu_08894860[10] = { 'L', 'l', 'a', 'm', 'a', 'r', 'a', 'd', 'a', 0 };

const JiminyLocalizedName gUnkEu_0889486C = { {
    gUnkEu_08894838,
    gUnkEu_08894843,
    gUnkEu_0889484F,
    gUnkEu_08894858,
    gUnkEu_08894860,
} };

const JiminyTextChar gUnkEu_08894880[15] = { 'B', 'l', 'i', 'z', 'z', 'a', 'r', 'd', ' ', 'B', 'o', 'o', 's', 't', 0 };

const JiminyTextChar gUnkEu_0889488F[14] = { 'B', 'o', 'o', 's', 't', 'e', 'r', ' ', 'G', 'l', 'a', 'c', 'e', 0 };

const JiminyTextChar gUnkEu_0889489D[8] = { 'E', 'i', 's', 'z', 'e', 'i', 't', 0 };

const JiminyTextChar gUnkEu_088948A5[11] = { 'G', 'h', 'i', 'a', 'c', 'c', 'i', 'o', ' ', '+', 0 };

const JiminyTextChar gUnkEu_088948B0[7] = { 'H', 'e', 'l', 'a', 'd', 'a', 0 };

const JiminyLocalizedName gUnkEu_088948B8 = { {
    gUnkEu_08894880,
    gUnkEu_0889488F,
    gUnkEu_0889489D,
    gUnkEu_088948A5,
    gUnkEu_088948B0,
} };

const JiminyTextChar gUnkEu_088948CC[14] = { 'T', 'h', 'u', 'n', 'd', 'e', 'r', ' ', 'B', 'o', 'o', 's', 't', 0 };

const JiminyTextChar gUnkEu_088948DA[13] = { 'B', 'o', 'o', 's', 't', 'e', 'r', ' ', 'T', 'o', 'N', 'R', 0 };

const JiminyTextChar gUnkEu_088948E7[9] = { 'G', 'e', 'w', 'i', 't', 't', 'e', 'r', 0 };

const JiminyTextChar gUnkEu_088948F0[10] = { 'F', 'u', 'l', 'm', 'i', 'n', 'e', ' ', '+', 0 };

const JiminyTextChar gUnkEu_088948FA[9] = { 'T', 'o', 'r', 'm', 'e', 'n', 't', 'a', 0 };

const JiminyLocalizedName gUnkEu_08894904 = { {
    gUnkEu_088948CC,
    gUnkEu_088948DA,
    gUnkEu_088948E7,
    gUnkEu_088948F0,
    gUnkEu_088948FA,
} };

const JiminyTextChar gUnkEu_08894918[11] = { 'C', 'u', 'r', 'e', ' ', 'B', 'o', 'o', 's', 't', 0 };

const JiminyTextChar gUnkEu_08894923[13] = { 'B', 'o', 'o', 's', 't', 'e', 'r', ' ', 'S', 'o', 'i', 'n', 0 };

const JiminyTextChar gUnkEu_08894930[8] = { 'M', 'e', 'd', 'i', 'k', 'u', 's', 0 };

const JiminyTextChar gUnkEu_08894938[7] = { 'C', 'u', 'r', 'a', ' ', '+', 0 };

const JiminyTextChar gUnkEu_0889493F[13] = { '1', 'o', 's', ' ', 'a', 'u', 'x', 'i', 'l', 'i', 'o', 's', 0 };

const JiminyLocalizedName gUnkEu_0889494C = { {
    gUnkEu_08894918,
    gUnkEu_08894923,
    gUnkEu_08894930,
    gUnkEu_08894938,
    gUnkEu_0889493F,
} };

const JiminyTextChar gUnkEu_08894960[13] = { 'S', 'u', 'm', 'm', 'o', 'n', ' ', 'B', 'o', 'o', 's', 't', 0 };

const JiminyTextChar gUnkEu_0889496D[14] = { 'B', 'o', 'o', 's', 't', 'e', 'r', ' ', 'I', 'n', 'v', 'o', 'c', 0 };

const JiminyTextChar gUnkEu_0889497B[11] = { 'B', 'e', 's', 'c', 'h', 'w', 0xf6, 'r', 'e', 'r', 0 };

const JiminyTextChar gUnkEu_08894986[14] = { 'I', 'n', 'v', 'o', 'c', 'a', 'z', 'i', 'o', 'n', 'e', ' ', '+', 0 };

const JiminyTextChar gUnkEu_08894994[8] = { 'C', 'o', 'n', 'j', 'u', 'r', 'a', 0 };

const JiminyLocalizedName gUnkEu_0889499C = { {
    gUnkEu_08894960,
    gUnkEu_0889496D,
    gUnkEu_0889497B,
    gUnkEu_08894986,
    gUnkEu_08894994,
} };

const JiminyTextChar gUnkEu_088949B0[8] = { 'B', 'e', 'r', 's', 'e', 'r', 'k', 0 };

const JiminyTextChar gUnkEu_088949B8[6] = { 'F', 'u', 'r', 'i', 'e', 0 };

const JiminyTextChar gUnkEu_088949BE[10] = { 'B', 'e', 'r', 's', 'e', 'r', 'k', 'e', 'r', 0 };

const JiminyTextChar gUnkEu_088949C8[6] = { 'F', 'u', 'r', 'i', 'a', 0 };

const JiminyTextChar gUnkEu_088949CE[7] = { 'L', 'o', 'c', 'u', 'r', 'a', 0 };

const JiminyLocalizedName gUnkEu_088949D8 = { {
    gUnkEu_088949B0,
    gUnkEu_088949B8,
    gUnkEu_088949BE,
    gUnkEu_088949C8,
    gUnkEu_088949CE,
} };

const JiminyTextChar gUnkEu_088949EC[4] = { 'B', 'i', 'o', 0 };

const JiminyTextChar gUnkEu_088949F0[8] = { 'C', 'y', 'a', 'n', 'u', 'r', 'e', 0 };

const JiminyTextChar gUnkEu_088949F8[4] = { 'B', 'i', 'o', 0 };

const JiminyTextChar gUnkEu_088949FC[4] = { 'B', 'i', 'o', 0 };

const JiminyTextChar gUnkEu_08894A00[4] = { 'B', 'i', 'o', 0 };

const JiminyLocalizedName gUnkEu_08894A04 = { {
    gUnkEu_088949EC,
    gUnkEu_088949F0,
    gUnkEu_088949F8,
    gUnkEu_088949FC,
    gUnkEu_08894A00,
} };

const JiminyTextChar gUnkEu_08894A18[7] = { 'V', 'a', 'n', 'i', 's', 'h', 0 };

const JiminyTextChar gUnkEu_08894A1F[13] = { 'I', 'n', 'v', 'i', 's', 'i', 'b', 'i', 'l', 'i', 't', 0xe9, 0 };

const JiminyTextChar gUnkEu_08894A2C[8] = { 'V', 'a', 'n', 'i', 't', 'a', 's', 0 };

const JiminyTextChar gUnkEu_08894A34[7] = { 'V', 'a', 'n', 'i', 's', 'h', 0 };

const JiminyTextChar gUnkEu_08894A3B[10] = { 'I', 'n', 'v', 'i', 's', 'i', 'b', 'l', 'e', 0 };

const JiminyLocalizedName gUnkEu_08894A48 = { {
    gUnkEu_08894A18,
    gUnkEu_08894A1F,
    gUnkEu_08894A2C,
    gUnkEu_08894A34,
    gUnkEu_08894A3B,
} };

const JiminyTextChar gUnkEu_08894A5C[12] = { 'I', 't', 'e', 'm', ' ', 'B', 'r', 'a', 'c', 'e', 'r', 0 };

const JiminyTextChar gUnkEu_08894A68[12] = { 'G', 'a', 'r', 'd', 'e', ' ', 'O', 'b', 'j', 'e', 't', 0 };

const JiminyTextChar gUnkEu_08894A74[12] = { 'I', 't', 'e', 'm', '-', 'S', 'c', 'h', 'u', 't', 'z', 0 };

const JiminyTextChar gUnkEu_08894A80[16] = { 'P', 'r', 'o', 't', 'e', 'g', 'g', 'i', 'o', 'g', 'g', 'e', 't', 't', 'i', 0 };

const JiminyTextChar gUnkEu_08894A90[17] = { 'F', 'u', 'n', 'd', 'a', ' ', 'p', 'r', 'o', 't', 'e', 'c', 't', 'o', 'r', 'a', 0 };

const JiminyLocalizedName gUnkEu_08894AA4 = { {
    gUnkEu_08894A5C,
    gUnkEu_08894A68,
    gUnkEu_08894A74,
    gUnkEu_08894A80,
    gUnkEu_08894A90,
} };

const JiminyTextChar gUnkEu_08894AB8[6] = { 'F', 'l', 'o', 'a', 't', 0 };

const JiminyTextChar gUnkEu_08894ABE[11] = { 'L', 0xe9, 'v', 'i', 't', 'a', 't', 'i', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_08894AC9[8] = { 'L', 'e', 'v', 'i', 't', 'a', 's', 0 };

const JiminyTextChar gUnkEu_08894AD1[7] = { 'L', 'e', 'v', 'i', 't', 'a', 0 };

const JiminyTextChar gUnkEu_08894AD8[7] = { 'L', 'e', 'v', 'i', 't', 'a', 0 };

const JiminyLocalizedName gUnkEu_08894AE0 = { {
    gUnkEu_08894AB8,
    gUnkEu_08894ABE,
    gUnkEu_08894AC9,
    gUnkEu_08894AD1,
    gUnkEu_08894AD8,
} };

const JiminyTextChar gUnkEu_08894AF4[6] = { 'D', 'r', 'a', 'i', 'n', 0 };

const JiminyTextChar gUnkEu_08894AFA[8] = { 'S', 'a', 'i', 'g', 'n', 0xe9, 'e', 0 };

const JiminyTextChar gUnkEu_08894B02[10] = { 'S', 'c', 'h', 'w', 0xe4, 'c', 'h', 'e', 'n', 0 };

const JiminyTextChar gUnkEu_08894B0C[10] = { 'P', 'a', 'r', 'a', 's', 's', 'i', 't', 'a', 0 };

const JiminyTextChar gUnkEu_08894B16[8] = { 'D', 'r', 'e', 'n', 'a', 'j', 'e', 0 };

const JiminyLocalizedName gUnkEu_08894B20 = { {
    gUnkEu_08894AF4,
    gUnkEu_08894AFA,
    gUnkEu_08894B02,
    gUnkEu_08894B0C,
    gUnkEu_08894B16,
} };

const JiminyTextChar gUnkEu_08894B34[12] = { 'L', 'e', 'a', 'f', ' ', 'B', 'r', 'a', 'c', 'e', 'r', 0 };

const JiminyTextChar gUnkEu_08894B40[13] = { 'P', 0xe9, 't', 'a', 'l', 'e', ' ', 'g', 'a', 'r', 'd', 'e', 0 };

const JiminyTextChar gUnkEu_08894B4D[15] = { 'K', 'r', 0xe4, 'u', 't', 'e', 'r', '-', 'S', 'c', 'h', 'u', 't', 'z', 0 };

const JiminyTextChar gUnkEu_08894B5C[13] = { 'P', 'r', 'o', 't', 'e', 'g', 'g', 'i', 'c', 'u', 'r', 'a', 0 };

const JiminyTextChar gUnkEu_08894B69[17] = { 'P', 'o', 'c', 'i', 0xf3, 'n', ' ', 'd', 'e', ' ', 'h', 'i', 'e', 'r', 'r', 'o', 0 };

const JiminyLocalizedName gUnkEu_08894B7C = { {
    gUnkEu_08894B34,
    gUnkEu_08894B40,
    gUnkEu_08894B4D,
    gUnkEu_08894B5C,
    gUnkEu_08894B69,
} };

const JiminyTextChar gUnkEu_08894B90[12] = { 'D', 'e', 'c', 'r', 'e', 'm', 'e', 'n', 't', 'o', 'r', 0 };

const JiminyTextChar gUnkEu_08894B9C[12] = { 'A', 'g', 'g', 'r', 'a', 'v', 'a', 't', 'i', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_08894BA8[12] = { 'M', 'a', 'l', 'i', 'f', 'i', 'k', 'a', 't', 'o', 'r', 0 };

const JiminyTextChar gUnkEu_08894BB4[16] = { 'D', 'i', 'm', 'i', 'n', 'u', 'i', 's', 'c', 'i', 'u', 'n', 'i', 't', 0xe0, 0 };

const JiminyTextChar gUnkEu_08894BC4[9] = { 'R', 'e', 'd', 'u', 'c', 't', 'o', 'r', 0 };

const JiminyLocalizedName gUnkEu_08894BD0 = { {
    gUnkEu_08894B90,
    gUnkEu_08894B9C,
    gUnkEu_08894BA8,
    gUnkEu_08894BB4,
    gUnkEu_08894BC4,
} };

const JiminyTextChar gUnkEu_08894BE4[10] = { 'C', 'a', 'r', 'd', 'b', 'l', 'i', 'n', 'd', 0 };

const JiminyTextChar gUnkEu_08894BEE[12] = { 'A', 'v', 'e', 'u', 'g', 'l', 'e', 'm', 'e', 'n', 't', 0 };

const JiminyTextChar gUnkEu_08894BFA[12] = { 'K', 'a', 'r', 't', 'e', 'n', 'b', 'l', 'i', 'n', 'd', 0 };

const JiminyTextChar gUnkEu_08894C06[14] = { 'N', 'a', 's', 'c', 'o', 'n', 'd', 'i', 'c', 'a', 'r', 't', 'a', 0 };

const JiminyTextChar gUnkEu_08894C14[15] = { 'N', 'a', 'i', 'p', 'e', ' ', 'c', 'u', 'b', 'i', 'e', 'r', 't', 'o', 0 };

const JiminyLocalizedName gUnkEu_08894C24 = { {
    gUnkEu_08894BE4,
    gUnkEu_08894BEE,
    gUnkEu_08894BFA,
    gUnkEu_08894C06,
    gUnkEu_08894C14,
} };

const JiminyTextChar gUnkEu_08894C38[12] = { 'R', 'e', 'l', 'o', 'a', 'd', ' ', 'L', 'o', 'c', 'k', 0 };

const JiminyTextChar gUnkEu_08894C44[14] = { 'C', 'h', 'a', 'r', 'g', 'e', ' ', 'g', 'r', 'a', 't', 'i', 's', 0 };

const JiminyTextChar gUnkEu_08894C52[10] = { 'L', 'a', 'd', 'e', 'p', 'a', 'u', 's', 'e', 0 };

const JiminyTextChar gUnkEu_08894C5C[12] = { 'R', 'i', 'c', 'a', 'r', 'i', 'c', 'a', 'r', 't', 'a', 0 };

const JiminyTextChar gUnkEu_08894C68[13] = { 'R', 'e', 'c', 'a', 'r', 'g', 'a', ' ', 'f', 'i', 'j', 'a', 0 };

const JiminyLocalizedName gUnkEu_08894C78 = { {
    gUnkEu_08894C38,
    gUnkEu_08894C44,
    gUnkEu_08894C52,
    gUnkEu_08894C5C,
    gUnkEu_08894C68,
} };

const JiminyTextChar gUnkEu_08894C8C[8] = { 'P', 'r', 'o', 't', 'e', 'c', 't', 0 };

const JiminyTextChar gUnkEu_08894C94[9] = { 'C', 'a', 'r', 'a', 'p', 'a', 'c', 'e', 0 };

const JiminyTextChar gUnkEu_08894C9D[7] = { 'P', 'r', 'o', 't', 'e', 's', 0 };

const JiminyTextChar gUnkEu_08894CA4[6] = { 'E', 'g', 'i', 'd', 'a', 0 };

const JiminyTextChar gUnkEu_08894CAA[7] = { 'C', 'o', 'r', 'a', 'z', 'a', 0 };

const JiminyLocalizedName gUnkEu_08894CB4 = { {
    gUnkEu_08894C8C,
    gUnkEu_08894C94,
    gUnkEu_08894C9D,
    gUnkEu_08894CA4,
    gUnkEu_08894CAA,
} };

const JiminyTextChar gUnkEu_08894CC8[14] = { 'H', 'y', 'p', 'e', 'r', ' ', 'H', 'e', 'a', 'l', 'i', 'n', 'g', 0 };

const JiminyTextChar gUnkEu_08894CD6[12] = { 'S', 'o', 'i', 'n', ' ', 'a', 'm', 'i', 'c', 'a', 'l', 0 };

const JiminyTextChar gUnkEu_08894CE2[10] = { 'F', 'r', 'o', 'h', 'n', 'a', 't', 'u', 'r', 0 };

const JiminyTextChar gUnkEu_08894CEC[9] = { 'I', 'p', 'e', 'r', 'c', 'u', 'r', 'a', 0 };

const JiminyTextChar gUnkEu_08894CF5[16] = { 'S', 'a', 'l', 'u', 'd', ' ', 'd', 'e', ' ', 'h', 'i', 'e', 'r', 'r', 'o', 0 };

const JiminyLocalizedName gUnkEu_08894D08 = { {
    gUnkEu_08894CC8,
    gUnkEu_08894CD6,
    gUnkEu_08894CE2,
    gUnkEu_08894CEC,
    gUnkEu_08894CF5,
} };

const JiminyTextChar gUnkEu_08894D1C[13] = { 'R', 'a', 'n', 'd', 'o', 'm', ' ', 'F', 'l', 'u', 's', 'h', 0 };

const JiminyTextChar gUnkEu_08894D29[15] = { 'S', 'o', 'r', 't', ' ', 'a', 'l', 0xe9, 'a', 't', 'o', 'i', 'r', 'e', 0 };

const JiminyTextChar gUnkEu_08894D38[9] = { 'R', 'o', 'u', 'l', 'e', 't', 't', 'e', 0 };

const JiminyTextChar gUnkEu_08894D41[12] = { 'S', 'l', 'o', 't', ' ', 'N', 'e', 'm', 'i', 'c', 'i', 0 };

const JiminyTextChar gUnkEu_08894D4D[9] = { 'F', 'o', 'r', 't', 'u', 'i', 't', 'o', 0 };

const JiminyLocalizedName gUnkEu_08894D58 = { {
    gUnkEu_08894D1C,
    gUnkEu_08894D29,
    gUnkEu_08894D38,
    gUnkEu_08894D41,
    gUnkEu_08894D4D,
} };

const JiminyTextChar gUnkEu_08894D6C[15] = { 'R', 'e', 'l', 'o', 'a', 'd', ' ', 'K', 'i', 'n', 'e', 's', 'i', 's', 0 };

const JiminyTextChar gUnkEu_08894D7B[14] = { 'C', 'h', 'a', 'r', 'g', 'e', ' ', 'm', 'o', 'b', 'i', 'l', 'e', 0 };

const JiminyTextChar gUnkEu_08894D89[18] = { 'N', 'a', 'c', 'h', 's', 't', 'o', 'c', 'k', '-', 'K', 'i', 'n', 'e', 't', 'i', 'k', 0 };

const JiminyTextChar gUnkEu_08894D9B[16] = { 'R', 'i', 'c', 'a', 'r', 'i', 'c', 'a', ' ', 'C', 'i', 'n', 'e', 's', 'i', 0 };

const JiminyTextChar gUnkEu_08894DAB[14] = { 'R', 'e', 'c', 'a', 'r', 'g', 'a', ' ', 'm', 0xf3, 'v', 'i', 'l', 0 };

const JiminyLocalizedName gUnkEu_08894DBC = { {
    gUnkEu_08894D6C,
    gUnkEu_08894D7B,
    gUnkEu_08894D89,
    gUnkEu_08894D9B,
    gUnkEu_08894DAB,
} };

const JiminyTextChar gUnkEu_08894DD0[13] = { 'R', 'e', 'l', 'o', 'a', 'd', ' ', 'H', 'a', 's', 't', 'e', 0 };

const JiminyTextChar gUnkEu_08894DDD[14] = { 'C', 'h', 'a', 'r', 'g', 'e', ' ', 'r', 'a', 'b', 'a', 'i', 's', 0 };

const JiminyTextChar gUnkEu_08894DEB[15] = { 'N', 'a', 'c', 'h', 's', 't', 'o', 'c', 'k', '-', 'H', 'a', 's', 't', 0 };

const JiminyTextChar gUnkEu_08894DFA[17] = { 'R', 'i', 'c', 'a', 'r', 'i', 'c', 'a', ' ', 'A', 'n', 'd', 'a', 'n', 't', 'e', 0 };

const JiminyTextChar gUnkEu_08894E0B[11] = { 'A', 'p', 'r', 'e', 's', 'u', 'r', 'a', 'd', 'o', 0 };

const JiminyLocalizedName gUnkEu_08894E18 = { {
    gUnkEu_08894DD0,
    gUnkEu_08894DDD,
    gUnkEu_08894DEB,
    gUnkEu_08894DFA,
    gUnkEu_08894E0B,
} };

const JiminyTextChar gUnkEu_08894E2C[12] = { 'A', 'u', 't', 'o', '-', 'R', 'e', 'l', 'o', 'a', 'd', 0 };

const JiminyTextChar gUnkEu_08894E38[14] = { 'A', 'u', 't', 'o', '-', 'r', 'e', 'c', 'h', 'a', 'r', 'g', 'e', 0 };

const JiminyTextChar gUnkEu_08894E46[17] = { 'A', 'u', 't', 'o', '-', 'N', 'a', 'c', 'h', 's', 't', 'o', 'c', 'k', 'e', 'n', 0 };

const JiminyTextChar gUnkEu_08894E57[13] = { 'A', 'u', 't', 'o', 'r', 'i', 'c', 'a', 'r', 'i', 'c', 'a', 0 };

const JiminyTextChar gUnkEu_08894E64[13] = { 'A', 'u', 't', 'o', '-', 'r', 'e', 'c', 'a', 'r', 'g', 'a', 0 };

const JiminyLocalizedName gUnkEu_08894E74 = { {
    gUnkEu_08894E2C,
    gUnkEu_08894E38,
    gUnkEu_08894E46,
    gUnkEu_08894E57,
    gUnkEu_08894E64,
} };

const JiminyTextChar gUnkEu_08894E88[10] = { 'Q', 'u', 'i', 'c', 'k', 'l', 'o', 'a', 'd', 0 };

const JiminyTextChar gUnkEu_08894E92[14] = { 'C', 'h', 'a', 'r', 'g', 'e', ' ', 'X', 'p', 'r', 'e', 's', 's', 0 };

const JiminyTextChar gUnkEu_08894EA0[20] = { 'S', 'c', 'h', 'n', 'e', 'l', 'l', '-', 'N', 'a', 'c', 'h', 's', 't', 'o', 'c', 'k', 'e', 'n', 0 };

const JiminyTextChar gUnkEu_08894EB4[13] = { 'C', 'a', 'r', 'i', 'c', 'a', 'r', 'a', 'p', 'i', 'd', 'o', 0 };

const JiminyTextChar gUnkEu_08894EC1[15] = { 'R', 'e', 'c', 'a', 'r', 'g', 'a', ' ', 'r', 0xe1, 'p', 'i', 'd', 'a', 0 };

const JiminyLocalizedName gUnkEu_08894ED0 = { {
    gUnkEu_08894E88,
    gUnkEu_08894E92,
    gUnkEu_08894EA0,
    gUnkEu_08894EB4,
    gUnkEu_08894EC1,
} };

const JiminyTextChar gUnkEu_08894EE4[12] = { 'W', 'i', 'd', 'e', ' ', 'A', 't', 't', 'a', 'c', 'k', 0 };

const JiminyTextChar gUnkEu_08894EF0[12] = { 0xc9, 'l', 'a', 'r', 'g', 'i', 's', 's', 'e', 'u', 'r', 0 };

const JiminyTextChar gUnkEu_08894EFC[13] = { 'R', 'e', 'i', 'c', 'h', 'w', 'e', 'i', 't', 'e', ' ', '+', 0 };

const JiminyTextChar gUnkEu_08894F09[12] = { 'A', 'm', 'p', 'i', 'a', 't', 't', 'a', 'c', 'c', 'o', 0 };

const JiminyTextChar gUnkEu_08894F15[14] = { 'L', 'a', 'r', 'g', 'o', ' ', 'a', 'l', 'c', 'a', 'n', 'c', 'e', 0 };

const JiminyLocalizedName gUnkEu_08894F24 = { {
    gUnkEu_08894EE4,
    gUnkEu_08894EF0,
    gUnkEu_08894EFC,
    gUnkEu_08894F09,
    gUnkEu_08894F15,
} };

const JiminyTextChar gUnkEu_08894F38[12] = { 'M', 'a', 'g', 'i', 'c', ' ', 'B', 'o', 'o', 's', 't', 0 };

const JiminyTextChar gUnkEu_08894F44[14] = { 'B', 'o', 'o', 's', 't', 'e', 'r', ' ', 'M', 'a', 'g', 'i', 'e', 0 };

const JiminyTextChar gUnkEu_08894F52[6] = { 'M', 'a', 'g', 'u', 's', 0 };

const JiminyTextChar gUnkEu_08894F58[8] = { 'M', 'a', 'g', 'i', 'a', ' ', '+', 0 };

const JiminyTextChar gUnkEu_08894F60[11] = { 'H', 'e', 'c', 'h', 'i', 'c', 'e', 'r', 0xed, 'a', 0 };

const JiminyLocalizedName gUnkEu_08894F6C = { {
    gUnkEu_08894F38,
    gUnkEu_08894F44,
    gUnkEu_08894F52,
    gUnkEu_08894F58,
    gUnkEu_08894F60,
} };

const JiminyTextChar gUnkEu_08894F80[14] = { 'A', 't', 't', 'a', 'c', 'k', ' ', 'B', 'r', 'a', 'c', 'e', 'r', 0 };

const JiminyTextChar gUnkEu_08894F8E[14] = { 'G', 'a', 'r', 'd', 'e', ' ', 'A', 't', 't', 'a', 'q', 'u', 'e', 0 };

const JiminyTextChar gUnkEu_08894F9C[16] = { 'A', 'n', 'g', 'r', 'i', 'f', 'f', 's', '-', 'S', 'c', 'h', 'u', 't', 'z', 0 };

const JiminyTextChar gUnkEu_08894FAC[16] = { 'P', 'r', 'o', 't', 'e', 'g', 'g', 'i', 'a', 't', 't', 'a', 'c', 'c', 'o', 0 };

const JiminyTextChar gUnkEu_08894FBC[9] = { 'G', 'u', 'e', 'r', 'r', 'e', 'r', 'o', 0 };

const JiminyLocalizedName gUnkEu_08894FC8 = { {
    gUnkEu_08894F80,
    gUnkEu_08894F8E,
    gUnkEu_08894F9C,
    gUnkEu_08894FAC,
    gUnkEu_08894FBC,
} };

const JiminyTextChar gUnkEu_08894FDC[6] = { 'M', 'i', 'm', 'i', 'c', 0 };

const JiminyTextChar gUnkEu_08894FE2[6] = { 'M', 'i', 'm', 'i', 'c', 0 };

const JiminyTextChar gUnkEu_08894FE8[8] = { 'M', 'i', 'm', 'i', 'k', 'r', 'y', 0 };

const JiminyTextChar gUnkEu_08894FF0[11] = { 'I', 'm', 'i', 't', 'a', 'z', 'i', 'o', 'n', 'e', 0 };

const JiminyTextChar gUnkEu_08894FFB[7] = { 'M', 0xed, 'm', 'i', 'c', 'o', 0 };

const JiminyLocalizedName gUnkEu_08895004 = { {
    gUnkEu_08894FDC,
    gUnkEu_08894FE2,
    gUnkEu_08894FE8,
    gUnkEu_08894FF0,
    gUnkEu_08894FFB,
} };

const JiminyTextChar gUnkEu_08895018[6] = { 'S', 'h', 'e', 'l', 'l', 0 };

const JiminyTextChar gUnkEu_0889501E[9] = { 'B', 'l', 'i', 'n', 'd', 'a', 'g', 'e', 0 };

const JiminyTextChar gUnkEu_08895027[8] = { 'M', 'u', 's', 'c', 'h', 'e', 'l', 0 };

const JiminyTextChar gUnkEu_0889502F[8] = { 'B', 'o', 'z', 'z', 'o', 'l', 'o', 0 };

const JiminyTextChar gUnkEu_08895037[7] = { 'E', 's', 'c', 'u', 'd', 'o', 0 };

const JiminyLocalizedName gUnkEu_08895040 = { {
    gUnkEu_08895018,
    gUnkEu_0889501E,
    gUnkEu_08895027,
    gUnkEu_0889502F,
    gUnkEu_08895037,
} };

const JiminyTextChar gUnkEu_08895054[6] = { 'R', 'e', 'g', 'e', 'n', 0 };

const JiminyTextChar gUnkEu_0889505A[13] = { 'R', 0xe9, 'c', 'u', 'p', 0xe9, 'r', 'a', 't', 'i', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_08895067[13] = { 'R', 'e', 'g', 'e', 'n', 'e', 'r', 'a', 't', 'i', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_08895074[7] = { 'R', 'i', 'g', 'e', 'n', 'e', 0 };

const JiminyTextChar gUnkEu_0889507B[10] = { 'R', 'e', 'v', 'i', 't', 'a', 'l', 'i', 'a', 0 };

const JiminyLocalizedName gUnkEu_08895088 = { {
    gUnkEu_08895054,
    gUnkEu_0889505A,
    gUnkEu_08895067,
    gUnkEu_08895074,
    gUnkEu_0889507B,
} };

const JiminyTextChar gUnkEu_0889509C[7] = { 'D', 'i', 's', 'p', 'e', 'l', 0 };

const JiminyTextChar gUnkEu_088950A3[12] = { 'D', 'i', 's', 's', 'i', 'p', 'a', 't', 'i', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_088950AF[7] = { 'T', 'r', 'u', 'm', 'p', 'f', 0 };

const JiminyTextChar gUnkEu_088950B6[10] = { 'A', 'n', 't', 'i', 'm', 'a', 'g', 'i', 'a', 0 };

const JiminyTextChar gUnkEu_088950C0[10] = { 'A', 'n', 't', 'i', 'm', 'a', 'g', 'i', 'a', 0 };

const JiminyLocalizedName gUnkEu_088950CC = { {
    gUnkEu_0889509C,
    gUnkEu_088950A3,
    gUnkEu_088950AF,
    gUnkEu_088950B6,
    gUnkEu_088950C0,
} };

const JiminyTextChar gUnkEu_088950E0[14] = { 'S', 'e', 'c', 'o', 'n', 'd', ' ', 'C', 'h', 'a', 'n', 'c', 'e', 0 };

const JiminyTextChar gUnkEu_088950EE[15] = { 'D', 'e', 'r', 'n', 'i', 0xe8, 'r', 'e', ' ', 'f', 'o', 'r', 'c', 'e', 0 };

const JiminyTextChar gUnkEu_088950FD[10] = { 'T', 'r', 'o', 't', 'z', 'k', 'o', 'p', 'f', 0 };

const JiminyTextChar gUnkEu_08895107[14] = { 'U', 'l', 't', 'i', 'm', 'a', ' ', 'C', 'h', 'a', 'n', 'c', 'e', 0 };

const JiminyTextChar gUnkEu_08895115[16] = { 0xda, 'l', 't', 'i', 'm', 'o', ' ', 'e', 's', 't', 'e', 'r', 't', 'o', 'r', 0 };

const JiminyLocalizedName gUnkEu_08895128 = { {
    gUnkEu_088950E0,
    gUnkEu_088950EE,
    gUnkEu_088950FD,
    gUnkEu_08895107,
    gUnkEu_08895115,
} };

const JiminyTextChar gUnkEu_0889513C[10] = { 'O', 'v', 'e', 'r', 'd', 'r', 'i', 'v', 'e', 0 };

const JiminyTextChar gUnkEu_08895146[10] = { 'O', 'v', 'e', 'r', 'd', 'r', 'i', 'v', 'e', 0 };

const JiminyTextChar gUnkEu_08895150[12] = { 'T', 'u', 'r', 'b', 'o', ' ', 'B', 'o', 'o', 's', 't', 0 };

const JiminyTextChar gUnkEu_0889515C[9] = { 'F', 'r', 'e', 'n', 'e', 's', 'i', 'a', 0 };

const JiminyTextChar gUnkEu_08895165[6] = { 'T', 'u', 'r', 'b', 'o', 0 };

const JiminyLocalizedName gUnkEu_0889516C = { {
    gUnkEu_0889513C,
    gUnkEu_08895146,
    gUnkEu_08895150,
    gUnkEu_0889515C,
    gUnkEu_08895165,
} };

const JiminyTextChar gUnkEu_08895180[13] = { 'A', 't', 't', 'a', 'c', 'k', ' ', 'H', 'a', 's', 't', 'e', 0 };

const JiminyTextChar gUnkEu_0889518D[13] = { 'A', 'c', 'c', 0xe9, 'l', 0xe9, 'r', 'a', 't', 'e', 'u', 'r', 0 };

const JiminyTextChar gUnkEu_0889519A[14] = { 'A', 'n', 'g', 'r', 'i', 'f', 'f', 's', '-', 'H', 'a', 's', 't', 0 };

const JiminyTextChar gUnkEu_088951A8[16] = { 'A', 't', 't', 'a', 'c', 'c', 'o', ' ', 'A', 'n', 'd', 'a', 'n', 't', 'e', 0 };

const JiminyTextChar gUnkEu_088951B8[13] = { 'A', 't', 'a', 'q', 'u', 'e', ' ', 'v', 'e', 'l', 'o', 'z', 0 };

const JiminyLocalizedName gUnkEu_088951C8 = { {
    gUnkEu_08895180,
    gUnkEu_0889518D,
    gUnkEu_0889519A,
    gUnkEu_088951A8,
    gUnkEu_088951B8,
} };

const JiminyTextChar gUnkEu_088951DC[15] = { 'Q', 'u', 'i', 'c', 'k', ' ', 'R', 'e', 'c', 'o', 'v', 'e', 'r', 'y', 0 };

const JiminyTextChar gUnkEu_088951EB[14] = { 'R', 'e', 'g', 'a', 'i', 'n', ' ', 'X', 'p', 'r', 'e', 's', 's', 0 };

const JiminyTextChar gUnkEu_088951F9[17] = { 'S', 'c', 'h', 'n', 'e', 'l', 'l', '-', 'E', 'r', 'h', 'o', 'l', 'u', 'n', 'g', 0 };

const JiminyTextChar gUnkEu_0889520A[16] = { 'P', 'r', 'o', 'n', 't', 'o', ' ', 'S', 'o', 'c', 'c', 'o', 'r', 's', 'o', 0 };

const JiminyTextChar gUnkEu_0889521A[10] = { 'I', 'm', 'p', 'a', 's', 'i', 'b', 'l', 'e', 0 };

const JiminyLocalizedName gUnkEu_08895224 = { {
    gUnkEu_088951DC,
    gUnkEu_088951EB,
    gUnkEu_088951F9,
    gUnkEu_0889520A,
    gUnkEu_0889521A,
} };

const JiminyTextChar gUnkEu_08895238[13] = { 'S', 'l', 'e', 'i', 'g', 'h', 't', 'b', 'l', 'i', 'n', 'd', 0 };

const JiminyTextChar gUnkEu_08895245[13] = { 'D', 'i', 's', 's', 'i', 'm', 'u', 'l', 'a', 't', 'o', 'r', 0 };

const JiminyTextChar gUnkEu_08895252[18] = { 'K', 'o', 'm', 'b', 'i', 'n', 'a', 't', 'i', 'o', 'n', 's', 'b', 'l', 'i', 'n', 'd', 0 };

const JiminyTextChar gUnkEu_08895264[12] = { 'T', 'r', 'u', 'c', 'c', 'o', 'c', 'i', 'e', 'c', 'o', 0 };

const JiminyTextChar gUnkEu_08895270[15] = { 'T', 'r', 'u', 'c', 'o', ' ', 'c', 'u', 'b', 'i', 'e', 'r', 't', 'o', 0 };

const JiminyLocalizedName gUnkEu_08895280 = { {
    gUnkEu_08895238,
    gUnkEu_08895245,
    gUnkEu_08895252,
    gUnkEu_08895264,
    gUnkEu_08895270,
} };

const JiminyTextChar gUnkEu_08895294[13] = { 'S', 'l', 'e', 'i', 'g', 'h', 't', ' ', 'L', 'o', 'c', 'k', 0 };

const JiminyTextChar gUnkEu_088952A1[12] = { 'T', 'o', 'u', 'r', ' ', 'v', 'e', 'r', 'r', 'o', 'u', 0 };

const JiminyTextChar gUnkEu_088952AD[20] = { 'K', 'o', 'm', 'b', 'i', 'n', 'a', 't', 'i', 'o', 'n', 's', '-', 'S', 'p', 'e', 'r', 'r', 'e', 0 };

const JiminyTextChar gUnkEu_088952C1[13] = { 'B', 'l', 'o', 'c', 'c', 'a', 't', 'r', 'u', 'c', 'c', 'o', 0 };

const JiminyTextChar gUnkEu_088952CE[11] = { 'T', 'r', 'u', 'c', 'o', ' ', 'f', 'i', 'j', 'o', 0 };

const JiminyLocalizedName gUnkEu_088952DC = { {
    gUnkEu_08895294,
    gUnkEu_088952A1,
    gUnkEu_088952AD,
    gUnkEu_088952C1,
    gUnkEu_088952CE,
} };

const JiminyTextChar gUnkEu_088952F0[10] = { 'A', 'u', 't', 'o', '-', 'L', 'i', 'f', 'e', 0 };

const JiminyTextChar gUnkEu_088952FA[8] = { 'A', 'u', 'r', 0xe9, 'o', 'l', 'e', 0 };

const JiminyTextChar gUnkEu_08895302[12] = { 'S', 'c', 'h', 'u', 't', 'z', 'e', 'n', 'g', 'e', 'l', 0 };

const JiminyTextChar gUnkEu_0889530E[10] = { 'R', 'i', 's', 'v', 'e', 'g', 'l', 'i', 'o', 0 };

const JiminyTextChar gUnkEu_08895318[11] = { 'A', 'u', 't', 'o', 'l', 0xe1, 'z', 'a', 'r', 'o', 0 };

const JiminyLocalizedName gUnkEu_08895324 = { {
    gUnkEu_088952F0,
    gUnkEu_088952FA,
    gUnkEu_08895302,
    gUnkEu_0889530E,
    gUnkEu_08895318,
} };

const JiminyTextChar gUnkEu_08895338[15] = { 'D', 'o', 'u', 'b', 'l', 'e', ' ', 'S', 'l', 'e', 'i', 'g', 'h', 't', 0 };

const JiminyTextChar gUnkEu_08895347[13] = { 'D', 0xe9, 'd', 'o', 'u', 'b', 'l', 'e', 'm', 'e', 'n', 't', 0 };

const JiminyTextChar gUnkEu_08895354[19] = { 'D', 'u', 'p', 'l', 'i', 'k', 'o', 'm', 'b', 'i', 'n', 'a', 't', 'i', 'o', 'n', 'e', 'n', 0 };

const JiminyTextChar gUnkEu_08895367[13] = { 'D', 'o', 'p', 'p', 'i', 'o', 't', 'r', 'u', 'c', 'c', 'o', 0 };

const JiminyTextChar gUnkEu_08895374[12] = { 'D', 'o', 'b', 'l', 'e', ' ', 't', 'r', 'u', 'c', 'o', 0 };

const JiminyLocalizedName gUnkEu_08895380 = { {
    gUnkEu_08895338,
    gUnkEu_08895347,
    gUnkEu_08895354,
    gUnkEu_08895367,
    gUnkEu_08895374,
} };

const JiminyTextChar gUnkEu_08895394[12] = { 'V', 'a', 'l', 'u', 'e', ' ', 'B', 'r', 'e', 'a', 'k', 0 };

const JiminyTextChar gUnkEu_088953A0[13] = { 'B', 'r', 'e', 'a', 'k', ' ', 'c', 'h', 'a', 'n', 'g', 'e', 0 };

const JiminyTextChar gUnkEu_088953AD[13] = { 'W', 'e', 'r', 't', 'e', 'b', 'r', 'e', 'c', 'h', 'e', 'r', 0 };

const JiminyTextChar gUnkEu_088953BA[10] = { 'F', 'e', 'r', 'm', 'u', 'n', 'i', 't', 0xe0, 0 };

const JiminyTextChar gUnkEu_088953C4[12] = { 'C', 'o', 'n', 't', 'r', 'a', 'v', 'a', 'l', 'o', 'r', 0 };

const JiminyLocalizedName gUnkEu_088953D0 = { {
    gUnkEu_08895394,
    gUnkEu_088953A0,
    gUnkEu_088953AD,
    gUnkEu_088953BA,
    gUnkEu_088953C4,
} };

const JiminyTextChar gUnkEu_088953E4[5] = { 'D', 'a', 's', 'h', 0 };

const JiminyTextChar gUnkEu_088953E9[10] = { 'A', 'i', 'g', 'u', 'i', 'l', 'l', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_088953F3[7] = { 'S', 'p', 'r', 'i', 'n', 't', 0 };

const JiminyTextChar gUnkEu_088953FA[7] = { 'S', 'c', 'a', 't', 't', 'o', 0 };

const JiminyTextChar gUnkEu_08895401[5] = { 'B', 'r', 0xed, 'o', 0 };

const JiminyLocalizedName gUnkEu_08895408 = { {
    gUnkEu_088953E4,
    gUnkEu_088953E9,
    gUnkEu_088953F3,
    gUnkEu_088953FA,
    gUnkEu_08895401,
} };

const JiminyTextChar gUnkEu_0889541C[11] = { 'W', 'a', 'r', 'p', ' ', 'B', 'r', 'e', 'a', 'k', 0 };

const JiminyTextChar gUnkEu_08895427[11] = { 'D', 'e', 's', 't', 'r', 'u', 'c', 't', 'o', 'r', 0 };

const JiminyTextChar gUnkEu_08895432[11] = { 'G', 'n', 'a', 'd', 'e', 'n', 's', 't', 'o', 0xdf, 0 };

const JiminyTextChar gUnkEu_0889543D[10] = { 'F', 'e', 'r', 'm', 'a', 'w', 'a', 'r', 'p', 0 };

const JiminyTextChar gUnkEu_08895447[10] = { 'D', 'e', 'm', 'o', 'l', 'e', 'd', 'o', 'r', 0 };

const JiminyLocalizedName gUnkEu_08895454 = { {
    gUnkEu_0889541C,
    gUnkEu_08895427,
    gUnkEu_08895432,
    gUnkEu_0889543D,
    gUnkEu_08895447,
} };

const JiminyTextChar gUnkEu_08895468[7] = { 'Z', 'e', 'x', 'i', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_0889546F[7] = { 'Z', 'e', 'x', 'i', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_08895476[7] = { 'Z', 'e', 'x', 'i', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_0889547D[7] = { 'Z', 'e', 'x', 'i', 'o', 'n', 0 };

const JiminyTextChar gUnkEu_08895484[7] = { 'Z', 'e', 'x', 'i', 0xf3, 'n', 0 };

asm(".align 2, 0\n.include \"asm/eu/jiminy_eu_epilogue_name_data.inc\"");

#endif
