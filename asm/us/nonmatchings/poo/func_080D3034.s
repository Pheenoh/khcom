.syntax unified
	.align 2, 0
	.global func_080D3034
	.thumb
	.thumb_func
	.type func_080D3034, %function
func_080D3034: @ 080D3034
	push {lr}
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	movs r1, #0x10
	asrs r0, r0, #0x10
	subs r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r2, #0x0
	bl func_08005810
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
