.syntax unified
	.align 2, 0
	.global func_08034368
	.thumb
	.thumb_func
	.type func_08034368, %function
func_08034368: @ 08034368
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08034388
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _08034388
	movs r0, #0xAD
	b _08034510
_08034388:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _080343A4
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _080343A4
	movs r0, #0xD3
	b _08034510
_080343A4:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _080343C0
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _080343C0
	movs r0, #0x2D
	b _08034510
_080343C0:
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _080343DC
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _080343DC
	movs r0, #0x53
	b _08034510
_080343DC:
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _080343FA
	movs r0, #0x20
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _080343FA
	movs r0, #0xAD
	b _08034510
_080343FA:
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _08034418
	movs r0, #0x10
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08034418
	movs r0, #0x53
	b _08034510
_08034418:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08034436
	movs r0, #0x20
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08034436
	movs r0, #0xD3
	b _08034510
_08034436:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _08034454
	movs r0, #0x10
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08034454
	movs r0, #0x2D
	b _08034510
_08034454:
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08034472
	movs r0, #0x40
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08034472
	movs r0, #0xD3
	b _08034510
_08034472:
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08034490
	movs r0, #0x80
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _08034490
	movs r0, #0xAD
	b _08034510
_08034490:
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _080344AE
	movs r0, #0x40
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _080344AE
	movs r0, #0x2D
	b _08034510
_080344AE:
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _080344CC
	movs r0, #0x80
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _080344CC
	movs r0, #0x53
	b _08034510
_080344CC:
	bl func_08001384
	movs r2, #0x80
	adds r1, r2, #0x0
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r5, #0x00
	beq _080344E2
	strb r2, [r4, #0x14]
	b _08034512
_080344E2:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _080344F2
	strb r5, [r4, #0x14]
	b _08034512
_080344F2:
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _08034502
	movs r0, #0xC0
	b _08034510
_08034502:
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _08034512
	movs r0, #0x40
_08034510:
	strb r0, [r4, #0x14]
_08034512:
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
