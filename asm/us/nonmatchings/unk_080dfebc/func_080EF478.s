.syntax unified
	.align 2, 0
	.global func_080EF478
	.thumb
	.thumb_func
	.type func_080EF478, %function
func_080EF478: @ 080EF478
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0x0
	adds r6, r1, #0x0
	adds r7, r2, #0x0
	adds r4, r5, #0x0
	adds r4, #0x08
	adds r0, r4, #0x0
	bl func_080DFBDC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080EF49C
	adds r0, r4, #0x0
	bl func_080DFF1C
	ldr r1, [r4, #0x08]
	cmp r0, r1
	beq _080EF4B0
_080EF49C:
	str r6, [r5, #0x08]
	str r7, [r4, #0x04]
	adds r0, r5, #0x0
	adds r0, #0xCC
	ldr r1, _080EF4B8 @ =0x080EF84D
	str r1, [r0, #0x00]
	subs r0, #0x84
	movs r1, #0x01
	bl func_08012614
_080EF4B0:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080EF4B8: .4byte 0x080EF84D
.syntax divided
