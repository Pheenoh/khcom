.syntax unified
	.align 2, 0
	.global task_smn_cloud_2
	.thumb
	.thumb_func
	.type task_smn_cloud_2, %function
task_smn_cloud_2: @ 08041BBC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r5, r0, #0x0
	adds r6, r5, #0x0
	adds r6, #0x38
	adds r0, #0x08
	bl func_08005AFC
	mov r8, r0
	ldr r0, [r6, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r6, #0x04]
	ldr r3, [r6, #0x08]
	ldr r0, [r6, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	movs r1, #0xA8
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r1, [r0, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x01
	mov r9, r4
	cmp r1, r0
	bne _08041C4C
	movs r2, #0xAA
	lsls r2, r2, #0x01
	adds r0, r5, r2
	ldr r3, [r0, #0x00]
	cmp r3, r1
	bne _08041C4C
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08041C30
	ldr r0, _08041C2C @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	adds r1, r2, #0x0
	b _08041C98
	.byte 0x00, 0x00
_08041C2C: .4byte 0x02039B84
_08041C30:
	ldr r0, _08041C44 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r2, [r0, #0x24]
	cmp r2, r3
	bne _08041C48
	adds r1, r2, #0x0
	movs r0, #0x01
	orrs r7, r0
	b _08041C98
	.byte 0x00, 0x00
_08041C44: .4byte 0x02039B84
_08041C48:
	negs r1, r2
	b _08041C98
_08041C4C:
	ldr r0, [r6, #0x34]
	ldr r1, [r6, #0x38]
	movs r2, #0x04
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _08041C78
	ldr r0, _08041C74 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r3, #0xA8
	lsls r3, r3, #0x01
	adds r1, r5, r3
	ldr r2, [r0, #0x24]
	ldr r0, [r1, #0x00]
	muls r0, r2
	asrs r1, r0, #0x08
	adds r3, #0x04
	b _08041C90
	.byte 0x00, 0x00
_08041C74: .4byte 0x02039B84
_08041C78:
	ldr r0, _08041CA8 @ =0x02039B84
	ldr r0, [r0, #0x00]
	movs r2, #0xA8
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r2, [r0, #0x24]
	ldr r0, [r1, #0x00]
	muls r0, r2
	asrs r0, r0, #0x08
	negs r1, r0
	movs r3, #0xAA
	lsls r3, r3, #0x01
_08041C90:
	adds r0, r5, r3
	ldr r0, [r0, #0x00]
	muls r0, r2
	asrs r2, r0, #0x08
_08041C98:
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r2, r0
	bne _08041CAC
	cmp r1, r2
	bne _08041CAC
	movs r4, #0x00
	b _08041CC0
_08041CA8: .4byte 0x02039B84
_08041CAC:
	cmp r2, #0xFF
	bgt _08041CB6
	movs r0, #0x00
	movs r3, #0x00
	b _08041CBA
_08041CB6:
	movs r0, #0x00
	movs r3, #0x01
_08041CBA:
	bl func_08002CB4
	adds r4, r0, #0x0
_08041CC0:
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	mov r2, r9
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldr r3, [r5, #0x00]
	ldr r2, [r5, #0x04]
	str r2, [sp, #0x000]
	str r4, [sp, #0x004]
	str r7, [sp, #0x008]
	ldr r2, [r6, #0x08]
	asrs r2, r2, #0x08
	lsls r2, r2, #0x02
	ldr r7, _08041D18 @ =0xFFFFEFFC
	adds r4, r7, #0x0
	subs r2, r4, r2
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	mov r2, r8
	bl func_080023E0
	ldr r0, [r6, #0x08]
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	subs r4, r4, r0
	movs r0, #0x02
	adds r1, r6, #0x0
	adds r1, #0xCC
	orrs r4, r0
	strh r4, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x20
	bl func_08000EE0
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08041D18: .4byte 0xFFFFEFFC
.syntax divided
