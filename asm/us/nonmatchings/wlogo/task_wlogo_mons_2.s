.syntax unified
	.align 2, 0
	.global task_wlogo_mons_2
	.thumb
	.thumb_func
	.type task_wlogo_mons_2, %function
task_wlogo_mons_2: @ 080B4A98
	push {r4, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	adds r0, #0x2D
	ldrb r0, [r0, #0x00]
	cmp r0, #0x01
	bne _080B4AC2
	movs r1, #0x08
	ldsh r0, [r4, r1]
	movs r2, #0x0A
	ldsh r1, [r4, r2]
	ldr r2, [r4, #0x0C]
	ldr r3, [r4, #0x00]
	ldr r4, [r4, #0x04]
	str r4, [sp, #0x000]
	movs r4, #0x00
	str r4, [sp, #0x004]
	str r4, [sp, #0x008]
	str r4, [sp, #0x00C]
	bl DrawSprite
_080B4AC2:
	add sp, #0x010
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
