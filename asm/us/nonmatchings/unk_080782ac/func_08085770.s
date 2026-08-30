.syntax unified
	.align 2, 0
	.global func_08085770
	.thumb
	.thumb_func
	.type func_08085770, %function
func_08085770: @ 08085770
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	ldr r2, _08085784 @ =0x02039DE0
	lsls r1, r0, #0x03
	subs r1, r1, r0
	lsls r1, r1, #0x05
	adds r1, r1, r2
	adds r1, #0xDA
	ldrh r0, [r1, #0x00]
	bx lr
_08085784: .4byte 0x02039DE0
.syntax divided
