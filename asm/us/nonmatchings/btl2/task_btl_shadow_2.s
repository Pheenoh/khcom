.syntax unified
	.align 2, 0
	.global task_btl_shadow_2
	.thumb
	.thumb_func
	.type task_btl_shadow_2, %function
task_btl_shadow_2: @ 0802F57C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldr r5, [r6, #0x08]
	adds r0, r5, #0x0
	adds r0, #0xCC
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0802F63E
	ldr r0, [r5, #0x34]
	ldr r1, [r5, #0x38]
	movs r2, #0x80
	lsls r2, r2, #0x12
	movs r3, #0x04
	ands r0, r2
	ands r1, r3
	orrs r0, r1
	cmp r0, #0x00
	bne _0802F63E
	ldr r0, [r5, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	blt _0802F5D0
	ldr r0, _0802F5CC @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bne _0802F5D0
	movs r7, #0x00
	b _0802F606
	.byte 0x00, 0x00
_0802F5CC: .4byte 0x02039B84
_0802F5D0:
	ldr r1, [r5, #0x10]
	ldr r0, [r5, #0x0C]
	subs r0, r1, r0
	cmp r0, #0x00
	bge _0802F5DC
	adds r0, #0x7F
_0802F5DC:
	asrs r0, r0, #0x07
	movs r1, #0x80
	lsls r1, r1, #0x01
	subs r2, r1, r0
	ldr r0, _0802F64C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x24]
	muls r0, r2
	asrs r2, r0, #0x08
	cmp r2, #0x7F
	bgt _0802F5F4
	movs r2, #0x80
_0802F5F4:
	movs r3, #0x00
	cmp r2, r1
	ble _0802F5FC
	movs r3, #0x01
_0802F5FC:
	movs r0, #0x00
	adds r1, r2, #0x0
	bl AllocObjAffine
	adds r7, r0, #0x0
_0802F606:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	ldr r0, [r5, #0x10]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	adds r4, r5, #0x0
	adds r4, #0xCC
	ldrh r4, [r4, #0x00]
	str r4, [sp, #0x00C]
	bl DrawSprite
_0802F63E:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0802F64C: .4byte 0x02039B84
.syntax divided
