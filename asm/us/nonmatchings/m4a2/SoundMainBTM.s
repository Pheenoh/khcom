.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global SoundMainBTM
	.thumb
	.thumb_func
	.type SoundMainBTM, %function
SoundMainBTM:
	mov r12, r4
	movs r1, 0
	movs r2, 0
	movs r3, 0
	movs r4, 0
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	stm r0!, {r1-r4}
	mov r4, r12
	bx lr
	.align 2, 0
.syntax divided
