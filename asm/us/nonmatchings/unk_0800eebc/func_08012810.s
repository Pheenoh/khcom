.syntax unified
	.align 2, 0
	.global func_08012810
	.thumb
	.thumb_func
	.type func_08012810, %function
func_08012810: @ 08012810
	push {lr}
	ldr r0, _08012820 @ =0x02034928
	ldr r0, [r0, #0x00]
	bl func_080009C4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08012820: .4byte 0x02034928
.syntax divided
