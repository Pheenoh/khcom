.syntax unified
	.align 2, 0
	.global mode_copyright1_1
	.thumb
	.thumb_func
	.type mode_copyright1_1, %function
mode_copyright1_1: @ 080D7160
	push {lr}
	ldr r0, _080D7174 @ =0x02034ED8
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D717C
	ldr r0, _080D7178 @ =0x09EF6AF0
	movs r1, #0x00
	bl func_080010CC
	b _080D71CC
_080D7174: .4byte 0x02034ED8
_080D7178: .4byte 0x09EF6AF0
_080D717C:
	bl func_08006314
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D71CC
	ldr r1, _080D71A4 @ =0x02034ED6
	ldrh r0, [r1, #0x00]
	cmp r0, #0x00
	beq _080D71A8
	subs r0, #0x01
	strh r0, [r1, #0x00]
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _080D71CC
	movs r0, #0x01
	movs r1, #0x43
	bl func_08006184
	b _080D71CC
	.byte 0x00, 0x00
_080D71A4: .4byte 0x02034ED6
_080D71A8:
	ldr r0, _080D71BC @ =0x02034ED4
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080D71C4
	ldr r0, _080D71C0 @ =0x09EF4EC0
	movs r1, #0x01
	bl func_080010CC
	b _080D71CC
	.byte 0x00, 0x00
_080D71BC: .4byte 0x02034ED4
_080D71C0: .4byte 0x09EF4EC0
_080D71C4:
	ldr r0, _080D71D0 @ =0x09EF4ED0
	movs r1, #0x01
	bl func_080010CC
_080D71CC:
	pop {r0}
	bx r0
_080D71D0: .4byte 0x09EF4ED0
.syntax divided
