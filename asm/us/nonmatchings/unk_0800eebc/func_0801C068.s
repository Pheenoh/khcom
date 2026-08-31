.syntax unified
	.align 2, 0
	.global func_0801C068
	.thumb
	.thumb_func
	.type func_0801C068, %function
func_0801C068: @ 0801C068
	push {r4, r5, lr}
	ldr r0, _0801C084 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _0801C08C
	movs r0, #0x84
	lsls r0, r0, #0x04
	movs r1, #0x00
	bl AllocObjTiles
	ldr r1, _0801C088 @ =0x02039B84
	b _0801C0D2
_0801C084: .4byte 0x02039BB0
_0801C088: .4byte 0x02039B84
_0801C08C:
	movs r5, #0xC8
	lsls r5, r5, #0x04
	adds r0, r5, #0x0
	movs r1, #0x00
	bl AllocObjTiles
	ldr r4, _0801C0F4 @ =0x02039B84
	ldr r1, [r4, #0x00]
	movs r3, #0x88
	lsls r3, r3, #0x01
	adds r1, r1, r3
	str r0, [r1, #0x00]
	movs r0, #0xA0
	lsls r0, r0, #0x04
	movs r1, #0x00
	bl AllocObjTiles
	ldr r2, [r4, #0x00]
	movs r3, #0x8A
	lsls r3, r3, #0x01
	adds r1, r2, r3
	str r0, [r1, #0x00]
	ldr r0, [r2, #0x68]
	ldr r1, [r2, #0x6C]
	movs r2, #0x80
	lsls r2, r2, #0x07
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0801C0DC
	adds r0, r5, #0x0
	bl AllocObjTiles
	ldr r1, _0801C0F8 @ =0x02039B9C
_0801C0D2:
	ldr r1, [r1, #0x00]
	movs r2, #0x88
	lsls r2, r2, #0x01
	adds r1, r1, r2
	str r0, [r1, #0x00]
_0801C0DC:
	ldr r0, _0801C0F4 @ =0x02039B84
	ldr r4, [r0, #0x00]
	ldr r0, [r4, #0x68]
	ldr r1, [r4, #0x6C]
	ldr r2, _0801C0FC @ =0x00000000
	ldr r3, _0801C100 @ =0x00010000
	orrs r1, r3
	str r0, [r4, #0x68]
	str r1, [r4, #0x6C]
	pop {r4, r5}
	pop {r0}
	bx r0
_0801C0F4: .4byte 0x02039B84
_0801C0F8: .4byte 0x02039B9C
_0801C0FC: .4byte 0x00000000
_0801C100: .4byte 0x00010000
.syntax divided
