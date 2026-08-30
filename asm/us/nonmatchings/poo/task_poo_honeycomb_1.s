.syntax unified
	.align 2, 0
	.global task_poo_honeycomb_1
	.thumb
	.thumb_func
	.type task_poo_honeycomb_1, %function
task_poo_honeycomb_1: @ 080CFAEC
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r0, #0x9C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080CFB90
	ldr r6, _080CFB40 @ =0x02034E1C
	ldr r0, [r6, #0x00]
	cmp r0, #0x01
	beq _080CFB54
	cmp r0, #0x01
	bcs _080CFB90
	adds r0, r4, #0x0
	adds r0, #0x38
	movs r1, #0x09
	bl func_08012660
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CFB90
	movs r0, #0x02
	bl func_080D2D50
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	cmp r5, #0x00
	bne _080CFB48
	ldr r1, _080CFB44 @ =0x0203C3F0
	movs r0, #0x09
	str r0, [r1, #0x00]
	bl func_080C9E70
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CFB90
	movs r0, #0x01
	str r0, [r6, #0x00]
	adds r0, r4, #0x0
	adds r0, #0x94
	strh r5, [r0, #0x00]
	b _080CFB90
	.byte 0x00, 0x00
_080CFB40: .4byte 0x02034E1C
_080CFB44: .4byte 0x0203C3F0
_080CFB48:
	ldr r1, _080CFB50 @ =0x0203C3F0
	movs r0, #0x0A
	str r0, [r1, #0x00]
	b _080CFB90
_080CFB50: .4byte 0x0203C3F0
_080CFB54:
	adds r3, r4, #0x0
	adds r3, #0x98
	ldr r1, _080CFB98 @ =0x08121400
	adds r2, r4, #0x0
	adds r2, #0x96
	ldrb r0, [r2, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	str r0, [r3, #0x00]
	ldrh r0, [r2, #0x00]
	adds r0, #0x10
	strh r0, [r2, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x94
	ldrh r0, [r1, #0x00]
	adds r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3C
	bls _080CFB90
	movs r0, #0x00
	str r0, [r3, #0x00]
	movs r0, #0x02
	str r0, [r6, #0x00]
	ldr r0, _080CFB9C @ =0x00000173
	bl func_0811FE70
_080CFB90:
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_080CFB98: .4byte 0x08121400
_080CFB9C: .4byte 0x00000173
.syntax divided
