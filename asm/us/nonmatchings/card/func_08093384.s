.syntax unified
	.align 2, 0
	.global func_08093384
	.thumb
	.thumb_func
	.type func_08093384, %function
func_08093384: @ 08093384
	push {r4, r5, r6, r7, lr}
	movs r4, #0x00
	movs r3, #0x00
	ldr r7, _080933A4 @ =0x0203A8C0
_0809338C:
	lsls r0, r3, #0x02
	adds r1, r0, r3
	lsls r2, r1, #0x01
	lsls r1, r1, #0x11
	lsrs r1, r1, #0x10
	adds r2, #0x0A
	adds r5, r0, #0x0
	adds r6, r3, #0x1
	cmp r1, r2
	bge _080933C6
	b _080933B8
	.byte 0x00, 0x00
_080933A4: .4byte 0x0203A8C0
_080933A8:
	adds r0, r1, #0x1
	lsls r0, r0, #0x10
	lsrs r1, r0, #0x10
	adds r0, r5, r3
	lsls r0, r0, #0x01
	adds r0, #0x0A
	cmp r1, r0
	bge _080933C6
_080933B8:
	adds r0, r1, r7
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080933A8
	adds r0, r4, #0x1
	lsls r0, r0, #0x10
	lsrs r4, r0, #0x10
_080933C6:
	lsls r0, r6, #0x10
	lsrs r3, r0, #0x10
	cmp r3, #0x1A
	bls _0809338C
	adds r0, r4, #0x0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
