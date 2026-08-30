.syntax unified
	.align 2, 0
	.global func_080DF814
	.thumb
	.thumb_func
	.type func_080DF814, %function
func_080DF814: @ 080DF814
	push {lr}
	movs r0, #0xFE
	movs r1, #0x01
	bl func_080DF730
	bl func_080E04EC
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
