.syntax unified
	.align 2, 0
	.global task_hum_axcel_3
	.thumb
	.thumb_func
	.type task_hum_axcel_3, %function
task_hum_axcel_3: @ 080541CC
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _08054204 @ =0x0000028E
	bl func_0811FF3C
	movs r1, #0x88
	lsls r1, r1, #0x02
	adds r0, r4, r1
	bl func_08000F0C
	movs r1, #0x86
	lsls r1, r1, #0x02
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	movs r1, #0x87
	lsls r1, r1, #0x02
	adds r0, r4, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	adds r0, r4, #0x0
	bl func_0800E380
	pop {r4}
	pop {r0}
	bx r0
_08054204: .4byte 0x0000028E
.syntax divided
