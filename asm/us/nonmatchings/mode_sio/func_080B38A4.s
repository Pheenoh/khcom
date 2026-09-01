.syntax unified
	.align 2, 0
	.global func_080B38A4
	.thumb
	.thumb_func
	.type func_080B38A4, %function
func_080B38A4: @ 080B38A4
	push {r4, r5, lr}
	ldr r5, _080B38F4 @ =0x0203AB20
	ldr r4, _080B38F8 @ =0x02034B4C
	ldr r0, [r4, #0x00]
	adds r0, #0x76
	movs r1, #0x00
	ldsh r0, [r0, r1]
	lsls r0, r0, #0x01
	adds r0, r0, r5
	ldrh r0, [r0, #0x00]
	bl func_08084068
	ldr r1, [r4, #0x00]
	adds r4, r1, #0x0
	adds r4, #0x76
	movs r2, #0x00
	ldsh r0, [r4, r2]
	lsls r0, r0, #0x01
	adds r0, r0, r5
	movs r2, #0x80
	lsls r2, r2, #0x04
	strh r2, [r0, #0x00]
	ldr r3, _080B38FC @ =0x0203AB10
	ldrh r0, [r4, #0x00]
	strb r0, [r3, #0x00]
	ldr r0, _080B3900 @ =0x00000202
	adds r1, r1, r0
	strh r2, [r1, #0x00]
	ldr r4, _080B3904 @ =0x02039B58
	ldrb r1, [r3, #0x00]
	movs r0, #0x0F
	ands r0, r1
	lsls r0, r0, #0x0C
	adds r2, #0x01
	orrs r0, r2
	strh r0, [r4, #0x06]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B38F4: .4byte 0x0203AB20
_080B38F8: .4byte 0x02034B4C
_080B38FC: .4byte 0x0203AB10
_080B3900: .4byte 0x00000202
_080B3904: .4byte 0x02039B58
.syntax divided
