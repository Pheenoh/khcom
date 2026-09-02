.syntax unified
	.align 2, 0
	.global func_0807D380
	.thumb
	.thumb_func
	.type func_0807D380, %function
func_0807D380: @ 0807D380
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r4, #0x0
	adds r5, #0x64
	ldr r1, [r4, #0x38]
	adds r0, r5, #0x0
	adds r2, r4, #0x0
	bl func_08000D20
	ldr r1, [r4, #0x38]
	adds r0, r5, #0x0
	bl func_08000D28
	pop {r4, r5}
	pop {r0}
	bx r0
.syntax divided
