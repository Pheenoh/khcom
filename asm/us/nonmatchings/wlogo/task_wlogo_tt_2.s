.syntax unified
	.align 2, 0
	.global task_wlogo_tt_2
	.thumb
	.thumb_func
	.type task_wlogo_tt_2, %function
task_wlogo_tt_2: @ 080B7444
	push {r4, r5, lr}
	add sp, #-0x010
	adds r4, r0, #0x0
	movs r1, #0x82
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B7474
	ldr r2, [r4, #0x30]
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x1C]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x04
	str r0, [sp, #0x00C]
	movs r0, #0x48
	movs r1, #0x40
	bl func_080023E0
_080B7474:
	ldr r1, _080B75A4 @ =0x00000105
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B749C
	ldr r2, [r4, #0x34]
	ldr r3, [r4, #0x08]
	ldr r0, [r4, #0x1C]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x06
	str r0, [sp, #0x00C]
	movs r0, #0x60
	movs r1, #0x50
	bl func_080023E0
_080B749C:
	movs r5, #0x80
	lsls r5, r5, #0x01
	adds r0, r4, r5
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B74DA
	movs r1, #0x84
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldr r1, [r0, #0x00]
	movs r0, #0x00
	adds r2, r5, #0x0
	movs r3, #0x00
	bl func_08002CB4
	adds r1, r0, #0x0
	ldr r2, [r4, #0x20]
	ldr r3, [r4, #0x0C]
	ldr r0, [r4, #0x1C]
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r0, #0x00
	str r0, [sp, #0x008]
	movs r0, #0x18
	str r0, [sp, #0x00C]
	movs r0, #0x4E
	movs r1, #0x48
	bl func_080023E0
_080B74DA:
	movs r1, #0x81
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B7504
	ldr r2, [r4, #0x28]
	ldr r3, [r4, #0x14]
	ldr r0, [r4, #0x1C]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x14
	str r0, [sp, #0x00C]
	movs r0, #0x41
	movs r1, #0x41
	bl func_080023E0
_080B7504:
	ldr r1, _080B75A8 @ =0x00000101
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B753E
	adds r1, #0x0B
	adds r0, r4, r1
	ldr r1, [r0, #0x00]
	movs r0, #0x00
	adds r2, r5, #0x0
	movs r3, #0x00
	bl func_08002CB4
	adds r1, r0, #0x0
	ldr r2, [r4, #0x24]
	ldr r3, [r4, #0x10]
	ldr r0, [r4, #0x1C]
	str r0, [sp, #0x000]
	str r1, [sp, #0x004]
	movs r0, #0x00
	str r0, [sp, #0x008]
	movs r0, #0x1A
	str r0, [sp, #0x00C]
	movs r0, #0x6C
	movs r1, #0x5E
	bl func_080023E0
_080B753E:
	ldr r1, _080B75AC @ =0x00000103
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B7566
	ldr r2, [r4, #0x2C]
	ldr r3, [r4, #0x14]
	ldr r0, [r4, #0x1C]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x16
	str r0, [sp, #0x00C]
	movs r0, #0x60
	movs r1, #0x57
	bl func_080023E0
_080B7566:
	movs r1, #0x83
	lsls r1, r1, #0x01
	adds r0, r4, r1
	ldrb r0, [r0, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x01
	bne _080B7590
	ldr r2, [r4, #0x38]
	ldr r3, [r4, #0x18]
	ldr r0, [r4, #0x1C]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	movs r0, #0x20
	str r0, [sp, #0x00C]
	movs r0, #0x40
	movs r1, #0x40
	bl func_080023E0
_080B7590:
	movs r1, #0x8A
	lsls r1, r1, #0x01
	adds r0, r4, r1
	bl func_08000EE0
	add sp, #0x010
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B75A4: .4byte 0x00000105
_080B75A8: .4byte 0x00000101
_080B75AC: .4byte 0x00000103
.syntax divided
