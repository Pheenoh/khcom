.syntax unified
	.align 2, 0
	.global func_08075064
	.thumb
	.thumb_func
	.type func_08075064, %function
func_08075064: @ 08075064
	push {r4, lr}
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	movs r2, #0x00
	cmp r0, #0x00
	beq _08075076
	cmp r0, #0x01
	beq _080750A0
	b _080750C4
_08075076:
	ldr r3, _0807509C @ =0x09033D50
	movs r1, #0x00
	ldsh r0, [r3, r1]
	movs r1, #0x01
	negs r1, r1
	cmp r0, r1
	beq _080750C4
_08075084:
	lsls r0, r2, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x0F
	adds r0, r0, r3
	movs r4, #0x00
	ldsh r0, [r0, r4]
	cmp r0, r1
	bne _08075084
	b _080750C4
_0807509C: .4byte 0x09033D50
_080750A0:
	ldr r3, _080750D0 @ =0x09033E76
	movs r1, #0x00
	ldsh r0, [r3, r1]
	movs r1, #0x01
	negs r1, r1
	cmp r0, r1
	beq _080750C4
_080750AE:
	lsls r0, r2, #0x10
	movs r2, #0x80
	lsls r2, r2, #0x09
	adds r0, r0, r2
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x0F
	adds r0, r0, r3
	movs r4, #0x00
	ldsh r0, [r0, r4]
	cmp r0, r1
	bne _080750AE
_080750C4:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080750D0: .4byte 0x09033E76
.syntax divided
