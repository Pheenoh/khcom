.syntax unified
	.align 2, 0
	.global func_080668F0
	.thumb
	.thumb_func
	.type func_080668F0, %function
func_080668F0: @ 080668F0
	push {lr}
	ldr r0, _08066900 @ =0x090D4180
	movs r1, #0xB4
	lsls r1, r1, #0x03
	bl func_080026A4
	pop {r1}
	bx r1
_08066900: .4byte 0x090D4180
.syntax divided
