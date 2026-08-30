.syntax unified
	.align 2, 0
	.global mode_dummy_1
	.thumb
	.thumb_func
	.type mode_dummy_1, %function
mode_dummy_1: @ 0800C15C
	push {lr}
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _0800C182
	bl func_08001390
	movs r1, #0x09
	ands r1, r0
	cmp r1, #0x00
	beq _0800C182
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006184
	ldr r0, _0800C1A4 @ =0x0800C065
	bl func_08001248
_0800C182:
	movs r0, #0x00
	bl func_080605A4
	bl func_08060598
	ldr r0, _0800C1A8 @ =0x03007480
	ldr r1, [r0, #0x00]
	lsls r1, r1, #0x0E
	lsrs r1, r1, #0x10
	movs r0, #0x01
	movs r2, #0x00
	bl func_080054EC
	bl func_0801CC80
	pop {r0}
	bx r0
_0800C1A4: .4byte 0x0800C065
_0800C1A8: .4byte 0x03007480
.syntax divided
