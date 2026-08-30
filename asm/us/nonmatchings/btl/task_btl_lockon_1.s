.syntax unified
	.align 2, 0
	.global task_btl_lockon_1
	.thumb
	.thumb_func
	.type task_btl_lockon_1, %function
task_btl_lockon_1: @ 0801D530
	push {r4, r5, lr}
	adds r4, r0, #0x0
	ldr r5, _0801D590 @ =0x02039B84
	ldr r0, [r5, #0x00]
	ldr r1, [r0, #0x6C]
	ldr r0, [r0, #0x68]
	movs r2, #0x80
	lsls r2, r2, #0x16
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	bne _0801D54E
	bl func_0801D288
_0801D54E:
	ldr r0, [r5, #0x00]
	ldr r0, [r0, #0x78]
	cmp r0, #0x00
	beq _0801D57A
	adds r0, r4, #0x0
	adds r0, #0x08
	bl func_08005A64
	str r0, [r4, #0x20]
	ldr r3, [r5, #0x00]
	ldr r0, [r3, #0x78]
	ldr r1, [r0, #0x38]
	ldr r0, [r0, #0x34]
	movs r2, #0x80
	lsls r2, r2, #0x11
	ands r0, r2
	movs r1, #0x00
	orrs r0, r1
	cmp r0, #0x00
	beq _0801D57A
	movs r0, #0x00
	str r0, [r3, #0x78]
_0801D57A:
	ldrh r1, [r4, #0x24]
	movs r2, #0x24
	ldsh r0, [r4, r2]
	cmp r0, #0x00
	beq _0801D588
	subs r0, r1, #0x1
	strh r0, [r4, #0x24]
_0801D588:
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
_0801D590: .4byte 0x02039B84
.syntax divided
