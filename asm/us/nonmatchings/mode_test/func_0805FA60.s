.syntax unified
	.align 2, 0
	.global func_0805FA60
	.thumb
	.thumb_func
	.type func_0805FA60, %function
func_0805FA60: @ 0805FA60
	push {r4, lr}
	adds r2, r1, #0x0
	lsls r3, r3, #0x18
	lsrs r1, r3, #0x18
	adds r4, r1, #0x0
	cmp r2, #0x00
	beq _0805FA7E
	lsls r1, r1, #0x05
	movs r0, #0xA0
	lsls r0, r0, #0x13
	adds r1, r1, r0
	adds r0, r2, #0x0
	movs r2, #0x20
	bl func_08005BE8
_0805FA7E:
	ldr r0, _0805FA88 @ =0x02034A18
	strb r4, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
_0805FA88: .4byte 0x02034A18
.syntax divided
