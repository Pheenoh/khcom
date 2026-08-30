.syntax unified
	.align 2, 0
	.global func_08006BFC
	.thumb
	.thumb_func
	.type func_08006BFC, %function
func_08006BFC: @ 08006BFC
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _08006C1C @ =0x03006C70
	str r4, [r0, #0x00]
	bl func_08006BB4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _08006C14
	ldr r0, _08006C20 @ =0x03006C5C
	ldr r0, [r0, #0x00]
	str r4, [r0, #0x00]
_08006C14:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08006C1C: .4byte 0x03006C70
_08006C20: .4byte 0x03006C5C
.syntax divided
