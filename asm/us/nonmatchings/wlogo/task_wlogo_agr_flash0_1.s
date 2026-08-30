.syntax unified
	.align 2, 0
	.global task_wlogo_agr_flash0_1
	.thumb
	.thumb_func
	.type task_wlogo_agr_flash0_1, %function
task_wlogo_agr_flash0_1: @ 080B6558
	push {r4, r5, lr}
	adds r5, r0, #0x0
	adds r4, r5, #0x0
	adds r4, #0x0C
	adds r0, r4, #0x0
	bl func_08005B1C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080B6578
	adds r0, r4, #0x0
	bl func_08005A64
	str r0, [r5, #0x08]
	movs r0, #0x01
	b _080B657A
_080B6578:
	movs r0, #0x00
_080B657A:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
