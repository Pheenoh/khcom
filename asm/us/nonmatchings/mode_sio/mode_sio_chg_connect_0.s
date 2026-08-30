.syntax unified
	.align 2, 0
	.global mode_sio_chg_connect_0
	.thumb
	.thumb_func
	.type mode_sio_chg_connect_0, %function
mode_sio_chg_connect_0: @ 080B1A24
	push {r4, r5, lr}
	ldr r4, _080B1AF4 @ =0x02034B48
	movs r0, #0xB7
	lsls r0, r0, #0x02
	bl func_08000918
	str r0, [r4, #0x00]
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006120
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x07
	movs r3, #0x0F
	bl func_08005074
	movs r0, #0x01
	movs r1, #0x01
	movs r2, #0x1F
	movs r3, #0x00
	bl func_08005074
	movs r0, #0x00
	bl func_08004FC8
	movs r0, #0x01
	bl func_08004FC8
	ldr r1, _080B1AF8 @ =0x096AD604
	movs r2, #0xA0
	lsls r2, r2, #0x01
	movs r0, #0x00
	bl func_080050B8
	ldr r1, _080B1AFC @ =0x096F6464
	movs r5, #0x80
	lsls r5, r5, #0x04
	movs r0, #0x00
	adds r2, r5, #0x0
	bl func_0800510C
	ldr r1, _080B1B00 @ =0x09611AB8
	movs r0, #0x00
	movs r2, #0x20
	bl func_080050DC
	ldr r1, _080B1B04 @ =0x096ACA44
	movs r2, #0xBC
	lsls r2, r2, #0x04
	movs r0, #0x01
	bl func_080050B8
	ldr r1, _080B1B08 @ =0x096FBA04
	movs r0, #0x01
	movs r2, #0x40
	bl func_080050DC
	ldr r1, _080B1B0C @ =0x096F5C64
	movs r0, #0x01
	adds r2, r5, #0x0
	bl func_0800510C
	ldr r0, [r4, #0x00]
	movs r2, #0x00
	movs r1, #0x00
	strh r1, [r0, #0x00]
	strh r1, [r0, #0x02]
	strb r2, [r0, #0x04]
	ldr r0, [r4, #0x00]
	strb r2, [r0, #0x05]
	ldr r0, [r4, #0x00]
	adds r0, #0x08
	movs r1, #0x5A
	bl func_08065ACC
	ldr r0, _080B1B10 @ =0x08159EC4
	ldr r1, [r4, #0x00]
	adds r1, #0x08
	bl func_08065B6C
	ldr r1, [r4, #0x00]
	strb r0, [r1, #0x05]
	ldr r0, _080B1B14 @ =0x096FBAA4
	movs r1, #0x20
	bl func_08002A14
	ldr r1, [r4, #0x00]
	movs r2, #0xB6
	lsls r2, r2, #0x02
	adds r1, r1, r2
	str r0, [r1, #0x00]
	bl func_08006E60
	ldr r0, _080B1B18 @ =0x080B1BE1
	ldr r1, _080B1B1C @ =0x080B1BFD
	movs r2, #0x01
	bl func_080C5A3C
	pop {r4, r5}
	pop {r0}
	bx r0
_080B1AF4: .4byte 0x02034B48
_080B1AF8: .4byte 0x096AD604
_080B1AFC: .4byte 0x096F6464
_080B1B00: .4byte 0x09611AB8
_080B1B04: .4byte 0x096ACA44
_080B1B08: .4byte 0x096FBA04
_080B1B0C: .4byte 0x096F5C64
_080B1B10: .4byte 0x08159EC4
_080B1B14: .4byte 0x096FBAA4
_080B1B18: .4byte 0x080B1BE1
_080B1B1C: .4byte 0x080B1BFD
.syntax divided
