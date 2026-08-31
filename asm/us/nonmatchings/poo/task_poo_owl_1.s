.syntax unified
	.align 2, 0
	.global task_poo_owl_1
	.thumb
	.thumb_func
	.type task_poo_owl_1, %function
task_poo_owl_1: @ 080CE0B4
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	bl func_080C9D5C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CE168
	ldr r4, _080CE148 @ =0x0203C3EC
	ldr r2, [r4, #0x00]
	ldr r0, [r2, #0x00]
	ldr r1, [r2, #0x04]
	ldr r2, [r2, #0x08]
	adds r1, r1, r2
	bl func_080C9FA8
	ldr r0, [r4, #0x00]
	ldr r1, [r0, #0x08]
	ldr r0, _080CE14C @ =0xFFFFC800
	cmp r1, r0
	bgt _080CE0E0
	bl func_080CA09C
_080CE0E0:
	bl func_080C9910
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CE168
	adds r1, r5, #0x0
	adds r1, #0x48
	ldrb r0, [r1, #0x00]
	adds r6, r5, #0x0
	adds r6, #0x0C
	cmp r0, #0x00
	bne _080CE114
	movs r0, #0x01
	strb r0, [r1, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x01
	movs r2, #0x00
	bl AnimStart
	adds r1, r5, #0x0
	adds r1, #0x4A
	movs r0, #0x3C
	strh r0, [r1, #0x00]
	ldr r0, _080CE150 @ =0x0000015F
	bl m4aSongNumStart
_080CE114:
	adds r0, r6, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x03
	bls _080CE160
	adds r4, r5, #0x0
	adds r4, #0x4A
	ldrh r0, [r4, #0x00]
	cmp r0, #0x00
	beq _080CE158
	adds r0, r5, #0x0
	adds r0, #0x2C
	ldr r1, _080CE154 @ =0xFFFF7000
	ldrh r2, [r4, #0x00]
	bl func_0800592C
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	ldr r0, [r5, #0x24]
	subs r0, #0xCC
	str r0, [r5, #0x24]
	b _080CE160
	.byte 0x00, 0x00
_080CE148: .4byte 0x0203C3EC
_080CE14C: .4byte 0xFFFFC800
_080CE150: .4byte 0x0000015F
_080CE154: .4byte 0xFFFF7000
_080CE158:
	ldr r0, [r5, #0x2C]
	ldr r1, _080CE1D0 @ =0xFFFFFF00
	adds r0, r0, r1
	str r0, [r5, #0x2C]
_080CE160:
	adds r0, r6, #0x0
	bl AnimUpdate
	str r0, [r5, #0x08]
_080CE168:
	bl func_080C9D48
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CE1C0
	adds r1, r5, #0x0
	adds r1, #0x49
	ldrb r0, [r1, #0x00]
	adds r6, r5, #0x0
	adds r6, #0x0C
	cmp r0, #0x00
	bne _080CE18E
	movs r0, #0x01
	strb r0, [r1, #0x00]
	adds r0, r6, #0x0
	movs r1, #0x04
	movs r2, #0x01
	bl AnimStart
_080CE18E:
	adds r0, r6, #0x0
	bl func_08005B34
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080CE1A8
	ldrh r0, [r5, #0x16]
	cmp r0, #0x00
	bne _080CE1A8
	movs r0, #0xAC
	lsls r0, r0, #0x01
	bl m4aSongNumStart
_080CE1A8:
	ldr r0, _080CE1D4 @ =0x0203C3EC
	adds r1, r5, #0x0
	adds r1, #0x24
	ldr r0, [r0, #0x00]
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	adds r0, r6, #0x0
	bl AnimUpdate
	str r0, [r5, #0x08]
_080CE1C0:
	adds r0, r5, #0x0
	adds r0, #0x34
	bl TaskPoolUpdate
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_080CE1D0: .4byte 0xFFFFFF00
_080CE1D4: .4byte 0x0203C3EC
.syntax divided
