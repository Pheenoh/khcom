.syntax unified
	.align 2, 0
	.global func_080F7F94
	.thumb
	.thumb_func
	.type func_080F7F94, %function
func_080F7F94: @ 080F7F94
	ldr r2, _080F7FA8 @ =0x09991F54
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r2, #0x08
	adds r0, r0, r2
	ldr r0, [r0, #0x00]
	bx lr
_080F7FA8: .4byte 0x09991F54
.syntax divided
