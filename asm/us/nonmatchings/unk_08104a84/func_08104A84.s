.syntax unified
	.align 2, 0
	.global func_08104A84
	.thumb
	.thumb_func
	.type func_08104A84, %function
func_08104A84: @ 08104A84
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, #0x03
	bgt _08104A9C
	ldr r1, _08104A98 @ =0x02035C20
	lsls r0, r0, #0x01
	adds r0, r0, r1
	ldrh r0, [r0, #0x00]
	b _08104A9E
	.byte 0x00, 0x00
_08104A98: .4byte 0x02035C20
_08104A9C:
	movs r0, #0x00
_08104A9E:
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	bx lr
.syntax divided
