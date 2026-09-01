.syntax unified
	.align 2, 0
	.global func_0805F1C0
	.thumb
	.thumb_func
	.type func_0805F1C0, %function
func_0805F1C0: @ 0805F1C0
	ldr r2, [r0, #0x00]
	subs r1, r1, r2
	asrs r1, r1, #0x01
	adds r2, r2, r1
	str r2, [r0, #0x00]
	bx lr
.syntax divided
