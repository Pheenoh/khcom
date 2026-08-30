.syntax unified
	.align 2, 0
	.global func_08085758
	.thumb
	.thumb_func
	.type func_08085758, %function
func_08085758: @ 08085758
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r1, #0x03
	subs r0, r0, r1
	lsls r0, r0, #0x05
	ldr r1, _0808576C @ =0x02039DE0
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
_0808576C: .4byte 0x02039DE0
.syntax divided
