.syntax unified
	.align 2, 0
	.global task_bos_boogie_knife_2
	.thumb
	.thumb_func
	.type task_bos_boogie_knife_2, %function
task_bos_boogie_knife_2: @ 080DB314
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r5, r0, #0x0
	adds r6, r5, #0x0
	adds r6, #0x2C
	mov r4, sp
	adds r4, #0x12
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r5, r1
	ldr r2, [r6, #0x04]
	ldr r0, [r0, #0x00]
	adds r2, r2, r0
	ldr r3, [r6, #0x08]
	ldr r7, _080DB38C @ =0xFFFFDC00
	adds r3, r3, r7
	ldr r0, [r6, #0x0C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	adds r0, #0x20
	lsls r0, r0, #0x10
	movs r1, #0x98
	lsls r1, r1, #0x11
	mov r9, r4
	cmp r0, r1
	bhi _080DB3EE
	ldr r0, [r6, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, _080DB390 @ =0x0203C574
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080DB39C
	ldr r0, _080DB394 @ =0x03007480
	ldr r0, [r0, #0x00]
	movs r1, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _080DB39C
	ldr r0, _080DB398 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080DB39C
	ldr r0, [r5, #0x10]
	mov r10, r0
	b _080DB3A0
_080DB38C: .4byte 0xFFFFDC00
_080DB390: .4byte 0x0203C574
_080DB394: .4byte 0x03007480
_080DB398: .4byte 0x02039B84
_080DB39C:
	ldr r1, [r5, #0x0C]
	mov r10, r1
_080DB3A0:
	movs r3, #0xA4
	lsls r3, r3, #0x01
	adds r0, r5, r3
	ldr r1, [r0, #0x00]
	movs r2, #0x80
	lsls r2, r2, #0x01
	movs r0, #0x00
	movs r3, #0x00
	bl func_08002CB4
	adds r4, r0, #0x0
	adds r0, r5, #0x0
	adds r0, #0x14
	bl func_08005AFC
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r7, #0x00
	ldsh r0, [r0, r7]
	mov r3, r9
	movs r7, #0x00
	ldsh r1, [r3, r7]
	ldr r3, [r5, #0x08]
	mov r5, r10
	str r5, [sp, #0x000]
	str r4, [sp, #0x004]
	mov r7, r8
	str r7, [sp, #0x008]
	ldr r5, [r6, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r6, _080DB400 @ =0xFFFFEFFC
	adds r4, r6, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
_080DB3EE:
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080DB400: .4byte 0xFFFFEFFC
.syntax divided
