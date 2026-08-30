.syntax unified
	.align 2, 0
	.global func_080D8590
	.thumb
	.thumb_func
	.type func_080D8590, %function
func_080D8590: @ 080D8590
	movs r2, #0x90
	lsls r2, r2, #0x01
	adds r3, r0, r2
	ldrh r2, [r3, #0x00]
	lsls r2, r2, #0x02
	adds r0, r0, r2
	str r1, [r0, #0x00]
	ldrh r0, [r3, #0x00]
	adds r0, #0x01
	strh r0, [r3, #0x00]
	bx lr
	.byte 0x00, 0x00
.syntax divided
