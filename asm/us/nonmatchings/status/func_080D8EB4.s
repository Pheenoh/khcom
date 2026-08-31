.syntax unified
	.align 2, 0
	.global func_080D8EB4
	.thumb
	.thumb_func
	.type func_080D8EB4, %function
func_080D8EB4: @ 080D8EB4
	push {r4, r5, r6, lr}
	add sp, #-0x008
	ldr r5, [sp, #0x018]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	lsls r3, r3, #0x10
	lsrs r3, r3, #0x10
	lsls r1, r1, #0x10
	ldr r6, _080D8EF4 @ =0x0000FFFF
	ldr r4, [sp, #0x004]
	ands r4, r6
	orrs r4, r1
	ldr r1, _080D8EF8 @ =0xFFFFFF00
	ands r4, r1
	orrs r4, r2
	str r4, [sp, #0x004]
	ldr r2, _080D8EFC @ =0xFFFF0000
	ldr r1, [sp, #0x000]
	ands r1, r2
	orrs r1, r3
	lsls r5, r5, #0x10
	ands r1, r6
	orrs r1, r5
	str r1, [sp, #0x000]
	ldr r1, _080D8F00 @ =0x09EF4FF8
	mov r2, sp
	bl TaskCreate
	add sp, #0x008
	pop {r4, r5, r6}
	pop {r1}
	bx r1
_080D8EF4: .4byte 0x0000FFFF
_080D8EF8: .4byte 0xFFFFFF00
_080D8EFC: .4byte 0xFFFF0000
_080D8F00: .4byte 0x09EF4FF8
.syntax divided
