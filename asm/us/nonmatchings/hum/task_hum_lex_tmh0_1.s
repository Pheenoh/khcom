.syntax unified
	.align 2, 0
	.global task_hum_lex_tmh0_1
	.thumb
	.thumb_func
	.type task_hum_lex_tmh0_1, %function
task_hum_lex_tmh0_1: @ 08057314
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _08057358 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x40
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0805735C
	adds r0, r4, #0x0
	adds r0, #0x30
	movs r1, #0x80
	lsls r1, r1, #0x01
	ldrh r2, [r4, #0x34]
	subs r3, r2, #0x1
	strh r3, [r4, #0x34]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl func_080058FC
	movs r1, #0x34
	ldsh r0, [r4, r1]
	cmp r0, #0x00
	ble _0805735C
	adds r0, r4, #0x0
	adds r0, #0x08
	bl AnimUpdate
	movs r0, #0x01
	b _0805735E
	.byte 0x00, 0x00
_08057358: .4byte 0x02039B84
_0805735C:
	movs r0, #0x00
_0805735E:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
