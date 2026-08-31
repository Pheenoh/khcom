.syntax unified
	.align 2, 0
	.global task_wlogo_poo_obj_2
	.thumb
	.thumb_func
	.type task_wlogo_poo_obj_2, %function
task_wlogo_poo_obj_2: @ 080B6DAC
	push {r4, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	adds r0, #0x42
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080B6DDA
	ldr r0, [r4, #0x24]
	lsls r0, r0, #0x08
	asrs r0, r0, #0x10
	ldr r1, [r4, #0x28]
	lsls r1, r1, #0x08
	asrs r1, r1, #0x10
	ldr r2, [r4, #0x08]
	ldr r3, [r4, #0x00]
	ldr r4, [r4, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	bl DrawSprite
_080B6DDA:
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
