.syntax unified
	.align 2, 0
	.global mode_sio_btl_option_2
	.thumb
	.thumb_func
	.type mode_sio_btl_option_2, %function
mode_sio_btl_option_2: @ 080B04F0
	push {r4, lr}
	ldr r4, _080B062C @ =0x02034B40
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x08]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x10]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x0C]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	ldr r0, [r0, #0x14]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	adds r0, #0xF4
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	movs r1, #0xA6
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	movs r1, #0xD2
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	ldr r1, _080B0630 @ =0x0000040C
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	adds r0, #0x54
	movs r1, #0x14
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	adds r0, #0xFC
	movs r1, #0x0A
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	movs r1, #0xAA
	lsls r1, r1, #0x01
	adds r0, r0, r1
	movs r1, #0x0A
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	movs r1, #0x8B
	lsls r1, r1, #0x02
	adds r0, r0, r1
	movs r1, #0x3C
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	movs r1, #0xD4
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	movs r1, #0xD6
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	movs r1, #0xDC
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	movs r1, #0xDE
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	movs r1, #0x87
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	movs r1, #0x88
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	movs r1, #0xF2
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	movs r1, #0xF4
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	movs r1, #0xFE
	lsls r1, r1, #0x01
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	movs r1, #0x83
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	movs r1, #0x80
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_080028C0
	ldr r0, [r4, #0x00]
	movs r1, #0x84
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl func_08002C10
	ldr r0, [r4, #0x00]
	bl func_080009C4
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B062C: .4byte 0x02034B40
_080B0630: .4byte 0x0000040C
.syntax divided
