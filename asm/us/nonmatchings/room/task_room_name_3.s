.syntax unified
	.align 2, 0
	.global task_room_name_3
	.thumb
	.thumb_func
	.type task_room_name_3, %function
task_room_name_3: @ 080F7DB0
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl func_080028C0
	adds r0, r4, #0x0
	adds r0, #0x3C
	movs r1, #0x24
	bl func_08065AE0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	ldr r0, [r4, #0x38]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
