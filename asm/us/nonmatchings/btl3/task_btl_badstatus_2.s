.syntax unified
	.align 2, 0
	.global task_btl_badstatus_2
	.thumb
	.thumb_func
	.type task_btl_badstatus_2, %function
task_btl_badstatus_2: @ 08040BC8
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r6, r0, #0x0
	ldr r5, [r6, #0x24]
	adds r0, r5, #0x0
	adds r0, #0xE8
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08040C5E
	ldr r0, [r5, #0x08]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	ldr r0, _08040C00 @ =0x02039B84
	ldr r0, [r0, #0x00]
	adds r0, #0x70
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _08040C04
	adds r0, r6, #0x0
	adds r0, #0x0C
	bl func_08005AFC
	b _08040C0C
_08040C00: .4byte 0x02039B84
_08040C04:
	adds r0, r6, #0x0
	adds r0, #0x0C
	bl func_08005A64
_08040C0C:
	adds r7, r0, #0x0
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x04]
	ldr r3, [r5, #0x08]
	adds r0, r5, #0x0
	adds r0, #0x9C
	ldrh r1, [r0, #0x00]
	adds r1, #0x08
	lsls r1, r1, #0x08
	ldr r0, [r5, #0x0C]
	subs r0, r0, r1
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r3, [r6, #0x00]
	ldr r2, [r6, #0x2C]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	mov r2, r8
	str r2, [sp, #0x008]
	ldr r4, [r5, #0x08]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r5, _08040C6C @ =0xFFFFEFFB
	adds r2, r5, #0x0
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r7, #0x0
	bl func_080023E0
_08040C5E:
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08040C6C: .4byte 0xFFFFEFFB
.syntax divided
