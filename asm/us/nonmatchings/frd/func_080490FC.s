.syntax unified
	.align 2, 0
	.global func_080490FC
	.thumb
	.thumb_func
	.type func_080490FC, %function
func_080490FC: @ 080490FC
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x20
	adds r0, #0x24
	adds r1, r4, #0x0
	adds r1, #0x28
	adds r2, r4, #0x0
	adds r2, #0x2C
	adds r3, r4, #0x0
	adds r3, #0x30
	bl func_0801C6D4
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08049134
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r0, [r5, #0x0C]
	ldr r1, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	ldr r0, _08049130 @ =0xFFFFFE00
	b _08049146
	.byte 0x00, 0x00
_08049130: .4byte 0xFFFFFE00
_08049134:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r2, r4, r0
	ldr r0, [r5, #0x0C]
	ldr r1, [r2, #0x00]
	adds r0, r0, r1
	str r0, [r5, #0x0C]
	ldr r0, [r2, #0x00]
	adds r0, #0x33
_08049146:
	str r0, [r2, #0x00]
	ldr r0, [r5, #0x0C]
	ldr r1, [r5, #0x10]
	cmp r0, r1
	bgt _08049154
	movs r0, #0x00
	b _08049162
_08049154:
	str r1, [r5, #0x0C]
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r1, r4, r0
	movs r0, #0x00
	str r0, [r1, #0x00]
	movs r0, #0x01
_08049162:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
