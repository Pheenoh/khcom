.syntax unified
	.align 2, 0
	.global task_bos_lst_lsr_0
	.thumb
	.thumb_func
	.type task_bos_lst_lsr_0, %function
task_bos_lst_lsr_0: @ 081116D0
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x04]
	ldr r0, [r1, #0x04]
	str r0, [r4, #0x08]
	ldr r0, [r1, #0x08]
	str r0, [r4, #0x0C]
	movs r0, #0x00
	strh r0, [r4, #0x00]
	ldr r0, _08111718 @ =0x09CD0334
	movs r1, #0x90
	lsls r1, r1, #0x04
	bl func_080026A4
	str r0, [r4, #0x3C]
	ldr r0, _0811171C @ =0x09D69594
	movs r1, #0x60
	bl func_08002A14
	str r0, [r4, #0x40]
	adds r4, #0x44
	ldr r1, _08111720 @ =0x09EFBF18
	ldr r2, _08111724 @ =0x09EFBEC4
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x04
	movs r2, #0x00
	bl func_080059A4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08111718: .4byte 0x09CD0334
_0811171C: .4byte 0x09D69594
_08111720: .4byte 0x09EFBF18
_08111724: .4byte 0x09EFBEC4
.syntax divided
