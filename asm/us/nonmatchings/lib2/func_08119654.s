.syntax unified
	.align 2, 0
	.global func_08119654
	.thumb
	.thumb_func
	.type func_08119654, %function
func_08119654: @ 08119654
	push {r7, lr}
	add sp, #-0x008
	mov r7, sp
	str r0, [r7, #0x00]
	ldr r0, [r7, #0x00]
	str r0, [r7, #0x04]
	ldr r0, [r7, #0x04]
	ldr r1, [r0, #0x40]
	adds r0, r1, #0x0
	b _08119668
_08119668:
	add sp, #0x008
	pop {r7}
	pop {r1}
	bx r1
.syntax divided
