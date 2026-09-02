.syntax unified
	.align 2, 0
	.global task_poo_tiggerroo_1
	.thumb
	.thumb_func
	.type task_poo_tiggerroo_1, %function
task_poo_tiggerroo_1: @ 080CEA78
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r0, #0x38
	adds r6, r5, #0x0
	adds r6, #0x28
	adds r2, r5, #0x0
	adds r2, #0xD0
	adds r1, r6, #0x0
	bl func_080C8B38
	adds r0, r5, #0x0
	adds r0, #0xC0
	ldr r0, [r0, #0x00]
	cmp r0, #0x02
	bne _080CEB4A
	adds r4, r5, #0x0
	adds r4, #0xBA
	movs r1, #0x00
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	ble _080CEAEC
	adds r0, r5, #0x0
	adds r0, #0xA8
	ldr r1, [r0, #0x00]
	ldrh r2, [r4, #0x00]
	adds r0, r6, #0x0
	bl func_0800592C
	adds r0, r5, #0x0
	adds r0, #0x2C
	adds r1, r5, #0x0
	adds r1, #0xAC
	ldr r1, [r1, #0x00]
	ldrh r2, [r4, #0x00]
	bl func_0800592C
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x30
	adds r1, r5, #0x0
	adds r1, #0xB0
	ldr r1, [r1, #0x00]
	adds r4, #0x02
	ldrh r2, [r4, #0x00]
	bl ApproachValue
	ldrh r0, [r4, #0x00]
	subs r0, #0x01
	strh r0, [r4, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080CEB4A
	adds r0, r5, #0x0
	bl func_080CE818
	b _080CEB4A
_080CEAEC:
	adds r1, r5, #0x0
	adds r1, #0xB8
	ldrb r0, [r1, #0x00]
	cmp r0, #0x53
	beq _080CEB0E
	cmp r0, #0x53
	bgt _080CEB00
	cmp r0, #0x2D
	beq _080CEB12
	b _080CEB1A
_080CEB00:
	cmp r0, #0xAD
	beq _080CEB0A
	cmp r0, #0xD3
	beq _080CEB16
	b _080CEB1A
_080CEB0A:
	movs r0, #0x53
	b _080CEB18
_080CEB0E:
	movs r0, #0x2D
	b _080CEB18
_080CEB12:
	movs r0, #0xD3
	b _080CEB18
_080CEB16:
	movs r0, #0xAD
_080CEB18:
	strb r0, [r1, #0x00]
_080CEB1A:
	adds r0, r5, #0x0
	adds r0, #0xD1
	ldrb r1, [r0, #0x00]
	adds r4, r0, #0x0
	cmp r1, #0x00
	beq _080CEB30
	adds r0, r5, #0x0
	movs r1, #0x00
	bl func_080CE77C
	b _080CEB38
_080CEB30:
	adds r0, r5, #0x0
	movs r1, #0x00
	bl func_080CE710
_080CEB38:
	adds r0, r5, #0x0
	bl func_080CE8B4
	ldr r0, [r5, #0x28]
	ldr r1, [r5, #0x2C]
	ldr r2, [r5, #0x30]
	ldrb r3, [r4, #0x00]
	bl func_080CE960
_080CEB4A:
	adds r0, r5, #0x0
	adds r0, #0x0C
	bl AnimUpdate
	str r0, [r5, #0x08]
	adds r0, r5, #0x0
	adds r0, #0x94
	bl TaskPoolUpdate
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
.syntax divided
