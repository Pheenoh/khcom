.syntax unified
	.align 2, 0
	.global task_bos_lst_ctr_2
	.thumb
	.thumb_func
	.type task_bos_lst_ctr_2, %function
task_bos_lst_ctr_2: @ 081122F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r5, r0, #0x0
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x14]
	ldr r0, [r5, #0x20]
	adds r2, r2, r0
	ldr r3, [r5, #0x18]
	ldr r0, [r5, #0x24]
	adds r3, r3, r0
	ldr r0, [r5, #0x1C]
	ldr r1, [r5, #0x28]
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	movs r7, #0x00
	ldr r0, [r5, #0x18]
	ldr r1, [r5, #0x24]
	adds r0, r0, r1
	bl func_0801AF1C
	movs r1, #0x04
	orrs r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, [r5, #0x18]
	ldr r1, [r5, #0x24]
	adds r0, r0, r1
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	ldr r2, _08112358 @ =0xFFFFEFFC
	adds r1, r2, #0x0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r8, r1
	movs r3, #0x08
	ldsh r0, [r5, r3]
	cmp r0, #0x01
	beq _08112382
	cmp r0, #0x01
	bgt _0811235C
	cmp r0, #0x00
	beq _08112362
	b _081123B6
	.byte 0x00, 0x00
_08112358: .4byte 0xFFFFEFFC
_0811235C:
	cmp r0, #0x02
	beq _08112394
	b _081123B6
_08112362:
	movs r0, #0x0C
	ldsh r1, [r5, r0]
	movs r2, #0x06
	ldsh r0, [r5, r2]
	lsls r0, r0, #0x03
	subs r2, r1, r0
	cmp r2, #0x00
	ble _081123EC
	cmp r2, #0x0F
	bgt _081123C6
	movs r1, #0x80
	lsls r1, r1, #0x01
	lsls r2, r2, #0x04
	movs r0, #0x00
	movs r3, #0x00
	b _081123AE
_08112382:
	movs r3, #0x0C
	ldsh r0, [r5, r3]
	lsls r0, r0, #0x02
	movs r2, #0x80
	lsls r2, r2, #0x01
	subs r2, r2, r0
	movs r0, #0x00
	adds r1, r2, #0x0
	b _081123AC
_08112394:
	movs r1, #0x12
	ldsh r0, [r5, r1]
	movs r2, #0x0C
	ldsh r1, [r5, r2]
	subs r1, r0, r1
	lsls r1, r1, #0x02
	movs r2, #0x80
	lsls r2, r2, #0x01
	subs r1, r2, r1
	lsls r0, r0, #0x02
	subs r2, r2, r0
	movs r0, #0x00
_081123AC:
	movs r3, #0x01
_081123AE:
	bl AllocObjAffine
	adds r7, r0, #0x0
	b _081123C6
_081123B6:
	ldr r0, [r5, #0x14]
	ldr r1, [r5, #0x20]
	adds r0, r0, r1
	ldr r1, [r5, #0x38]
	cmp r0, r1
	ble _081123C6
	movs r0, #0x01
	orrs r6, r0
_081123C6:
	adds r0, r5, #0x0
	adds r0, #0x44
	bl AnimGetGfx
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r3, #0x00
	ldsh r0, [r0, r3]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	ldr r3, [r5, #0x5C]
	ldr r4, [r5, #0x60]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	str r6, [sp, #0x008]
	mov r4, r8
	str r4, [sp, #0x00C]
	bl DrawSprite
_081123EC:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
.syntax divided
