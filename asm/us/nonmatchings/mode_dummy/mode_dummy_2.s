.syntax unified
	.align 2, 0
	.global mode_dummy_2
	.thumb
	.thumb_func
	.type mode_dummy_2, %function
mode_dummy_2: @ 0800C1AC
	push {lr}
	bl func_080609A0
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
