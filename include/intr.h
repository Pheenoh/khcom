#ifndef GUARD_INTR_H
#define GUARD_INTR_H

#include "types.h"

typedef void (*IntrFunc)(void);

void EnableVBlankIntr(void);
void DisableVBlankIntr(void);
void EnableHBlankIntr(void);
void DisableHBlankIntr(void);
void SetVBlankCallback(IntrFunc fn);
void ResetVBlankCallback(void);
void SetHBlankCallback(IntrFunc fn);
void ResetHBlankCallback(void);
void SetVCountCallback(IntrFunc fn);
void ResetVCountCallback(void);
void SetSerialCallback(IntrFunc fn);
void ResetSerialCallback(void);
void SetTimer3Callback(IntrFunc fn);
void ResetTimer3Callback(void);
void ApplyIntrCallbacks(void);

#endif
