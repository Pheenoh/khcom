.syntax unified
	.align 2, 0
	.global task_bos_pc_acd_1
	.thumb
	.thumb_func
	.type task_bos_pc_acd_1, %function
task_bos_pc_acd_1: @ 0810BFA0
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r0, [r5, #0x08]
	ldrh r0, [r0, #0x06]
	adds r0, #0x11
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080062F4
	ldr r0, [r5, #0x08]
	ldrh r0, [r0, #0x06]
	adds r0, #0x12
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080062F4
	adds r6, r5, #0x0
	adds r6, #0x20
	adds r0, r6, #0x0
	bl AnimUpdate
	ldr r0, _0810C038 @ =0x02039B84
	ldr r1, [r0, #0x00]
	ldr r0, [r1, #0x7C]
	ldr r0, [r0, #0x0C]
	cmp r0, #0x00
	blt _0810C02E
	ldr r3, [r1, #0x68]
	ldr r4, [r1, #0x6C]
	movs r0, #0x80
	lsls r0, r0, #0x16
	adds r1, r3, #0x0
	ands r1, r0
	movs r2, #0x00
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	beq _0810C000
	movs r0, #0x80
	lsls r0, r0, #0x0E
	adds r1, r3, #0x0
	ands r1, r0
	adds r0, r2, #0x0
	orrs r0, r1
	cmp r0, #0x00
	bne _0810C02E
_0810C000:
	ldr r0, [r5, #0x0C]
	cmp r0, #0x00
	blt _0810C014
	adds r0, r6, #0x0
	bl AnimIsFinished
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	bne _0810C02E
_0810C014:
	movs r4, #0x00
	ldrb r0, [r5, #0x18]
	cmp r0, #0x01
	bne _0810C01E
	movs r4, #0x01
_0810C01E:
	adds r0, r6, #0x0
	bl func_08005B64
	adds r1, r4, #0x0
	adds r0, r6, #0x0
	movs r2, #0x00
	bl AnimStart
_0810C02E:
	movs r0, #0x01
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_0810C038: .4byte 0x02039B84
.syntax divided
