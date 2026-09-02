.syntax unified
	.include "gba_constants.inc"
	.align 2, 0
	.global umul3232H32
	.thumb
	.thumb_func
	.type umul3232H32, %function
umul3232H32:
	adr r2, __umul3232H32
	bx r2
	.arm
__umul3232H32:
	umull r2, r3, r0, r1
	add r0, r3, 0
	bx lr
.syntax divided
