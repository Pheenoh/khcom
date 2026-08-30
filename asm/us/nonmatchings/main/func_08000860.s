.syntax unified
	.align 2, 0
	.global func_08000860
	.thumb
	.thumb_func
	.type func_08000860, %function
func_08000860: @ 08000860
	push {r4, r5, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	ldr r0, _0800087C @ =0x081213DC
	bl func_08000AD8
	ldr r2, _08000880 @ =0x030074A8
	adds r0, r4, #0x0
	adds r1, r5, #0x0
	bl func_08000800
	pop {r4, r5}
	pop {r0}
	bx r0
_0800087C: .4byte 0x081213DC
_08000880: .4byte 0x030074A8
.syntax divided
