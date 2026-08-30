.syntax unified
	.align 2, 0
	.global func_080007D4
	.thumb
	.thumb_func
	.type func_080007D4, %function
func_080007D4: @ 080007D4
	adds r3, r0, #0x0
	ldr r0, [r1, #0x00]
	ldr r2, [r0, #0x08]
	cmp r2, #0x00
	beq _080007FA
	ldr r0, [r1, #0x04]
	cmp r2, r0
	beq _080007FA
	adds r1, r0, #0x0
_080007E6:
	ldr r0, [r2, #0x00]
	cmp r0, r3
	blt _080007F0
	adds r0, r2, #0x0
	b _080007FC
_080007F0:
	ldr r2, [r2, #0x08]
	cmp r2, #0x00
	beq _080007FA
	cmp r2, r1
	bne _080007E6
_080007FA:
	movs r0, #0x00
_080007FC:
	bx lr
	.byte 0x00, 0x00
.syntax divided
