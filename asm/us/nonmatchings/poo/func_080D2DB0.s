.syntax unified
	.align 2, 0
	.global func_080D2DB0
	.thumb
	.thumb_func
	.type func_080D2DB0, %function
func_080D2DB0: @ 080D2DB0
	push {lr}
	ldr r1, _080D2DC0 @ =0x0203C470
	movs r2, #0x44
	bl _0811F030
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D2DC0: .4byte 0x0203C470
.syntax divided
