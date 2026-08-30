.syntax unified
	.align 2, 0
	.global task_hum_lex_tmh_1
	.thumb
	.thumb_func
	.type task_hum_lex_tmh_1, %function
task_hum_lex_tmh_1: @ 08056FEC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x00C
	adds r6, r0, #0x0
	ldr r3, _0805701C @ =0x02039B84
	ldr r5, [r3, #0x00]
	ldr r0, [r5, #0x68]
	ldr r1, [r5, #0x6C]
	movs r2, #0x40
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	mov r12, r3
	cmp r0, #0x00
	beq _08057018
	adds r0, r6, #0x0
	adds r0, #0x2D
	ldrb r1, [r0, #0x00]
	adds r3, r0, #0x0
	cmp r1, #0x00
	beq _08057020
_08057018:
	movs r0, #0x00
	b _08057170
_0805701C: .4byte 0x02039B84
_08057020:
	ldr r7, [r6, #0x30]
	cmp r7, #0x00
	beq _0805702C
	cmp r7, #0x01
	beq _08057092
	b _08057166
_0805702C:
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x20]
	subs r0, r0, r1
	asrs r0, r0, #0x04
	adds r1, r1, r0
	str r1, [r6, #0x20]
	ldr r0, [r6, #0x38]
	ldr r2, [r6, #0x24]
	subs r0, r0, r2
	asrs r0, r0, #0x04
	adds r2, r2, r0
	str r2, [r6, #0x24]
	ldr r3, [r6, #0x28]
	ldr r0, [r6, #0x3C]
	adds r3, r3, r0
	str r3, [r6, #0x28]
	adds r0, #0x40
	str r0, [r6, #0x3C]
	movs r0, #0xA3
	lsls r0, r0, #0x01
	movs r5, #0x10
	str r5, [sp, #0x000]
	movs r4, #0x0C
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	bl func_08011F78
	cmp r0, #0x00
	beq _08057070
	ldr r0, _0805706C @ =0x000002B3
	b _08057078
	.byte 0x00, 0x00
_0805706C: .4byte 0x000002B3
_08057070:
	ldr r0, [r6, #0x28]
	cmp r0, #0x00
	blt _0805708C
	ldr r0, _08057088 @ =0x000002B2
_08057078:
	bl func_0811FE70
	adds r0, r6, #0x0
	adds r0, #0x4A
	strh r7, [r0, #0x00]
	movs r0, #0x01
	str r0, [r6, #0x30]
	b _08057166
_08057088: .4byte 0x000002B2
_0805708C:
	adds r1, r6, #0x0
	adds r1, #0x4A
	b _08057160
_08057092:
	adds r0, r6, #0x0
	adds r0, #0x4A
	movs r1, #0x00
	ldsh r2, [r0, r1]
	mov r8, r0
	adds r4, r6, #0x0
	adds r4, #0x48
	cmp r2, #0x00
	bne _080570C0
	ldr r0, [r6, #0x3C]
	negs r0, r0
	asrs r0, r0, #0x01
	str r0, [r6, #0x3C]
	movs r1, #0x98
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r1, [r0, #0x00]
	ldr r0, [r6, #0x20]
	cmp r1, r0
	bge _080570BE
	strb r7, [r4, #0x00]
	b _080570C0
_080570BE:
	strb r2, [r4, #0x00]
_080570C0:
	mov r0, r12
	ldr r2, [r0, #0x00]
	adds r0, r2, #0x0
	adds r0, #0xDA
	movs r1, #0x00
	ldsh r0, [r0, r1]
	subs r0, #0x20
	lsls r0, r0, #0x08
	ldr r1, [r6, #0x20]
	cmp r1, r0
	blt _080570E6
	adds r0, r2, #0x0
	adds r0, #0xDC
	movs r2, #0x00
	ldsh r0, [r0, r2]
	adds r0, #0x20
	lsls r0, r0, #0x08
	cmp r1, r0
	ble _080570EA
_080570E6:
	movs r0, #0x01
	strb r0, [r3, #0x00]
_080570EA:
	ldrb r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080570FC
	ldr r0, [r6, #0x20]
	ldr r1, _080570F8 @ =0xFFFFFC00
	adds r0, r0, r1
	b _08057104
_080570F8: .4byte 0xFFFFFC00
_080570FC:
	ldr r0, [r6, #0x20]
	movs r2, #0x80
	lsls r2, r2, #0x03
	adds r0, r0, r2
_08057104:
	str r0, [r6, #0x20]
	mov r1, r12
	ldr r0, [r1, #0x00]
	movs r2, #0x9A
	lsls r2, r2, #0x01
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	ldr r2, [r6, #0x24]
	subs r0, r0, r2
	asrs r0, r0, #0x04
	adds r2, r2, r0
	str r2, [r6, #0x24]
	ldr r3, [r6, #0x28]
	ldr r0, [r6, #0x3C]
	adds r3, r3, r0
	str r3, [r6, #0x28]
	adds r0, #0x40
	str r0, [r6, #0x3C]
	movs r0, #0xA3
	lsls r0, r0, #0x01
	ldr r1, [r6, #0x20]
	movs r5, #0x10
	str r5, [sp, #0x000]
	movs r4, #0x0C
	str r4, [sp, #0x004]
	str r5, [sp, #0x008]
	bl func_08011F78
	cmp r0, #0x00
	beq _08057146
	ldr r0, _0805717C @ =0x000002B3
	bl func_0811FE70
_08057146:
	ldr r0, [r6, #0x28]
	cmp r0, #0x00
	blt _0805715E
	ldr r0, _08057180 @ =0x000002B2
	bl func_0811FE70
	ldr r0, [r6, #0x3C]
	negs r0, r0
	asrs r0, r0, #0x01
	str r0, [r6, #0x3C]
	movs r0, #0x00
	str r0, [r6, #0x28]
_0805715E:
	mov r1, r8
_08057160:
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
_08057166:
	adds r0, r6, #0x0
	adds r0, #0x08
	bl func_08005A64
	movs r0, #0x01
_08057170:
	add sp, #0x00C
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_0805717C: .4byte 0x000002B3
_08057180: .4byte 0x000002B2
.syntax divided
