.syntax unified
	.align 2, 0
	.global func_080FD9B8
	.thumb
	.thumb_func
	.type func_080FD9B8, %function
func_080FD9B8: @ 080FD9B8
	push {r4, r5, lr}
	lsls r0, r0, #0x10
	lsls r1, r1, #0x10
	lsrs r5, r1, #0x10
	ldr r2, _080FD9E8 @ =0x09992F70
	lsrs r4, r0, #0x10
	asrs r0, r0, #0x10
	lsls r1, r0, #0x01
	adds r1, r1, r0
	lsls r1, r1, #0x03
	adds r1, r1, r2
	movs r2, #0x02
	ldsh r0, [r1, r2]
	cmp r0, #0x0D
	bne _080FD9F0
	bl func_080D2DD8
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _080FD9F0
	ldr r0, _080FD9EC @ =0x09A3CDDC
	movs r1, #0x40
	b _080FDA04
	.byte 0x00, 0x00
_080FD9E8: .4byte 0x09992F70
_080FD9EC: .4byte 0x09A3CDDC
_080FD9F0:
	ldr r2, _080FDA20 @ =0x09992F70
	lsls r1, r4, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #0x01
	adds r0, r0, r1
	lsls r0, r0, #0x03
	adds r2, #0x08
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	movs r1, #0x20
_080FDA04:
	bl func_08002A14
	ldr r3, _080FDA24 @ =0x02034FF8
	lsls r2, r5, #0x10
	asrs r2, r2, #0x10
	lsls r1, r2, #0x01
	adds r1, r1, r2
	lsls r1, r1, #0x03
	adds r3, #0x0C
	adds r1, r1, r3
	str r0, [r1, #0x00]
	pop {r4, r5}
	pop {r0}
	bx r0
_080FDA20: .4byte 0x09992F70
_080FDA24: .4byte 0x02034FF8
.syntax divided
