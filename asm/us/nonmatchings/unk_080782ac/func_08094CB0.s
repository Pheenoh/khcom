.syntax unified
	.align 2, 0
	.global func_08094CB0
	.thumb
	.thumb_func
	.type func_08094CB0, %function
func_08094CB0: @ 08094CB0
	adds r2, r0, #0x0
	ldr r1, [r2, #0x4C]
	ldr r0, _08094CD8 @ =0xFFFFF000
	cmp r1, r0
	blt _08094CE0
	movs r0, #0x80
	lsls r0, r0, #0x09
	cmp r1, r0
	bgt _08094CE0
	ldr r1, [r2, #0x50]
	ldr r0, _08094CDC @ =0xFFFFEC00
	cmp r1, r0
	blt _08094CE0
	movs r0, #0xC0
	lsls r0, r0, #0x08
	cmp r1, r0
	bgt _08094CE0
	movs r0, #0x01
	b _08094CE2
	.byte 0x00, 0x00
_08094CD8: .4byte 0xFFFFF000
_08094CDC: .4byte 0xFFFFEC00
_08094CE0:
	movs r0, #0x00
_08094CE2:
	bx lr
.syntax divided
