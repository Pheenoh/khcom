.syntax unified
	.align 2, 0
	.global func_080DFAA8
	.thumb
	.thumb_func
	.type func_080DFAA8, %function
func_080DFAA8: @ 080DFAA8
	push {r4, lr}
	ldr r2, _080DFAE8 @ =0x02039BB0
	movs r0, #0x0E
	ldsb r0, [r2, r0]
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldr r3, _080DFAEC @ =0x0203C590
	ldrh r1, [r3, #0x02]
	movs r4, #0xC2
	lsls r4, r4, #0x01
	adds r0, r0, r4
	strh r1, [r0, #0x00]
	movs r0, #0x0E
	ldsb r0, [r2, r0]
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldrb r1, [r3, #0x04]
	adds r4, #0x02
	adds r0, r0, r4
	strb r1, [r0, #0x00]
	movs r0, #0x0E
	ldsb r0, [r2, r0]
	lsls r0, r0, #0x02
	adds r0, r0, r2
	ldrb r1, [r3, #0x05]
	ldr r2, _080DFAF0 @ =0x00000187
	adds r0, r0, r2
	strb r1, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DFAE8: .4byte 0x02039BB0
_080DFAEC: .4byte 0x0203C590
_080DFAF0: .4byte 0x00000187
.syntax divided
