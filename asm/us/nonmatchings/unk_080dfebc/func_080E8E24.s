.syntax unified
	.align 2, 0
	.global func_080E8E24
	.thumb
	.thumb_func
	.type func_080E8E24, %function
func_080E8E24: @ 080E8E24
	push {r4, lr}
	adds r4, r0, #0x0
	movs r0, #0x00
	bl func_080E8D1C
	ldrb r0, [r0, #0x02]
	cmp r0, #0x04
	bne _080E8E5C
	ldr r2, _080E8E4C @ =0x02034F80
	ldrb r1, [r2, #0x03]
	ldrh r0, [r4, #0x02]
	cmp r1, r0
	bls _080E8E54
	subs r0, r1, r0
	strb r0, [r2, #0x03]
	ldr r1, _080E8E50 @ =0x02034F84
	ldr r1, [r1, #0x00]
	strb r0, [r1, #0x01]
	movs r0, #0x00
	b _080E8E68
_080E8E4C: .4byte 0x02034F80
_080E8E50: .4byte 0x02034F84
_080E8E54:
	ldr r0, _080E8E70 @ =0x02034F84
	ldr r1, [r0, #0x00]
	movs r0, #0x00
	strb r0, [r1, #0x01]
_080E8E5C:
	ldr r0, _080E8E70 @ =0x02034F84
	ldr r1, [r0, #0x00]
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	movs r0, #0x01
_080E8E68:
	pop {r4}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080E8E70: .4byte 0x02034F84
.syntax divided
