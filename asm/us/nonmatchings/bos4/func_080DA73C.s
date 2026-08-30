.syntax unified
	.align 2, 0
	.global func_080DA73C
	.thumb
	.thumb_func
	.type func_080DA73C, %function
func_080DA73C: @ 080DA73C
	ldr r0, _080DA750 @ =0x02039B84
	ldr r0, [r0, #0x00]
	ldr r0, [r0, #0x7C]
	ldr r1, [r0, #0x08]
	ldr r0, _080DA754 @ =0x00023EFF
	cmp r1, r0
	ble _080DA758
	movs r0, #0x00
	b _080DA75A
	.byte 0x00, 0x00
_080DA750: .4byte 0x02039B84
_080DA754: .4byte 0x00023EFF
_080DA758:
	movs r0, #0x01
_080DA75A:
	bx lr
.syntax divided
