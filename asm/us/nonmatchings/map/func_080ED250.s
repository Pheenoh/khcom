.syntax unified
	.align 2, 0
	.global func_080ED250
	.thumb
	.thumb_func
	.type func_080ED250, %function
func_080ED250: @ 080ED250
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0x0
	ldr r1, _080ED2F8 @ =0x099597E4
	movs r2, #0xA0
	lsls r2, r2, #0x01
	movs r0, #0x00
	bl LoadBgTiles
	ldr r1, _080ED2FC @ =0x09985F44
	movs r2, #0x80
	lsls r2, r2, #0x04
	movs r0, #0x00
	bl LoadBgMap
	ldr r0, _080ED300 @ =0x09611AB8
	ldr r1, _080ED304 @ =0x050001E0
	movs r2, #0x20
	bl LoadPalette
	movs r0, #0x0F
	movs r1, #0x01
	bl func_080062F4
	movs r0, #0x00
	movs r1, #0x00
	movs r2, #0x00
	bl SetBgScroll
	movs r0, #0x01
	bl _08066468
	movs r2, #0xBE
	lsls r2, r2, #0x01
	adds r1, r7, r2
	str r0, [r1, #0x00]
	movs r0, #0xC0
	lsls r0, r0, #0x01
	adds r4, r7, r0
	adds r0, r4, #0x0
	movs r1, #0x21
	bl func_08065ACC
	movs r2, #0xA3
	lsls r2, r2, #0x02
	adds r5, r7, r2
	adds r0, r5, #0x0
	movs r1, #0x06
	bl func_08065ACC
	movs r0, #0xB0
	lsls r0, r0, #0x02
	adds r6, r7, r0
	adds r0, r6, #0x0
	movs r1, #0x09
	bl func_08065ACC
	ldr r0, _080ED308 @ =0x0815A03A
	adds r1, r4, #0x0
	bl func_08065B6C
	movs r2, #0xA2
	lsls r2, r2, #0x02
	adds r1, r7, r2
	strb r0, [r1, #0x00]
	ldr r0, _080ED30C @ =0x08159E10
	adds r1, r5, #0x0
	bl func_08065B6C
	movs r2, #0xAF
	lsls r2, r2, #0x02
	adds r1, r7, r2
	strb r0, [r1, #0x00]
	ldr r0, _080ED310 @ =0x08159E18
	adds r1, r6, #0x0
	bl func_08065B6C
	movs r2, #0xC2
	lsls r2, r2, #0x02
	adds r1, r7, r2
	strb r0, [r1, #0x00]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080ED2F8: .4byte 0x099597E4
_080ED2FC: .4byte 0x09985F44
_080ED300: .4byte 0x09611AB8
_080ED304: .4byte 0x050001E0
_080ED308: .4byte 0x0815A03A
_080ED30C: .4byte 0x08159E10
_080ED310: .4byte 0x08159E18
.syntax divided
