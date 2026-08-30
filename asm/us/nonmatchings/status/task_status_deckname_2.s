.syntax unified
	.align 2, 0
	.global task_status_deckname_2
	.thumb
	.thumb_func
	.type task_status_deckname_2, %function
task_status_deckname_2: @ 080D7E08
	push {lr}
	add sp, #-0x008
	adds r2, r0, #0x0
	ldr r0, [r2, #0x58]
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080D7E2C
	ldr r3, [r2, #0x50]
	movs r0, #0x04
	str r0, [sp, #0x000]
	adds r0, r2, #0x0
	adds r0, #0x54
	ldrb r0, [r0, #0x00]
	str r0, [sp, #0x004]
	movs r0, #0x90
	movs r1, #0x8E
	bl func_080664D8
_080D7E2C:
	add sp, #0x008
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
