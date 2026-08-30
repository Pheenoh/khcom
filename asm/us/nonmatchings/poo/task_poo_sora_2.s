.syntax unified
	.align 2, 0
	.global task_poo_sora_2
	.thumb
	.thumb_func
	.type task_poo_sora_2, %function
task_poo_sora_2: @ 080CB8F0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r5, r0, #0x0
	ldr r6, _080CB958 @ =0x0203C420
	adds r0, #0xA0
	ldrh r1, [r0, #0x00]
	movs r0, #0x02
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x04
	mov r8, r1
	cmp r0, #0x00
	beq _080CB912
	ldr r3, _080CB95C @ =0x00000801
	mov r8, r3
_080CB912:
	adds r0, r5, #0x0
	adds r0, #0xAC
	ldrb r4, [r0, #0x00]
	cmp r4, #0x00
	beq _080CB980
	ldr r2, _080CB960 @ =0x02034DEC
	subs r0, #0x2C
	ldr r0, [r0, #0x00]
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	ldr r4, _080CB964 @ =0xFFFFEFF8
	adds r1, r4, #0x0
	subs r3, r1, r0
	strh r3, [r2, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x84
	ldr r1, [r0, #0x00]
	ldr r0, [r5, #0x48]
	mov r12, r2
	cmp r1, r0
	ble _080CB94C
	adds r0, r5, #0x0
	adds r0, #0x88
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x10]
	movs r0, #0x80
	lsls r0, r0, #0x03
	cmp r1, r0
	bne _080CB974
_080CB94C:
	ldr r0, [r5, #0x78]
	cmp r0, #0x00
	beq _080CB968
	movs r0, #0x00
	b _080CB96A
	.byte 0x00, 0x00
_080CB958: .4byte 0x0203C420
_080CB95C: .4byte 0x00000801
_080CB960: .4byte 0x02034DEC
_080CB964: .4byte 0xFFFFEFF8
_080CB968:
	adds r0, r3, #0x1
_080CB96A:
	strh r0, [r6, #0x3A]
	movs r0, #0x00
	str r0, [r6, #0x3C]
	ldr r3, [r6, #0x04]
	b _080CB9AC
_080CB974:
	ldr r0, [r5, #0x78]
	str r0, [r6, #0x3C]
	adds r0, r3, #0x1
	strh r0, [r6, #0x3A]
	ldr r3, [r6, #0x04]
	b _080CB9AC
_080CB980:
	ldr r2, _080CB9A0 @ =0x02034DEC
	ldr r3, [r6, #0x04]
	asrs r0, r3, #0x08
	lsls r0, r0, #0x02
	ldr r7, _080CB9A4 @ =0xFFFFEFF8
	adds r1, r7, #0x0
	subs r1, r1, r0
	strh r1, [r2, #0x00]
	str r4, [r6, #0x3C]
	ldr r0, [r6, #0x0C]
	mov r12, r2
	cmp r4, r0
	beq _080CB9A8
	strh r4, [r6, #0x3A]
	b _080CB9AC
	.byte 0x00, 0x00
_080CB9A0: .4byte 0x02034DEC
_080CB9A4: .4byte 0xFFFFEFF8
_080CB9A8:
	adds r0, r1, #0x1
	strh r0, [r6, #0x3A]
_080CB9AC:
	ldr r0, [r6, #0x00]
	asrs r0, r0, #0x08
	ldr r1, _080CBA00 @ =0x0203C40C
	ldrh r1, [r1, #0x00]
	subs r0, r0, r1
	asrs r1, r3, #0x08
	ldr r2, [r6, #0x08]
	asrs r2, r2, #0x08
	adds r1, r1, r2
	ldr r2, _080CBA04 @ =0x0203C3F8
	ldrh r2, [r2, #0x00]
	subs r1, r1, r2
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r5, #0x20]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	mov r6, r12
	ldrh r4, [r6, #0x00]
	subs r4, #0x01
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	adds r0, r5, #0x0
	adds r0, #0x24
	bl func_08000EE0
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080CBA00: .4byte 0x0203C40C
_080CBA04: .4byte 0x0203C3F8
.syntax divided
