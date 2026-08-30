.syntax unified
	.align 2, 0
	.global func_080B8334
	.thumb
	.thumb_func
	.type func_080B8334, %function
func_080B8334: @ 080B8334
	push {r4, r5, r6, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	adds r4, r1, #0x0
	adds r5, r2, #0x0
	lsls r4, r4, #0x10
	asrs r4, r4, #0x08
	str r4, [r6, #0x04]
	lsls r5, r5, #0x10
	asrs r5, r5, #0x08
	str r5, [r6, #0x08]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x08
	movs r0, #0xC8
	lsls r0, r0, #0x05
	adds r3, r3, r0
	str r3, [r6, #0x0C]
	ldr r1, _080B8398 @ =0x09619C94
	str r3, [sp, #0x000]
	adds r0, r6, #0x0
	adds r2, r4, #0x0
	adds r3, r5, #0x0
	bl func_0801B37C
	adds r1, r6, #0x0
	adds r1, #0x9E
	movs r0, #0x0E
	strh r0, [r1, #0x00]
	adds r1, #0x02
	movs r0, #0x28
	strh r0, [r1, #0x00]
	subs r1, #0x04
	movs r0, #0x1C
	strh r0, [r1, #0x00]
	ldr r2, [r6, #0x34]
	ldr r3, [r6, #0x38]
	ldr r0, _080B839C @ =0x00000400
	ldr r1, _080B83A0 @ =0x00000000
	orrs r2, r0
	movs r4, #0x04
	movs r5, #0x00
	adds r0, r2, #0x0
	orrs r0, r4
	adds r1, r3, #0x0
	str r0, [r6, #0x34]
	str r1, [r6, #0x38]
	add sp, #0x004
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080B8398: .4byte 0x09619C94
_080B839C: .4byte 0x00000400
_080B83A0: .4byte 0x00000000
.syntax divided
