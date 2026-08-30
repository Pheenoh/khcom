.syntax unified
	.align 2, 0
	.global func_080028A0
	.thumb
	.thumb_func
	.type func_080028A0, %function
func_080028A0: @ 080028A0
	push {lr}
	movs r1, #0x00
	str r1, [r0, #0x2C]
	adds r0, #0x0C
	ldr r1, _080028BC @ =0x030074C8
	ldr r1, [r1, #0x00]
	movs r2, #0xC0
	lsls r2, r2, #0x05
	adds r1, r1, r2
	bl func_08000C54
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080028BC: .4byte 0x030074C8
.syntax divided
