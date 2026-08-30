.syntax unified
	.align 2, 0
	.global task_bos_pc_flt_2
	.thumb
	.thumb_func
	.type task_bos_pc_flt_2, %function
task_bos_pc_flt_2: @ 0810BE30
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldr r0, [r6, #0x30]
	cmp r0, #0x00
	bgt _0810BEE6
	adds r5, r6, #0x0
	adds r5, #0x9C
	adds r0, r5, #0x0
	bl func_08005B38
	lsls r0, r0, #0x10
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r6, #0x28]
	ldr r1, _0810BE9C @ =0x09A4CEDC
	lsrs r0, r0, #0x0D
	adds r0, r0, r1
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r7, r0, #0x08
	ldr r3, [r6, #0x2C]
	adds r3, r3, r7
	ldr r0, [r6, #0x30]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	ldr r0, _0810BEA0 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0xF0
	ldr r0, [r0, #0x00]
	mov r8, r5
	cmp r0, #0x00
	beq _0810BEA8
	ldr r0, [r6, #0x2C]
	adds r0, r0, r7
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r1, [r6, #0x2C]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r2, _0810BEA4 @ =0xFFFFEFFC
	adds r0, r2, #0x0
	subs r0, r0, r1
	movs r1, #0x03
	orrs r0, r1
	b _0810BEBE
	.byte 0x00, 0x00
_0810BE9C: .4byte 0x09A4CEDC
_0810BEA0: .4byte 0x02039B84
_0810BEA4: .4byte 0xFFFFEFFC
_0810BEA8:
	ldr r0, [r6, #0x2C]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r7, r0, #0x10
	ldr r1, [r6, #0x2C]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r3, _0810BEF4 @ =0xFFFFEFFC
	adds r0, r3, #0x0
	subs r0, r0, r1
_0810BEBE:
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	mov r0, r8
	bl func_08005AFC
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r3, #0x00
	ldsh r1, [r4, r3]
	ldr r3, [r6, #0x34]
	ldr r4, [r6, #0x38]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r7, [sp, #0x008]
	str r5, [sp, #0x00C]
	bl func_080023E0
_0810BEE6:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0810BEF4: .4byte 0xFFFFEFFC
.syntax divided
