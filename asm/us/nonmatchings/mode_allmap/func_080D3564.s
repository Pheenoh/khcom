.syntax unified
	.align 2, 0
	.global func_080D3564
	.thumb
	.thumb_func
	.type func_080D3564, %function
func_080D3564: @ 080D3564
	push {lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	bl func_080DEE44
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	cmp r1, #0x00
	beq _080D3582
	movs r0, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080D3586
_080D3582:
	movs r0, #0x00
	b _080D3588
_080D3586:
	movs r0, #0x01
_080D3588:
	pop {r1}
	bx r1
.syntax divided
