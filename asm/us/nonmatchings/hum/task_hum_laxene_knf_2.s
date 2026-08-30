.syntax unified
	.align 2, 0
	.global task_hum_laxene_knf_2
	.thumb
	.thumb_func
	.type task_hum_laxene_knf_2, %function
task_hum_laxene_knf_2: @ 080525DC
	push {r4, r5, r6, r7, lr}
	mov r7, r9
	mov r6, r8
	push {r6, r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	adds r0, #0x08
	bl func_08005AFC
	mov r8, r0
	adds r0, r6, #0x0
	adds r0, #0x2C
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08052602
	ldr r0, [r6, #0x24]
	bl func_0801AF1C
	b _0805260C
_08052602:
	ldr r0, [r6, #0x24]
	bl func_0801AF1C
	movs r1, #0x01
	orrs r0, r1
_0805260C:
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r6, #0x20]
	ldr r3, [r6, #0x24]
	ldr r0, [r6, #0x28]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r5, r2]
	ldr r3, [r6, #0x00]
	ldr r2, [r6, #0x04]
	str r2, [sp, #0x000]
	movs r7, #0x00
	mov r9, r7
	mov r2, r9
	str r2, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r4, [r6, #0x24]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r7, _0805268C @ =0xFFFFEFFC
	adds r2, r7, #0x0
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	mov r2, r8
	bl func_080023E0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r5, r2]
	movs r2, #0x20
	str r2, [sp, #0x000]
	str r2, [sp, #0x004]
	movs r2, #0x02
	movs r3, #0x02
	bl func_080035CC
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _0805267C
	adds r0, r6, #0x0
	adds r0, #0x2D
	mov r7, r9
	strb r7, [r0, #0x00]
_0805267C:
	add sp, #0x014
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0805268C: .4byte 0xFFFFEFFC
.syntax divided
