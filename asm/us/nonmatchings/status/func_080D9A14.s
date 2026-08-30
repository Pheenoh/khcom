.syntax unified
	.align 2, 0
	.global func_080D9A14
	.thumb
	.thumb_func
	.type func_080D9A14, %function
func_080D9A14: @ 080D9A14
	push {r4, r5, lr}
	ldr r0, _080D9A54 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x80
	bl func_08000C8C
	adds r2, r0, #0x0
	cmp r2, #0x00
	beq _080D9A4C
	movs r4, #0x40
	movs r5, #0x00
_080D9A2A:
	ldr r0, [r2, #0x00]
	cmp r0, #0x27
	beq _080D9A3E
	ldr r0, [r2, #0x34]
	ldr r1, [r2, #0x38]
	orrs r0, r4
	str r0, [r2, #0x34]
	str r1, [r2, #0x38]
	movs r0, #0x00
	str r0, [r2, #0x24]
_080D9A3E:
	adds r0, r2, #0x0
	adds r0, #0xB8
	bl func_08000CD4
	adds r2, r0, #0x0
	cmp r2, #0x00
	bne _080D9A2A
_080D9A4C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080D9A54: .4byte 0x02039B84
.syntax divided
