.syntax unified
	.align 2, 0
	.global mode_copyright2_1
	.thumb
	.thumb_func
	.type mode_copyright2_1, %function
mode_copyright2_1: @ 080D724C
	push {lr}
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D7280
	ldr r1, _080D7274 @ =0x02034EDC
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080D7278
	subs r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080D7280
	movs r0, #0x00
	movs r1, #0x43
	bl func_08006184
	b _080D7280
_080D7274: .4byte 0x02034EDC
_080D7278:
	ldr r0, _080D7284 @ =0x09EF4E50
	movs r1, #0x00
	bl func_080010CC
_080D7280:
	pop {r0}
	bx r0
_080D7284: .4byte 0x09EF4E50
.syntax divided
