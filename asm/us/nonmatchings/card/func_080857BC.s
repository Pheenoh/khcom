.syntax unified
	.align 2, 0
	.global func_080857BC
	.thumb
	.thumb_func
	.type func_080857BC, %function
func_080857BC: @ 080857BC
	adds r1, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x18
	lsls r0, r1, #0x03
	subs r0, r0, r1
	lsls r0, r0, #0x05
	ldr r1, _080857D0 @ =0x02039EA6
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
_080857D0: .4byte 0x02039EA6
.syntax divided
