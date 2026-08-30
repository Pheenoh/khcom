.syntax unified
	.align 2, 0
	.global func_08010548
	.thumb
	.thumb_func
	.type func_08010548, %function
func_08010548: @ 08010548
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	movs r0, #0x80
	lsls r0, r0, #0x02
	ands r0, r5
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0x00
	beq _08010588
	ldr r0, _08010580 @ =0x020348CC
	lsls r1, r1, #0x01
	adds r3, r1, r0
	ldrh r0, [r3, #0x00]
	adds r0, #0x01
	movs r2, #0x00
	strh r0, [r3, #0x00]
	ldr r0, _08010584 @ =0x020348D4
	adds r0, r1, r0
	strh r2, [r0, #0x00]
	ldrh r0, [r3, #0x00]
	adds r4, r1, #0x0
	cmp r0, #0x20
	bls _080105A0
	movs r0, #0x1D
	strh r0, [r3, #0x00]
	b _080105A0
	.byte 0x00, 0x00
_08010580: .4byte 0x020348CC
_08010584: .4byte 0x020348D4
_08010588:
	ldr r0, _080105CC @ =0x020348CC
	lsls r1, r1, #0x01
	adds r0, r1, r0
	strh r2, [r0, #0x00]
	ldr r0, _080105D0 @ =0x020348D4
	adds r2, r1, r0
	ldrh r0, [r2, #0x00]
	adds r4, r1, #0x0
	cmp r0, #0xFE
	bhi _080105A0
	adds r0, #0x01
	strh r0, [r2, #0x00]
_080105A0:
	movs r0, #0x80
	lsls r0, r0, #0x01
	ands r0, r5
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x00
	beq _080105DC
	ldr r0, _080105D4 @ =0x020348D0
	adds r2, r4, r0
	ldrh r0, [r2, #0x00]
	adds r0, #0x01
	movs r1, #0x00
	strh r0, [r2, #0x00]
	ldr r0, _080105D8 @ =0x020348D8
	adds r0, r4, r0
	strh r1, [r0, #0x00]
	ldrh r0, [r2, #0x00]
	cmp r0, #0x20
	bls _080105F0
	movs r0, #0x1D
	strh r0, [r2, #0x00]
	b _080105F0
_080105CC: .4byte 0x020348CC
_080105D0: .4byte 0x020348D4
_080105D4: .4byte 0x020348D0
_080105D8: .4byte 0x020348D8
_080105DC:
	ldr r0, _080105F8 @ =0x020348D0
	adds r0, r4, r0
	strh r1, [r0, #0x00]
	ldr r0, _080105FC @ =0x020348D8
	adds r1, r4, r0
	ldrh r0, [r1, #0x00]
	cmp r0, #0xFE
	bhi _080105F0
	adds r0, #0x01
	strh r0, [r1, #0x00]
_080105F0:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080105F8: .4byte 0x020348D0
_080105FC: .4byte 0x020348D8
.syntax divided
