.syntax unified
	.align 2, 0
	.global func_0801DEB8
	.thumb
	.thumb_func
	.type func_0801DEB8, %function
func_0801DEB8: @ 0801DEB8
	push {r4, lr}
	adds r4, r0, #0x0
	movs r1, #0x92
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	subs r1, #0x14
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x00]
	adds r1, #0x62
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0801DEE0
	ldr r0, _0801DEDC @ =0x08F683A4
	b _0801DEE2
	.byte 0x00, 0x00
_0801DEDC: .4byte 0x08F683A4
_0801DEE0:
	ldr r0, _0801DEF0 @ =0x096FAC64
_0801DEE2:
	movs r1, #0x20
	bl LoadObjPalette
	str r0, [r4, #0x04]
	pop {r4}
	pop {r0}
	bx r0
_0801DEF0: .4byte 0x096FAC64
.syntax divided
