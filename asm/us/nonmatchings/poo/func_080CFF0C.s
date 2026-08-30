.syntax unified
	.align 2, 0
	.global func_080CFF0C
	.thumb
	.thumb_func
	.type func_080CFF0C, %function
func_080CFF0C: @ 080CFF0C
	push {lr}
	ldr r1, _080CFF24 @ =0x0203C420
	ldr r0, [r1, #0x08]
	cmp r0, #0x00
	blt _080CFF28
	adds r0, r1, #0x0
	bl func_080CFE34
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080CFF2A
	.byte 0x00, 0x00
_080CFF24: .4byte 0x0203C420
_080CFF28:
	movs r0, #0x00
_080CFF2A:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
