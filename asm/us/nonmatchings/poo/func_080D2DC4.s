.syntax unified
	.align 2, 0
	.global func_080D2DC4
	.thumb
	.thumb_func
	.type func_080D2DC4, %function
func_080D2DC4: @ 080D2DC4
	push {lr}
	adds r1, r0, #0x0
	ldr r0, _080D2DD4 @ =0x0203C470
	movs r2, #0x44
	bl _0811F030
	pop {r0}
	bx r0
_080D2DD4: .4byte 0x0203C470
.syntax divided
