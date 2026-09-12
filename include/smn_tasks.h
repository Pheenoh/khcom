#ifndef GUARD_SMN_TASKS_H
#define GUARD_SMN_TASKS_H

#include "types.h"

struct BtlObj;
struct SmnArgs;
struct SmnBambiWork;
struct SmnCloudWork;
struct SmnDumboWork;
struct SmnGenieWork;
struct SmnKingWork;
struct SmnMushuWork;
struct SmnSimbaWork;
struct SmnTinkWork;
struct SmnTinkeffWork;

void task_smn_cloud_0(struct SmnCloudWork* work, struct SmnArgs* args);
u8 task_smn_cloud_1(struct SmnCloudWork* work);
void task_smn_cloud_2(struct SmnCloudWork* work);
void task_smn_cloud_3(struct SmnCloudWork* work);
void task_smn_bambi_0(struct SmnBambiWork* work, struct SmnArgs* args);
u8 task_smn_bambi_1(struct SmnBambiWork* work);
void task_smn_bambi_2(struct SmnBambiWork* work);
void task_smn_bambi_3(struct SmnBambiWork* work);
void task_smn_tink_0(struct SmnTinkWork* work, struct SmnArgs* args);
u8 task_smn_tink_1(struct SmnTinkWork* work);
void task_smn_tink_2(struct SmnTinkWork* work);
void task_smn_tink_3(struct SmnTinkWork* work);
void task_smn_tinkeff_0(struct SmnTinkeffWork* work, struct BtlObj* args);
u8 task_smn_tinkeff_1(struct SmnTinkeffWork* work);
void task_smn_tinkeff_2(struct SmnTinkeffWork* work);
void task_smn_tinkeff_3(struct SmnTinkeffWork* work);
void task_smn_simba_0(struct SmnSimbaWork* work, struct SmnArgs* args);
u8 task_smn_simba_1(struct SmnSimbaWork* work);
void task_smn_simba_2(struct SmnSimbaWork* work);
void task_smn_simba_3(struct SmnSimbaWork* work);
void task_smn_mushu_0(struct SmnMushuWork* work, struct SmnArgs* args);
u8 task_smn_mushu_1(struct SmnMushuWork* work);
void task_smn_mushu_2(struct SmnMushuWork* work);
void task_smn_mushu_3(struct SmnMushuWork* work);
void task_smn_dumbo_0(struct SmnDumboWork* work, struct SmnArgs* args);
u8 task_smn_dumbo_1(struct SmnDumboWork* work);
void task_smn_dumbo_2(struct SmnDumboWork* work);
void task_smn_dumbo_3(struct SmnDumboWork* work);
void task_smn_genie_0(struct SmnGenieWork* work, struct SmnArgs* args);
u8 task_smn_genie_1(struct SmnGenieWork* work);
void task_smn_genie_2(struct SmnGenieWork* work);
void task_smn_genie_3(struct SmnGenieWork* work);
void task_smn_king_0(struct SmnKingWork* work, struct SmnArgs* args);
u8 task_smn_king_1(struct SmnKingWork* work);
void task_smn_king_2(struct SmnKingWork* work);
void task_smn_king_3(struct SmnKingWork* work);

#endif
