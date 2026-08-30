.syntax unified
	.align 2, 0
	.global task_allmap_doorinfo_3
	.thumb
	.thumb_func
	.type task_allmap_doorinfo_3, %function
task_allmap_doorinfo_3: @ 080D4AAC
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0x0
	movs r1, #0x8B
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D4AC8
	movs r0, #0x00
	movs r1, #0x08
	bl func_080061E8
_080D4AC8:
	adds r0, r5, #0x0
	adds r0, #0xF0
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldrb r0, [r5, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080D4AFC
	ldrb r0, [r5, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	beq _080D4AFC
	ldrb r0, [r5, #0x04]
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x02
	bne _080D4B2C
_080D4AFC:
	movs r6, #0x00
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r5, r1
	movs r1, #0xF4
	adds r1, r1, r5
	mov r8, r1
	ldrh r0, [r0, #0x00]
	cmp r6, r0
	bge _080D4B8C
	adds r4, r5, #0x0
	adds r4, #0x1C
	movs r0, #0x8A
	lsls r0, r0, #0x01
	adds r5, r5, r0
_080D4B1A:
	adds r0, r4, #0x0
	bl func_08098778
	adds r4, #0x34
	adds r6, #0x01
	ldrh r1, [r5, #0x00]
	cmp r6, r1
	blt _080D4B1A
	b _080D4B8C
_080D4B2C:
	ldr r0, [r5, #0x18]
	bl func_080028C0
	adds r0, r5, #0x0
	adds r0, #0xEC
	ldr r0, [r0, #0x00]
	bl func_08002C10
	movs r6, #0x00
	movs r0, #0xF4
	adds r0, r0, r5
	mov r8, r0
	adds r7, r5, #0x0
	adds r7, #0x08
_080D4B48:
	ldr r0, [r7, #0x00]
	cmp r0, #0x00
	beq _080D4B84
	movs r0, #0x34
	adds r4, r6, #0x0
	muls r4, r0
	adds r0, r5, #0x0
	adds r0, #0x1C
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_080028C0
	adds r0, r5, #0x0
	adds r0, #0x28
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_08002C10
	adds r0, r5, #0x0
	adds r0, #0x20
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_080028C0
	adds r0, r5, #0x0
	adds r0, #0x2C
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_08002C10
_080D4B84:
	adds r7, #0x04
	adds r6, #0x01
	cmp r6, #0x03
	ble _080D4B48
_080D4B8C:
	movs r6, #0x00
_080D4B8E:
	lsls r0, r6, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x01
	bl func_080062F4
	adds r6, #0x01
	cmp r6, #0x1F
	ble _080D4B8E
	movs r0, #0x0A
	movs r1, #0x00
	bl func_080062F4
	mov r1, r8
	ldr r0, [r1, #0x00]
	bl func_080009C4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
