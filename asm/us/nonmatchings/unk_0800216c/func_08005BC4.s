.syntax unified
	.align 2, 0
	.global func_08005BC4
	.thumb
	.thumb_func
	.type func_08005BC4, %function
func_08005BC4: @ 08005BC4
	push {lr}
	add sp, #-0x004
	movs r0, #0x00
	str r0, [sp, #0x000]
	ldr r0, _08005BE0 @ =0x03007568
	ldr r1, [r0, #0x00]
	ldr r2, _08005BE4 @ =0x05000166
	mov r0, sp
	bl func_08117FE8
	add sp, #0x004
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08005BE0: .4byte 0x03007568
_08005BE4: .4byte 0x05000166
.syntax divided
