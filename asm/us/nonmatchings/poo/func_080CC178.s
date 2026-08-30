.syntax unified
	.align 2, 0
	.global func_080CC178
	.thumb
	.thumb_func
	.type func_080CC178, %function
func_080CC178: @ 080CC178
	push {lr}
	add sp, #-0x00C
	str r1, [sp, #0x000]
	str r2, [sp, #0x008]
	ldr r1, _080CC190 @ =0x09EF4958
	mov r2, sp
	bl func_08000E14
	add sp, #0x00C
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080CC190: .4byte 0x09EF4958
.syntax divided
