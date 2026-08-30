.syntax unified
	.align 2, 0
	.global task_pc_acddmg_0
	.thumb
	.thumb_func
	.type task_pc_acddmg_0, %function
task_pc_acddmg_0: @ 08049DCC
	str r1, [r0, #0x04]
	movs r2, #0x00
	movs r1, #0x00
	strh r1, [r0, #0x02]
	movs r1, #0x28
	strh r1, [r0, #0x00]
	strb r2, [r0, #0x08]
	bx lr
.syntax divided
