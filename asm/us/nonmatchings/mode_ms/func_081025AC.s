.syntax unified
	.align 2, 0
	.global func_081025AC
	.thumb
	.thumb_func
	.type func_081025AC, %function
func_081025AC: @ 081025AC
	ldr r1, _081025CC @ =0x02035B68
	movs r2, #0x00
	adds r0, r1, #0x0
	adds r0, #0x3E
_081025B4:
	strh r2, [r0, #0x00]
	subs r0, #0x02
	cmp r0, r1
	bge _081025B4
	ldr r1, _081025D0 @ =0x02035BA8
	movs r2, #0x00
	adds r0, r1, #0x2
_081025C2:
	strh r2, [r0, #0x00]
	subs r0, #0x02
	cmp r0, r1
	bge _081025C2
	bx lr
_081025CC: .4byte 0x02035B68
_081025D0: .4byte 0x02035BA8
.syntax divided
