.syntax unified
	.align 2, 0
	.global func_080CA724
	.thumb
	.thumb_func
	.type func_080CA724, %function
func_080CA724: @ 080CA724
	push {r4, r5, lr}
	adds r4, r0, #0x0
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _080CA744
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _080CA744
	movs r0, #0xAD
	b _080CA8CC
_080CA744:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _080CA760
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _080CA760
	movs r0, #0xD3
	b _080CA8CC
_080CA760:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _080CA77C
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _080CA77C
	movs r0, #0x2D
	b _080CA8CC
_080CA77C:
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _080CA798
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _080CA798
	movs r0, #0x53
	b _080CA8CC
_080CA798:
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _080CA7B6
	movs r0, #0x20
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _080CA7B6
	movs r0, #0xAD
	b _080CA8CC
_080CA7B6:
	bl func_08001384
	movs r1, #0x80
	ands r1, r0
	cmp r1, #0x00
	beq _080CA7D4
	movs r0, #0x10
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _080CA7D4
	movs r0, #0x53
	b _080CA8CC
_080CA7D4:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _080CA7F2
	movs r0, #0x20
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _080CA7F2
	movs r0, #0xD3
	b _080CA8CC
_080CA7F2:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _080CA810
	movs r0, #0x10
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _080CA810
	movs r0, #0x2D
	b _080CA8CC
_080CA810:
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _080CA82E
	movs r0, #0x40
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _080CA82E
	movs r0, #0xD3
	b _080CA8CC
_080CA82E:
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _080CA84C
	movs r0, #0x80
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _080CA84C
	movs r0, #0xAD
	b _080CA8CC
_080CA84C:
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _080CA86A
	movs r0, #0x40
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _080CA86A
	movs r0, #0x2D
	b _080CA8CC
_080CA86A:
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _080CA888
	movs r0, #0x80
	bl func_08001534
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bhi _080CA888
	movs r0, #0x53
	b _080CA8CC
_080CA888:
	bl func_08001384
	movs r2, #0x80
	adds r1, r2, #0x0
	ands r1, r0
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	cmp r5, #0x00
	beq _080CA89E
	strb r2, [r4, #0x14]
	b _080CA8CE
_080CA89E:
	bl func_08001384
	movs r1, #0x40
	ands r1, r0
	cmp r1, #0x00
	beq _080CA8AE
	strb r5, [r4, #0x14]
	b _080CA8CE
_080CA8AE:
	bl func_08001384
	movs r1, #0x20
	ands r1, r0
	cmp r1, #0x00
	beq _080CA8BE
	movs r0, #0xC0
	b _080CA8CC
_080CA8BE:
	bl func_08001384
	movs r1, #0x10
	ands r1, r0
	cmp r1, #0x00
	beq _080CA8CE
	movs r0, #0x40
_080CA8CC:
	strb r0, [r4, #0x14]
_080CA8CE:
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
