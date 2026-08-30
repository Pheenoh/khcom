.syntax unified
	.align 2, 0
	.global func_080D3A70
	.thumb
	.thumb_func
	.type func_080D3A70, %function
func_080D3A70: @ 080D3A70
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r5, r1, #0x18
	adds r0, r4, #0x0
	bl func_080DF51C
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080D3A94
	adds r0, r4, #0x0
	movs r1, #0x08
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3AA2
_080D3A94:
	adds r0, r4, #0x0
	movs r1, #0x02
	bl func_080D5944
	lsls r0, r0, #0x18
	cmp r0, #0x00
	bne _080D3AA6
_080D3AA2:
	movs r0, #0x00
	b _080D3AB2
_080D3AA6:
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_080D3564
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
_080D3AB2:
	pop {r4, r5}
	pop {r1}
	bx r1
.syntax divided
