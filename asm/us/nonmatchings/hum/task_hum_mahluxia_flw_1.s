.syntax unified
	.align 2, 0
	.global task_hum_mahluxia_flw_1
	.thumb
	.thumb_func
	.type task_hum_mahluxia_flw_1, %function
task_hum_mahluxia_flw_1: @ 08057B8C
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, [r4, #0x00]
	cmp r0, #0x00
	beq _08057B9C
	cmp r0, #0x01
	beq _08057BBE
	b _08057C34
_08057B9C:
	ldr r0, [r4, #0x30]
	ldr r1, [r4, #0x2C]
	adds r0, r0, r1
	str r0, [r4, #0x30]
	ldr r0, [r4, #0x38]
	ldr r1, [r4, #0x28]
	adds r0, r0, r1
	str r0, [r4, #0x38]
	adds r1, #0x11
	str r1, [r4, #0x28]
	movs r0, #0xE6
	lsls r0, r0, #0x01
	cmp r1, r0
	ble _08057C34
	movs r0, #0x01
	str r0, [r4, #0x00]
	b _08057C34
_08057BBE:
	ldr r0, [r4, #0x30]
	ldr r1, [r4, #0x2C]
	adds r0, r0, r1
	str r0, [r4, #0x30]
	ldr r0, [r4, #0x38]
	ldr r1, [r4, #0x28]
	adds r0, r0, r1
	str r0, [r4, #0x38]
	subs r1, #0x0C
	str r1, [r4, #0x28]
	cmp r1, #0x00
	bge _08057C26
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0xB5
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0xCC
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x2C]
	cmp r0, #0x00
	ble _08057C10
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08057C0C @ =0x00000101
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x80
	negs r0, r0
	b _08057C24
	.byte 0x00, 0x00
_08057C0C: .4byte 0x00000101
_08057C10:
	bl func_080065A4
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, _08057C30 @ =0x00000101
	bl func_0811D7CC
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	adds r0, #0x80
_08057C24:
	str r0, [r4, #0x2C]
_08057C26:
	ldr r0, [r4, #0x38]
	cmp r0, #0x00
	blt _08057C34
	movs r0, #0x00
	b _08057C3E
_08057C30: .4byte 0x00000101
_08057C34:
	adds r0, r4, #0x0
	adds r0, #0x0C
	bl func_08005A64
	movs r0, #0x01
_08057C3E:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
