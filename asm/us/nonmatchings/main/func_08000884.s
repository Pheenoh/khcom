.syntax unified
	.align 2, 0
	.global func_08000884
	.thumb
	.thumb_func
	.type func_08000884, %function
func_08000884: @ 08000884
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _080008A0 @ =0x081213E8
	bl func_08000AE4
	ldr r2, _080008A4 @ =0x030074B8
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_08000800
	pop {r4, r5}
	pop {r0}
	bx r0
_080008A0: .4byte 0x081213E8
_080008A4: .4byte 0x030074B8
.syntax divided
