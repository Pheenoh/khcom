.syntax unified
	.align 2, 0
	.global mode_test_1
	.thumb
	.thumb_func
	.type mode_test_1, %function
mode_test_1: @ 0805F120
	push {lr}
	add sp, #-0x010
	bl func_0800139C
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _0805F13C
	ldr r1, _0805F138 @ =0x02034A10
	ldr r0, [r1, #0x00]
	subs r0, #0x01
	b _0805F14E
_0805F138: .4byte 0x02034A10
_0805F13C:
	bl func_0800139C
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _0805F150
	ldr r1, _0805F190 @ =0x02034A10
	ldr r0, [r1, #0x00]
	adds r0, #0x01
_0805F14E:
	str r0, [r1, #0x00]
_0805F150:
	ldr r2, _0805F190 @ =0x02034A10
	ldr r0, [r2, #0x00]
	cmp r0, #0x00
	bge _0805F15C
	movs r0, #0x00
	str r0, [r2, #0x00]
_0805F15C:
	ldr r0, [r2, #0x00]
	cmp r0, #0x0D
	ble _0805F166
	movs r0, #0x0D
	str r0, [r2, #0x00]
_0805F166:
	ldr r1, _0805F194 @ =0x09EE14D4
	ldr r0, [r2, #0x00]
	lsls r0, r0, #0x02
	adds r0, r0, r1
	ldr r2, [r0, #0x00]
	ldr r0, _0805F198 @ =0x02034A08
	ldr r3, [r0, #0x00]
	ldr r0, _0805F19C @ =0x02034A0C
	ldr r0, [r0, #0x00]
	str r0, [sp, #0x000]
	movs r0, #0x00
	str r0, [sp, #0x004]
	str r0, [sp, #0x008]
	str r0, [sp, #0x00C]
	movs r0, #0x78
	movs r1, #0x50
	bl func_080023E0
	add sp, #0x010
	pop {r0}
	bx r0
_0805F190: .4byte 0x02034A10
_0805F194: .4byte 0x09EE14D4
_0805F198: .4byte 0x02034A08
_0805F19C: .4byte 0x02034A0C
.syntax divided
