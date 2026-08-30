.syntax unified
	.align 2, 0
	.global func_080D8584
	.thumb
	.thumb_func
	.type func_080D8584, %function
func_080D8584: @ 080D8584
	movs r1, #0x90
	lsls r1, r1, #0x01
	adds r0, r0, r1
	movs r1, #0x00
	strh r1, [r0, #0x00]
	bx lr
.syntax divided
