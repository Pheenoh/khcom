.syntax unified
	.align 2, 0
	.global VBlankIntrWait
	.thumb
	.thumb_func
	.type VBlankIntrWait, %function
VBlankIntrWait:
	movs r2, #0
	swi #5
	bx lr
	.align 2, 0
.syntax divided
