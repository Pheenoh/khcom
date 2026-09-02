.syntax unified
	.align 2, 0
	.global task_bos_md_fire_2
	.thumb
	.thumb_func
	.type task_bos_md_fire_2, %function
task_bos_md_fire_2: @ 080FD314
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	movs r1, #0x06
	ldsh r0, [r6, r1]
	cmp r0, #0x00
	ble _080FD33C
	ldr r0, _080FD338 @ =0x03007480
	ldr r0, [r0, #0x00]
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080FD33C
	ldr r7, [r6, #0x10]
	b _080FD33E
	.byte 0x00, 0x00
_080FD338: .4byte 0x03007480
_080FD33C:
	ldr r7, [r6, #0x0C]
_080FD33E:
	mov r5, sp
	adds r5, #0x12
	movs r3, #0xA4
	lsls r3, r3, #0x01
	adds r0, r6, r3
	ldr r2, [r0, #0x00]
	movs r0, #0xA6
	lsls r0, r0, #0x01
	adds r4, r6, r0
	ldr r3, [r4, #0x00]
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r6, r1
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl WorldToScreen
	ldr r0, [r4, #0x00]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, [r6, #0x00]
	cmp r0, #0x00
	bne _080FD382
	adds r0, r6, #0x0
	adds r0, #0x30
	movs r1, #0x80
	lsls r1, r1, #0x01
	ldrh r2, [r6, #0x34]
	b _080FD38E
_080FD382:
	cmp r0, #0x04
	bne _080FD3A2
	adds r0, r6, #0x0
	adds r0, #0x30
	ldrh r2, [r6, #0x34]
	movs r1, #0x19
_080FD38E:
	bl ApproachValue
	ldr r2, [r6, #0x30]
	movs r0, #0x00
	adds r1, r2, #0x0
	movs r3, #0x00
	bl AllocObjAffine
	adds r4, r0, #0x0
	b _080FD3A4
_080FD3A2:
	movs r4, #0x00
_080FD3A4:
	adds r0, r6, #0x0
	adds r0, #0x18
	bl AnimUpdate
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r3, #0x00
	ldsh r0, [r0, r3]
	movs r3, #0x00
	ldsh r1, [r5, r3]
	ldr r3, [r6, #0x14]
	str r7, [sp, #0x000]
	str r4, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	movs r5, #0xA6
	lsls r5, r5, #0x01
	adds r4, r6, r5
	ldr r5, [r4, #0x00]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r6, _080FD3EC @ =0xFFFFEFFC
	adds r4, r6, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl DrawSprite
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080FD3EC: .4byte 0xFFFFEFFC
.syntax divided
