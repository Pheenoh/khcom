.syntax unified
	.align 2, 0
	.global task_bos_dsd_main_2
	.thumb
	.thumb_func
	.type task_bos_dsd_main_2, %function
task_bos_dsd_main_2: @ 080C2514
	push {r4, r5, r6, r7, lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5, r6, r7}
	add sp, #-0x014
	adds r7, r0, #0x0
	ldr r0, [r7, #0x00]
	mov r9, r0
	ldr r0, _080C2544 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C254C
	ldr r0, _080C2548 @ =0x096FB744
	movs r1, #0xA0
	lsls r1, r1, #0x13
	movs r2, #0x20
	bl func_08007E00
	ldr r1, [r7, #0x4C]
	mov r10, r1
	b _080C25A0
_080C2544: .4byte 0x02039B84
_080C2548: .4byte 0x096FB744
_080C254C:
	movs r0, #0xD6
	lsls r0, r0, #0x02
	add r0, r9
	ldrh r1, [r0, #0x00]
	movs r2, #0x01
	adds r0, r2, #0x0
	ands r0, r1
	cmp r0, #0x00
	beq _080C259C
	ldr r0, _080C257C @ =0x03007480
	ldr r0, [r0, #0x00]
	ands r0, r2
	cmp r0, #0x00
	beq _080C2584
	ldr r0, _080C2580 @ =0x08F69BC4
	movs r1, #0xA0
	lsls r1, r1, #0x13
	movs r2, #0x20
	bl func_08007E00
	ldr r2, [r7, #0x50]
	mov r10, r2
	b _080C25A0
	.byte 0x00, 0x00
_080C257C: .4byte 0x03007480
_080C2580: .4byte 0x08F69BC4
_080C2584:
	ldr r0, _080C2598 @ =0x096FB744
	movs r1, #0xA0
	lsls r1, r1, #0x13
	movs r2, #0x20
	bl func_08007E00
	ldr r4, [r7, #0x4C]
	mov r10, r4
	b _080C25A0
	.byte 0x00, 0x00
_080C2598: .4byte 0x096FB744
_080C259C:
	ldr r5, [r7, #0x4C]
	mov r10, r5
_080C25A0:
	ldr r0, _080C2690 @ =0x02039B84
	ldr r3, [r0, #0x00]
	ldr r1, [r3, #0x00]
	mov r6, r9
	ldr r0, [r6, #0x04]
	subs r1, r1, r0
	asrs r1, r1, #0x08
	adds r1, #0x64
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [r6, #0x08]
	ldr r2, [r6, #0x0C]
	adds r0, r0, r2
	ldr r2, [r3, #0x04]
	subs r2, r2, r0
	asrs r2, r2, #0x08
	movs r0, #0x8C
	lsls r0, r0, #0x01
	adds r2, r2, r0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	movs r0, #0x01
	bl func_08005244
	adds r0, r7, #0x0
	adds r0, #0x54
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080C2678
	ldr r0, [r6, #0x08]
	bl func_0801AF1C
	mov r6, sp
	adds r6, #0x12
	mov r1, r9
	ldr r2, [r1, #0x04]
	ldr r3, [r1, #0x08]
	ldr r0, _080C2694 @ =0xFFFF9C00
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x60
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r6, #0x00]
	adds r1, #0x14
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x14]
	ldr r3, [r7, #0x0C]
	mov r4, r10
	str r4, [sp, #0x000]
	movs r5, #0x00
	mov r8, r5
	str r5, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x03
	str r4, [sp, #0x008]
	mov r4, r9
	ldr r5, [r4, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	mov r12, r5
	ldr r5, _080C2698 @ =0xFFFFEFFB
	adds r4, r5, #0x0
	mov r5, r12
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
	add r0, sp, #0x010
	ldrh r0, [r0, #0x00]
	subs r0, #0x60
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r6, #0x00]
	adds r1, #0x14
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r2, [r7, #0x18]
	ldr r3, [r7, #0x10]
	mov r6, r10
	str r6, [sp, #0x000]
	mov r4, r8
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	mov r6, r9
	ldr r5, [r6, #0x08]
	asrs r5, r5, #0x08
	lsls r5, r5, #0x02
	ldr r6, _080C269C @ =0xFFFFEFFD
	adds r4, r6, #0x0
	subs r4, r4, r5
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	str r4, [sp, #0x00C]
	bl func_080023E0
_080C2678:
	adds r0, r7, #0x0
	adds r0, #0x58
	bl func_08000EE0
	add sp, #0x014
	pop {r3, r4, r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_080C2690: .4byte 0x02039B84
_080C2694: .4byte 0xFFFF9C00
_080C2698: .4byte 0xFFFFEFFB
_080C269C: .4byte 0xFFFFEFFD
.syntax divided
