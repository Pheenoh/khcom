.syntax unified
	.align 2, 0
	.global task_bos_lst_ptl_2
	.thumb
	.thumb_func
	.type task_bos_lst_ptl_2, %function
task_bos_lst_ptl_2: @ 08111B54
	push {r4, r5, r6, lr}
	mov r6, r9
	mov r5, r8
	push {r5, r6}
	add sp, #-0x010
	mov r8, r0
	ldr r5, [r0, #0x08]
	asrs r5, r5, #0x08
	ldr r1, [r0, #0x10]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x02
	asrs r0, r0, #0x08
	adds r5, r5, r0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov r0, r8
	ldr r4, [r0, #0x0C]
	asrs r4, r4, #0x08
	ldr r1, [r0, #0x14]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x01
	asrs r0, r0, #0x08
	adds r4, r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	ldr r0, _08111BD4 @ =0x00020100
	bl func_0801AF1C
	adds r6, r0, #0x0
	lsls r6, r6, #0x10
	lsrs r6, r6, #0x10
	ldr r1, _08111BD8 @ =0x0000E7F8
	mov r9, r1
	mov r0, r8
	adds r0, #0x18
	bl AnimGetGfx
	adds r2, r0, #0x0
	lsls r5, r5, #0x10
	asrs r5, r5, #0x10
	lsls r4, r4, #0x10
	asrs r4, r4, #0x10
	mov r0, r8
	ldr r3, [r0, #0x30]
	ldr r0, [r0, #0x34]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r6, [sp, #0x008]
	mov r1, r9
	str r1, [sp, #0x00C]
	adds r0, r5, #0x0
	adds r1, r4, #0x0
	bl DrawSprite
	add sp, #0x010
	pop {r3, r4}
	mov r8, r3
	mov r9, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08111BD4: .4byte 0x00020100
_08111BD8: .4byte 0x0000E7F8
.syntax divided
