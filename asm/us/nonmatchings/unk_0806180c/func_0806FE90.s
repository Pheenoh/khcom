.syntax unified
	.align 2, 0
	.global func_0806FE90
	.thumb
	.thumb_func
	.type func_0806FE90, %function
func_0806FE90: @ 0806FE90
	push {r4, r5, lr}
	adds r5, r0, #0x0
	bl GetKeysHeld
	lsls r0, r0, #0x10
	movs r1, #0xF0
	lsls r1, r1, #0x10
	ands r1, r0
	lsrs r4, r1, #0x10
	cmp r4, #0x50
	bne _0806FEA8
	b _0806FFD0
_0806FEA8:
	cmp r4, #0x50
	bgt _0806FEC0
	cmp r4, #0x20
	beq _0806FF54
	cmp r4, #0x20
	bgt _0806FEBA
	cmp r4, #0x10
	beq _0806FF8C
	b _0806FFFC
_0806FEBA:
	cmp r4, #0x40
	beq _0806FEDE
	b _0806FFFC
_0806FEC0:
	cmp r4, #0x80
	beq _0806FF20
	cmp r4, #0x80
	bgt _0806FED0
	cmp r4, #0x60
	bne _0806FECE
	b _0806FFDC
_0806FECE:
	b _0806FFFC
_0806FED0:
	cmp r4, #0x90
	bne _0806FED6
	b _0806FFE8
_0806FED6:
	cmp r4, #0xA0
	bne _0806FEDC
	b _0806FFF4
_0806FEDC:
	b _0806FFFC
_0806FEDE:
	movs r0, #0x20
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _0806FEF8
	ldr r0, _0806FEF4 @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0xD3
	b _0806FFFA
_0806FEF4: .4byte 0x000001AB
_0806FEF8:
	movs r0, #0x10
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _0806FF14
	ldr r0, _0806FF10 @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0x2D
	b _0806FFFA
	.byte 0x00, 0x00
_0806FF10: .4byte 0x000001AB
_0806FF14:
	ldr r0, _0806FF1C @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0x00
	b _0806FFFA
_0806FF1C: .4byte 0x000001AB
_0806FF20:
	movs r0, #0x20
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bls _0806FFF4
	movs r0, #0x10
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _0806FF48
	ldr r0, _0806FF44 @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0x53
	b _0806FFFA
_0806FF44: .4byte 0x000001AB
_0806FF48:
	ldr r1, _0806FF50 @ =0x000001AB
	adds r0, r5, r1
	strb r4, [r0, #0x00]
	b _0806FFFC
_0806FF50: .4byte 0x000001AB
_0806FF54:
	movs r0, #0x40
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _0806FF70
	ldr r0, _0806FF6C @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0xD3
	b _0806FFFA
	.byte 0x00, 0x00
_0806FF6C: .4byte 0x000001AB
_0806FF70:
	movs r0, #0x80
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bls _0806FFF4
	ldr r0, _0806FF88 @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0xC0
	b _0806FFFA
	.byte 0x00, 0x00
_0806FF88: .4byte 0x000001AB
_0806FF8C:
	movs r0, #0x40
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _0806FFA8
	ldr r0, _0806FFA4 @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0x2D
	b _0806FFFA
	.byte 0x00, 0x00
_0806FFA4: .4byte 0x000001AB
_0806FFA8:
	movs r0, #0x80
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _0806FFC4
	ldr r0, _0806FFC0 @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0x53
	b _0806FFFA
	.byte 0x00, 0x00
_0806FFC0: .4byte 0x000001AB
_0806FFC4:
	ldr r0, _0806FFCC @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0x40
	b _0806FFFA
_0806FFCC: .4byte 0x000001AB
_0806FFD0:
	ldr r0, _0806FFD8 @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0x2D
	b _0806FFFA
_0806FFD8: .4byte 0x000001AB
_0806FFDC:
	ldr r0, _0806FFE4 @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0xD3
	b _0806FFFA
_0806FFE4: .4byte 0x000001AB
_0806FFE8:
	ldr r0, _0806FFF0 @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0x53
	b _0806FFFA
_0806FFF0: .4byte 0x000001AB
_0806FFF4:
	ldr r0, _08070004 @ =0x000001AB
	adds r1, r5, r0
	movs r0, #0xAD
_0806FFFA:
	strb r0, [r1, #0x00]
_0806FFFC:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08070004: .4byte 0x000001AB
.syntax divided
