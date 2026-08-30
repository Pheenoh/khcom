.syntax unified
	.align 2, 0
	.global task_bos_md_2
	.thumb
	.thumb_func
	.type task_bos_md_2, %function
task_bos_md_2: @ 080FC8B0
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x024
	mov r8, r0
	ldrb r0, [r0, #0x1C]
	cmp r0, #0x00
	bne _080FC8C6
	b _080FCA0C
_080FC8C6:
	mov r0, r8
	adds r0, #0x68
	bl func_0801CA00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080FC8FC
	mov r1, r8
	ldr r0, [r1, #0x28]
	ldr r4, _080FC8F8 @ =0x08F69BC4
	cmp r0, r4
	beq _080FC8EE
	movs r1, #0xA0
	lsls r1, r1, #0x13
	adds r0, r4, #0x0
	movs r2, #0x20
	bl func_08005BE8
	mov r2, r8
	str r4, [r2, #0x28]
_080FC8EE:
	mov r3, r8
	ldr r3, [r3, #0x24]
	str r3, [sp, #0x014]
	b _080FC91C
	.byte 0x00, 0x00
_080FC8F8: .4byte 0x08F69BC4
_080FC8FC:
	mov r4, r8
	ldr r0, [r4, #0x28]
	ldr r4, _080FCA1C @ =0x09A3C97C
	cmp r0, r4
	beq _080FC916
	movs r1, #0xA0
	lsls r1, r1, #0x13
	adds r0, r4, #0x0
	movs r2, #0x20
	bl func_08005BE8
	mov r0, r8
	str r4, [r0, #0x28]
_080FC916:
	mov r1, r8
	ldr r1, [r1, #0x20]
	str r1, [sp, #0x014]
_080FC91C:
	ldr r0, _080FCA20 @ =0x02039B84
	ldr r2, [r0, #0x00]
	ldr r1, [r2, #0x00]
	asrs r1, r1, #0x08
	movs r0, #0xBC
	lsls r0, r0, #0x01
	add r0, r8
	ldrh r0, [r0, #0x00]
	subs r0, #0x48
	subs r1, r1, r0
	add r0, sp, #0x010
	strh r1, [r0, #0x00]
	ldr r2, [r2, #0x04]
	asrs r2, r2, #0x08
	movs r0, #0xBD
	lsls r0, r0, #0x01
	add r0, r8
	ldrh r0, [r0, #0x00]
	subs r0, #0x30
	subs r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	mov r4, sp
	adds r4, #0x12
	strh r2, [r4, #0x00]
	add r0, sp, #0x010
	ldrh r1, [r0, #0x00]
	movs r0, #0x01
	bl func_08005244
	mov r2, r8
	adds r2, #0x2C
	str r2, [sp, #0x020]
	mov r3, r8
	adds r3, #0x40
	str r3, [sp, #0x018]
	mov r0, r8
	adds r0, #0x54
	str r0, [sp, #0x01C]
	movs r7, #0xC4
	lsls r7, r7, #0x01
	add r7, r8
	movs r1, #0x00
	mov r9, r1
	movs r2, #0x01
	mov r10, r2
_080FC978:
	movs r3, #0x00
	ldsh r2, [r7, r3]
	adds r2, #0xE0
	lsls r2, r2, #0x08
	movs r4, #0x02
	ldsh r5, [r7, r4]
	movs r0, #0x80
	lsls r0, r0, #0x01
	adds r5, r5, r0
	lsls r5, r5, #0x08
	movs r1, #0x04
	ldsh r0, [r7, r1]
	lsls r0, r0, #0x08
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, sp
	adds r1, #0x12
	adds r3, r5, #0x0
	bl func_0801909C
	adds r0, r5, #0x0
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r1, sp, #0x010
	movs r2, #0x00
	ldsh r6, [r1, r2]
	mov r3, sp
	movs r4, #0x12
	ldsh r1, [r3, r4]
	movs r2, #0xC2
	lsls r2, r2, #0x01
	add r2, r8
	add r2, r9
	ldr r2, [r2, #0x00]
	movs r3, #0xBE
	lsls r3, r3, #0x01
	add r3, r8
	add r3, r9
	ldr r3, [r3, #0x00]
	ldr r4, [sp, #0x014]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r0, [sp, #0x008]
	asrs r5, r5, #0x06
	ldr r4, _080FCA24 @ =0xFFFFEFFC
	adds r0, r4, #0x0
	subs r0, r0, r5
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r6, #0x0
	bl func_080023E0
	adds r7, #0x14
	movs r0, #0x14
	add r9, r0
	movs r1, #0x01
	negs r1, r1
	add r10, r1
	mov r2, r10
	cmp r2, #0x00
	bge _080FC978
	ldr r0, [sp, #0x020]
	bl func_08000EE0
	ldr r0, [sp, #0x018]
	bl func_08000EE0
	ldr r0, [sp, #0x01C]
	bl func_08000EE0
_080FCA0C:
	add sp, #0x024
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080FCA1C: .4byte 0x09A3C97C
_080FCA20: .4byte 0x02039B84
_080FCA24: .4byte 0xFFFFEFFC
.syntax divided
