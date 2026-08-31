.syntax unified
	.align 2, 0
	.global func_0800E380
	.thumb
	.thumb_func
	.type func_0800E380, %function
func_0800E380: @ 0800E380
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	ldr r6, _0800E3CC @ =0x02039B84
	ldr r1, [r6, #0x00]
	adds r5, r4, #0x0
	adds r5, #0x40
	ldr r0, [r1, #0x78]
	cmp r0, r5
	bne _0800E396
	movs r0, #0x00
	str r0, [r1, #0x78]
_0800E396:
	ldr r0, [r4, #0x0C]
	bl func_0800E364
	ldr r0, [r4, #0x10]
	bl func_0800E364
	ldr r0, [r6, #0x00]
	adds r0, #0xA8
	movs r1, #0x00
	str r1, [r0, #0x00]
	adds r0, r5, #0x0
	bl func_0801B7D8
	ldr r0, [r4, #0x04]
	bl ReleaseObjTiles
	ldr r0, [r4, #0x08]
	bl ReleaseObjPalette
	adds r0, r4, #0x0
	adds r0, #0x2C
	bl TaskPoolDestroy
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0800E3CC: .4byte 0x02039B84
.syntax divided
