.syntax unified
	.align 2, 0
	.global func_0806180C
	.thumb
	.thumb_func
	.type func_0806180C, %function
func_0806180C: @ 0806180C
	push {lr}
	adds r1, r0, #0x0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, _08061820 @ =0x09EE274C
	bl func_080010CC
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08061820: .4byte 0x09EE274C
.syntax divided
