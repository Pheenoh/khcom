.syntax unified
	.align 2, 0
	.global task_bos_dsd_ita_2
	.thumb
	.thumb_func
	.type task_bos_dsd_ita_2, %function
task_bos_dsd_ita_2: @ 080C4128
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldr r0, [r6, #0x00]
	movs r1, #0xD6
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _080C416C
	movs r2, #0x80
	lsls r2, r2, #0x04
	mov r8, r2
	ldr r0, [r6, #0x64]
	ldr r4, _080C4164 @ =0xFFFFC000
	adds r0, r0, r4
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	ldr r5, _080C4168 @ =0xFFFFEFFC
	adds r1, r5, #0x0
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r9, r1
	b _080C418A
_080C4164: .4byte 0xFFFFC000
_080C4168: .4byte 0xFFFFEFFC
_080C416C:
	ldr r0, [r6, #0x64]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r1, [r6, #0x64]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r7, _080C41E8 @ =0xFFFFEFFA
	adds r0, r7, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r9, r0
_080C418A:
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r6, #0x60]
	ldr r3, [r6, #0x64]
	ldr r0, [r6, #0x68]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r5, r2]
	adds r2, r6, #0x0
	adds r2, #0x88
	ldr r2, [r2, #0x00]
	ldr r4, [r6, #0x00]
	movs r7, #0xDA
	lsls r7, r7, #0x02
	adds r3, r4, r7
	ldr r3, [r3, #0x00]
	adds r7, #0x04
	adds r4, r4, r7
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	mov r4, r8
	str r4, [sp, #0x008]
	mov r7, r9
	str r7, [sp, #0x00C]
	bl func_080023E0
	ldr r0, [r6, #0x68]
	cmp r0, #0x00
	blt _080C41F0
	ldr r0, _080C41EC @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x24]
	movs r0, #0x80
	lsls r0, r0, #0x01
	cmp r1, r0
	bne _080C41F0
	movs r7, #0x00
	b _080C421A
_080C41E8: .4byte 0xFFFFEFFA
_080C41EC: .4byte 0x02039B84
_080C41F0:
	ldr r0, [r6, #0x68]
	negs r0, r0
	cmp r0, #0x00
	bge _080C41FA
	adds r0, #0x7F
_080C41FA:
	asrs r0, r0, #0x07
	movs r1, #0x80
	lsls r1, r1, #0x01
	subs r2, r1, r0
	cmp r2, #0x7F
	bgt _080C4208
	movs r2, #0x80
_080C4208:
	movs r3, #0x00
	cmp r2, r1
	ble _080C4210
	movs r3, #0x01
_080C4210:
	movs r0, #0x00
	adds r1, r2, #0x0
	bl func_08002CB4
	adds r7, r0, #0x0
_080C421A:
	ldr r2, [r6, #0x60]
	ldr r3, [r6, #0x64]
	movs r0, #0x00
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r5, r2]
	adds r2, r6, #0x0
	adds r2, #0x8C
	ldr r2, [r2, #0x00]
	ldr r4, [r6, #0x00]
	movs r5, #0xDA
	lsls r5, r5, #0x02
	adds r3, r4, r5
	ldr r3, [r3, #0x00]
	adds r5, #0x08
	adds r4, r4, r5
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	str r7, [sp, #0x004]
	movs r4, #0xC0
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	ldr r4, _080C426C @ =0x0000FFF0
	str r4, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C426C: .4byte 0x0000FFF0
.syntax divided
