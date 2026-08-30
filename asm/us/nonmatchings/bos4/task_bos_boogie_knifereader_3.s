.syntax unified
	.align 2, 0
	.global task_bos_boogie_knifereader_3
	.thumb
	.thumb_func
	.type task_bos_boogie_knifereader_3, %function
task_bos_boogie_knifereader_3: @ 080DB690
	push {r4, lr}
	adds r4, r0, #0x0
	adds r0, #0x1C
	bl func_0801B7D8
	adds r4, #0x08
	adds r0, r4, #0x0
	bl func_08000F0C
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
