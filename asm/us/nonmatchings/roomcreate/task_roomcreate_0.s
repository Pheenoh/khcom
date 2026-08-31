.syntax unified
	.align 2, 0
	.global task_roomcreate_0
	.thumb
	.thumb_func
	.type task_roomcreate_0, %function
task_roomcreate_0: @ 0803F254
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	bl func_08093C04
	ldr r4, _0803F300 @ =0x02039BA0
	ldr r2, [r4, #0x00]
	ldr r0, [r2, #0x70]
	movs r1, #0x80
	lsls r1, r1, #0x0B
	orrs r0, r1
	movs r1, #0x02
	orrs r0, r1
	str r0, [r2, #0x70]
	adds r1, r6, #0x0
	adds r1, #0x29
	movs r0, #0x00
	strb r0, [r1, #0x00]
	subs r1, #0x01
	strb r0, [r1, #0x00]
	strh r0, [r6, #0x26]
	str r0, [r6, #0x40]
	movs r1, #0x02
	bl SetBgPriority
	movs r0, #0x01
	movs r1, #0x02
	bl SetBgPriority
	adds r0, r6, #0x0
	adds r0, #0x2C
	movs r1, #0x03
	bl TaskPoolInit
	ldr r3, [r4, #0x00]
	ldr r0, [r3, #0x18]
	str r0, [r6, #0x00]
	ldr r0, [r3, #0x1C]
	str r0, [r6, #0x04]
	ldr r0, [r3, #0x20]
	str r0, [r6, #0x08]
	ldr r1, [r3, #0x68]
	ldr r0, [r1, #0x00]
	str r0, [r6, #0x0C]
	ldr r0, [r1, #0x04]
	str r0, [r6, #0x10]
	ldr r0, [r1, #0x08]
	str r0, [r6, #0x14]
	ldrb r0, [r1, #0x14]
	adds r2, r6, #0x0
	adds r2, #0x24
	strb r0, [r2, #0x00]
	ldr r5, _0803F304 @ =0x08121400
	ldrb r0, [r2, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r5
	movs r1, #0x00
	ldsh r0, [r0, r1]
	movs r4, #0x32
	adds r1, r0, #0x0
	muls r1, r4
	ldr r0, [r6, #0x0C]
	adds r0, r0, r1
	str r0, [r6, #0x18]
	ldrb r0, [r2, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r5
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	adds r1, r0, #0x0
	muls r1, r4
	ldr r0, [r6, #0x10]
	adds r0, r0, r1
	str r0, [r6, #0x1C]
	ldr r0, [r6, #0x14]
	str r0, [r6, #0x20]
	adds r3, #0x2C
	ldrb r1, [r3, #0x00]
	adds r0, r6, #0x0
	adds r0, #0x25
	strb r1, [r0, #0x00]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0803F300: .4byte 0x02039BA0
_0803F304: .4byte 0x08121400
.syntax divided
