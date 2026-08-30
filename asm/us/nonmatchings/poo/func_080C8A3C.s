.syntax unified
	.align 2, 0
	.global func_080C8A3C
	.thumb
	.thumb_func
	.type func_080C8A3C, %function
func_080C8A3C: @ 080C8A3C
	push {lr}
	ldr r1, _080C8A4C @ =0x096FC2F0
	movs r2, #0x10
	bl func_080C89B4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C8A4C: .4byte 0x096FC2F0
.syntax divided
