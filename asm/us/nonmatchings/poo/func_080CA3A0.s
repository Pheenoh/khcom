.syntax unified
	.align 2, 0
	.global func_080CA3A0
	.thumb
	.thumb_func
	.type func_080CA3A0, %function
func_080CA3A0: @ 080CA3A0
	push {lr}
	adds r1, r0, #0x0
	ldr r0, [r1, #0x00]
	lsls r0, r0, #0x08
	lsrs r0, r0, #0x10
	ldr r1, [r1, #0x04]
	lsls r1, r1, #0x08
	lsrs r1, r1, #0x10
	bl func_080CA36C
	ldr r1, _080CA3EC @ =0x000003FF
	ands r1, r0
	subs r0, r1, #0x1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x08
	bls _080CA3E6
	adds r0, r1, #0x0
	subs r0, #0x20
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x09
	bls _080CA3E6
	adds r0, r1, #0x0
	subs r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x09
	bls _080CA3E6
	ldr r2, _080CA3F0 @ =0xFFFFFE20
	adds r0, r1, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5F
	bhi _080CA3F4
_080CA3E6:
	movs r0, #0x00
	b _080CA3F6
	.byte 0x00, 0x00
_080CA3EC: .4byte 0x000003FF
_080CA3F0: .4byte 0xFFFFFE20
_080CA3F4:
	movs r0, #0x01
_080CA3F6:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
