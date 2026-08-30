.syntax unified
	.align 2, 0
	.global func_0809D280
	.thumb
	.thumb_func
	.type func_0809D280, %function
func_0809D280: @ 0809D280
	adds r2, r0, #0x0
	movs r3, #0x00
	cmp r2, #0x00
	bne _0809D28C
	movs r0, #0x00
	b _0809D2AC
_0809D28C:
	ldrb r0, [r2, #0x00]
	adds r2, #0x01
	cmp r0, #0x00
	beq _0809D2A6
_0809D294:
	ldrb r1, [r2, #0x00]
	cmp r1, #0x00
	beq _0809D2A0
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
_0809D2A0:
	adds r2, #0x01
	cmp r1, #0x00
	bne _0809D294
_0809D2A6:
	adds r0, r3, #0x1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_0809D2AC:
	bx lr
	.byte 0x00, 0x00
.syntax divided
