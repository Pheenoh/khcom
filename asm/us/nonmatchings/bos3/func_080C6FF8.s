.syntax unified
	.align 2, 0
	.global func_080C6FF8
	.thumb
	.thumb_func
	.type func_080C6FF8, %function
func_080C6FF8: @ 080C6FF8
	ldr r0, _080C7004 @ =0x0203C3C0
	movs r1, #0x00
	strh r1, [r0, #0x00]
	ldr r0, _080C7008 @ =0x0203C3BC
	strh r1, [r0, #0x00]
	bx lr
_080C7004: .4byte 0x0203C3C0
_080C7008: .4byte 0x0203C3BC
.syntax divided
