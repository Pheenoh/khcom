.syntax unified
	.align 2, 0
	.global task_evt_obj_2
	.thumb
	.thumb_func
	.type task_evt_obj_2, %function
task_evt_obj_2: @ 0801CF3C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x010
	adds r6, r0, #0x0
	ldr r7, [r6, #0x00]
	ldrh r1, [r7, #0x14]
	movs r0, #0x02
	ands r0, r1
	cmp r0, #0x00
	bne _0801CFCA
	ldr r5, [r7, #0x04]
	asrs r5, r5, #0x08
	ldr r0, _0801CFD8 @ =0x02039DC8
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x58]
	asrs r0, r0, #0x08
	subs r5, r5, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	ldr r4, [r7, #0x08]
	asrs r4, r4, #0x08
	ldr r0, [r7, #0x0C]
	asrs r0, r0, #0x08
	adds r4, r4, r0
	ldr r0, [r1, #0x5C]
	asrs r0, r0, #0x08
	subs r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	adds r0, r6, #0x0
	adds r0, #0x0C
	bl func_08005AFC
	mov r8, r0
	adds r0, r7, #0x0
	adds r0, #0x28
	ldrb r0, [r0, #0x00]
	ldr r1, [r7, #0x20]
	ldr r2, [r7, #0x24]
	movs r3, #0x01
	bl func_08002CB4
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	ldr r3, [r6, #0x04]
	ldr r1, [r6, #0x08]
	str r1, [sp, #0x000]
	str r0, [sp, #0x004]
	ldrh r0, [r7, #0x16]
	str r0, [sp, #0x008]
	ldr r1, [r7, #0x08]
	asrs r1, r1, #0x08
	lsls r1, r1, #0x02
	ldr r2, _0801CFDC @ =0xFFFFEFFE
	adds r0, r2, #0x0
	subs r0, r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	mov r2, r8
	bl func_080023E0
	adds r0, r6, #0x0
	adds r0, #0x24
	bl func_08000EE0
_0801CFCA:
	add sp, #0x010
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801CFD8: .4byte 0x02039DC8
_0801CFDC: .4byte 0xFFFFEFFE
.syntax divided
