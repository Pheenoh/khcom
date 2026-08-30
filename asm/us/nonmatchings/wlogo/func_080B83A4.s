.syntax unified
	.align 2, 0
	.global func_080B83A4
	.thumb
	.thumb_func
	.type func_080B83A4, %function
func_080B83A4: @ 080B83A4
	lsls r1, r1, #0x10
	asrs r1, r1, #0x08
	str r1, [r0, #0x04]
	lsls r2, r2, #0x10
	asrs r2, r2, #0x08
	str r2, [r0, #0x08]
	lsls r3, r3, #0x10
	asrs r3, r3, #0x08
	str r3, [r0, #0x0C]
	bx lr
.syntax divided
