.syntax unified
	.align 2, 0
	.global task_poo_shadowdodai_1
	.thumb
	.thumb_func
	.type task_poo_shadowdodai_1, %function
task_poo_shadowdodai_1: @ 080CBFCC
	ldr r2, [r0, #0x14]
	ldr r1, [r2, #0x00]
	str r1, [r0, #0x00]
	ldr r1, [r2, #0x04]
	str r1, [r0, #0x04]
	movs r0, #0x01
	bx lr
	.byte 0x00, 0x00
.syntax divided
