.syntax unified
	.align 2, 0
	.global func_0800EFE8
	.thumb
	.thumb_func
	.type func_0800EFE8, %function
func_0800EFE8: @ 0800EFE8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r5, r6, #0x0
	adds r5, #0x40
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	movs r1, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _0800F00E
	movs r2, #0x80
	lsls r2, r2, #0x04
	mov r8, r2
	b _0800F01A
_0800F00E:
	ldr r0, [r5, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
_0800F01A:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	movs r3, #0xB4
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldr r1, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bne _0800F088
	movs r7, #0xB6
	lsls r7, r7, #0x01
	adds r0, r6, r7
	ldr r3, [r0, #0x00]
	cmp r3, r1
	bne _0800F088
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800F068
	ldr r0, _0800F064 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	adds r1, r2, #0x0
	b _0800F0D0
_0800F064: .4byte 0x02039B84
_0800F068:
	ldr r0, _0800F080 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	cmp r2, r3
	bne _0800F084
	adds r1, r2, #0x0
	movs r0, #0x01
	mov r3, r8
	orrs r3, r0
	mov r8, r3
	b _0800F0D0
	.byte 0x00, 0x00
_0800F080: .4byte 0x02039B84
_0800F084:
	negs r1, r2
	b _0800F0D0
_0800F088:
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0800F0B0
	ldr r0, _0800F0AC @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r7, #0xB4
	lsls r7, r7, #0x01
	adds r1, r6, r7
	ldr r2, [r0, #0x24]
	ldr r0, [r1, #0x00]
	muls r0, r2
	asrs r1, r0, #0x08
	b _0800F0C4
_0800F0AC: .4byte 0x02039B84
_0800F0B0:
	ldr r0, _0800F0E0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r7, #0xB4
	lsls r7, r7, #0x01
	adds r1, r6, r7
	ldr r2, [r0, #0x24]
	ldr r0, [r1, #0x00]
	muls r0, r2
	asrs r0, r0, #0x08
	negs r1, r0
_0800F0C4:
	movs r3, #0xB6
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldr r0, [r0, #0x00]
	muls r0, r2
	asrs r2, r0, #0x08
_0800F0D0:
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _0800F0E4
	cmp r1, r2
	bne _0800F0E4
	movs r7, #0x00
	b _0800F0F8
_0800F0E0: .4byte 0x02039B84
_0800F0E4:
	cmp r2, #0xFF
	bgt _0800F0EE
	movs r0, #0x00
	movs r3, #0x00
	b _0800F0F2
_0800F0EE:
	movs r0, #0x00
	movs r3, #0x01
_0800F0F2:
	bl func_08002CB4
	adds r7, r0, #0x0
_0800F0F8:
	movs r1, #0xB8
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	cmp r0, #0x11
	bne _0800F17E
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r0, r6, r2
	ldrh r2, [r0, #0x00]
	lsls r0, r2, #0x10
	asrs r1, r0, #0x12
	adds r0, r1, #0x0
	cmp r1, #0x00
	bge _0800F118
	adds r0, r1, #0x7
_0800F118:
	asrs r0, r0, #0x03
	lsls r0, r0, #0x03
	subs r0, r1, r0
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	movs r0, #0x01
	ands r0, r2
	cmp r0, #0x00
	beq _0800F15C
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r2, r6, r0
	ldr r0, [r2, #0x00]
	movs r1, #0x02
	orrs r0, r1
	str r0, [r2, #0x00]
	ldr r0, [r6, #0x08]
	ldrh r0, [r0, #0x06]
	ldr r2, _0800F154 @ =0x08133E54
	lsls r1, r3, #0x10
	asrs r1, r1, #0x10
	adds r1, r1, r2
	ldrb r1, [r1, #0x00]
	lsls r1, r1, #0x05
	ldr r2, _0800F158 @ =0x08F6DA24
	adds r1, r1, r2
	bl func_08002BAC
	b _0800F1D0
	.byte 0x00, 0x00
_0800F154: .4byte 0x08133E54
_0800F158: .4byte 0x08F6DA24
_0800F15C:
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r2, r6, r1
	ldr r0, [r2, #0x00]
	movs r1, #0x03
	negs r1, r1
	ands r0, r1
	str r0, [r2, #0x00]
	ldr r0, [r6, #0x08]
	ldrh r0, [r0, #0x06]
	movs r2, #0xBC
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r1, [r1, #0x00]
	bl func_08002BAC
	b _0800F1D0
_0800F17E:
	adds r0, r5, #0x0
	bl func_0801CA00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0800F1A8
	movs r3, #0xAA
	lsls r3, r3, #0x01
	adds r2, r6, r3
	ldr r0, [r2, #0x00]
	movs r1, #0x02
	orrs r0, r1
	str r0, [r2, #0x00]
	ldr r0, [r6, #0x08]
	ldrh r0, [r0, #0x06]
	ldr r1, _0800F1A4 @ =0x08F69BC4
	bl func_08002BAC
	b _0800F1D0
_0800F1A4: .4byte 0x08F69BC4
_0800F1A8:
	movs r0, #0xAA
	lsls r0, r0, #0x01
	adds r2, r6, r0
	ldr r1, [r2, #0x00]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	beq _0800F1D0
	movs r0, #0x03
	negs r0, r0
	ands r1, r0
	str r1, [r2, #0x00]
	ldr r0, [r6, #0x08]
	ldrh r0, [r0, #0x06]
	movs r2, #0xBC
	lsls r2, r2, #0x01
	adds r1, r6, r2
	ldr r1, [r1, #0x00]
	bl func_08002BAC
_0800F1D0:
	add r0, sp, #0x010
	movs r3, #0x00
	ldsh r0, [r0, r3]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	movs r3, #0xC0
	lsls r3, r3, #0x01
	adds r2, r6, r3
	ldr r2, [r2, #0x00]
	ldr r3, [r6, #0x04]
	ldr r4, [r6, #0x08]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	ldr r5, [r5, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r7, _0800F22C @ =0xFFFFEFFC
	adds r4, r7, #0x0
	subs r4, r4, r5
	movs r5, #0x03
	orrs r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	ldr r1, [r6, #0x0C]
	adds r0, r6, #0x0
	bl func_0800EEBC
	ldr r1, [r6, #0x10]
	adds r0, r6, #0x0
	bl func_0800EEBC
	adds r0, r6, #0x0
	adds r0, #0x2C
	bl func_08000EE0
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_0800F22C: .4byte 0xFFFFEFFC
.syntax divided
