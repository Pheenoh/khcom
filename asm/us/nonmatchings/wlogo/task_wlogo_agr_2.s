.syntax unified
	.align 2, 0
	.global task_wlogo_agr_2
	.thumb
	.thumb_func
	.type task_wlogo_agr_2, %function
task_wlogo_agr_2: @ 080B63B4
	push {r4, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldrb r0, [r4, #0x10]
	cmp r0, #0x01
	bne _080B63DE
	movs r1, #0x0C
	ldsh r0, [r4, r1]
	movs r2, #0x0E
	ldsh r1, [r4, r2]
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r4, [r4, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	movs r4, #0x03
	str r4, [sp, #0x00C]
	bl func_080023E0
_080B63DE:
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
