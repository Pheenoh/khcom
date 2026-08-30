.syntax unified
	.align 2, 0
	.global func_080DB428
	.thumb
	.thumb_func
	.type func_080DB428, %function
func_080DB428: @ 080DB428
	ldr r0, [r0, #0x38]
	cmp r0, #0x00
	bge _080DB432
	movs r0, #0x00
	b _080DB434
_080DB432:
	movs r0, #0x01
_080DB434:
	bx lr
	.byte 0x00, 0x00
.syntax divided
