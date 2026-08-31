.syntax unified
	.align 2, 0
	.global task_hum_laxene_0
	.thumb
	.thumb_func
	.type task_hum_laxene_0, %function
task_hum_laxene_0: @ 08050F7C
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _08050FCC @ =0x0813F588
	bl func_0800E168
	movs r1, #0xC7
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r2, #0x00
	strh r2, [r0, #0x00]
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, _08050FD0 @ =0xFFFFD000
	str r0, [r1, #0x00]
	movs r1, #0xC8
	lsls r1, r1, #0x01
	adds r0, r4, r1
	strh r2, [r0, #0x00]
	ldr r0, [r4, #0x74]
	ldr r1, [r4, #0x78]
	ldr r2, _08050FD4 @ =0x00000000
	ldr r3, _08050FD8 @ =0x00000800
	orrs r1, r3
	str r0, [r4, #0x74]
	str r1, [r4, #0x78]
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, _08050FDC @ =0x0813F480
	str r0, [r1, #0x00]
	movs r1, #0xCA
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r1, #0x0C
	bl TaskPoolInit
	pop {r4}
	pop {r0}
	bx r0
_08050FCC: .4byte 0x0813F588
_08050FD0: .4byte 0xFFFFD000
_08050FD4: .4byte 0x00000000
_08050FD8: .4byte 0x00000800
_08050FDC: .4byte 0x0813F480
.syntax divided
