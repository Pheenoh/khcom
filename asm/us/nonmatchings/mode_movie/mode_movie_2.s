.syntax unified
	.align 2, 0
	.global mode_movie_2
	.thumb
	.thumb_func
	.type mode_movie_2, %function
mode_movie_2: @ 0805F0D8
	ldr r1, _0805F0E0 @ =0x03007484
	movs r0, #0x00
	str r0, [r1, #0x00]
	bx lr
_0805F0E0: .4byte 0x03007484
.syntax divided
