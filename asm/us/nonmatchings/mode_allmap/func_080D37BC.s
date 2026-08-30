.syntax unified
	.align 2, 0
	.global func_080D37BC
	.thumb
	.thumb_func
	.type func_080D37BC, %function
func_080D37BC: @ 080D37BC
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r4, r0, #0x18
	movs r5, #0x00
	adds r0, r4, #0x0
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080D37E0
	adds r0, r4, #0x0
	bl func_080DF51C
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x04
	bne _080D37E2
_080D37E0:
	movs r5, #0x01
_080D37E2:
	lsls r0, r5, #0x05
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
