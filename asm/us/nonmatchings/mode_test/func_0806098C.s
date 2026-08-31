.syntax unified
	.align 2, 0
	.global func_0806098C
	.thumb
	.thumb_func
	.type func_0806098C, %function
func_0806098C: @ 0806098C
	push {lr}
	ldr r0, _0806099C @ =0x02034A1C
	ldr r0, [r0, #0x00]
	bl EwramFree
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0806099C: .4byte 0x02034A1C
.syntax divided
