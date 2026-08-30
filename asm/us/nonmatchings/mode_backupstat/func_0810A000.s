.syntax unified
	.align 2, 0
	.global func_0810A000
	.thumb
	.thumb_func
	.type func_0810A000, %function
func_0810A000: @ 0810A000
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r3, _0810A014 @ =0xFFFFEFFC
	adds r0, r3, #0x0
	subs r0, r0, r1
	orrs r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bx lr
	.byte 0x00, 0x00
_0810A014: .4byte 0xFFFFEFFC
.syntax divided
