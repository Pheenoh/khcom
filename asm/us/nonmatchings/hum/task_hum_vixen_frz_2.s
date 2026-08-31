.syntax unified
	.align 2, 0
	.global task_hum_vixen_frz_2
	.thumb
	.thumb_func
	.type task_hum_vixen_frz_2, %function
task_hum_vixen_frz_2: @ 08055DAC
	push {r4, r5, r6, r7, lr}
	add sp, #-0x014
	adds r7, r0, #0x0
	ldr r0, [r7, #0x2C]
	cmp r0, #0x06
	beq _08055E14
	adds r0, r7, #0x0
	adds r0, #0x08
	bl AnimGetGfx
	adds r6, r0, #0x0
	ldr r0, [r7, #0x24]
	bl func_0801AF1C
	adds r4, r0, #0x0
	ldrh r0, [r7, #0x34]
	orrs r4, r0
	lsls r4, r4, #0x10
	lsrs r4, r4, #0x10
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r7, #0x20]
	ldr r3, [r7, #0x24]
	ldr r0, [r7, #0x28]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl WorldToScreen
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r5, r2]
	ldr r3, [r7, #0x00]
	ldr r2, [r7, #0x04]
	str r2, [sp, #0x000]
	movs r2, #0x00
	str r2, [sp, #0x004]
	str r4, [sp, #0x008]
	ldr r4, [r7, #0x24]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r5, _08055E1C @ =0xFFFFEFFC
	adds r2, r5, #0x0
	subs r2, r2, r4
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	str r2, [sp, #0x00C]
	adds r2, r6, #0x0
	bl DrawSprite
_08055E14:
	add sp, #0x014
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
_08055E1C: .4byte 0xFFFFEFFC
.syntax divided
