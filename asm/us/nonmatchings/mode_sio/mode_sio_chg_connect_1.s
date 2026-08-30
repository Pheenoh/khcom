.syntax unified
	.align 2, 0
	.global mode_sio_chg_connect_1
	.thumb
	.thumb_func
	.type mode_sio_chg_connect_1, %function
mode_sio_chg_connect_1: @ 080B1B20
	push {r4, lr}
	add sp, #-0x008
	ldr r4, _080B1B38 @ =0x02034B48
	ldr r0, [r4, #0x00]
	ldrb r0, [r0, #0x04]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x00
	beq _080B1B3C
	cmp r0, #0x01
	beq _080B1B42
	b _080B1B88
_080B1B38: .4byte 0x02034B48
_080B1B3C:
	bl func_080C54B4
	b _080B1B88
_080B1B42:
	bl func_080C54B4
	ldr r1, [r4, #0x00]
	ldrh r0, [r1, #0x02]
	adds r0, #0x01
	strh r0, [r1, #0x02]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x04
	ble _080B1B88
	ldr r0, _080B1B7C @ =0x080C5D51
	ldr r1, _080B1B80 @ =0x080C5D81
	bl func_080C5DC0
	bl func_080C5D00
	ldr r2, _080B1B84 @ =0x03006C78
	ldrh r0, [r2, #0x00]
	movs r1, #0x01
	orrs r0, r1
	strh r0, [r2, #0x00]
	ldrh r0, [r2, #0x00]
	movs r1, #0x10
	orrs r0, r1
	strh r0, [r2, #0x00]
	bl func_080B1C14
	b _080B1BA8
	.byte 0x00, 0x00
_080B1B7C: .4byte 0x080C5D51
_080B1B80: .4byte 0x080C5D81
_080B1B84: .4byte 0x03006C78
_080B1B88:
	ldr r0, _080B1BB0 @ =0x02034B48
	ldr r1, [r0, #0x00]
	adds r2, r1, #0x0
	adds r2, #0x08
	movs r3, #0xB6
	lsls r3, r3, #0x02
	adds r0, r1, r3
	ldr r3, [r0, #0x00]
	movs r0, #0x14
	str r0, [sp, #0x000]
	ldrb r0, [r1, #0x05]
	str r0, [sp, #0x004]
	movs r0, #0x3D
	movs r1, #0x44
	bl func_080664D8
_080B1BA8:
	add sp, #0x008
	pop {r4}
	pop {r0}
	bx r0
_080B1BB0: .4byte 0x02034B48
.syntax divided
