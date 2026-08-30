.syntax unified
	.align 2, 0
	.global func_080CC284
	.thumb
	.thumb_func
	.type func_080CC284, %function
func_080CC284: @ 080CC284
	lsls r1, r1, #0x10
	lsrs r2, r1, #0x10
	lsls r0, r0, #0x10
	movs r1, #0x80
	lsls r1, r1, #0x0F
	adds r0, r0, r1
	movs r1, #0xB8
	lsls r1, r1, #0x11
	cmp r0, r1
	bhi _080CC2A8
	lsls r0, r2, #0x10
	asrs r1, r0, #0x10
	movs r0, #0x40
	negs r0, r0
	cmp r1, r0
	blt _080CC2A8
	cmp r1, #0xE0
	ble _080CC2AC
_080CC2A8:
	movs r0, #0x00
	b _080CC2AE
_080CC2AC:
	movs r0, #0x01
_080CC2AE:
	bx lr
.syntax divided
