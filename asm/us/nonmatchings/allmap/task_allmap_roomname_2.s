.syntax unified
	.align 2, 0
	.global task_allmap_roomname_2
	.thumb
	.thumb_func
	.type task_allmap_roomname_2, %function
task_allmap_roomname_2: @ 080D3E88
	push {lr}
	add sp, #-0x008
	adds r2, r0, #0x0
	adds r0, #0xCE
	ldrh r0, [r0, #0x00]
	adds r0, #0x75
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	adds r1, r2, #0x0
	adds r1, #0xC8
	ldr r3, [r1, #0x00]
	movs r1, #0x32
	str r1, [sp, #0x000]
	adds r1, r2, #0x0
	adds r1, #0xCC
	ldrb r1, [r1, #0x00]
	str r1, [sp, #0x004]
	movs r1, #0x03
	bl func_080664D8
	add sp, #0x008
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
