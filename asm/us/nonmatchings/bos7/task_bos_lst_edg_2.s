.syntax unified
	.align 2, 0
	.global task_bos_lst_edg_2
	.thumb
	.thumb_func
	.type task_bos_lst_edg_2, %function
task_bos_lst_edg_2: @ 08110810
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	add sp, #-0x014
	adds r4, r0, #0x0
	movs r0, #0x12
	add r0, sp
	mov r8, r0
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x0C]
	ldr r0, [r4, #0x10]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	mov r1, r8
	bl WorldToScreen
	ldr r0, [r4, #0x0C]
	bl func_0801AF1C
	adds r6, r0, #0x0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r0, [r4, #0x0C]
	asrs r0, r0, #0x08
	lsls r0, r0, #0x02
	ldr r1, _08110880 @ =0xFFFFEFFC
	adds r5, r1, #0x0
	subs r5, r5, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	adds r0, r4, #0x0
	adds r0, #0x2C
	bl AnimGetGfx
	adds r2, r0, #0x0
	add r0, sp, #0x010
	movs r3, #0x00
	ldsh r0, [r0, r3]
	mov r7, r8
	movs r3, #0x00
	ldsh r1, [r7, r3]
	ldr r3, [r4, #0x44]
	ldr r4, [r4, #0x48]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r6, [sp, #0x008]
	str r5, [sp, #0x00C]
	bl DrawSprite
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08110880: .4byte 0xFFFFEFFC
.syntax divided
