.syntax unified
	.align 2, 0
	.global task_allmap_room_2
	.thumb
	.thumb_func
	.type task_allmap_room_2, %function
task_allmap_room_2: @ 080D38B4
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x018
	mov r8, r0
	adds r0, #0x9C
	ldrh r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D391C
	mov r0, r8
	adds r0, #0x8C
	movs r2, #0x00
	ldsh r1, [r0, r2]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	ldr r1, _080D3910 @ =0x0203C540
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r3, r0, #0x10
	mov r0, r8
	adds r0, #0x8E
	movs r4, #0x00
	ldsh r2, [r0, r4]
	lsls r0, r2, #0x01
	adds r0, r0, r2
	lsls r0, r0, #0x03
	ldr r1, _080D3914 @ =0x0203C53C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x04
	mov r10, r0
	lsls r2, r2, #0x02
	ldr r1, _080D3918 @ =0xFFFFEFFC
	adds r0, r1, #0x0
	subs r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	b _080D393C
	.byte 0x00, 0x00
_080D3910: .4byte 0x0203C540
_080D3914: .4byte 0x0203C53C
_080D3918: .4byte 0xFFFFEFFC
_080D391C:
	ldr r0, _080D39EC @ =0x02039BA0
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x70]
	movs r1, #0x80
	lsls r1, r1, #0x0B
	ands r0, r1
	cmp r0, #0x00
	bne _080D39DC
	mov r0, r8
	adds r0, #0x8C
	ldrh r3, [r0, #0x00]
	adds r0, #0x02
	ldrh r4, [r0, #0x00]
	movs r2, #0x00
	mov r10, r2
	movs r5, #0x50
_080D393C:
	lsls r0, r3, #0x10
	asrs r6, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x0E
	adds r2, r0, r1
	movs r1, #0x88
	lsls r1, r1, #0x11
	str r0, [sp, #0x010]
	cmp r2, r1
	bhi _080D39DC
	lsls r0, r4, #0x10
	asrs r4, r0, #0x10
	movs r1, #0x20
	negs r1, r1
	str r0, [sp, #0x014]
	cmp r4, r1
	blt _080D39DC
	cmp r4, #0xA0
	bgt _080D39DC
	mov r0, r8
	ldr r2, [r0, #0x08]
	cmp r2, #0x00
	beq _080D3982
	ldr r3, [r0, #0x00]
	ldr r0, [r0, #0x04]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	mov r1, r10
	str r1, [sp, #0x008]
	str r5, [sp, #0x00C]
	adds r0, r6, #0x0
	adds r1, r4, #0x0
	bl DrawSprite
_080D3982:
	movs r6, #0x00
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	mov r9, r0
	mov r5, r8
	adds r5, #0x1C
	mov r7, r8
	adds r7, #0x2C
_080D3992:
	lsls r4, r6, #0x02
	ldr r0, [r5, #0x00]
	cmp r0, #0x00
	beq _080D39D2
	adds r0, r7, #0x0
	bl AnimUpdate
	adds r2, r0, #0x0
	str r2, [r5, #0x00]
	mov r0, r8
	adds r0, #0x0C
	adds r0, r0, r4
	ldr r3, [r0, #0x00]
	mov r4, r8
	ldr r0, [r4, #0x04]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	mov r0, r10
	str r0, [sp, #0x008]
	ldr r1, _080D39F0 @ =0x0000FFFC
	adds r0, r6, r1
	add r0, r9
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	ldr r4, [sp, #0x010]
	asrs r0, r4, #0x10
	ldr r4, [sp, #0x014]
	asrs r1, r4, #0x10
	bl DrawSprite
_080D39D2:
	adds r5, #0x04
	adds r7, #0x18
	adds r6, #0x01
	cmp r6, #0x03
	ble _080D3992
_080D39DC:
	add sp, #0x018
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080D39EC: .4byte 0x02039BA0
_080D39F0: .4byte 0x0000FFFC
.syntax divided
