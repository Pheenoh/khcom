.syntax unified
	.align 2, 0
	.global task_evt_obj_1
	.thumb
	.thumb_func
	.type task_evt_obj_1, %function
task_evt_obj_1: @ 0801CF0C
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	ldrh r1, [r0, #0x14]
	movs r0, #0x01
	ands r0, r1
	cmp r0, #0x00
	beq _0801CF22
	adds r0, r4, #0x0
	bl func_0801CE70
_0801CF22:
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08005A64
	adds r0, r4, #0x0
	adds r0, #0x24
	bl func_08000EA4
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
