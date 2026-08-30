.syntax unified
	.align 2, 0
	.global task_hum_ansem_0
	.thumb
	.thumb_func
	.type task_hum_ansem_0, %function
task_hum_ansem_0: @ 0804D0E4
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _0804D12C @ =0x0813F1E8
	bl func_0800E168
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r2, _0804D130 @ =0x0813F1E0
	adds r0, r4, #0x0
	bl func_0800E314
	movs r0, #0xE2
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, _0804D134 @ =0xFFFFF400
	str r0, [r1, #0x00]
	movs r0, #0xE4
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x00
	str r0, [r1, #0x00]
	movs r0, #0xBA
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, _0804D138 @ =0x0000FFCE
	strh r0, [r1, #0x00]
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, _0804D13C @ =0x0813F0B8
	str r0, [r1, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0804D12C: .4byte 0x0813F1E8
_0804D130: .4byte 0x0813F1E0
_0804D134: .4byte 0xFFFFF400
_0804D138: .4byte 0x0000FFCE
_0804D13C: .4byte 0x0813F0B8
.syntax divided
