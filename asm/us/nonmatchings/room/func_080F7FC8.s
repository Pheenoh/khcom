.syntax unified
	.align 2, 0
	.global func_080F7FC8
	.thumb
	.thumb_func
	.type func_080F7FC8, %function
func_080F7FC8: @ 080F7FC8
	push {lr}
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	bl func_080F7F94
	ldr r1, _080F7FE0 @ =0x02039B84
	ldr r1, [r1, #0x00]
	adds r1, #0xD0
	ldr r1, [r1, #0x00]
	adds r0, r0, r1
	pop {r1}
	bx r1
_080F7FE0: .4byte 0x02039B84
.syntax divided
