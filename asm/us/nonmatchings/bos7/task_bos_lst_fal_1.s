.syntax unified
	.align 2, 0
	.global task_bos_lst_fal_1
	.thumb
	.thumb_func
	.type task_bos_lst_fal_1, %function
task_bos_lst_fal_1: @ 08111E04
	push {r4, r5, r6, lr}
	add sp, #-0x008
	adds r4, r0, #0x0
	movs r6, #0x01
	ldr r0, [r4, #0x04]
	ldr r1, [r4, #0x10]
	adds r0, r0, r1
	str r0, [r4, #0x04]
	ldr r1, [r4, #0x0C]
	ldr r0, [r4, #0x14]
	adds r1, r1, r0
	str r1, [r4, #0x0C]
	ldr r0, [r4, #0x00]
	cmp r0, #0x04
	beq _08111E52
	ldr r2, [r4, #0x18]
	cmp r2, #0x00
	ble _08111E3C
	movs r0, #0x80
	lsls r0, r0, #0x02
	cmp r2, r0
	bgt _08111E32
	adds r0, r2, #0x0
_08111E32:
	subs r0, r1, r0
	str r0, [r4, #0x0C]
	adds r0, r2, #0x0
	subs r0, #0x19
	b _08111E50
_08111E3C:
	bl GetRandom
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x41
	bl __umodsi3
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x40
_08111E50:
	str r0, [r4, #0x18]
_08111E52:
	mov r5, sp
	adds r5, #0x06
	ldr r2, [r4, #0x04]
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x004
	adds r1, r5, #0x0
	bl WorldToScreen
	add r0, sp, #0x004
	ldrh r0, [r0, #0x00]
	adds r0, #0x10
	lsls r0, r0, #0x10
	movs r1, #0x88
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _08111E86
	movs r0, #0x00
	ldsh r1, [r5, r0]
	movs r0, #0x40
	negs r0, r0
	cmp r1, r0
	blt _08111E86
	cmp r1, #0xE0
	ble _08111E88
_08111E86:
	movs r6, #0x00
_08111E88:
	adds r0, r4, #0x0
	adds r0, #0x28
	bl AnimUpdate
	adds r0, r6, #0x0
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
