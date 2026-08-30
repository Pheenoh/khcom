.syntax unified
	.align 2, 0
	.global func_08110B10
	.thumb
	.thumb_func
	.type func_08110B10, %function
func_08110B10: @ 08110B10
	lsls r0, r0, #0x18
	lsrs r2, r0, #0x18
	lsls r1, r1, #0x18
	lsrs r0, r1, #0x18
	cmp r2, r0
	bls _08110B30
	subs r0, r2, r0
	cmp r0, #0x80
	ble _08110B26
	ldr r1, _08110B2C @ =0xFFFFFF00
	adds r0, r0, r1
_08110B26:
	negs r0, r0
	b _08110B3A
	.byte 0x00, 0x00
_08110B2C: .4byte 0xFFFFFF00
_08110B30:
	subs r0, r0, r2
	cmp r0, #0x80
	ble _08110B3A
	ldr r1, _08110B3C @ =0xFFFFFF00
	adds r0, r0, r1
_08110B3A:
	bx lr
_08110B3C: .4byte 0xFFFFFF00
.syntax divided
