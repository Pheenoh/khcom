.syntax unified
	.align 2, 0
	.global task_hum_axcel_2
	.thumb
	.thumb_func
	.type task_hum_axcel_2, %function
task_hum_axcel_2: @ 08054198
	push {r4, lr}
	adds r4, r0, #0x0
	bl func_0800EFE8
	movs r0, #0xC4
	lsls r0, r0, #0x01
	adds r1, r4, r0
	adds r0, r4, #0x0
	bl func_08054100
	movs r0, #0xE2
	lsls r0, r0, #0x01
	adds r1, r4, r0
	adds r0, r4, #0x0
	bl func_08054100
	movs r0, #0x88
	lsls r0, r0, #0x02
	adds r4, r4, r0
	adds r0, r4, #0x0
	bl TaskPoolDraw
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
