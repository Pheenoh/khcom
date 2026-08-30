.syntax unified
	.align 2, 0
	.global task_status_meswindow_1
	.thumb
	.thumb_func
	.type task_status_meswindow_1, %function
task_status_meswindow_1: @ 080D8958
	push {r4, r5, lr}
	add sp, #-0x004
	adds r4, r0, #0x0
	ldr r0, [r4, #0x1C]
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D89C6
	bl func_080D789C
	lsls r0, r0, #0x10
	cmp r0, #0x00
	blt _080D89C6
	bl func_080D789C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bl func_080D855C
	adds r1, r0, #0x0
	ldr r0, [r4, #0x18]
	cmp r0, r1
	beq _080D89C0
	str r1, [r4, #0x18]
	ldr r0, [r4, #0x14]
	adds r5, r4, #0x0
	adds r5, #0x20
	cmp r0, #0x00
	beq _080D899E
	bl func_080D8F04
	strb r0, [r5, #0x00]
	ldr r1, [r4, #0x14]
	adds r0, r4, #0x0
	bl func_08000DE8
_080D899E:
	ldr r0, [r4, #0x18]
	bl _080D85F8
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldrb r2, [r5, #0x00]
	movs r0, #0x62
	str r0, [sp, #0x000]
	adds r0, r4, #0x0
	movs r3, #0x58
	bl func_080D8EB4
	str r0, [r4, #0x14]
	ldr r0, [r4, #0x18]
	bl func_0800FD68
_080D89C0:
	adds r0, r4, #0x0
	bl func_08000EA4
_080D89C6:
	movs r0, #0x01
	add sp, #0x004
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
