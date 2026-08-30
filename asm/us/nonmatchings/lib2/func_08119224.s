.syntax unified
	.align 2, 0
	.global func_08119224
	.thumb
	.thumb_func
	.type func_08119224, %function
func_08119224: @ 08119224
	push {r4, r7, lr}
	add sp, #-0x008
	mov r7, sp
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x00]
	str r0, [r7, #0x04]
	ldr r1, [r7, #0x04]
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x60]
	adds r1, r2, #0x1
	str r1, [r0, #0x60]
	ldr r1, [r7, #0x04]
	adds r0, r1, #0x0
	adds r1, #0x8C
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _08119256
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x04]
	ldr r0, [r0, #0x60]
	ldr r1, [r1, #0x38]
	cmp r0, r1
	beq _08119256
	b _08119272
_08119256:
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x0
	adds r0, #0x8C
	ldrb r1, [r0, #0x00]
	movs r2, #0x00
	ands r1, r2
	adds r2, r1, #0x0
	movs r3, #0x01
	adds r1, r2, #0x0
	orrs r1, r3
	adds r2, r1, #0x0
	strb r2, [r0, #0x00]
	movs r0, #0x00
	b _081192A8
_08119272:
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x6C]
	cmp r1, #0x00
	bne _08119288
	ldr r0, [r7, #0x04]
	movs r1, #0x01
	str r1, [r0, #0x6C]
	bl func_081185CC
	ldr r1, [r7, #0x04]
	str r0, [r1, #0x68]
_08119288:
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x04]
	ldr r2, [r7, #0x04]
	ldr r3, [r7, #0x04]
	ldr r4, [r3, #0x60]
	adds r3, r4, #0x0
	lsls r4, r3, #0x01
	ldr r3, [r2, #0x50]
	adds r2, r4, r3
	subs r3, r2, #0x2
	ldrh r2, [r3, #0x00]
	ldr r1, [r1, #0x14]
	adds r2, r1, r2
	str r2, [r0, #0x14]
	movs r0, #0x01
	b _081192A8
_081192A8:
	add sp, #0x008
	pop {r4, r7}
	pop {r1}
	bx r1
.syntax divided
