.syntax unified
	.align 2, 0
	.global m4aSoundMain
	.thumb
	.thumb_func
	.type m4aSoundMain, %function
m4aSoundMain: @ 0811FE64
	push {lr}
	bl _0811F150
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
