.syntax unified
	.align 2, 0
	.global func_080D855C
	.thumb
	.thumb_func
	.type func_080D855C, %function
func_080D855C: @ 080D855C
	ldr r1, _080D8580 @ =0x02034F04
	ldr r3, [r1, #0x00]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x0E
	movs r2, #0x98
	lsls r2, r2, #0x03
	adds r1, r3, r2
	ldr r1, [r1, #0x00]
	ldr r2, [r1, #0x00]
	lsls r1, r2, #0x03
	adds r1, r1, r2
	lsls r1, r1, #0x03
	adds r1, r1, r2
	lsls r1, r1, #0x02
	adds r0, r0, r1
	adds r3, r3, r0
	ldr r0, [r3, #0x00]
	bx lr
_080D8580: .4byte 0x02034F04
.syntax divided
