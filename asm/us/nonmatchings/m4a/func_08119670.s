.syntax unified
	.align 2, 0
	.global func_08119670
	.thumb
	.thumb_func
	.type func_08119670, %function
func_08119670: @ 08119670
	push {r7, lr}
	add sp, #-0x008
	mov r7, sp
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x00]
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x44]
	adds r0, r1, #0x0
	b _08119684
_08119684:
	add sp, #0x008
	pop {r7}
	pop {r1}
	bx r1
.syntax divided
