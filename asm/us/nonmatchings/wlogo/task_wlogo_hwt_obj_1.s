.syntax unified
	.align 2, 0
	.global task_wlogo_hwt_obj_1
	.thumb
	.thumb_func
	.type task_wlogo_hwt_obj_1, %function
task_wlogo_hwt_obj_1: @ 080B4DD0
	push {r4, r5, lr}
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
	ldrh r2, [r4, #0x3E]
	adds r2, #0x01
	strh r2, [r4, #0x3E]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	ldr r5, _080B4E44 @ =0x09619530
	ldrh r0, [r4, #0x3C]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	movs r0, #0x4A
	adds r0, r0, r4
	mov r12, r0
	ldrb r3, [r0, #0x00]
	lsls r0, r3, #0x03
	adds r0, r0, r3
	lsls r0, r0, #0x04
	adds r1, r1, r0
	adds r1, r1, r5
	movs r3, #0x00
	ldsh r0, [r1, r3]
	cmp r2, r0
	blt _080B4EBC
	movs r0, #0x00
	strh r0, [r4, #0x3E]
	ldrh r3, [r4, #0x3C]
	lsls r1, r3, #0x01
	adds r1, r1, r3
	lsls r1, r1, #0x03
	mov r0, r12
	ldrb r2, [r0, #0x00]
	lsls r0, r2, #0x03
	adds r0, r0, r2
	lsls r0, r0, #0x04
	adds r1, r1, r0
	adds r1, r1, r5
	ldrb r0, [r1, #0x14]
	cmp r0, #0x01
	bne _080B4E48
	movs r0, #0x00
	b _080B4EC8
	.byte 0x00, 0x00
_080B4E44: .4byte 0x09619530
_080B4E48:
	adds r0, r3, #0x1
	strh r0, [r4, #0x3C]
	ldrh r0, [r4, #0x3C]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	mov r3, r12
	ldrb r2, [r3, #0x00]
	lsls r0, r2, #0x03
	adds r0, r0, r2
	lsls r0, r0, #0x04
	adds r1, r1, r0
	adds r0, r5, #0x4
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x2C]
	ldrh r0, [r4, #0x3C]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldrb r2, [r3, #0x00]
	lsls r0, r2, #0x03
	adds r0, r0, r2
	lsls r0, r0, #0x04
	adds r1, r1, r0
	adds r0, r5, #0x0
	adds r0, #0x08
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x30]
	ldrh r0, [r4, #0x3C]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldrb r2, [r3, #0x00]
	lsls r0, r2, #0x03
	adds r0, r0, r2
	lsls r0, r0, #0x04
	adds r1, r1, r0
	adds r0, r5, #0x0
	adds r0, #0x0C
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x34]
	ldrh r0, [r4, #0x3C]
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	ldrb r2, [r3, #0x00]
	lsls r0, r2, #0x03
	adds r0, r0, r2
	lsls r0, r0, #0x04
	adds r1, r1, r0
	adds r0, r5, #0x0
	adds r0, #0x10
	adds r1, r1, r0
	ldr r0, [r1, #0x00]
	str r0, [r4, #0x38]
_080B4EBC:
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08005A64
	str r0, [r4, #0x08]
	movs r0, #0x01
_080B4EC8:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
