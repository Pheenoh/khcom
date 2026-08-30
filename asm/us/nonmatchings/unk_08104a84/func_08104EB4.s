.syntax unified
	.align 2, 0
	.global func_08104EB4
	.thumb
	.thumb_func
	.type func_08104EB4, %function
func_08104EB4: @ 08104EB4
	push {lr}
	ldr r0, _08104ED0 @ =0x02035E0C
	movs r1, #0x00
	ldsh r0, [r0, r1]
	ldr r1, _08104ED4 @ =0x02035E0E
	movs r2, #0x00
	ldsh r1, [r1, r2]
	bl func_08104E9C
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08104ED0: .4byte 0x02035E0C
_08104ED4: .4byte 0x02035E0E
.syntax divided
