.syntax unified
	.align 2, 0
	.global task_poo_tigerstump_1
	.thumb
	.thumb_func
	.type task_poo_tigerstump_1, %function
task_poo_tigerstump_1: @ 080CD5B8
	push {lr}
	adds r1, r0, #0x0
	ldr r0, [r1, #0x04]
	cmp r0, #0x00
	beq _080CD5D8
	adds r0, r1, #0x0
	adds r0, #0x34
	movs r1, #0x09
	bl func_08012660
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080CD5D8
	ldr r1, _080CD5E0 @ =0x0203C3F0
	movs r0, #0x05
	str r0, [r1, #0x00]
_080CD5D8:
	movs r0, #0x01
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080CD5E0: .4byte 0x0203C3F0
.syntax divided
