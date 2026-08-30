.syntax unified
	.align 2, 0
	.global task_ms_shop_hosi_1
	.thumb
	.thumb_func
	.type task_ms_shop_hosi_1, %function
task_ms_shop_hosi_1: @ 08109590
	adds r2, r0, #0x0
	movs r3, #0x01
	ldr r0, [r2, #0x00]
	ldr r1, [r2, #0x08]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	ldr r1, [r2, #0x0C]
	adds r1, #0x0A
	str r1, [r2, #0x0C]
	ldr r0, [r2, #0x04]
	adds r0, r0, r1
	str r0, [r2, #0x04]
	ldrh r0, [r2, #0x12]
	subs r0, #0x01
	strh r0, [r2, #0x12]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bgt _081095C8
	ldrh r0, [r2, #0x14]
	strh r0, [r2, #0x12]
	ldrh r0, [r2, #0x10]
	adds r0, #0x01
	strh r0, [r2, #0x10]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x05
	ble _081095C8
	movs r3, #0x00
_081095C8:
	adds r0, r3, #0x0
	bx lr
.syntax divided
