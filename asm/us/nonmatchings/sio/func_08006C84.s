.syntax unified
	.align 2, 0
	.global func_08006C84
	.thumb
	.thumb_func
	.type func_08006C84, %function
func_08006C84: @ 08006C84
	push {r4, lr}
	adds r4, r0, #0x0
	ldr r0, _08006CA4 @ =0x03006C64
	str r4, [r0, #0x00]
	bl func_08006BB4
	lsls r0, r0, #0x10
	cmp r0, #0x00
	bne _08006C9C
	ldr r0, _08006CA8 @ =0x03006C74
	ldr r0, [r0, #0x00]
	str r4, [r0, #0x00]
_08006C9C:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08006CA4: .4byte 0x03006C64
_08006CA8: .4byte 0x03006C74
.syntax divided
