.syntax unified
	.align 2, 0
	.global func_080E58F8
	.thumb
	.thumb_func
	.type func_080E58F8, %function
func_080E58F8: @ 080E58F8
	push {lr}
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080E55A4
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
