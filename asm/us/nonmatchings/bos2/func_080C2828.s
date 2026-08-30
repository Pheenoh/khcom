.syntax unified
	.align 2, 0
	.global func_080C2828
	.thumb
	.thumb_func
	.type func_080C2828, %function
func_080C2828: @ 080C2828
	push {r4, r5, r6, lr}
	adds r5, r0, #0x0
	ldr r6, [r5, #0x00]
	movs r0, #0x88
	lsls r0, r0, #0x01
	adds r4, r6, r0
	movs r1, #0xD5
	lsls r1, r1, #0x02
	adds r0, r6, r1
	movs r1, #0x00
	strh r1, [r0, #0x00]
	strh r1, [r5, #0x0A]
	ldr r0, [r5, #0x00]
	ldr r2, _080C2880 @ =0x00000356
	adds r0, r0, r2
	strh r1, [r0, #0x00]
	movs r0, #0x00
	movs r1, #0x60
	bl func_080C213C
	adds r1, r5, #0x0
	adds r1, #0x54
	movs r0, #0x01
	strb r0, [r1, #0x00]
	adds r0, r5, #0x0
	adds r0, #0x1C
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	adds r0, r5, #0x0
	adds r0, #0x34
	movs r1, #0x00
	movs r2, #0x01
	bl func_080059A4
	ldr r0, _080C2884 @ =0xFFFF9C00
	str r0, [r6, #0x0C]
	ldr r0, _080C2888 @ =0xFFFF7400
	str r0, [r4, #0x0C]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C2880: .4byte 0x00000356
_080C2884: .4byte 0xFFFF9C00
_080C2888: .4byte 0xFFFF7400
.syntax divided
