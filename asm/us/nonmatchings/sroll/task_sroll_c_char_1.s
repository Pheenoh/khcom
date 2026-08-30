.syntax unified
	.align 2, 0
	.global task_sroll_c_char_1
	.thumb
	.thumb_func
	.type task_sroll_c_char_1, %function
task_sroll_c_char_1: @ 08115224
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r4, #0x20
	movs r5, #0x04
_0811522C:
	adds r0, r4, #0x0
	bl func_08005A64
	adds r4, #0x18
	subs r5, #0x01
	cmp r5, #0x00
	bge _0811522C
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
