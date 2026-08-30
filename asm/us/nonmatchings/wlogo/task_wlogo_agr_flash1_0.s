.syntax unified
	.align 2, 0
	.global task_wlogo_agr_flash1_0
	.thumb
	.thumb_func
	.type task_wlogo_agr_flash1_0, %function
task_wlogo_agr_flash1_0: @ 080B65C4
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldrb r0, [r1, #0x0C]
	adds r5, r6, #0x0
	adds r5, #0x28
	strb r0, [r5, #0x00]
	ldrh r0, [r1, #0x08]
	strh r0, [r6, #0x24]
	ldrh r0, [r1, #0x0A]
	strh r0, [r6, #0x26]
	ldr r0, _080B6614 @ =0x0961DC0E
	movs r1, #0xEF
	lsls r1, r1, #0x05
	bl func_080026A4
	str r0, [r6, #0x00]
	ldr r0, _080B6618 @ =0x096FADE4
	movs r1, #0x20
	bl func_08002A14
	str r0, [r6, #0x04]
	adds r4, r6, #0x0
	adds r4, #0x0C
	ldr r1, _080B661C @ =0x09EF36AC
	ldr r2, _080B6620 @ =0x09EF3614
	adds r0, r4, #0x0
	bl func_08005968
	ldrb r1, [r5, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x01
	bl func_080059A4
	adds r0, r4, #0x0
	bl func_08005AFC
	str r0, [r6, #0x08]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080B6614: .4byte 0x0961DC0E
_080B6618: .4byte 0x096FADE4
_080B661C: .4byte 0x09EF36AC
_080B6620: .4byte 0x09EF3614
.syntax divided
