.syntax unified
	.align 2, 0
	.global func_080D3AB8
	.thumb
	.thumb_func
	.type func_080D3AB8, %function
func_080D3AB8: @ 080D3AB8
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	adds r0, r4, #0x0
	bl func_080DF51C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3ADE
_080D3ACE:
	adds r0, r4, #0x0
	movs r1, #0x02
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3AEE
	b _080D3B12
_080D3ADE:
	adds r0, r4, #0x0
	movs r1, #0x08
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3B12
	b _080D3ACE
_080D3AEE:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_080D3564
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D3B12
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_080D358C
	movs r1, #0x00
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3B0E
	movs r1, #0x01
_080D3B0E:
	adds r0, r1, #0x0
	b _080D3B14
_080D3B12:
	movs r0, #0x00
_080D3B14:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
