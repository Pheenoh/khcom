.syntax unified
	.align 2, 0
	.global task_btl_raid_3
	.thumb
	.thumb_func
	.type task_btl_raid_3, %function
task_btl_raid_3: @ 08040A68
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	ldr r0, [r4, #0x60]
	bl func_080028C0
	ldr r0, [r4, #0x64]
	bl func_08002C10
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
