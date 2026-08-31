.syntax unified
	.align 2, 0
	.global task_btl_escape_2
	.thumb
	.thumb_func
	.type task_btl_escape_2, %function
task_btl_escape_2: @ 08030A64
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r0, #0x22
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08030B5E
	ldr r0, _08030AD0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r4, [r0, #0x7C]
	ldr r0, [r4, #0x34]
	ldr r1, [r4, #0x38]
	movs r2, #0x04
	movs r3, #0x00
	mov r8, r3
	ands r0, r2
	movs r1, #0x00
	adds r7, r1, #0x0
	orrs r7, r0
	cmp r7, #0x00
	beq _08030ADC
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r4, #0x04]
	ldr r0, _08030AD4 @ =0xFFFFFD00
	adds r2, r2, r0
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x0C]
	ldr r1, _08030AD8 @ =0xFFFFD800
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x00
	ldsh r1, [r5, r3]
	ldr r2, [r6, #0x08]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r4, #0x02
	str r4, [sp, #0x00C]
	bl DrawSprite
	b _08030B16
_08030AD0: .4byte 0x02039B84
_08030AD4: .4byte 0xFFFFFD00
_08030AD8: .4byte 0xFFFFD800
_08030ADC:
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r4, #0x04]
	ldr r0, _08030B2C @ =0xFFFFF400
	adds r2, r2, r0
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x0C]
	ldr r1, _08030B30 @ =0xFFFFD800
	adds r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r2, #0x00
	ldsh r0, [r0, r2]
	movs r3, #0x00
	ldsh r1, [r5, r3]
	ldr r2, [r6, #0x0C]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	str r7, [sp, #0x008]
	movs r4, #0x02
	str r4, [sp, #0x00C]
	bl DrawSprite
_08030B16:
	ldr r1, [r6, #0x14]
	cmp r1, #0x00
	ble _08030B5E
	lsls r1, r1, #0x01
	movs r2, #0x80
	lsls r2, r2, #0x01
	cmp r1, r2
	ble _08030B34
	movs r0, #0x00
	movs r3, #0x01
	b _08030B38
_08030B2C: .4byte 0xFFFFF400
_08030B30: .4byte 0xFFFFD800
_08030B34:
	movs r0, #0x00
	movs r3, #0x00
_08030B38:
	bl AllocObjAffine
	adds r7, r0, #0x0
	add r0, sp, #0x010
	movs r4, #0x00
	ldsh r0, [r0, r4]
	movs r2, #0x00
	ldsh r1, [r5, r2]
	ldr r2, [r6, #0x10]
	ldr r3, [r6, #0x00]
	ldr r4, [r6, #0x04]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	movs r4, #0x00
	str r4, [sp, #0x008]
	movs r4, #0x01
	str r4, [sp, #0x00C]
	bl DrawSprite
_08030B5E:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
