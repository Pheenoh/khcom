.syntax unified
	.align 2, 0
	.global func_08116BEC
	.thumb
	.thumb_func
	.type func_08116BEC, %function
func_08116BEC: @ 08116BEC
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x008
	adds r6, r0, #0x0
	adds r5, r1, #0x0
	adds r4, r2, #0x0
	str r3, [sp, #0x004]
	ldr r1, [sp, #0x028]
	lsls r5, r5, #0x10
	lsrs r0, r5, #0x10
	mov r9, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	mov r8, r1
	adds r0, r6, #0x0
	movs r1, #0x00
	bl func_08116AD8
	lsrs r7, r5, #0x13
	adds r0, r6, #0x0
	adds r1, r7, #0x0
	adds r2, r4, #0x0
	bl func_08116228
	movs r0, #0x07
	mov r10, r0
	mov r5, r9
	ands r5, r0
	cmp r5, #0x00
	beq _08116C5C
	ldrh r1, [r6, #0x22]
	ldrh r0, [r6, #0x1C]
	muls r0, r1
	adds r0, r0, r7
	lsls r7, r0, #0x05
	ldr r0, _08116CD8 @ =0x00008140
	ldr r1, [r6, #0x34]
	ldr r2, [r6, #0x38]
	ldrh r3, [r6, #0x26]
	ldrh r4, [r6, #0x24]
	str r4, [sp, #0x000]
	bl func_08116008
	adds r4, r0, #0x0
	ldr r1, [r6, #0x50]
	adds r1, r1, r7
	adds r0, r6, #0x0
	adds r2, r4, #0x0
	adds r3, r5, #0x0
	bl func_08116034
_08116C5C:
	adds r0, r6, #0x0
	mov r1, r9
	bl func_08116254
	adds r0, r6, #0x0
	ldr r1, [sp, #0x004]
	bl func_081167F8
	adds r0, r6, #0x0
	movs r1, #0x00
	bl func_08116AD8
	ldrh r2, [r6, #0x20]
	mov r0, r10
	ands r0, r2
	cmp r0, #0x00
	beq _08116CB2
	ldrh r1, [r6, #0x22]
	ldrh r0, [r6, #0x1C]
	muls r0, r1
	lsrs r1, r2, #0x03
	adds r0, r0, r1
	lsls r7, r0, #0x05
	ldr r0, _08116CD8 @ =0x00008140
	ldr r1, [r6, #0x34]
	ldr r2, [r6, #0x38]
	ldrh r3, [r6, #0x26]
	ldrh r4, [r6, #0x24]
	str r4, [sp, #0x000]
	bl func_08116008
	adds r4, r0, #0x0
	ldr r1, [r6, #0x50]
	adds r1, r1, r7
	ldrh r2, [r6, #0x20]
	mov r0, r10
	ands r0, r2
	movs r3, #0x08
	subs r3, r3, r0
	adds r0, r6, #0x0
	adds r2, r4, #0x0
	bl func_08116034
_08116CB2:
	mov r1, r8
	cmp r1, #0x01
	bne _08116CC6
	ldrh r0, [r6, #0x00]
	ands r1, r0
	cmp r1, #0x00
	beq _08116CC6
	adds r0, r6, #0x0
	bl func_08116B1C
_08116CC6:
	add sp, #0x008
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08116CD8: .4byte 0x00008140
.syntax divided
