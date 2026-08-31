.syntax unified
	.align 2, 0
	.global func_080D8AA4
	.thumb
	.thumb_func
	.type func_080D8AA4, %function
func_080D8AA4: @ 080D8AA4
	push {lr}
	add sp, #-0x008
	lsls r1, r1, #0x10
	lsls r2, r2, #0x10
	lsrs r1, r1, #0x10
	orrs r1, r2
	str r1, [sp, #0x004]
	str r3, [sp, #0x000]
	ldr r1, _080D8AC4 @ =0x09EF4FC8
	mov r2, sp
	bl TaskCreate
	add sp, #0x008
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D8AC4: .4byte 0x09EF4FC8
.syntax divided
