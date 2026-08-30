.syntax unified
	.align 2, 0
	.global task_wlogo_agr_0
	.thumb
	.thumb_func
	.type task_wlogo_agr_0, %function
task_wlogo_agr_0: @ 080B5F94
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	movs r6, #0x00
	strb r1, [r4, #0x17]
	ldr r5, _080B6008 @ =0x096FADE4
	movs r0, #0x00
	adds r1, r5, #0x0
	movs r2, #0x20
	bl func_080050DC
	ldr r1, _080B600C @ =0x096B9C64
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
	ldr r1, _080B6010 @ =0x09642CE4
	movs r2, #0xC0
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_080050B8
	ldr r0, _080B6014 @ =0x0961DC0E
	movs r1, #0xEF
	lsls r1, r1, #0x05
	bl func_080026A4
	str r0, [r4, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x20
	bl func_08002A14
	str r0, [r4, #0x04]
	ldr r0, _080B6018 @ =0x09EF3614
	ldr r0, [r0, #0x2C]
	str r0, [r4, #0x08]
	movs r1, #0x00
	movs r0, #0x40
	strh r0, [r4, #0x0C]
	strh r0, [r4, #0x0E]
	strb r1, [r4, #0x10]
	strh r6, [r4, #0x12]
	strb r1, [r4, #0x11]
	strh r6, [r4, #0x14]
	strb r1, [r4, #0x16]
	movs r0, #0x00
	movs r1, #0x10
	movs r2, #0x00
	bl func_080057A0
	ldr r0, _080B601C @ =0x02034C80
	movs r1, #0x32
	bl func_08000E64
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B6008: .4byte 0x096FADE4
_080B600C: .4byte 0x096B9C64
_080B6010: .4byte 0x09642CE4
_080B6014: .4byte 0x0961DC0E
_080B6018: .4byte 0x09EF3614
_080B601C: .4byte 0x02034C80
.syntax divided
