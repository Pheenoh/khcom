.syntax unified
	.align 2, 0
	.global mode_sio_btl_connect_2
	.thumb
	.thumb_func
	.type mode_sio_btl_connect_2, %function
mode_sio_btl_connect_2: @ 080AEE24
	push {r4, lr}
	ldr r4, _080AEE4C @ =0x02034B3C
	ldr r0, [r4, #0x00]
	movs r1, #0xB6
	lsls r1, r1, #0x02
	adds r0, r0, r1
	ldr r0, [r0, #0x00]
	bl ReleaseObjPalette
	ldr r0, [r4, #0x00]
	adds r0, #0x08
	movs r1, #0x5A
	bl func_08065AE0
	ldr r0, [r4, #0x00]
	bl EwramFree
	pop {r4}
	pop {r0}
	bx r0
_080AEE4C: .4byte 0x02034B3C
.syntax divided
