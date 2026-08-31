.syntax unified
	.align 2, 0
	.global task_hum_vixen_ndl_2
	.thumb
	.thumb_func
	.type task_hum_vixen_ndl_2, %function
task_hum_vixen_ndl_2: @ 080555F4
	push {r4, r5, r6, r7, lr}
	add sp, #-0x014
	adds r5, r0, #0x0
	adds r0, #0x08
	bl AnimGetGfx
	adds r7, r0, #0x0
	ldr r0, [r5, #0x24]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r6, r0, #0x10
	adds r0, r5, #0x0
	adds r0, #0x2E
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _0805561A
	movs r0, #0x01
	orrs r6, r0
_0805561A:
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x20]
	ldr r3, [r5, #0x24]
	ldr r0, [r5, #0x28]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r3, [r5, #0x00]
	ldr r2, [r5, #0x04]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	str r6, [sp, #0x008]
	ldr r4, [r5, #0x24]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r5, _08055664 @ =0xFFFFEFFC
	adds r2, r5, #0x0
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r7, #0x0
	bl DrawSprite
	add sp, #0x014
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08055664: .4byte 0xFFFFEFFC
.syntax divided
