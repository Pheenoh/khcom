.syntax unified
	.align 2, 0
	.global func_08101740
	.thumb
	.thumb_func
	.type func_08101740, %function
func_08101740: @ 08101740
	push {lr}
	ldr r3, _08101760 @ =0x020357D8
	ldr r2, _08101764 @ =0x09993118
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x5C
	muls r0, r1
	adds r0, r0, r2
	ldrh r1, [r0, #0x0E]
	adds r0, r3, #0x0
	movs r2, #0x01
	bl func_080059A4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08101760: .4byte 0x020357D8
_08101764: .4byte 0x09993118
.syntax divided
