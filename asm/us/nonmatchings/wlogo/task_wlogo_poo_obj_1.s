.syntax unified
	.align 2, 0
	.global task_wlogo_poo_obj_1
	.thumb
	.thumb_func
	.type task_wlogo_poo_obj_1, %function
task_wlogo_poo_obj_1: @ 080B6CC0
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x24]
	ldr r2, [r4, #0x2C]
	adds r0, r0, r2
	str r0, [r4, #0x24]
	ldr r0, [r4, #0x28]
	ldr r1, [r4, #0x30]
	adds r0, r0, r1
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x34]
	adds r2, r2, r0
	str r2, [r4, #0x2C]
	ldr r0, [r4, #0x38]
	adds r1, r1, r0
	str r1, [r4, #0x30]
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl AnimUpdate
	str r0, [r4, #0x08]
	movs r0, #0x40
	adds r0, r0, r4
	mov r12, r0
	ldrb r5, [r0, #0x00]
	cmp r5, #0x00
	beq _080B6D04
	ldrh r0, [r4, #0x3E]
	cmp r0, #0x96
	bls _080B6D96
	movs r0, #0x00
	b _080B6D9E
_080B6D04:
	ldrh r1, [r4, #0x3E]
	mov r8, r1
	ldr r7, _080B6DA8 @ =0x09619A04
	ldrh r1, [r4, #0x3C]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r1, r0, #0x02
	adds r3, r4, #0x0
	adds r3, #0x41
	ldrb r0, [r3, #0x00]
	movs r6, #0x64
	muls r0, r6
	adds r0, r1, r0
	adds r0, r0, r7
	movs r2, #0x00
	ldsh r0, [r0, r2]
	cmp r8, r0
	bne _080B6D96
	strh r5, [r4, #0x3E]
	ldrb r0, [r3, #0x00]
	muls r0, r6
	adds r0, r1, r0
	adds r1, r7, #0x4
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x2C]
	ldrh r1, [r4, #0x3C]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	ldrb r1, [r3, #0x00]
	muls r1, r6
	adds r0, r0, r1
	adds r1, r7, #0x0
	adds r1, #0x08
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x30]
	ldrh r1, [r4, #0x3C]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	ldrb r1, [r3, #0x00]
	muls r1, r6
	adds r0, r0, r1
	adds r1, r7, #0x0
	adds r1, #0x0C
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x34]
	ldrh r1, [r4, #0x3C]
	lsls r0, r1, #0x02
	adds r0, r0, r1
	lsls r0, r0, #0x02
	ldrb r1, [r3, #0x00]
	muls r1, r6
	adds r0, r0, r1
	adds r1, r7, #0x0
	adds r1, #0x10
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	str r0, [r4, #0x38]
	ldrh r0, [r4, #0x3C]
	adds r0, #0x01
	strh r0, [r4, #0x3C]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x04
	bls _080B6D96
	mov r1, r12
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
_080B6D96:
	ldrh r0, [r4, #0x3E]
	adds r0, #0x01
	strh r0, [r4, #0x3E]
	movs r0, #0x01
_080B6D9E:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
_080B6DA8: .4byte 0x09619A04
.syntax divided
