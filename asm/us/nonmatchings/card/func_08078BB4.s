.syntax unified
	.align 2, 0
	.global func_08078BB4
	.thumb
	.thumb_func
	.type func_08078BB4, %function
func_08078BB4: @ 08078BB4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x004
	adds r6, r0, #0x0
	ldr r5, [r6, #0x44]
	ldr r7, _08078C40 @ =0x02039DD4
	ldr r2, [r7, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xBC
	ldr r3, [r0, #0x00]
	ldr r0, _08078C44 @ =0x0000028F
	cmp r3, r0
	bne _08078C4C
	adds r2, r6, #0x0
	adds r2, #0xA8
	movs r0, #0x00
	ldsh r1, [r2, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	subs r0, #0x3C
	str r3, [r0, #0x00]
	movs r4, #0x00
	ldsh r1, [r2, r4]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	subs r0, #0x3C
	ldrh r1, [r2, #0x00]
	subs r1, #0x05
	movs r3, #0x00
	strh r1, [r0, #0x04]
	movs r0, #0x00
	ldsh r1, [r2, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	subs r0, #0x3C
	strb r3, [r0, #0x06]
	movs r4, #0x00
	ldsh r1, [r2, r4]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	subs r0, #0x3C
	strb r3, [r0, #0x07]
	movs r0, #0x00
	ldsh r1, [r2, r0]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	subs r0, #0x3C
	strb r3, [r0, #0x0A]
	movs r4, #0x00
	ldsh r1, [r2, r4]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	subs r0, #0x3C
	strb r3, [r0, #0x08]
	ldr r0, [r7, #0x00]
	adds r0, #0xBC
	ldr r1, _08078C48 @ =0x000003B6
	str r1, [r0, #0x00]
	b _08078D04
_08078C40: .4byte 0x02039DD4
_08078C44: .4byte 0x0000028F
_08078C48: .4byte 0x000003B6
_08078C4C:
	adds r3, r6, #0x0
	adds r3, #0xA8
	movs r0, #0xDA
	adds r0, r0, r2
	mov r12, r0
	movs r4, #0x00
	ldsh r1, [r3, r4]
	ldrb r0, [r0, #0x00]
	adds r1, r1, r0
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	subs r0, #0xA8
	adds r1, r2, #0x0
	adds r1, #0xB8
	ldr r1, [r1, #0x00]
	str r1, [r0, #0x00]
	movs r1, #0x00
	ldsh r0, [r3, r1]
	mov r4, r12
	ldrb r2, [r4, #0x00]
	adds r0, r2, r0
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x02
	adds r1, r1, r5
	subs r1, #0xA8
	ldr r4, _08078D8C @ =0x0000FFF2
	adds r0, r4, #0x0
	ldrh r4, [r3, #0x00]
	adds r0, r0, r4
	adds r2, r2, r0
	movs r4, #0x00
	strh r2, [r1, #0x04]
	movs r0, #0x00
	ldsh r1, [r3, r0]
	mov r2, r12
	ldrb r2, [r2, #0x00]
	adds r1, r1, r2
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	subs r0, #0xA8
	strb r4, [r0, #0x06]
	ldr r0, [r7, #0x00]
	adds r0, #0xDA
	movs r2, #0x00
	ldsh r1, [r3, r2]
	ldrb r0, [r0, #0x00]
	adds r1, r1, r0
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	subs r0, #0xA8
	strb r4, [r0, #0x07]
	ldr r0, [r7, #0x00]
	adds r0, #0xDA
	movs r2, #0x00
	ldsh r1, [r3, r2]
	ldrb r0, [r0, #0x00]
	adds r1, r1, r0
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	subs r0, #0xA8
	strb r4, [r0, #0x0A]
	ldr r0, [r7, #0x00]
	adds r0, #0xDA
	movs r2, #0x00
	ldsh r1, [r3, r2]
	ldrb r0, [r0, #0x00]
	adds r1, r1, r0
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r0, r0, r5
	subs r0, #0xA8
	strb r4, [r0, #0x08]
	ldr r1, [r7, #0x00]
	adds r2, r1, #0x0
	adds r2, #0xB8
	ldr r0, _08078D90 @ =0x000003B6
	str r0, [r2, #0x00]
	adds r1, #0xDA
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	adds r2, r3, #0x0
_08078D04:
	adds r1, r6, #0x0
	adds r1, #0xB0
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	ldrh r0, [r2, #0x00]
	subs r0, #0x01
	adds r2, r6, #0x0
	adds r2, #0x94
	strh r0, [r2, #0x00]
	adds r0, r6, #0x0
	adds r0, #0xB8
	movs r1, #0x00
	ldsb r1, [r0, r1]
	adds r7, r0, #0x0
	cmp r1, #0x00
	bne _08078D82
	ldr r0, _08078D94 @ =0x02034A98
	ldr r0, [r0, #0x00]
	adds r0, #0x44
	ldrh r0, [r0, #0x00]
	strh r0, [r2, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x54
	bl func_08000C8C
	adds r5, r6, #0x0
	adds r5, #0xBC
	cmp r0, #0x00
	beq _08078D52
	movs r4, #0x07
_08078D42:
	adds r1, r0, #0x0
	adds r1, #0xA1
	strb r4, [r1, #0x00]
	adds r0, #0x64
	bl func_08000CD4
	cmp r0, #0x00
	bne _08078D42
_08078D52:
	adds r0, r6, #0x0
	bl func_08000EA4
	adds r0, r6, #0x0
	movs r1, #0x00
	bl func_0807682C
	movs r3, #0x00
	ldsb r3, [r7, r3]
	adds r0, r5, r3
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _08078D82
	lsls r2, r3, #0x01
	adds r2, #0xB0
	adds r2, r6, r2
	adds r3, #0xBC
	adds r3, r6, r3
	movs r0, #0x01
	str r0, [sp, #0x000]
	adds r0, r6, #0x0
	adds r1, r7, #0x0
	bl func_080991CC
_08078D82:
	add sp, #0x004
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08078D8C: .4byte 0x0000FFF2
_08078D90: .4byte 0x000003B6
_08078D94: .4byte 0x02034A98
.syntax divided
