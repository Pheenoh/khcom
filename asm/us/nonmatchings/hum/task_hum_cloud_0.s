.syntax unified
	.align 2, 0
	.global task_hum_cloud_0
	.thumb
	.thumb_func
	.type task_hum_cloud_0, %function
task_hum_cloud_0: @ 0804A014
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r1, _0804A038 @ =0x0813EF28
	bl func_0800E168
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x00
	str r0, [r1, #0x00]
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r4, r4, r0
	ldr r0, _0804A03C @ =0x0813EDD0
	str r0, [r4, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_0804A038: .4byte 0x0813EF28
_0804A03C: .4byte 0x0813EDD0
.syntax divided
