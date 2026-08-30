.syntax unified
	.align 2, 0
	.global task_wlogo_tvt_0
	.thumb
	.thumb_func
	.type task_wlogo_tvt_0, %function
task_wlogo_tvt_0: @ 080B6690
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldr r5, _080B673C @ =0x096FAE44
	movs r0, #0x00
	adds r1, r5, #0x0
	movs r2, #0x20
	bl func_080050DC
	ldr r1, _080B6740 @ =0x09645C84
	movs r2, #0xC0
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080B6744 @ =0x096BCC64
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
	ldr r4, _080B6748 @ =0x096474A4
	movs r0, #0x00
	bl func_08005130
	adds r1, r0, #0x0
	adds r1, #0x20
	movs r2, #0xC0
	lsls r2, r2, #0x02
	adds r0, r4, #0x0
	bl func_080043B4
	movs r0, #0xF0
	lsls r0, r0, #0x03
	ldr r1, _080B674C @ =0x09620B0E
	bl func_080028F8
	str r0, [r6, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x04]
	movs r1, #0x00
	movs r3, #0x00
	movs r0, #0x40
	strh r0, [r6, #0x08]
	strh r0, [r6, #0x0A]
	strh r3, [r6, #0x2A]
	adds r0, r6, #0x0
	adds r0, #0x29
	strb r1, [r0, #0x00]
	adds r2, r6, #0x0
	adds r2, #0x30
	strb r1, [r2, #0x00]
	adds r0, #0x03
	strb r1, [r0, #0x00]
	strh r3, [r6, #0x2E]
	subs r0, #0x04
	strb r1, [r0, #0x00]
	ldrb r2, [r2, #0x00]
	movs r1, #0x10
	subs r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x00
	bl func_080057A0
	adds r4, r6, #0x0
	adds r4, #0x10
	ldr r1, _080B6750 @ =0x09EF3730
	ldr r2, _080B6754 @ =0x09EF36D8
	adds r0, r4, #0x0
	bl func_08005968
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x00
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r6, #0x0C]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080B673C: .4byte 0x096FAE44
_080B6740: .4byte 0x09645C84
_080B6744: .4byte 0x096BCC64
_080B6748: .4byte 0x096474A4
_080B674C: .4byte 0x09620B0E
_080B6750: .4byte 0x09EF3730
_080B6754: .4byte 0x09EF36D8
.syntax divided
