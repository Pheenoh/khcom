.syntax unified
	.align 2, 0
	.global task_wlogo_dil_2
	.thumb
	.thumb_func
	.type task_wlogo_dil_2, %function
task_wlogo_dil_2: @ 080B5F48
	push {r4, r5, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	ldrb r0, [r4, #0x16]
	cmp r0, #0x01
	bne _080B5F74
	movs r1, #0x12
	ldsh r0, [r4, r1]
	movs r2, #0x14
	ldsh r1, [r4, r2]
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r4, [r4, #0x04]
	str r4, [sp, #0x000]
	movs r5, #0x00
	str r5, [sp, #0x004]
	movs r4, #0x80
	lsls r4, r4, #0x03
	str r4, [sp, #0x008]
	str r5, [sp, #0x00C]
	bl func_080023E0
_080B5F74:
	add sp, #0x010
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
