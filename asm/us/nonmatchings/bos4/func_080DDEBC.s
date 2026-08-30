.syntax unified
	.align 2, 0
	.global func_080DDEBC
	.thumb
	.thumb_func
	.type func_080DDEBC, %function
func_080DDEBC: @ 080DDEBC
	push {lr}
	bl func_080D2DC4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
