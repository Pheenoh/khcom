.syntax unified
	.align 2, 0
	.global func_08006390
	.thumb
	.thumb_func
	.type func_08006390, %function
func_08006390: @ 08006390
	ldr r0, _080063A4 @ =0x03007568
	ldr r0, [r0, #0x00]
	movs r1, #0xB0
	lsls r1, r1, #0x03
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	lsls r0, r0, #0x08
	lsrs r0, r0, #0x10
	bx lr
	.byte 0x00, 0x00
_080063A4: .4byte 0x03007568
.syntax divided
