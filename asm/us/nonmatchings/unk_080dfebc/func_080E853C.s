.syntax unified
	.align 2, 0
	.global func_080E853C
	.thumb
	.thumb_func
	.type func_080E853C, %function
func_080E853C: @ 080E853C
	push {r4, r5, lr}
	ldr r0, _080E8580 @ =0x02039BB0
	ldrb r5, [r0, #0x00]
	cmp r5, #0x00
	bne _080E8576
	ldr r4, _080E8584 @ =0x0203C7B8
	movs r0, #0xC0
	lsls r0, r0, #0x01
	bl EwramAlloc
	str r0, [r4, #0x00]
	ldr r0, _080E8588 @ =0x02034F78
	strb r5, [r0, #0x00]
	ldr r0, _080E858C @ =0x02034F79
	strb r5, [r0, #0x00]
	ldr r0, _080E8590 @ =0x02034F7A
	strh r5, [r0, #0x00]
	bl func_080E7DF8
	bl func_080E7E3C
	bl func_080E7FCC
	bl func_080E8058
	bl func_080E826C
	bl func_080E80E0
_080E8576:
	bl func_080E8594
	pop {r4, r5}
	pop {r0}
	bx r0
_080E8580: .4byte 0x02039BB0
_080E8584: .4byte 0x0203C7B8
_080E8588: .4byte 0x02034F78
_080E858C: .4byte 0x02034F79
_080E8590: .4byte 0x02034F7A
.syntax divided
