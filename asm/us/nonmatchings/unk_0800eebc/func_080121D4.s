.syntax unified
	.align 2, 0
	.global func_080121D4
	.thumb
	.thumb_func
	.type func_080121D4, %function
func_080121D4: @ 080121D4
	push {r4, r5, lr}
	adds r2, r0, #0x0
	adds r5, r2, #0x0
	adds r5, #0x1C
	ldr r4, _080121F8 @ =0x02039BA0
	ldr r1, [r4, #0x00]
	adds r1, #0x58
	adds r0, r5, #0x0
	bl func_08000D20
	ldr r1, [r4, #0x00]
	adds r1, #0x58
	adds r0, r5, #0x0
	bl func_08000D28
	pop {r4, r5}
	pop {r0}
	bx r0
_080121F8: .4byte 0x02039BA0
.syntax divided
