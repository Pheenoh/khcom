.syntax unified
	.align 2, 0
	.global func_08002BAC
	.thumb
	.thumb_func
	.type func_08002BAC, %function
func_08002BAC: @ 08002BAC
	push {lr}
	adds r2, r0, #0x0
	adds r0, r1, #0x0
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x0B
	ldr r1, _08002BC8 @ =0x05000200
	adds r2, r2, r1
	adds r1, r2, #0x0
	movs r2, #0x20
	bl func_08005BE8
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08002BC8: .4byte 0x05000200
.syntax divided
