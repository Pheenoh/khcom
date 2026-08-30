.syntax unified
	.align 2, 0
	.global func_080B3A48
	.thumb
	.thumb_func
	.type func_080B3A48, %function
func_080B3A48: @ 080B3A48
	push {lr}
	movs r0, #0x00
	bl func_0800501C
	ldr r0, _080B3A64 @ =0x02034B4C
	ldr r0, [r0, #0x00]
	movs r1, #0xD8
	lsls r1, r1, #0x02
	adds r0, r0, r1
	movs r1, #0x00
	strb r1, [r0, #0x00]
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080B3A64: .4byte 0x02034B4C
.syntax divided
