.syntax unified
	.align 2, 0
	.global func_08111660
	.thumb
	.thumb_func
	.type func_08111660, %function
func_08111660: @ 08111660
	push {lr}
	ldr r0, [r0, #0x04]
	movs r1, #0x00
	strh r1, [r0, #0x00]
	strh r1, [r0, #0x10]
	adds r0, #0x44
	movs r1, #0x04
	movs r2, #0x00
	bl func_080059A4
	pop {r0}
	bx r0
.syntax divided
