.syntax unified
	.align 2, 0
	.global task_btl_pop_cb_1
	.thumb
	.thumb_func
	.type task_btl_pop_cb_1, %function
task_btl_pop_cb_1: @ 0805CD4C
	adds r1, r0, #0x0
	ldr r0, [r1, #0x14]
	subs r0, #0xC0
	str r0, [r1, #0x14]
	ldrh r2, [r1, #0x18]
	movs r3, #0x18
	ldsh r0, [r1, r3]
	cmp r0, #0x31
	bgt _0805CD66
	adds r0, r2, #0x1
	strh r0, [r1, #0x18]
	movs r0, #0x01
	b _0805CD68
_0805CD66:
	movs r0, #0x00
_0805CD68:
	bx lr
	.byte 0x00, 0x00
.syntax divided
