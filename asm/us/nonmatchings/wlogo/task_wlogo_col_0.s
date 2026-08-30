.syntax unified
	.align 2, 0
	.global task_wlogo_col_0
	.thumb
	.thumb_func
	.type task_wlogo_col_0, %function
task_wlogo_col_0: @ 080B59C8
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldr r5, _080B5A78 @ =0x096FADC4
	movs r0, #0x00
	adds r1, r5, #0x0
	movs r2, #0x20
	bl func_080050DC
	ldr r1, _080B5A7C @ =0x0963CC84
	movs r2, #0x83
	lsls r2, r2, #0x05
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080B5A80 @ =0x096B9464
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl func_0800510C
	ldr r4, _080B5A84 @ =0x096424E4
	movs r0, #0x00
	bl func_08005130
	adds r1, r0, #0x0
	movs r2, #0xC4
	lsls r2, r2, #0x03
	adds r0, r4, #0x0
	bl func_080043B4
	ldr r0, _080B5A88 @ =0x0961C7F4
	movs r1, #0x8A
	lsls r1, r1, #0x05
	bl func_080026A4
	str r0, [r6, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x04]
	ldr r2, _080B5A8C @ =0x0961C792
	ldrh r0, [r2, #0x00]
	movs r1, #0x00
	movs r3, #0x00
	strh r0, [r6, #0x08]
	ldrh r0, [r2, #0x02]
	strh r0, [r6, #0x0A]
	strh r3, [r6, #0x2A]
	adds r0, r6, #0x0
	adds r0, #0x28
	strb r1, [r0, #0x00]
	adds r2, r6, #0x0
	adds r2, #0x30
	strb r1, [r2, #0x00]
	adds r0, #0x04
	strb r1, [r0, #0x00]
	strh r3, [r6, #0x2E]
	adds r0, #0x05
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
	ldr r1, _080B5A90 @ =0x09EF3610
	ldr r2, _080B5A94 @ =0x09EF35B8
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
	.byte 0x00, 0x00
_080B5A78: .4byte 0x096FADC4
_080B5A7C: .4byte 0x0963CC84
_080B5A80: .4byte 0x096B9464
_080B5A84: .4byte 0x096424E4
_080B5A88: .4byte 0x0961C7F4
_080B5A8C: .4byte 0x0961C792
_080B5A90: .4byte 0x09EF3610
_080B5A94: .4byte 0x09EF35B8
.syntax divided
