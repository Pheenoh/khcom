.syntax unified
	.align 2, 0
	.global task_bos_lst_edg_0
	.thumb
	.thumb_func
	.type task_bos_lst_edg_0, %function
task_bos_lst_edg_0: @ 0811067C
	push {r4, lr}
	adds r4, r0, #0x0
	movs r0, #0x00
	strh r0, [r4, #0x00]
	strh r0, [r4, #0x02]
	strh r0, [r4, #0x04]
	ldr r0, [r1, #0x00]
	strh r0, [r4, #0x06]
	ldr r3, [r1, #0x04]
	str r3, [r4, #0x08]
	ldr r2, [r1, #0x08]
	str r2, [r4, #0x0C]
	ldr r0, [r1, #0x0C]
	str r0, [r4, #0x10]
	str r3, [r4, #0x14]
	str r2, [r4, #0x18]
	str r0, [r4, #0x1C]
	ldr r1, _081106D0 @ =0x09C5C4E2
	movs r0, #0x80
	bl func_080028F8
	str r0, [r4, #0x44]
	ldr r0, _081106D4 @ =0x09D69594
	movs r1, #0x60
	bl func_08002A14
	str r0, [r4, #0x48]
	adds r4, #0x2C
	ldr r1, _081106D8 @ =0x09EFAF1C
	ldr r2, _081106DC @ =0x09EFAEF8
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_081106D0: .4byte 0x09C5C4E2
_081106D4: .4byte 0x09D69594
_081106D8: .4byte 0x09EFAF1C
_081106DC: .4byte 0x09EFAEF8
.syntax divided
