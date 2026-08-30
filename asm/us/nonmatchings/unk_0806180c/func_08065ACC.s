.syntax unified
	.align 2, 0
	.global func_08065ACC
	.thumb
	.thumb_func
	.type func_08065ACC, %function
func_08065ACC: @ 08065ACC
	cmp r1, #0x00
	ble _08065ADE
	movs r2, #0x00
_08065AD2:
	str r2, [r0, #0x00]
	strb r2, [r0, #0x05]
	adds r0, #0x08
	subs r1, #0x01
	cmp r1, #0x00
	bne _08065AD2
_08065ADE:
	bx lr
.syntax divided
