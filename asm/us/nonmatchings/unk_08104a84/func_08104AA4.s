.syntax unified
	.align 2, 0
	.global func_08104AA4
	.thumb
	.thumb_func
	.type func_08104AA4, %function
func_08104AA4: @ 08104AA4
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	bgt _08104ABC
	ldr r1, _08104AB8 @ =0x02035C28
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r1, [r0, #0x00]
	b _08104AE2
	.byte 0x00, 0x00
_08104AB8: .4byte 0x02035C28
_08104ABC:
	movs r1, #0x00
	movs r2, #0x00
	ldr r3, _08104AE8 @ =0x02035C28
_08104AC2:
	lsls r0, r2, #0x10
	asrs r0, r0, #0x10
	lsls r2, r0, #0x01
	adds r2, r2, r3
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldrh r2, [r2, #0x00]
	adds r1, r1, r2
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, #0x01
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	ble _08104AC2
_08104AE2:
	lsls r0, r1, #0x10
	asrs r0, r0, #0x10
	bx lr
_08104AE8: .4byte 0x02035C28
.syntax divided
