.syntax unified
	.align 2, 0
	.global task_emy_08_3
	.thumb
	.thumb_func
	.type task_emy_08_3, %function
task_emy_08_3: @ 08038810
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_0800E0D0
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r4, r4, r0
	ldr r0, [r4, #0x00]
	bl ReleaseObjPalette
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
