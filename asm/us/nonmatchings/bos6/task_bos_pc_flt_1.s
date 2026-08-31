.syntax unified
	.align 2, 0
	.global task_bos_pc_flt_1
	.thumb
	.thumb_func
	.type task_bos_pc_flt_1, %function
task_bos_pc_flt_1: @ 0810BDCC
	push {r4, r5, lr}
	adds r5, r0, #0x0
	bl _0810BAE4
	adds r4, r5, #0x0
	adds r4, #0x9C
	adds r0, r4, #0x0
	bl AnimUpdate
	adds r0, r4, #0x0
	bl func_08005B38
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x00
	bne _0810BDF8
	ldr r0, [r5, #0x30]
	movs r1, #0x80
	lsls r1, r1, #0x05
	adds r0, r0, r1
	str r0, [r5, #0x30]
	b _0810BE14
_0810BDF8:
	ldr r0, _0810BE2C @ =0x09A4CEDC
	lsls r2, r2, #0x03
	adds r2, r2, r0
	movs r0, #0x02
	ldsh r1, [r2, r0]
	lsls r1, r1, #0x08
	ldr r0, [r5, #0x30]
	adds r0, r0, r1
	str r0, [r5, #0x30]
	adds r0, r5, #0x0
	adds r0, #0x40
	ldrh r1, [r2, #0x04]
	bl func_08012650
_0810BE14:
	adds r0, r5, #0x0
	bl func_0810BCD4
	ldr r0, [r5, #0x3C]
	ldrb r1, [r0, #0x00]
	movs r0, #0x01
	ands r0, r1
	strb r0, [r5, #0x07]
	movs r0, #0x01
	pop {r4, r5}
	pop {r1}
	bx r1
_0810BE2C: .4byte 0x09A4CEDC
.syntax divided
