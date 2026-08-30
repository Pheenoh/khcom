.syntax unified
	.align 2, 0
	.global func_08008884
	.thumb
	.thumb_func
	.type func_08008884, %function
func_08008884: @ 08008884
	push {lr}
	ldr r0, _08008898 @ =0x02034080
	ldr r0, [r0, #0x00]
	bl func_0800833C
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_08008898: .4byte 0x02034080
.syntax divided
