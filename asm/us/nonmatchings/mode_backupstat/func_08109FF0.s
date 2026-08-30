.syntax unified
	.align 2, 0
	.global func_08109FF0
	.thumb
	.thumb_func
	.type func_08109FF0, %function
func_08109FF0: @ 08109FF0
	push {lr}
	adds r0, r1, #0x0
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
.syntax divided
