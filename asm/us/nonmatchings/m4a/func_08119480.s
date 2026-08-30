.syntax unified
	.align 2, 0
	.global func_08119480
	.thumb
	.thumb_func
	.type func_08119480, %function
func_08119480: @ 08119480
	push {r4, r7, lr}
	add sp, #-0x008
	mov r7, sp
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x00]
	str r0, [r7, #0x04]
	ldr r1, [r7, #0x04]
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x04]
	ldr r2, [r1, #0x64]
	adds r1, r2, #0x1
	str r1, [r0, #0x64]
	ldr r1, [r7, #0x04]
	adds r0, r1, #0x0
	adds r1, #0x8D
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	bne _081194B2
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x04]
	ldr r0, [r0, #0x64]
	ldr r1, [r1, #0x3C]
	cmp r0, r1
	beq _081194B2
	b _081194DA
_081194B2:
	ldr r1, [r7, #0x04]
	adds r0, r1, #0x0
	adds r1, #0x8D
	ldrb r0, [r1, #0x00]
	cmp r0, #0x02
	beq _081194D6
	ldr r0, [r7, #0x04]
	adds r1, r0, #0x0
	adds r0, #0x8D
	ldrb r1, [r0, #0x00]
	movs r2, #0x00
	ands r1, r2
	adds r2, r1, #0x0
	movs r3, #0x01
	adds r1, r2, #0x0
	orrs r1, r3
	adds r2, r1, #0x0
	strb r2, [r0, #0x00]
_081194D6:
	movs r0, #0x00
	b _08119502
_081194DA:
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x40]
	cmp r1, #0x00
	beq _081194FE
	ldr r0, [r7, #0x04]
	ldr r1, [r7, #0x04]
	ldr r2, [r7, #0x04]
	ldr r3, [r7, #0x04]
	ldr r4, [r3, #0x64]
	adds r3, r4, #0x0
	lsls r4, r3, #0x01
	ldr r3, [r2, #0x58]
	adds r2, r4, r3
	subs r3, r2, #0x2
	ldrh r2, [r3, #0x00]
	ldr r1, [r1, #0x1C]
	adds r2, r1, r2
	str r2, [r0, #0x1C]
_081194FE:
	movs r0, #0x01
	b _08119502
_08119502:
	add sp, #0x008
	pop {r4, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
