.syntax unified
	.align 2, 0
	.global func_08004D74
	.thumb
	.thumb_func
	.type func_08004D74, %function
func_08004D74: @ 08004D74
	push {r4, lr}
	ldr r0, _08004DA8 @ =0x030074D8
	movs r4, #0x00
	strh r4, [r0, #0x00]
	movs r0, #0x00
	bl func_0800501C
	movs r0, #0x01
	bl func_0800501C
	movs r0, #0x02
	bl func_0800501C
	movs r0, #0x03
	bl func_0800501C
	movs r0, #0x00
	movs r1, #0x00
	bl func_080054C8
	ldr r0, _08004DAC @ =0x03007554
	strh r4, [r0, #0x00]
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_08004DA8: .4byte 0x030074D8
_08004DAC: .4byte 0x03007554
.syntax divided
