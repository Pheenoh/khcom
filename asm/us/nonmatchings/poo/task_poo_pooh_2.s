.syntax unified
	.align 2, 0
	.global task_poo_pooh_2
	.thumb
	.thumb_func
	.type task_poo_pooh_2, %function
task_poo_pooh_2: @ 080C9A24
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r0, [r5, #0x28]
	asrs r0, r0, #0x08
	ldr r1, _080C9AA4 @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r1, [r5, #0x2C]
	asrs r1, r1, #0x08
	ldr r0, [r5, #0x30]
	asrs r0, r0, #0x08
	adds r1, r1, r0
	ldr r0, _080C9AA8 @ =0x0203C3F8
	ldrh r0, [r0, #0x00]
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r7, r1, #0x10
	adds r0, r5, #0x0
	adds r0, #0x24
	ldrb r0, [r0, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x04
	mov r9, r1
	cmp r0, #0x00
	beq _080C9A68
	ldr r2, _080C9AAC @ =0x00000801
	mov r9, r2
_080C9A68:
	ldr r0, _080C9AB0 @ =0x02034DAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x14
	bne _080C9AEC
	adds r0, r5, #0x0
	adds r0, #0xA8
	ldr r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080C9AEC
	adds r0, r5, #0x0
	adds r0, #0x0C
	bl func_08005B34
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bhi _080C9AC0
	ldr r0, _080C9AB4 @ =0x0203C3E8
	ldr r0, [r0, #0x00]
	ldr r3, _080C9AB8 @ =0xFFFFFB00
	adds r0, r0, r3
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	ldr r4, _080C9ABC @ =0xFFFFEFFD
	adds r1, r4, #0x0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	b _080C9C2A
	.byte 0x00, 0x00
_080C9AA4: .4byte 0x0203C40C
_080C9AA8: .4byte 0x0203C3F8
_080C9AAC: .4byte 0x00000801
_080C9AB0: .4byte 0x02034DAC
_080C9AB4: .4byte 0x0203C3E8
_080C9AB8: .4byte 0xFFFFFB00
_080C9ABC: .4byte 0xFFFFEFFD
_080C9AC0:
	ldr r0, _080C9AE0 @ =0x0203C3E8
	ldr r0, [r0, #0x00]
	ldr r1, _080C9AE4 @ =0xFFFFFB00
	adds r0, r0, r1
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	ldr r2, _080C9AE8 @ =0xFFFFEFFB
	adds r1, r2, #0x0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r6, r1, #0x10
	adds r1, r5, #0x0
	adds r1, #0xE0
	movs r0, #0x00
	b _080C9C7A
	.byte 0x00, 0x00
_080C9AE0: .4byte 0x0203C3E8
_080C9AE4: .4byte 0xFFFFFB00
_080C9AE8: .4byte 0xFFFFEFFB
_080C9AEC:
	bl func_080C9DAC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080C9AFE
	bl func_080D06C8
	subs r0, #0x04
	b _080C9BA6
_080C9AFE:
	ldr r0, _080C9B34 @ =0x0203C3EC
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x00]
	ldr r1, [r1, #0x04]
	bl func_080D0210
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080C9BBA
	ldr r0, _080C9B38 @ =0x02034DAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x15
	bne _080C9B3C
	adds r0, r5, #0x0
	adds r0, #0xA8
	ldr r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080C9B3C
	adds r0, r5, #0x0
	adds r0, #0xF6
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C9B3C
	bl func_080D06BC
	subs r0, #0x03
	b _080C9BA6
_080C9B34: .4byte 0x0203C3EC
_080C9B38: .4byte 0x02034DAC
_080C9B3C:
	ldr r4, _080C9B78 @ =0x0203C3EC
	ldr r1, [r4, #0x00]
	ldr r0, [r1, #0x00]
	ldr r1, [r1, #0x04]
	bl func_080D0210
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x53
	beq _080C9B62
	ldr r1, [r4, #0x00]
	ldr r0, [r1, #0x00]
	ldr r1, [r1, #0x04]
	bl func_080D0210
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0xAD
	bne _080C9B88
_080C9B62:
	ldr r0, [r4, #0x00]
	ldr r1, _080C9B7C @ =0x0203C420
	ldr r2, [r0, #0x04]
	ldr r0, [r1, #0x04]
	cmp r2, r0
	bge _080C9B80
	bl func_080D06C8
	adds r0, #0x05
	b _080C9BA6
	.byte 0x00, 0x00
_080C9B78: .4byte 0x0203C3EC
_080C9B7C: .4byte 0x0203C420
_080C9B80:
	bl func_080D06C8
	adds r0, #0x01
	b _080C9BA6
_080C9B88:
	ldr r0, [r4, #0x00]
	ldr r1, _080C9B9C @ =0x0203C420
	ldr r2, [r0, #0x04]
	ldr r0, [r1, #0x04]
	cmp r2, r0
	bge _080C9BA0
	bl func_080D06BC
	subs r0, #0x02
	b _080C9BA6
_080C9B9C: .4byte 0x0203C420
_080C9BA0:
	bl func_080D06BC
	subs r0, #0x06
_080C9BA6:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r1, r6, #0x1
	adds r0, r5, #0x0
	adds r0, #0xE0
	movs r2, #0x00
	strh r1, [r0, #0x00]
	adds r0, #0x04
	str r2, [r0, #0x00]
	b _080C9C7C
_080C9BBA:
	adds r0, r5, #0x0
	adds r0, #0xE8
	ldrb r2, [r0, #0x00]
	cmp r2, #0x00
	beq _080C9C4A
	subs r0, #0x54
	ldr r1, [r0, #0x00]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r3, _080C9BE4 @ =0xFFFFEFF8
	adds r0, r3, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	ldr r0, _080C9BE8 @ =0x0203C420
	ldr r1, [r5, #0x2C]
	ldr r0, [r0, #0x04]
	cmp r1, r0
	blt _080C9BEC
	subs r0, r6, #0x2
	b _080C9BEE
_080C9BE4: .4byte 0xFFFFEFF8
_080C9BE8: .4byte 0x0203C420
_080C9BEC:
	adds r0, r6, #0x2
_080C9BEE:
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r5, #0x0
	adds r0, #0x98
	ldr r1, [r0, #0x00]
	ldr r0, [r5, #0x5C]
	cmp r1, r0
	ble _080C9C0E
	adds r0, r5, #0x0
	adds r0, #0x9C
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x03
	cmp r1, r0
	bne _080C9C34
_080C9C0E:
	adds r0, r5, #0x0
	adds r0, #0x8C
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C9C22
	adds r1, r5, #0x0
	adds r1, #0xE0
	movs r0, #0x00
	strh r0, [r1, #0x00]
	b _080C9C2A
_080C9C22:
	adds r1, r6, #0x1
	adds r0, r5, #0x0
	adds r0, #0xE0
	strh r1, [r0, #0x00]
_080C9C2A:
	adds r1, r5, #0x0
	adds r1, #0xE4
	movs r0, #0x00
	str r0, [r1, #0x00]
	b _080C9C7C
_080C9C34:
	adds r1, r5, #0x0
	adds r1, #0xE4
	adds r0, r5, #0x0
	adds r0, #0x8C
	ldr r0, [r0, #0x00]
	str r0, [r1, #0x00]
	adds r1, r6, #0x1
	adds r0, r5, #0x0
	adds r0, #0xE0
	strh r1, [r0, #0x00]
	b _080C9C7C
_080C9C4A:
	ldr r1, [r5, #0x2C]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r4, _080C9C70 @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r5, #0x0
	adds r0, #0xE4
	str r2, [r0, #0x00]
	ldr r0, [r5, #0x34]
	cmp r2, r0
	beq _080C9C74
	adds r0, r5, #0x0
	adds r0, #0xE0
	strh r2, [r0, #0x00]
	b _080C9C7C
	.byte 0x00, 0x00
_080C9C70: .4byte 0xFFFFEFFC
_080C9C74:
	adds r1, r5, #0x0
	adds r1, #0xE0
	ldr r0, _080C9CC4 @ =0x0000FFF0
_080C9C7A:
	strh r0, [r1, #0x00]
_080C9C7C:
	adds r0, r5, #0x0
	adds r0, #0xFA
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C9C8E
	adds r1, r5, #0x0
	adds r1, #0xE0
	movs r0, #0x00
	strh r0, [r1, #0x00]
_080C9C8E:
	mov r1, r8
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	lsls r1, r7, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	mov r4, r9
	str r4, [sp, #0x008]
	str r6, [sp, #0x00C]
	bl DrawSprite
	adds r0, r5, #0x0
	adds r0, #0xB0
	bl TaskPoolDraw
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080C9CC4: .4byte 0x0000FFF0
.syntax divided
