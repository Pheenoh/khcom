.syntax unified
	.align 2, 0
	.global func_080F7F70
	.thumb
	.thumb_func
	.type func_080F7F70, %function
func_080F7F70: @ 080F7F70
	ldr r3, _080F7F90 @ =0x09991F54
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	lsls r2, r1, #0x03
	adds r2, r2, r1
	lsls r2, r2, #0x02
	adds r3, #0x04
	adds r2, r2, r3
	ldr r2, [r2, #0x00]
	ldr r0, [r0, #0x18]
	cmp r0, #0x00
	beq _080F7F8A
	negs r2, r2
_080F7F8A:
	adds r0, r2, #0x0
	bx lr
	.byte 0x00, 0x00
_080F7F90: .4byte 0x09991F54
.syntax divided
