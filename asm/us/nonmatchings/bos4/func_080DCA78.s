.syntax unified
	.align 2, 0
	.global func_080DCA78
	.thumb
	.thumb_func
	.type func_080DCA78, %function
func_080DCA78: @ 080DCA78
	push {r4, lr}
	adds r4, r0, #0x0
	lsls r4, r4, #0x18
	lsrs r4, r4, #0x18
	bl func_080DC510
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r4, r0
	beq _080DCA90
	movs r0, #0x06
	b _080DCA92
_080DCA90:
	movs r0, #0x0C
_080DCA92:
	pop {r4}
	pop {r1}
	bx r1
.syntax divided
