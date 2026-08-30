.syntax unified
	.align 2, 0
	.global func_080DFF1C
	.thumb
	.thumb_func
	.type func_080DFF1C, %function
func_080DFF1C: @ 080DFF1C
	push {lr}
	ldr r3, [r0, #0x00]
	ldr r1, [r0, #0x04]
	ldr r2, [r0, #0x0C]
	adds r1, r1, r2
	adds r0, r3, #0x0
	bl func_080DFEBC
	pop {r1}
	bx r1
.syntax divided
