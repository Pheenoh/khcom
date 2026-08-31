.syntax unified
	.align 2, 0
	.global task_emy_16_p_2
	.thumb
	.thumb_func
	.type task_emy_16_p_2, %function
task_emy_16_p_2: @ 080392A4
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	add sp, #-0x014
	adds r4, r0, #0x0
	adds r0, #0x08
	bl AnimGetGfx
	mov r8, r0
	ldr r0, [r4, #0x24]
	bl func_0801AF1C
	adds r5, r0, #0x0
	lsls r5, r5, #0x10
	lsrs r5, r5, #0x10
	mov r6, sp
	adds r6, #0x12
	ldr r2, [r4, #0x20]
	ldr r3, [r4, #0x24]
	ldr r0, [r4, #0x28]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r6, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r6, r2]
	ldr r3, [r4, #0x00]
	ldr r2, [r4, #0x04]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	str r5, [sp, #0x008]
	ldr r4, [r4, #0x24]
	movs r5, #0x80
	lsls r5, r5, #0x05
	adds r4, r4, r5
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r5, _08039318 @ =0xFFFFEFFC
	adds r2, r5, #0x0
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	mov r2, r8
	bl DrawSprite
	add sp, #0x014
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08039318: .4byte 0xFFFFEFFC
.syntax divided
