.syntax unified
	.align 2, 0
	.global func_08006C40
	.thumb
	.thumb_func
	.type func_08006C40, %function
func_08006C40: @ 08006C40
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _08006C60 @ =0x03006C6C
	str r4, [r0, #0x00]
	bl func_08006BB4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _08006C58
	ldr r0, _08006C64 @ =0x03006C58
	ldr r0, [r0, #0x00]
	str r4, [r0, #0x00]
_08006C58:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08006C60: .4byte 0x03006C6C
_08006C64: .4byte 0x03006C58
.syntax divided
