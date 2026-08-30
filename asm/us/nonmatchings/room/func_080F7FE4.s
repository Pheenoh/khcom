.syntax unified
	.align 2, 0
	.global func_080F7FE4
	.thumb
	.thumb_func
	.type func_080F7FE4, %function
func_080F7FE4: @ 080F7FE4
	ldr r2, _080F8004 @ =0x09991F54
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r0, r1, #0x03
	adds r0, r0, r1
	lsls r0, r0, #0x02
	adds r2, #0x0C
	adds r0, r0, r2
	ldr r1, _080F8008 @ =0x02039B84
	ldr r1, [r1, #0x00]
	adds r1, #0xD4
	ldr r0, [r0, #0x00]
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	bx lr
	.byte 0x00, 0x00
_080F8004: .4byte 0x09991F54
_080F8008: .4byte 0x02039B84
.syntax divided
