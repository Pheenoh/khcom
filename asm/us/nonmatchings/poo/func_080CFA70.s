.syntax unified
	.align 2, 0
	.global func_080CFA70
	.thumb
	.thumb_func
	.type func_080CFA70, %function
func_080CFA70: @ 080CFA70
	ldr r0, _080CFA7C @ =0x02034E18
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080CFA80
	movs r0, #0x00
	b _080CFA82
_080CFA7C: .4byte 0x02034E18
_080CFA80:
	movs r0, #0x01
_080CFA82:
	bx lr
.syntax divided
