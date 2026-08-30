.syntax unified
	.align 2, 0
	.global func_080DFB7C
	.thumb
	.thumb_func
	.type func_080DFB7C, %function
func_080DFB7C: @ 080DFB7C
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	bl func_080E5590
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
