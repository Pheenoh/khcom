.syntax unified
	.align 2, 0
	.global mode_sio_btl_connect_0
	.thumb
	.thumb_func
	.type mode_sio_btl_connect_0, %function
mode_sio_btl_connect_0: @ 080AEBA0
	push {r4, r5, lr}
	ldr r4, _080AEC70 @ =0x02034B3C
	movs r0, #0xB7
	lsls r0, r0, #0x02
	bl EwramAlloc
	str r0, [r4, #0x00]
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006120
	bl func_08004DB0
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x07
	movs r3, #0x0F
	bl SetupBg
	movs r0, #0x01
	movs r1, #0x01
	movs r2, #0x1F
	movs r3, #0x00
	bl SetupBg
	movs r0, #0x00
	bl func_08004FC8
	movs r0, #0x01
	bl func_08004FC8
	ldr r1, _080AEC74 @ =0x096AD604
	movs r2, #0xA0
	lsls r2, r2, #0x01
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _080AEC78 @ =0x096F6464
	movs r5, #0x80
	lsls r5, r5, #0x04
	movs r0, #0x00
	adds r2, r5, #0x0
	bl LoadBgMap
	ldr r1, _080AEC7C @ =0x09611AB8
	movs r0, #0x00
	movs r2, #0x20
	bl LoadBgPalette
	ldr r1, _080AEC80 @ =0x096ACA44
	movs r2, #0xBC
	lsls r2, r2, #0x04
	movs r0, #0x01
	bl LoadBgTiles
	ldr r1, _080AEC84 @ =0x096FBA04
	movs r0, #0x01
	movs r2, #0x40
	bl LoadBgPalette
	ldr r1, _080AEC88 @ =0x096F5C64
	movs r0, #0x01
	adds r2, r5, #0x0
	bl LoadBgMap
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
	ldr r0, _080AEC8C @ =0x08159E4A
	ldr r1, [r4, #0x00]
	adds r1, #0x08
	bl func_08065B6C
	ldr r1, [r4, #0x00]
	strb r0, [r1, #0x05]
	ldr r0, _080AEC90 @ =0x096FBAA4
	movs r1, #0x20
	bl LoadObjPalette
	ldr r1, [r4, #0x00]
	movs r2, #0xB6
	lsls r2, r2, #0x02
	adds r1, r1, r2
	str r0, [r1, #0x00]
	bl func_08006E60
	ldr r0, _080AEC94 @ =0x080AEE51
	ldr r1, _080AEC98 @ =0x080AEE6D
	movs r2, #0x00
	bl func_080C5A3C
	pop {r4, r5}
	pop {r0}
	bx r0
_080AEC70: .4byte 0x02034B3C
_080AEC74: .4byte 0x096AD604
_080AEC78: .4byte 0x096F6464
_080AEC7C: .4byte 0x09611AB8
_080AEC80: .4byte 0x096ACA44
_080AEC84: .4byte 0x096FBA04
_080AEC88: .4byte 0x096F5C64
_080AEC8C: .4byte 0x08159E4A
_080AEC90: .4byte 0x096FBAA4
_080AEC94: .4byte 0x080AEE51
_080AEC98: .4byte 0x080AEE6D
.syntax divided
