.syntax unified
	.align 2, 0
	.global func_08085740
	.thumb
	.thumb_func
	.type func_08085740, %function
func_08085740: @ 08085740
	ldr r0, _08085750 @ =0x02034AB0
	ldrb r1, [r0, #0x00]
	lsls r0, r1, #0x03
	subs r0, r0, r1
	lsls r0, r0, #0x05
	ldr r1, _08085754 @ =0x02039DE0
	adds r0, r0, r1
	bx lr
_08085750: .4byte 0x02034AB0
_08085754: .4byte 0x02039DE0
.syntax divided
