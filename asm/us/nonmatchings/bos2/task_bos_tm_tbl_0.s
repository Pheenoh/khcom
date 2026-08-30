.syntax unified
	.align 2, 0
	.global task_bos_tm_tbl_0
	.thumb
	.thumb_func
	.type task_bos_tm_tbl_0, %function
task_bos_tm_tbl_0: @ 080BCBA4
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	adds r4, r6, #0x4
	adds r0, r4, #0x0
	movs r1, #0x07
	movs r2, #0x1C
	movs r3, #0x00
	bl func_080122AC
	movs r1, #0x80
	lsls r1, r1, #0x09
	movs r2, #0xB0
	lsls r2, r2, #0x09
	adds r0, r4, #0x0
	movs r3, #0x00
	bl func_08012324
	adds r0, r4, #0x0
	movs r1, #0x00
	bl func_08012614
	movs r0, #0x01
	bl func_0800501C
	str r5, [r6, #0x00]
	movs r1, #0x00
	str r1, [r6, #0x68]
	adds r2, r6, #0x0
	adds r2, #0x62
	movs r0, #0x01
	strb r0, [r2, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x64
	movs r2, #0x00
	strh r1, [r0, #0x00]
	adds r0, #0x02
	strb r2, [r0, #0x00]
	adds r0, #0x01
	strb r2, [r0, #0x00]
	subs r0, #0x07
	strh r1, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
