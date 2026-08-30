.syntax unified
	.align 2, 0
	.global func_0801227C
	.thumb
	.thumb_func
	.type func_0801227C, %function
func_0801227C: @ 0801227C
	push {lr}
	ldr r0, _0801229C @ =0x020348E8
	bl func_08000BA4
	ldr r0, _080122A0 @ =0x020348F8
	bl func_08000BA4
	ldr r0, _080122A4 @ =0x02034908
	bl func_08000BA4
	ldr r0, _080122A8 @ =0x02034918
	bl func_08000BA4
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_0801229C: .4byte 0x020348E8
_080122A0: .4byte 0x020348F8
_080122A4: .4byte 0x02034908
_080122A8: .4byte 0x02034918
.syntax divided
