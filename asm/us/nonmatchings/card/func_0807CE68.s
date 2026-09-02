.syntax unified
	.align 2, 0
	.global func_0807CE68
	.thumb
	.thumb_func
	.type func_0807CE68, %function
func_0807CE68: @ 0807CE68
	adds r2, r0, #0x0
	ldr r1, [r2, #0x4C]
	movs r0, #0x80
	lsls r0, r0, #0x09
	cmp r1, r0
	bgt _0807CE98
	ldr r0, _0807CE90 @ =0xFFFFF000
	cmp r1, r0
	blt _0807CE98
	ldr r1, [r2, #0x50]
	movs r0, #0xC0
	lsls r0, r0, #0x08
	cmp r1, r0
	bgt _0807CE98
	ldr r0, _0807CE94 @ =0xFFFFE000
	cmp r1, r0
	blt _0807CE98
	movs r0, #0x00
	b _0807CE9A
	.byte 0x00, 0x00
_0807CE90: .4byte 0xFFFFF000
_0807CE94: .4byte 0xFFFFE000
_0807CE98:
	movs r0, #0x01
_0807CE9A:
	bx lr
.syntax divided
