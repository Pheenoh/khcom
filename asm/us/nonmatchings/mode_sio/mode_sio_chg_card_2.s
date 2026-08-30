.syntax unified
	.align 2, 0
	.global mode_sio_chg_card_2
	.thumb
	.thumb_func
	.type mode_sio_chg_card_2, %function
mode_sio_chg_card_2: @ 080B2BF4
	push {r4, r5, r6, lr}
	ldr r4, _080B2CC8 @ =0x02034B4C
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x08]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x0C]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x10]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x14]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x50]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x54]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	adds r0, #0x80
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	adds r0, #0x84
	ldr r0, [r0, #0x00]
	bl func_08002C10
	movs r5, #0x00
	adds r6, r4, #0x0
_080B2C40:
	ldr r0, [r6, #0x00]
	lsls r4, r5, #0x02
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r0, r1
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r6, #0x00]
	movs r1, #0x94
	lsls r1, r1, #0x01
	adds r0, r0, r1
	adds r0, r0, r4
	ldr r0, [r0, #0x00]
	bl func_08002C10
	adds r5, #0x01
	cmp r5, #0x09
	ble _080B2C40
	ldr r4, _080B2CC8 @ =0x02034B4C
	ldr r0, [r4, #0x00]
	movs r1, #0xBC
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	movs r1, #0xBE
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	movs r1, #0x81
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	movs r1, #0x84
	lsls r1, r1, #0x02
	adds r0, r0, r1
	movs r1, #0x2A
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	movs r1, #0xD9
	lsls r1, r1, #0x02
	adds r0, r0, r1
	movs r1, #0x14
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	ldr r1, _080B2CCC @ =0x00000BE4
	adds r0, r0, r1
	bl func_08000F0C
	ldr r0, [r4, #0x00]
	bl func_080009C4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B2CC8: .4byte 0x02034B4C
_080B2CCC: .4byte 0x00000BE4
.syntax divided
