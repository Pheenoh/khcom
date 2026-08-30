.syntax unified
	.align 2, 0
	.global task_hum_lexceus_0
	.thumb
	.thumb_func
	.type task_hum_lexceus_0, %function
task_hum_lexceus_0: @ 080560F8
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _08056150 @ =0x0813FB38
	bl func_0800E168
	movs r1, #0xE5
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r1, #0x00
	strh r1, [r0, #0x00]
	movs r2, #0xE2
	lsls r2, r2, #0x01
	adds r0, r4, r2
	str r1, [r0, #0x00]
	adds r2, #0x08
	adds r0, r4, r2
	strh r1, [r0, #0x00]
	adds r2, #0x2C
	adds r0, r4, r2
	strh r1, [r0, #0x00]
	subs r2, #0x08
	adds r0, r4, r2
	str r1, [r0, #0x00]
	adds r2, #0x04
	adds r0, r4, r2
	str r1, [r0, #0x00]
	adds r2, #0x08
	adds r0, r4, r2
	str r1, [r0, #0x00]
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r1, r4, r0
	ldr r0, _08056154 @ =0x0813FA8C
	str r0, [r1, #0x00]
	movs r1, #0xEC
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r1, #0x03
	bl func_08000E64
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08056150: .4byte 0x0813FB38
_08056154: .4byte 0x0813FA8C
.syntax divided
