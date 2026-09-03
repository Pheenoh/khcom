.syntax unified
	.align 2, 0
	.global func_080BA2B0
	.thumb
	.thumb_func
	.type func_080BA2B0, %function
func_080BA2B0: @ 080BA2B0
	push {r4, r5, lr}
	adds r5, r0, #0x0
	ldr r0, [r5, #0x0C]
	ldr r4, _080BA360 @ =0x09654C04
	adds r1, r4, #0x0
	bl func_08002A10
	ldr r0, [r5, #0x10]
	adds r1, r4, #0x0
	bl func_08002A10
	movs r0, #0x96
	lsls r0, r0, #0x01
	adds r2, r5, r0
	ldr r0, _080BA364 @ =0x09EF39DC
	ldr r1, [r0, #0x00]
	str r1, [r2, #0x00]
	movs r2, #0x91
	lsls r2, r2, #0x02
	adds r0, r5, r2
	str r1, [r0, #0x00]
	ldr r4, _080BA368 @ =0x0000047C
	adds r3, r5, r4
	ldr r2, [r3, #0x00]
	ldrh r1, [r2, #0x28]
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0x00
	beq _080BA374
	ldr r0, [r2, #0x08]
	movs r1, #0x80
	lsls r1, r1, #0x01
	adds r0, r0, r1
	str r0, [r5, #0x20]
	movs r2, #0x9C
	lsls r2, r2, #0x01
	adds r1, r5, r2
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x08]
	ldr r4, _080BA36C @ =0xFFFFFA00
	adds r0, r0, r4
	str r0, [r1, #0x00]
	movs r0, #0x94
	lsls r0, r0, #0x02
	adds r1, r5, r0
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x08]
	movs r2, #0xC0
	lsls r2, r2, #0x03
	adds r0, r0, r2
	str r0, [r1, #0x00]
	movs r4, #0xDA
	lsls r4, r4, #0x02
	adds r1, r5, r4
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x08]
	ldr r2, _080BA370 @ =0xFFFFFE00
	adds r0, r0, r2
	str r0, [r1, #0x00]
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x18]
	movs r4, #0x80
	lsls r4, r4, #0x02
	adds r0, r0, r4
	str r0, [r5, #0x24]
	movs r0, #0x9E
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x18]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	movs r2, #0x95
	lsls r2, r2, #0x02
	adds r1, r5, r2
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x18]
	movs r4, #0xA0
	lsls r4, r4, #0x03
	adds r0, r0, r4
	str r0, [r1, #0x00]
	movs r0, #0xDB
	lsls r0, r0, #0x02
	adds r1, r5, r0
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x18]
	ldr r2, _080BA370 @ =0xFFFFFE00
	b _080BA3E2
_080BA360: .4byte 0x09654C04
_080BA364: .4byte 0x09EF39DC
_080BA368: .4byte 0x0000047C
_080BA36C: .4byte 0xFFFFFA00
_080BA370: .4byte 0xFFFFFE00
_080BA374:
	ldr r0, [r2, #0x08]
	movs r4, #0xC0
	lsls r4, r4, #0x03
	adds r0, r0, r4
	str r0, [r5, #0x20]
	movs r0, #0x9C
	lsls r0, r0, #0x01
	adds r1, r5, r0
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x08]
	ldr r2, _080BA428 @ =0xFFFFFF00
	adds r0, r0, r2
	str r0, [r1, #0x00]
	movs r4, #0x94
	lsls r4, r4, #0x02
	adds r1, r5, r4
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x08]
	movs r2, #0x80
	lsls r2, r2, #0x02
	adds r0, r0, r2
	str r0, [r1, #0x00]
	movs r0, #0xDA
	lsls r0, r0, #0x02
	adds r1, r5, r0
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x08]
	ldr r4, _080BA42C @ =0xFFFFFA00
	adds r0, r0, r4
	str r0, [r1, #0x00]
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x18]
	ldr r1, _080BA430 @ =0xFFFFFE00
	adds r0, r0, r1
	str r0, [r5, #0x24]
	movs r4, #0x9E
	lsls r4, r4, #0x01
	adds r1, r5, r4
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x18]
	adds r0, r0, r2
	str r0, [r1, #0x00]
	movs r0, #0x95
	lsls r0, r0, #0x02
	adds r1, r5, r0
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x18]
	ldr r4, _080BA434 @ =0xFFFFFB00
	adds r0, r0, r4
	str r0, [r1, #0x00]
	movs r0, #0xDB
	lsls r0, r0, #0x02
	adds r1, r5, r0
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x18]
_080BA3E2:
	adds r0, r0, r2
	str r0, [r1, #0x00]
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x1C]
	ldr r1, _080BA438 @ =0xFFFFFC00
	adds r0, r0, r1
	str r0, [r5, #0x28]
	movs r4, #0xA0
	lsls r4, r4, #0x01
	adds r2, r5, r4
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x1C]
	adds r0, r0, r1
	str r0, [r2, #0x00]
	movs r0, #0x96
	lsls r0, r0, #0x02
	adds r1, r5, r0
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x1C]
	movs r2, #0xC8
	lsls r2, r2, #0x05
	adds r0, r0, r2
	str r0, [r1, #0x00]
	movs r4, #0xDC
	lsls r4, r4, #0x02
	adds r1, r5, r4
	ldr r0, [r3, #0x00]
	ldr r0, [r0, #0x1C]
	movs r2, #0xE0
	lsls r2, r2, #0x05
	adds r0, r0, r2
	str r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_080BA428: .4byte 0xFFFFFF00
_080BA42C: .4byte 0xFFFFFA00
_080BA430: .4byte 0xFFFFFE00
_080BA434: .4byte 0xFFFFFB00
_080BA438: .4byte 0xFFFFFC00
.syntax divided
