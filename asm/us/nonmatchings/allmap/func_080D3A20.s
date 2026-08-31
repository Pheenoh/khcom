.syntax unified
	.align 2, 0
	.global func_080D3A20
	.thumb
	.thumb_func
	.type func_080D3A20, %function
func_080D3A20: @ 080D3A20
	push {r4, lr}
	add sp, #-0x008
	ldr r2, _080D3A5C @ =0xFFFF0000
	ldr r1, [sp, #0x000]
	ands r1, r2
	movs r2, #0xD0
	orrs r1, r2
	ldr r4, _080D3A60 @ =0x0000FFFF
	ands r1, r4
	str r1, [sp, #0x000]
	ldr r1, _080D3A64 @ =0x0203C590
	ldrb r3, [r1, #0x06]
	ldr r2, _080D3A68 @ =0xFFFFFF00
	ldr r1, [sp, #0x004]
	ands r1, r2
	orrs r1, r3
	ands r1, r4
	movs r2, #0x80
	lsls r2, r2, #0x09
	orrs r1, r2
	str r1, [sp, #0x004]
	ldr r1, _080D3A6C @ =0x09EF4DC0
	mov r2, sp
	bl TaskCreate
	add sp, #0x008
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080D3A5C: .4byte 0xFFFF0000
_080D3A60: .4byte 0x0000FFFF
_080D3A64: .4byte 0x0203C590
_080D3A68: .4byte 0xFFFFFF00
_080D3A6C: .4byte 0x09EF4DC0
.syntax divided
