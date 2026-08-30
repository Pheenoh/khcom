.syntax unified
	.align 2, 0
	.global func_080FB8E8
	.thumb
	.thumb_func
	.type func_080FB8E8, %function
func_080FB8E8: @ 080FB8E8
	push {lr}
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	movs r0, #0x4C
	muls r1, r0
	ldr r0, _080FB904 @ =0x09992114
	adds r1, r1, r0
	movs r0, #0x01
	movs r2, #0x02
	movs r3, #0x02
	bl func_0800516C
	pop {r0}
	bx r0
_080FB904: .4byte 0x09992114
.syntax divided
