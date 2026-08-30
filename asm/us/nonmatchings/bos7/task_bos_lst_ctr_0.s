.syntax unified
	.align 2, 0
	.global task_bos_lst_ctr_0
	.thumb
	.thumb_func
	.type task_bos_lst_ctr_0, %function
task_bos_lst_ctr_0: @ 08111F98
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x00]
	ldrh r0, [r1, #0x04]
	movs r2, #0x00
	strh r0, [r4, #0x04]
	ldrh r0, [r1, #0x06]
	strh r0, [r4, #0x06]
	strh r2, [r4, #0x08]
	strh r2, [r4, #0x0A]
	strh r2, [r4, #0x0C]
	ldr r0, [r1, #0x08]
	strh r0, [r4, #0x0E]
	str r2, [r4, #0x20]
	str r2, [r4, #0x24]
	str r2, [r4, #0x28]
	ldr r3, [r1, #0x0C]
	str r3, [r4, #0x14]
	ldr r2, [r1, #0x10]
	str r2, [r4, #0x18]
	ldr r0, [r1, #0x14]
	str r0, [r4, #0x1C]
	str r3, [r4, #0x2C]
	str r2, [r4, #0x30]
	str r0, [r4, #0x34]
	ldr r0, _08112000 @ =0x09C5C704
	movs r1, #0xA0
	lsls r1, r1, #0x03
	bl func_080026A4
	str r0, [r4, #0x5C]
	ldr r0, _08112004 @ =0x09D69594
	movs r1, #0x60
	bl func_08002A14
	str r0, [r4, #0x60]
	adds r4, #0x44
	ldr r1, _08112008 @ =0x09EFAF50
	ldr r2, _0811200C @ =0x09EFAF24
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x03
	movs r2, #0x01
	bl func_080059A4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08112000: .4byte 0x09C5C704
_08112004: .4byte 0x09D69594
_08112008: .4byte 0x09EFAF50
_0811200C: .4byte 0x09EFAF24
.syntax divided
