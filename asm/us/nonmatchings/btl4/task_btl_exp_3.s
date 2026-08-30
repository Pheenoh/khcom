.syntax unified
	.align 2, 0
	.global task_btl_exp_3
	.thumb
	.thumb_func
	.type task_btl_exp_3, %function
task_btl_exp_3: @ 0805D180
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	adds r6, r5, #0x0
	adds r6, #0x08
	movs r4, #0x05
_0805D18A:
	ldm r6!, {r0}
	bl func_080028C0
	subs r4, #0x01
	cmp r4, #0x00
	bge _0805D18A
	ldr r0, [r5, #0x04]
	bl func_080028C0
	ldr r0, [r5, #0x00]
	bl func_08002C10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
