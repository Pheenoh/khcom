.syntax unified
	.align 2, 0
	.global func_080D4D50
	.thumb
	.thumb_func
	.type func_080D4D50, %function
func_080D4D50: @ 080D4D50
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x004
	adds r7, r2, #0x0
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	mov r10, r3
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080D4D80
	ldr r0, _080D4D7C @ =0x0203C530
	b _080D4D82
	.byte 0x00, 0x00
_080D4D7C: .4byte 0x0203C530
_080D4D80:
	ldr r0, _080D4E14 @ =0x0203C504
_080D4D82:
	ldr r0, [r0, #0x00]
	mov r9, r0
	lsls r4, r2, #0x10
	asrs r0, r4, #0x10
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldr r0, _080D4E18 @ =0x0203C4B4
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xAC
	movs r3, #0x00
	ldsh r0, [r0, r3]
	subs r0, r1, r0
	cmp r0, #0x00
	bge _080D4DA4
	adds r0, #0x07
_080D4DA4:
	lsls r0, r0, #0x0D
	lsrs r0, r0, #0x10
	str r0, [sp, #0x000]
	lsls r3, r5, #0x10
	asrs r1, r3, #0x10
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r1, r2, #0x0
	adds r1, #0xAE
	movs r2, #0x00
	ldsh r1, [r1, r2]
	subs r0, r0, r1
	cmp r0, #0x00
	bge _080D4DC4
	adds r0, #0x07
_080D4DC4:
	lsls r0, r0, #0x0D
	lsrs r0, r0, #0x10
	mov r8, r0
	lsrs r6, r4, #0x10
	orrs r6, r3
	adds r0, r6, #0x0
	bl func_080D5494
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r0, r7, #0x14
	lsrs r4, r0, #0x10
	adds r0, r5, #0x0
	movs r1, #0x08
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D4E04
	adds r0, r5, #0x0
	movs r1, #0x02
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D4E04
	adds r0, r6, #0x0
	bl func_080D422C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D4E32
_080D4E04:
	mov r3, r10
	cmp r3, #0x00
	beq _080D4E1C
	movs r1, #0x80
	lsls r1, r1, #0x06
	adds r0, r4, r1
	b _080D4E48
	.byte 0x00, 0x00
_080D4E14: .4byte 0x0203C504
_080D4E18: .4byte 0x0203C4B4
_080D4E1C:
	cmp r7, #0x01
	bne _080D4E26
	movs r2, #0x80
	lsls r2, r2, #0x05
	b _080D4E46
_080D4E26:
	cmp r7, #0x11
	bne _080D4E4C
	movs r3, #0xF0
	lsls r3, r3, #0x08
	adds r0, r4, r3
	b _080D4E48
_080D4E32:
	cmp r7, #0x01
	beq _080D4E3A
	cmp r7, #0x11
	bne _080D4E42
_080D4E3A:
	movs r1, #0xF0
	lsls r1, r1, #0x08
	adds r0, r4, r1
	b _080D4E48
_080D4E42:
	movs r2, #0xE0
	lsls r2, r2, #0x08
_080D4E46:
	adds r0, r4, r2
_080D4E48:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_080D4E4C:
	movs r6, #0x00
	mov r3, r8
	lsls r0, r3, #0x10
	ldr r2, [sp, #0x000]
	lsls r1, r2, #0x10
	asrs r0, r0, #0x10
	mov r8, r0
	asrs r1, r1, #0x10
	mov r12, r1
_080D4E5E:
	movs r5, #0x00
	adds r7, r6, #0x1
_080D4E62:
	mov r3, r8
	adds r2, r3, r6
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _080D4E6E
	adds r0, #0x1F
_080D4E6E:
	asrs r0, r0, #0x05
	lsls r1, r0, #0x0B
	lsls r0, r0, #0x05
	subs r0, r2, r0
	lsls r0, r0, #0x05
	adds r3, r1, r0
	mov r0, r12
	adds r2, r0, r5
	adds r0, r2, #0x0
	cmp r2, #0x00
	bge _080D4E86
	adds r0, #0x1F
_080D4E86:
	asrs r0, r0, #0x05
	lsls r1, r0, #0x0A
	adds r1, r3, r1
	lsls r0, r0, #0x05
	subs r0, r2, r0
	adds r1, r1, r0
	lsls r1, r1, #0x10
	asrs r1, r1, #0x0F
	add r1, r9
	strh r4, [r1, #0x00]
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	adds r5, #0x01
	cmp r5, #0x03
	ble _080D4E62
	adds r6, r7, #0x0
	cmp r6, #0x03
	ble _080D4E5E
	add sp, #0x004
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
