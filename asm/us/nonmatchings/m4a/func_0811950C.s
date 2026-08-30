.syntax unified
	.align 2, 0
	.global func_0811950C
	.thumb
	.thumb_func
	.type func_0811950C, %function
func_0811950C: @ 0811950C
	push {r4, r5, r6, r7, lr}
	add sp, #-0x014
	mov r7, sp
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x00]
	str r0, [r7, #0x10]
	ldr r1, [r7, #0x10]
	adds r0, r1, #0x0
	adds r1, #0x8C
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08119590
	ldr r1, [r7, #0x10]
	adds r0, r1, #0x0
	adds r1, #0x8D
	ldrb r0, [r1, #0x00]
	cmp r0, #0x00
	beq _08119590
	ldr r0, [r7, #0x10]
	adds r1, r0, #0x0
	adds r0, #0x8C
	ldrb r1, [r0, #0x00]
	movs r2, #0x00
	ands r1, r2
	adds r2, r1, #0x0
	strb r2, [r0, #0x00]
	ldr r1, [r7, #0x10]
	adds r0, r1, #0x0
	adds r1, #0x8D
	ldrb r0, [r1, #0x00]
	cmp r0, #0x02
	beq _0811955C
	ldr r0, [r7, #0x10]
	adds r1, r0, #0x0
	adds r0, #0x8D
	ldrb r1, [r0, #0x00]
	movs r2, #0x00
	ands r1, r2
	adds r2, r1, #0x0
	strb r2, [r0, #0x00]
_0811955C:
	ldr r0, [r7, #0x10]
	movs r1, #0x00
	str r1, [r0, #0x64]
	ldr r0, [r7, #0x10]
	ldr r1, [r7, #0x10]
	ldr r2, [r1, #0x18]
	str r2, [r0, #0x1C]
	ldr r0, [r7, #0x10]
	movs r1, #0x00
	str r1, [r0, #0x60]
	ldr r0, [r7, #0x10]
	ldr r1, [r7, #0x10]
	ldr r2, [r1, #0x10]
	str r2, [r0, #0x14]
	ldr r0, [r7, #0x10]
	movs r1, #0x00
	str r1, [r0, #0x74]
	ldr r0, [r7, #0x10]
	movs r1, #0x01
	str r1, [r0, #0x6C]
	bl func_081185CC
	ldr r1, [r7, #0x10]
	str r0, [r1, #0x68]
	movs r0, #0x01
	b _0811964A
_08119590:
	ldr r0, [r7, #0x10]
	ldr r1, [r0, #0x6C]
	cmp r1, #0x00
	bne _081195AC
	ldr r0, [r7, #0x10]
	movs r1, #0x00
	str r1, [r0, #0x74]
	ldr r0, [r7, #0x10]
	movs r1, #0x01
	str r1, [r0, #0x6C]
	bl func_081185CC
	ldr r1, [r7, #0x10]
	str r0, [r1, #0x68]
_081195AC:
	bl func_081185CC
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x10]
	ldr r1, [r7, #0x04]
	ldr r0, [r0, #0x68]
	subs r1, r1, r0
	adds r0, r1, #0x0
	bl func_08118630
	str r0, [r7, #0x08]
	ldr r4, [r7, #0x10]
	ldr r0, [r7, #0x10]
	ldr r1, [r0, #0x60]
	adds r6, r1, #0x1
	cmp r6, #0x00
	blt _081195D8
	adds r0, r6, #0x0
	bl __floatsisf
	adds r5, r0, #0x0
	b _081195F4
_081195D8:
	movs r0, #0x01
	adds r1, r6, #0x0
	ands r1, r0
	lsrs r0, r6, #0x01
	orrs r1, r0
	adds r0, r1, #0x0
	bl __floatsisf
	adds r5, r0, #0x0
	adds r0, r5, #0x0
	adds r1, r5, #0x0
	bl __addsf3
	adds r5, r0, #0x0
_081195F4:
	ldr r0, [r4, #0x70]
	adds r1, r5, #0x0
	bl __mulsf3
	str r0, [r7, #0x0C]
	ldr r0, [r7, #0x10]
	ldr r1, [r0, #0x74]
	cmp r1, #0x00
	beq _08119636
	ldr r0, [r7, #0x10]
	movs r1, #0x00
	str r1, [r0, #0x74]
	ldr r0, [r7, #0x0C]
	ldr r1, _0811962C @ =0x3C23D70A
	bl __addsf3
	adds r1, r0, #0x0
	ldr r0, [r7, #0x08]
	bl __gesf2
	cmp r0, #0x00
	blt _08119630
	ldr r0, [r7, #0x10]
	movs r1, #0x00
	str r1, [r0, #0x78]
	movs r0, #0x01
	b _0811964A
	.byte 0x00, 0x00
_0811962C: .4byte 0x3C23D70A
_08119630:
	ldr r0, [r7, #0x10]
	movs r1, #0x01
	str r1, [r0, #0x78]
_08119636:
	movs r4, #0x00
	ldr r0, [r7, #0x08]
	ldr r1, [r7, #0x0C]
	bl __gesf2
	cmp r0, #0x00
	blt _08119646
	movs r4, #0x01
_08119646:
	adds r0, r4, #0x0
	b _0811964A
_0811964A:
	add sp, #0x014
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
