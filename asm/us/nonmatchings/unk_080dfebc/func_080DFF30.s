.syntax unified
	.align 2, 0
	.global func_080DFF30
	.thumb
	.thumb_func
	.type func_080DFF30, %function
func_080DFF30: @ 080DFF30
	push {lr}
	ldr r3, [r0, #0x00]
	ldr r1, [r0, #0x04]
	ldr r0, [r0, #0x08]
	adds r1, r1, r0
	ldr r2, _080DFF48 @ =0xFFF00000
	adds r0, r3, #0x0
	bl func_080DFEBC
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080DFF48: .4byte 0xFFF00000
.syntax divided
