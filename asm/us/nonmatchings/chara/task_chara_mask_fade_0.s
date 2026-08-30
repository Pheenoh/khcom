.syntax unified
	.align 2, 0
	.global task_chara_mask_fade_0
	.thumb
	.thumb_func
	.type task_chara_mask_fade_0, %function
task_chara_mask_fade_0: @ 080C51C4
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r0, [r1, #0x00]
	str r0, [r5, #0x00]
	ldrh r0, [r1, #0x04]
	movs r2, #0x00
	strh r0, [r5, #0x04]
	strh r2, [r5, #0x0A]
	movs r0, #0x01
	strh r0, [r5, #0x08]
	ldrh r0, [r1, #0x06]
	strh r0, [r5, #0x06]
	movs r6, #0x00
	b _080C51F8
_080C51E0:
	bl func_080065A4
	adds r4, r5, #0x0
	adds r4, #0x4C
	adds r4, r4, r6
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x05
	bl func_0811D7CC
	strb r0, [r4, #0x00]
	adds r6, #0x01
_080C51F8:
	ldrh r0, [r5, #0x04]
	cmp r6, r0
	blt _080C51E0
	pop {r4, r5, r6}
	pop {r0}
	bx r0
.syntax divided
