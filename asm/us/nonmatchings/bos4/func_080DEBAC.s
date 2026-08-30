.syntax unified
	.align 2, 0
	.global func_080DEBAC
	.thumb
	.thumb_func
	.type func_080DEBAC, %function
func_080DEBAC: @ 080DEBAC
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #0x01
	beq _080DEBCC
	cmp r0, #0x01
	bgt _080DEBBE
	cmp r0, #0x00
	beq _080DEBC8
	b _080DEBD6
_080DEBBE:
	cmp r0, #0x02
	beq _080DEBD0
	cmp r0, #0x03
	beq _080DEBD4
	b _080DEBD6
_080DEBC8:
	movs r0, #0x01
	b _080DEBD6
_080DEBCC:
	movs r0, #0x00
	b _080DEBD6
_080DEBD0:
	movs r0, #0x03
	b _080DEBD6
_080DEBD4:
	movs r0, #0x02
_080DEBD6:
	bx lr
.syntax divided
