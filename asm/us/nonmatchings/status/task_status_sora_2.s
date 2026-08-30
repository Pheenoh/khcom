.syntax unified
	.align 2, 0
	.global task_status_sora_2
	.thumb
	.thumb_func
	.type task_status_sora_2, %function
task_status_sora_2: @ 080D7D6C
	push {r4, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldr r0, _080D7D84 @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D7D88
	movs r0, #0xA0
	movs r1, #0x41
	b _080D7D8C
_080D7D84: .4byte 0x02039BB0
_080D7D88:
	movs r0, #0x8C
	movs r1, #0x38
_080D7D8C:
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r4, [r4, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x04
	str r4, [sp, #0x008]
	movs r4, #0x0C
	str r4, [sp, #0x00C]
	bl func_080023E0
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
