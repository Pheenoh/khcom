.syntax unified
	.align 2, 0
	.global func_0801CB44
	.thumb
	.thumb_func
	.type func_0801CB44, %function
func_0801CB44: @ 0801CB44
	push {lr}
	ldr r0, _0801CB64 @ =0x03007480
	ldr r0, [r0, #0x00]
	bl func_08006578
	bl func_0801CA88
	bl func_0801CB00
	bl func_0800ABD8
	ldr r1, _0801CB68 @ =0x02039DC0
	movs r0, #0x00
	str r0, [r1, #0x00]
	pop {r0}
	bx r0
_0801CB64: .4byte 0x03007480
_0801CB68: .4byte 0x02039DC0
.syntax divided
