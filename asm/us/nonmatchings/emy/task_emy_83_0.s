.syntax unified
	.align 2, 0
	.global task_emy_83_0
	.thumb
	.thumb_func
	.type task_emy_83_0, %function
task_emy_83_0: @ 0803E580
	push {r4, lr}
	adds r4, r0, #0x0
	adds r2, r1, #0x0
	ldr r1, _0803E5B4 @ =0x0813E6AC
	bl func_0800C778
	movs r0, #0xC2
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x00
	str r0, [r1, #0x00]
	movs r0, #0xA8
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x16
	str r0, [r1, #0x00]
	movs r1, #0xC4
	lsls r1, r1, #0x01
	adds r0, r4, r1
	movs r1, #0x04
	bl func_08000E64
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803E5B4: .4byte 0x0813E6AC
.syntax divided
