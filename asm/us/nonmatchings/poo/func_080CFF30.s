.syntax unified
	.align 2, 0
	.global func_080CFF30
	.thumb
	.thumb_func
	.type func_080CFF30, %function
func_080CFF30: @ 080CFF30
	push {lr}
	ldr r2, _080CFF48 @ =0x0203C420
	ldr r1, [r2, #0x08]
	ldr r0, _080CFF4C @ =0xFFFFE000
	cmp r1, r0
	blt _080CFF50
	adds r0, r2, #0x0
	bl func_080CFE34
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	b _080CFF52
_080CFF48: .4byte 0x0203C420
_080CFF4C: .4byte 0xFFFFE000
_080CFF50:
	movs r0, #0x00
_080CFF52:
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
