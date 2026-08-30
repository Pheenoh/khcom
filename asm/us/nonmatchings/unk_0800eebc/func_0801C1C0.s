.syntax unified
	.align 2, 0
	.global func_0801C1C0
	.thumb
	.thumb_func
	.type func_0801C1C0, %function
func_0801C1C0: @ 0801C1C0
	lsls r0, r0, #0x18
	lsrs r1, r0, #0x18
	cmp r1, #0x04
	bhi _0801C1E2
	movs r0, #0x80
	lsls r0, r0, #0x11
	lsls r0, r1
	lsrs r3, r0, #0x18
	ldr r0, _0801C1E8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r2, r0, #0x0
	adds r2, #0xFB
	ldrb r1, [r2, #0x00]
	adds r0, r3, #0x0
	ands r0, r1
	cmp r0, #0x00
	bne _0801C1EC
_0801C1E2:
	movs r0, #0x00
	b _0801C1F4
	.byte 0x00, 0x00
_0801C1E8: .4byte 0x02039B84
_0801C1EC:
	adds r0, r1, #0x0
	bics r0, r3
	strb r0, [r2, #0x00]
	movs r0, #0x01
_0801C1F4:
	bx lr
	.byte 0x00, 0x00
.syntax divided
