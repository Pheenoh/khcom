#include "registration_data.h"
#include "monsgage.h"

const char gTaskNameMonsgage[] __attribute__((section(".rodata_registration_name_gTaskDescMonsgage"), aligned(1))) = "task_monsgage";

TaskDesc gTaskDescMonsgage __attribute__((section(".data_registration_gTaskDescMonsgage"))) = {
    gTaskNameMonsgage,
#ifdef VERSION_EU
    (void (*)(void*, void*))eu_0805E9F0,
    eu_0805EA44,
    (void (*)(void*))eu_0805EC60,
    (void (*)(void*))eu_0805ECE4,
#else
    (void (*)(void*, void*))task_monsgage_0,
    task_monsgage_1,
    (void (*)(void*))task_monsgage_2,
    (void (*)(void*))task_monsgage_3,
#endif
    0x28,
};
