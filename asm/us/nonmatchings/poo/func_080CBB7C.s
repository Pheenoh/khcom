.syntax unified
	.align 2, 0
	.global func_080CBB7C
	.thumb
	.thumb_func
	.type func_080CBB7C, %function
func_080CBB7C: @ 080CBB7C
	ldr r0, _080CBB88 @ =0x02034DEC
	ldrh r0, [r0, #0x00]
	subs r0, #0x01
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	bx lr
_080CBB88: .4byte 0x02034DEC
.syntax divided
