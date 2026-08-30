.syntax unified
	.align 2, 0
	.global func_08000E14
	.thumb
	.thumb_func
	.type func_08000E14, %function
func_08000E14: @ 08000E14
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	adds r7, r2, #0x0
	bl func_08000D0C
	adds r4, r0, #0x0
	cmp r4, #0x00
	beq _08000E36
	ldr r0, [r5, #0x14]
	cmp r0, #0x00
	ble _08000E3A
	bl func_08000918
	str r0, [r4, #0x04]
	cmp r0, #0x00
	bne _08000E3E
_08000E36:
	movs r0, #0x00
	b _08000E5E
_08000E3A:
	movs r0, #0x00
	str r0, [r4, #0x04]
_08000E3E:
	str r5, [r4, #0x00]
	ldr r0, [r5, #0x08]
	str r0, [r4, #0x20]
	adds r0, r4, #0x0
	adds r0, #0x0C
	adds r1, r6, #0x0
	bl func_08000BC8
	ldr r2, [r5, #0x04]
	cmp r2, #0x00
	beq _08000E5C
	ldr r0, [r4, #0x04]
	adds r1, r7, #0x0
	bl _call_via_r2
_08000E5C:
	adds r0, r4, #0x0
_08000E5E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
.syntax divided
