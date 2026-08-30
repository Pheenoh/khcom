.syntax unified
	.align 2, 0
	.global func_080FDA98
	.thumb
	.thumb_func
	.type func_080FDA98, %function
func_080FDA98: @ 080FDA98
	push {r4, r5, lr}
	adds r2, r0, #0x0
	lsls r2, r2, #0x10
	lsls r1, r1, #0x10
	lsrs r4, r1, #0x10
	ldr r3, _080FDADC @ =0x09992F70
	lsrs r5, r2, #0x10
	asrs r2, r2, #0x10
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x03
	adds r1, r1, r3
	movs r2, #0x02
	ldsh r1, [r1, r2]
	cmp r1, #0x0D
	bne _080FDAE8
	bl func_080D2DD8
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	cmp r1, #0x00
	beq _080FDAE8
	ldr r3, _080FDAE0 @ =0x02034FF8
	lsls r2, r4, #0x10
	asrs r2, r2, #0x10
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x03
	adds r3, #0x14
	adds r1, r1, r3
	ldr r2, _080FDAE4 @ =0x099A8914
	str r2, [r1, #0x00]
	b _080FDB0C
	.byte 0x00, 0x00
_080FDADC: .4byte 0x09992F70
_080FDAE0: .4byte 0x02034FF8
_080FDAE4: .4byte 0x099A8914
_080FDAE8:
	ldr r2, _080FDB14 @ =0x02034FF8
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r3, r1, #0x01
	adds r3, r3, r1
	lsls r3, r3, #0x03
	adds r2, #0x14
	adds r3, r3, r2
	ldr r4, _080FDB18 @ =0x09992F70
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x03
	adds r4, #0x10
	adds r1, r1, r4
	ldr r1, [r1, #0x00]
	str r1, [r3, #0x00]
_080FDB0C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080FDB14: .4byte 0x02034FF8
_080FDB18: .4byte 0x09992F70
.syntax divided
