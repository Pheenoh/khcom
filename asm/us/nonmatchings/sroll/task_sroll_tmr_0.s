.syntax unified
	.align 2, 0
	.global task_sroll_tmr_0
	.thumb
	.thumb_func
	.type task_sroll_tmr_0, %function
task_sroll_tmr_0: @ 081152A4
	push {r4, lr}
	adds r4, r0, #0x0
	movs r0, #0x00
	strb r0, [r4, #0x00]
	str r0, [r4, #0x04]
	ldr r0, _081152CC @ =0x09C904B4
	movs r1, #0xB0
	lsls r1, r1, #0x01
	bl func_080026A4
	str r0, [r4, #0x08]
	ldr r0, _081152D0 @ =0x09D6D114
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x0C]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081152CC: .4byte 0x09C904B4
_081152D0: .4byte 0x09D6D114
.syntax divided
