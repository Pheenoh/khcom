.syntax unified
	.align 2, 0
	.global task_hum_axcel_ptc_2
	.thumb
	.thumb_func
	.type task_hum_axcel_ptc_2, %function
task_hum_axcel_ptc_2: @ 080542BC
	push {r4, r5, r6, lr}
	add sp, #-0x014
	adds r5, r0, #0x0
	mov r4, sp
	adds r4, #0x12
	ldr r2, [r5, #0x24]
	ldr r3, [r5, #0x28]
	ldr r0, [r5, #0x2C]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r4, #0x0
	bl func_0801909C
	ldr r0, [r5, #0x28]
	bl func_0801AF1C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	add r1, sp, #0x010
	movs r2, #0x00
	ldsh r6, [r1, r2]
	movs r2, #0x00
	ldsh r1, [r4, r2]
	ldr r2, [r5, #0x08]
	ldr r3, [r5, #0x00]
	ldr r4, [r5, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r0, [sp, #0x008]
	ldr r4, [r5, #0x28]
	asrs r4, r4, #0x08
	lsls r4, r4, #0x02
	ldr r5, _08054318 @ =0xFFFFEFFC
	adds r0, r5, #0x0
	subs r0, r0, r4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp, #0x00C]
	adds r0, r6, #0x0
	bl func_080023E0
	add sp, #0x014
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_08054318: .4byte 0xFFFFEFFC
.syntax divided
