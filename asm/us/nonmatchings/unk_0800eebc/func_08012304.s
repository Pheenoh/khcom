.syntax unified
	.align 2, 0
	.global func_08012304
	.thumb
	.thumb_func
	.type func_08012304, %function
func_08012304: @ 08012304
	push {r4, lr}
	ldr r1, [r0, #0x54]
	cmp r1, r0
	bne _0801231E
	adds r4, r1, #0x0
	adds r4, #0x18
	ldr r0, [r1, #0x00]
	bl _08012218
	adds r1, r0, #0x0
	adds r0, r4, #0x0
	bl func_08000D90
_0801231E:
	pop {r4}
	pop {r0}
	bx r0
.syntax divided
