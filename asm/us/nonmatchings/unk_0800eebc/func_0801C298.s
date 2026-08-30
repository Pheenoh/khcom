.syntax unified
	.align 2, 0
	.global func_0801C298
	.thumb
	.thumb_func
	.type func_0801C298, %function
func_0801C298: @ 0801C298
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	adds r4, r3, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r3, #0x1F
	bhi _0801C2D0
	cmp r1, #0x00
	beq _0801C2C0
	ldr r0, _0801C2BC @ =0x02039B84
	ldr r2, [r0, #0x00]
	adds r2, #0xFC
	movs r1, #0x01
	lsls r1, r3
	ldr r0, [r2, #0x00]
	orrs r0, r1
	b _0801C2CE
_0801C2BC: .4byte 0x02039B84
_0801C2C0:
	ldr r0, _0801C2D8 @ =0x02039B84
	ldr r2, [r0, #0x00]
	adds r2, #0xFC
	movs r1, #0x01
	lsls r1, r4
	ldr r0, [r2, #0x00]
	bics r0, r1
_0801C2CE:
	str r0, [r2, #0x00]
_0801C2D0:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801C2D8: .4byte 0x02039B84
.syntax divided
