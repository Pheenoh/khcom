.syntax unified
	.align 2, 0
	.global task_bos_dsd_energy1_0
	.thumb
	.thumb_func
	.type task_bos_dsd_energy1_0, %function
task_bos_dsd_energy1_0: @ 080C49A4
	push {r4, r5, lr}
	mov r12, r0
	str r1, [r0, #0x00]
	movs r0, #0xBC
	lsls r0, r0, #0x08
	mov r1, r12
	str r0, [r1, #0x04]
	movs r0, #0xB4
	lsls r0, r0, #0x09
	str r0, [r1, #0x08]
	ldr r0, _080C4A2C @ =0xFFFFDC00
	str r0, [r1, #0x0C]
	movs r1, #0x00
	mov r3, r12
	str r1, [r3, #0x10]
	str r1, [r3, #0x14]
	str r1, [r3, #0x18]
	mov r2, r12
	adds r2, #0x28
	movs r0, #0xF4
	strb r0, [r2, #0x00]
	adds r3, #0x29
	strb r0, [r3, #0x00]
	movs r0, #0x80
	lsls r0, r0, #0x04
	mov r4, r12
	str r0, [r4, #0x2C]
	movs r0, #0x19
	str r0, [r4, #0x30]
	movs r3, #0x00
	strh r1, [r4, #0x34]
	strh r1, [r4, #0x36]
	strh r1, [r4, #0x38]
	movs r0, #0x0F
	strh r0, [r4, #0x3C]
	movs r0, #0x3C
	strh r0, [r4, #0x3A]
	mov r0, r12
	adds r0, #0x48
	strb r3, [r0, #0x00]
	ldr r4, _080C4A30 @ =0x08121400
	ldrb r0, [r2, #0x00]
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r5, #0x00
	ldsh r0, [r0, r5]
	mov r5, r12
	ldr r3, [r5, #0x2C]
	muls r0, r3
	asrs r0, r0, #0x08
	str r0, [r5, #0x1C]
	str r1, [r5, #0x20]
	ldrb r0, [r2, #0x00]
	adds r0, #0x40
	lsls r0, r0, #0x01
	adds r0, r0, r4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	negs r0, r0
	muls r0, r3
	asrs r0, r0, #0x08
	str r0, [r5, #0x24]
	ldr r0, _080C4A34 @ =0x08B22CBC
	str r0, [r5, #0x44]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C4A2C: .4byte 0xFFFFDC00
_080C4A30: .4byte 0x08121400
_080C4A34: .4byte 0x08B22CBC
.syntax divided
