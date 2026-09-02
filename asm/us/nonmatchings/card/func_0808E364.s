.syntax unified
	.align 2, 0
	.global func_0808E364
	.thumb
	.thumb_func
	.type func_0808E364, %function
func_0808E364: @ 0808E364
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	cmp r1, #0x00
	beq _0808E376
	cmp r1, #0x01
	beq _0808E398
	b _0808E3C4
_0808E376:
	ldr r0, [r5, #0x04]
	ldr r1, _0808E388 @ =0x090A4A0C
	bl func_08002A10
	ldr r0, _0808E38C @ =0x00000818
	adds r4, r5, r0
	ldr r1, _0808E390 @ =0x09EEB064
	ldr r2, _0808E394 @ =0x09EEB050
	b _0808E3A8
_0808E388: .4byte 0x090A4A0C
_0808E38C: .4byte 0x00000818
_0808E390: .4byte 0x09EEB064
_0808E394: .4byte 0x09EEB050
_0808E398:
	ldr r0, [r5, #0x04]
	ldr r1, _0808E3CC @ =0x090A51F6
	bl func_08002A10
	ldr r0, _0808E3D0 @ =0x00000818
	adds r4, r5, r0
	ldr r1, _0808E3D4 @ =0x09EEB07C
	ldr r2, _0808E3D8 @ =0x09EEB068
_0808E3A8:
	adds r0, r4, #0x0
	bl AnimInit
	adds r0, r4, #0x0
	movs r1, #0x00
	movs r2, #0x01
	bl AnimStart
	adds r0, r4, #0x0
	bl AnimGetGfx
	ldr r2, _0808E3DC @ =0x000004F4
	adds r1, r5, r2
	str r0, [r1, #0x00]
_0808E3C4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0808E3CC: .4byte 0x090A51F6
_0808E3D0: .4byte 0x00000818
_0808E3D4: .4byte 0x09EEB07C
_0808E3D8: .4byte 0x09EEB068
_0808E3DC: .4byte 0x000004F4
.syntax divided
