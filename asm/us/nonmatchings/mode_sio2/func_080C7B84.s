.syntax unified
	.align 2, 0
	.global func_080C7B84
	.thumb
	.thumb_func
	.type func_080C7B84, %function
func_080C7B84: @ 080C7B84
	push {r4, lr}
	adds r1, r0, #0x0
	ldr r0, _080C7BC4 @ =0x02034D44
	ldrb r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080C7BBC
	ldr r0, _080C7BC8 @ =0x02034D48
	str r1, [r0, #0x00]
	movs r4, #0x00
_080C7B96:
	lsls r0, r4, #0x10
	lsrs r0, r0, #0x10
	movs r1, #0x00
	bl func_080062F4
	adds r4, #0x01
	cmp r4, #0x1F
	ble _080C7B96
	movs r0, #0x00
	movs r1, #0x10
	bl func_08006184
	movs r0, #0x00
	movs r1, #0x10
	bl func_080C75A4
	ldr r1, _080C7BC4 @ =0x02034D44
	movs r0, #0x01
	strb r0, [r1, #0x00]
_080C7BBC:
	pop {r4}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
_080C7BC4: .4byte 0x02034D44
_080C7BC8: .4byte 0x02034D48
.syntax divided
