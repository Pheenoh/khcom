.syntax unified
	.align 2, 0
	.global func_080A5830
	.thumb
	.thumb_func
	.type func_080A5830, %function
func_080A5830: @ 080A5830
	push {lr}
	add sp, #-0x00C
	str r1, [sp, #0x000]
	str r2, [sp, #0x004]
	str r3, [sp, #0x008]
	ldr r1, _080A5848 @ =0x09EE8ED8
	mov r2, sp
	bl TaskCreate
	add sp, #0x00C
	pop {r0}
	bx r0
_080A5848: .4byte 0x09EE8ED8
.syntax divided
