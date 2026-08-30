.syntax unified
	.align 2, 0
	.global task_status_1
	.thumb
	.thumb_func
	.type task_status_1, %function
task_status_1: @ 080D7848
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_080D7B94
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D785C
	adds r0, r4, #0x0
	bl func_080D764C
_080D785C:
	ldr r1, _080D7874 @ =0x02034F02
	ldrh r0, [r4, #0x1C]
	ldrh r2, [r4, #0x1A]
	adds r0, r0, r2
	strh r0, [r1, #0x00]
	adds r0, r4, #0x0
	bl func_08000EA4
	movs r0, #0x01
	pop {r4}
	pop {r1}
	bx r1
_080D7874: .4byte 0x02034F02
.syntax divided
