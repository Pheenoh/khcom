.syntax unified
	.align 2, 0
	.global mode_test_0
	.thumb
	.thumb_func
	.type mode_test_0, %function
mode_test_0: @ 0805F0E4
	push {lr}
	ldr r1, _0805F10C @ =0x02034A10
	movs r0, #0x00
	str r0, [r1, #0x00]
	ldr r0, _0805F110 @ =0x08B24DAA
	movs r1, #0xF8
	lsls r1, r1, #0x03
	bl LoadObjTiles
	ldr r1, _0805F114 @ =0x02034A08
	str r0, [r1, #0x00]
	ldr r0, _0805F118 @ =0x08F69BA4
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, _0805F11C @ =0x02034A0C
	str r0, [r1, #0x00]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805F10C: .4byte 0x02034A10
_0805F110: .4byte 0x08B24DAA
_0805F114: .4byte 0x02034A08
_0805F118: .4byte 0x08F69BA4
_0805F11C: .4byte 0x02034A0C
.syntax divided
