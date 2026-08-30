.syntax unified
	.align 2, 0
	.global task_title_logo_2
	.thumb
	.thumb_func
	.type task_title_logo_2, %function
task_title_logo_2: @ 080D6438
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	movs r7, #0x00
	mov r10, r6
	movs r0, #0x00
	str r0, [sp, #0x010]
_080D644E:
	ldr r1, _080D64B8 @ =0x02039BB0
	mov r8, r1
	cmp r7, #0x01
	bne _080D6462
	ldr r1, [r1, #0x08]
	movs r0, #0x80
	lsls r0, r0, #0x02
	ands r1, r0
	cmp r1, #0x00
	beq _080D64FA
_080D6462:
	mov r2, r8
	ldr r0, [r2, #0x08]
	movs r3, #0x80
	lsls r3, r3, #0x02
	mov r9, r3
	ands r0, r3
	movs r4, #0x50
	cmp r0, #0x00
	beq _080D6476
	movs r4, #0xA4
_080D6476:
	movs r1, #0x46
	cmp r7, #0x00
	bne _080D6486
	lsls r0, r4, #0x10
	movs r4, #0x80
	lsls r4, r4, #0x09
	adds r0, r0, r4
	lsrs r4, r0, #0x10
_080D6486:
	cmp r7, #0x01
	bne _080D64C4
	ldr r2, [r6, #0x4C]
	cmp r2, #0x00
	beq _080D64FA
	movs r0, #0x00
	movs r1, #0x80
	lsls r1, r1, #0x01
	movs r3, #0x00
	bl func_08002CB4
	adds r5, r0, #0x0
	mov r1, r8
	ldr r0, [r1, #0x08]
	mov r2, r9
	ands r0, r2
	cmp r0, #0x00
	beq _080D64C0
	movs r1, #0x56
	lsls r0, r4, #0x10
	ldr r3, _080D64BC @ =0xFFFF0000
	adds r0, r0, r3
	lsrs r4, r0, #0x10
	b _080D64C6
	.byte 0x00, 0x00
_080D64B8: .4byte 0x02039BB0
_080D64BC: .4byte 0xFFFF0000
_080D64C0:
	movs r1, #0x57
	b _080D64C6
_080D64C4:
	movs r5, #0x00
_080D64C6:
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	adds r2, r6, #0x0
	adds r2, #0x08
	ldr r4, [sp, #0x010]
	adds r2, r2, r4
	ldr r2, [r2, #0x00]
	mov r3, r10
	ldr r3, [r3, #0x00]
	mov r8, r3
	adds r4, r6, #0x4
	ldr r3, [sp, #0x010]
	adds r4, r4, r3
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	str r5, [sp, #0x004]
	movs r4, #0x00
	str r4, [sp, #0x008]
	adds r4, r7, #0x0
	adds r4, #0x14
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	mov r3, r8
	bl func_080023E0
_080D64FA:
	movs r4, #0x0C
	add r10, r4
	ldr r0, [sp, #0x010]
	adds r0, #0x0C
	str r0, [sp, #0x010]
	adds r7, #0x01
	cmp r7, #0x05
	ble _080D644E
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
