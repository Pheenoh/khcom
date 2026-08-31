.syntax unified
	.align 2, 0
	.global task_wlogo_agr_flash0_0
	.thumb
	.thumb_func
	.type task_wlogo_agr_flash0_0, %function
task_wlogo_agr_flash0_0: @ 080B64F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	adds r5, r6, #0x0
	adds r5, #0x28
	movs r0, #0x04
	strb r0, [r5, #0x00]
	movs r0, #0x40
	strh r0, [r6, #0x24]
	strh r0, [r6, #0x26]
	ldr r0, _080B6548 @ =0x0961DC0E
	movs r1, #0xEF
	lsls r1, r1, #0x05
	bl LoadObjTiles
	str r0, [r6, #0x00]
	ldr r0, _080B654C @ =0x096FADE4
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r6, #0x04]
	adds r4, r6, #0x0
	adds r4, #0x0C
	ldr r1, _080B6550 @ =0x09EF36AC
	ldr r2, _080B6554 @ =0x09EF3614
	adds r0, r4, #0x0
	bl AnimInit
	ldrb r1, [r5, #0x00]
	adds r0, r4, #0x0
	movs r2, #0x00
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	str r0, [r6, #0x08]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B6548: .4byte 0x0961DC0E
_080B654C: .4byte 0x096FADE4
_080B6550: .4byte 0x09EF36AC
_080B6554: .4byte 0x09EF3614
.syntax divided
