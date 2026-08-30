.syntax unified
	.align 2, 0
	.global task_wlogo_bks_2
	.thumb
	.thumb_func
	.type task_wlogo_bks_2, %function
task_wlogo_bks_2: @ 080B7C1C
	push {r4, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	adds r0, #0x30
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B7C46
	ldr r2, [r4, #0x14]
	ldr r3, [r4, #0x0C]
	ldr r0, [r4, #0x10]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	str r0, [sp, #0x00C]
	movs r0, #0x40
	movs r1, #0x40
	bl func_080023E0
_080B7C46:
	adds r0, r4, #0x0
	adds r0, #0x3C
	bl func_08000EE0
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
