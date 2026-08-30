.syntax unified
	.align 2, 0
	.global func_08104B2C
	.thumb
	.thumb_func
	.type func_08104B2C, %function
func_08104B2C: @ 08104B2C
	push {lr}
	bl func_08104AEC
	ldr r2, _08104B44 @ =0x02035C10
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r1, #0x34
	muls r1, r0
	ldr r0, [r2, #0x00]
	adds r0, r0, r1
	pop {r1}
	bx r1
_08104B44: .4byte 0x02035C10
.syntax divided
