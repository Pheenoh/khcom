.syntax unified
	.align 2, 0
	.global task_wlogo_agr_3
	.thumb
	.thumb_func
	.type task_wlogo_agr_3, %function
task_wlogo_agr_3: @ 080B63E8
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x04]
	bl func_08002C10
	ldr r0, _080B6404 @ =0x02034C80
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
_080B6404: .4byte 0x02034C80
.syntax divided
