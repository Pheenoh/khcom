.syntax unified
	.align 2, 0
	.global task_status_cursor_1
	.thumb
	.thumb_func
	.type task_status_cursor_1, %function
task_status_cursor_1: @ 080D7F48
	push {r4, r5, r6, lr}
	adds r4, r0, #0x0
	adds r2, r4, #0x0
	adds r2, #0x4C
	ldr r0, [r4, #0x48]
	movs r3, #0x00
	ldsh r1, [r2, r3]
	ldrh r3, [r0, #0x00]
	movs r5, #0x00
	ldsh r0, [r0, r5]
	cmp r1, r0
	beq _080D7FA2
	strh r3, [r2, #0x00]
	adds r1, r4, #0x0
	adds r1, #0x4E
	movs r0, #0x04
	strh r0, [r1, #0x00]
	movs r1, #0x00
	ldsh r0, [r2, r1]
	cmp r0, #0x00
	bge _080D7F88
	ldr r1, _080D7F84 @ =0x096FDD8C
	mvns r0, r0
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x5C]
	movs r0, #0x80
	lsls r0, r0, #0x05
	b _080D7FA0
_080D7F84: .4byte 0x096FDD8C
_080D7F88:
	movs r0, #0xC0
	lsls r0, r0, #0x05
	str r0, [r4, #0x5C]
	ldr r0, [r4, #0x48]
	movs r5, #0x00
	ldsh r1, [r0, r5]
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x0A
	movs r1, #0x90
	lsls r1, r1, #0x06
	adds r0, r0, r1
_080D7FA0:
	str r0, [r4, #0x54]
_080D7FA2:
	adds r0, r4, #0x0
	adds r0, #0x50
	ldr r1, [r4, #0x54]
	bl func_0805F1C0
	adds r0, r4, #0x0
	adds r0, #0x58
	ldr r1, [r4, #0x5C]
	bl func_0805F1C0
	adds r6, r4, #0x0
	adds r6, #0x10
	adds r4, #0x18
	movs r5, #0x01
_080D7FBE:
	adds r0, r4, #0x0
	bl AnimUpdate
	stm r6!, {r0}
	adds r4, #0x18
	subs r5, #0x01
	cmp r5, #0x00
	bge _080D7FBE
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
