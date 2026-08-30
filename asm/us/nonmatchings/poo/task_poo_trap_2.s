.syntax unified
	.align 2, 0
	.global task_poo_trap_2
	.thumb
	.thumb_func
	.type task_poo_trap_2, %function
task_poo_trap_2: @ 080CBC20
	push {r4, r5, r6, r7, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r1, [r4, #0x0C]
	asrs r1, r1, #0x08
	ldr r0, _080CBC78 @ =0x0203C40C
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	ldr r0, [r4, #0x10]
	asrs r0, r0, #0x08
	ldr r2, _080CBC7C @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	lsls r1, r1, #0x10
	asrs r7, r1, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x0D
	adds r1, r1, r0
	movs r0, #0x88
	lsls r0, r0, #0x11
	cmp r1, r0
	bhi _080CBC60
	lsls r0, r2, #0x10
	asrs r5, r0, #0x10
	movs r0, #0x10
	negs r0, r0
	cmp r5, r0
	blt _080CBC60
	cmp r5, #0xB0
	ble _080CBC80
_080CBC60:
	adds r5, r4, #0x0
	adds r5, #0x8C
	ldrb r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080CBCBA
	adds r0, r4, #0x0
	adds r0, #0x1C
	bl func_08012304
	movs r0, #0x00
	strb r0, [r5, #0x00]
	b _080CBCBA
_080CBC78: .4byte 0x0203C40C
_080CBC7C: .4byte 0x0203C3F8
_080CBC80:
	adds r6, r4, #0x0
	adds r6, #0x8C
	ldrb r0, [r6, #0x00]
	cmp r0, #0x00
	bne _080CBC9C
	adds r0, r4, #0x0
	adds r0, #0x1C
	movs r1, #0x0A
	movs r2, #0x08
	movs r3, #0x10
	bl func_080122AC
	movs r0, #0x01
	strb r0, [r6, #0x00]
_080CBC9C:
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	movs r0, #0x80
	lsls r0, r0, #0x04
	str r0, [sp, #0x008]
	ldr r0, _080CBCC4 @ =0x0000FFEF
	str r0, [sp, #0x00C]
	adds r0, r7, #0x0
	adds r1, r5, #0x0
	bl func_080023E0
_080CBCBA:
	add sp, #0x010
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CBCC4: .4byte 0x0000FFEF
.syntax divided
