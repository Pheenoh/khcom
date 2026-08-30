.syntax unified
	.align 2, 0
	.global func_080FDA28
	.thumb
	.thumb_func
	.type func_080FDA28, %function
func_080FDA28: @ 080FDA28
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r2, _080FDA54 @ =0x09992F70
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r1, r1, r2
	movs r2, #0x02
	ldsh r0, [r1, r2]
	cmp r0, #0x0D
	bne _080FDA5C
	bl func_080D2DD8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080FDA5C
	ldr r0, _080FDA58 @ =0x099EDE7C
	b _080FDA6E
_080FDA54: .4byte 0x09992F70
_080FDA58: .4byte 0x099EDE7C
_080FDA5C:
	ldr r2, _080FDA90 @ =0x09992F70
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, #0x0C
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
_080FDA6E:
	movs r1, #0x80
	lsls r1, r1, #0x05
	bl func_080026A4
	ldr r3, _080FDA94 @ =0x02034FF8
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x03
	adds r3, #0x10
	adds r1, r1, r3
	str r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080FDA90: .4byte 0x09992F70
_080FDA94: .4byte 0x02034FF8
.syntax divided
