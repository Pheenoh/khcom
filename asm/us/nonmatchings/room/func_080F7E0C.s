.syntax unified
	.align 2, 0
	.global func_080F7E0C
	.thumb
	.thumb_func
	.type func_080F7E0C, %function
func_080F7E0C: @ 080F7E0C
	push {r4, lr}
	subs r2, r2, r0
	subs r1, r3, r1
	cmp r2, #0x00
	blt _080F7E26
	movs r4, #0x00
	cmp r1, #0x00
	bge _080F7E3A
	movs r4, #0x03
	adds r0, r2, #0x0
	negs r2, r1
	adds r1, r0, #0x0
	b _080F7E3A
_080F7E26:
	cmp r1, #0x00
	blt _080F7E34
	movs r4, #0x01
	adds r0, r2, #0x0
	adds r2, r1, #0x0
	negs r1, r0
	b _080F7E3A
_080F7E34:
	movs r4, #0x02
	negs r2, r2
	negs r1, r1
_080F7E3A:
	cmp r1, r2
	ble _080F7E58
	cmp r1, #0x00
	beq _080F7E5C
	lsls r2, r2, #0x08
	adds r0, r2, #0x0
	bl func_0811D5EC
	bl func_080F7DD8
	movs r1, #0x40
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	b _080F7E72
_080F7E58:
	cmp r2, #0x00
	bne _080F7E60
_080F7E5C:
	movs r0, #0x00
	b _080F7E7C
_080F7E60:
	lsls r1, r1, #0x08
	adds r0, r1, #0x0
	adds r1, r2, #0x0
	bl func_0811D5EC
	bl func_080F7DD8
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
_080F7E72:
	lsls r0, r4, #0x06
	adds r0, r1, r0
	adds r0, #0x40
	movs r1, #0xFF
	ands r0, r1
_080F7E7C:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
