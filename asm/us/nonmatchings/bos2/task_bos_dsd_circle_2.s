.syntax unified
	.align 2, 0
	.global task_bos_dsd_circle_2
	.thumb
	.thumb_func
	.type task_bos_dsd_circle_2, %function
task_bos_dsd_circle_2: @ 080C4948
	push {r4, r5, lr}
	add sp, #-0x014
	adds r4, r0, #0x0
	mov r5, sp
	adds r5, #0x12
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x0C]
	ldr r0, [r4, #0x10]
	str r0, [sp, #0x000]
	add r0, sp, #0x010
	adds r1, r5, #0x0
	bl func_0801909C
	add r0, sp, #0x010
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r2, #0x00
	ldsh r1, [r5, r2]
	ldr r2, [r4, #0x04]
	ldr r4, [r4, #0x00]
	movs r5, #0xD8
	lsls r5, r5, #0x02
	adds r3, r4, r5
	ldr r3, [r3, #0x00]
	adds r5, #0x04
	adds r4, r4, r5
	ldr r4, [r4, #0x00]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0xC0
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	ldr r4, _080C499C @ =0x0000FFFF
	str r4, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x014
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C499C: .4byte 0x0000FFFF
.syntax divided
