.syntax unified
	.align 2, 0
	.global func_08118F7C
	.thumb
	.thumb_func
	.type func_08118F7C, %function
func_08118F7C: @ 08118F7C
	push {r4, r5, r7, lr}
	add sp, #-0x00C
	mov r7, sp
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x00]
	str r0, [r7, #0x08]
	ldr r0, [r7, #0x08]
	ldr r1, [r7, #0x08]
	ldr r0, [r0, #0x4C]
	ldr r2, [r1, #0x60]
	adds r1, r0, r2
	ldrb r0, [r1, #0x00]
	cmp r0, #0x01
	beq _08118FCA
	cmp r0, #0x01
	bgt _08118FA2
	cmp r0, #0x00
	beq _08118FA8
	b _08119028
_08118FA2:
	cmp r0, #0x02
	beq _08118FEA
	b _08119028
_08118FA8:
	ldr r0, [r7, #0x08]
	ldr r2, [r7, #0x08]
	ldr r1, [r2, #0x24]
	ldr r3, [r7, #0x08]
	ldr r2, [r3, #0x2C]
	ldr r4, [r7, #0x08]
	ldr r3, [r4, #0x30]
	ldr r5, [r7, #0x08]
	ldr r4, [r5, #0x5C]
	ldr r5, [r0, #0x7C]
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	adds r2, r3, #0x0
	adds r3, r4, #0x0
	bl _call_via_r5
	b _08119028
_08118FCA:
	ldr r0, [r7, #0x08]
	adds r1, r0, #0x0
	adds r0, #0x84
	ldr r2, [r7, #0x08]
	ldr r1, [r2, #0x20]
	ldr r3, [r7, #0x08]
	ldr r2, [r3, #0x24]
	ldr r4, [r7, #0x08]
	ldr r3, [r4, #0x5C]
	ldr r4, [r0, #0x00]
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	adds r2, r3, #0x0
	bl _call_via_r4
	b _08119028
_08118FEA:
	ldr r0, [r7, #0x08]
	adds r1, r0, #0x0
	adds r0, #0x84
	ldr r2, [r7, #0x08]
	ldr r1, [r2, #0x20]
	ldr r3, [r7, #0x08]
	ldr r2, [r3, #0x24]
	ldr r4, [r7, #0x08]
	ldr r3, [r4, #0x5C]
	ldr r4, [r0, #0x00]
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	adds r2, r3, #0x0
	bl _call_via_r4
	ldr r0, [r7, #0x08]
	adds r1, r0, #0x0
	adds r0, #0x80
	ldr r2, [r7, #0x08]
	ldr r1, [r2, #0x24]
	ldr r3, [r7, #0x08]
	ldr r2, [r3, #0x2C]
	ldr r4, [r7, #0x08]
	ldr r3, [r4, #0x30]
	ldr r4, [r0, #0x00]
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	adds r2, r3, #0x0
	bl _call_via_r4
	b _08119028
_08119028:
	ldr r0, [r7, #0x08]
	movs r1, #0x01
	str r1, [r0, #0x74]
	ldr r0, [r7, #0x08]
	ldr r1, [r0, #0x20]
	str r1, [r7, #0x04]
	ldr r0, [r7, #0x08]
	ldr r1, [r7, #0x08]
	ldr r2, [r1, #0x24]
	str r2, [r0, #0x20]
	ldr r0, [r7, #0x08]
	ldr r1, [r7, #0x04]
	str r1, [r0, #0x24]
	add sp, #0x00C
	pop {r4, r5, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
