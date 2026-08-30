.syntax unified
	.align 2, 0
	.global task_bos_md_fire_1
	.thumb
	.thumb_func
	.type task_bos_md_fire_1, %function
task_bos_md_fire_1: @ 080FD2C8
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl _080FCC14
	adds r0, r4, #0x0
	bl _080FCCB4
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	ldrh r1, [r4, #0x06]
	movs r2, #0x06
	ldsh r0, [r4, r2]
	cmp r0, #0x00
	ble _080FD2E8
	subs r0, r1, #0x1
	strh r0, [r4, #0x06]
_080FD2E8:
	movs r3, #0xA4
	lsls r3, r3, #0x01
	adds r0, r4, r3
	ldr r1, [r0, #0x00]
	str r1, [r4, #0x3C]
	movs r2, #0xA6
	lsls r2, r2, #0x01
	adds r0, r4, r2
	ldr r2, [r0, #0x00]
	str r2, [r4, #0x40]
	adds r3, #0x08
	adds r0, r4, r3
	ldr r3, [r0, #0x00]
	str r3, [r4, #0x44]
	adds r0, r4, #0x0
	adds r0, #0x78
	bl func_08012324
	adds r0, r5, #0x0
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
