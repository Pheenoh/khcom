.syntax unified
	.align 2, 0
	.global func_080062F4
	.thumb
	.thumb_func
	.type func_080062F4, %function
func_080062F4: @ 080062F4
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x18
	lsrs r3, r1, #0x18
	cmp r2, #0x1F
	bhi _0800630E
	ldr r0, _08006310 @ =0x03007568
	ldr r0, [r0, #0x00]
	movs r1, #0x2C
	muls r1, r2
	adds r0, r0, r1
	adds r0, #0x28
	strb r3, [r0, #0x00]
_0800630E:
	bx lr
_08006310: .4byte 0x03007568
.syntax divided
