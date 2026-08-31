.syntax unified
	.align 2, 0
	.global func_080C5B50
	.thumb
	.thumb_func
	.type func_080C5B50, %function
func_080C5B50: @ 080C5B50
	push {r4, r5, lr}
	ldr r2, _080C5B8C @ =0x0203C3A8
	movs r0, #0x00
	ldsb r0, [r2, r0]
	cmp r0, #0x00
	bne _080C5C18
	ldr r3, _080C5B90 @ =0x0203C3A0
	movs r0, #0x00
	ldsb r0, [r3, r0]
	cmp r0, #0x00
	bne _080C5BDC
	ldr r5, _080C5B94 @ =0x020397E0
	ldrh r1, [r5, #0x00]
	ldr r2, _080C5B98 @ =0x0000FEFE
	cmp r1, r2
	beq _080C5B76
	ldrh r0, [r5, #0x02]
	cmp r0, r2
	bne _080C5BA0
_080C5B76:
	ldr r0, _080C5B9C @ =0x0203C3B0
	ldrh r1, [r5, #0x04]
	ldrh r0, [r0, #0x00]
	cmp r1, r0
	bne _080C5C18
	ldrh r0, [r5, #0x06]
	cmp r0, r1
	bne _080C5C18
	movs r0, #0x01
	strb r0, [r3, #0x00]
	b _080C5C18
_080C5B8C: .4byte 0x0203C3A8
_080C5B90: .4byte 0x0203C3A0
_080C5B94: .4byte 0x020397E0
_080C5B98: .4byte 0x0000FEFE
_080C5B9C: .4byte 0x0203C3B0
_080C5BA0:
	ldr r4, _080C5BBC @ =0x0000AFAF
	cmp r1, r4
	beq _080C5BAA
	cmp r0, r4
	bne _080C5C18
_080C5BAA:
	bl func_080078A4
	ldr r0, _080C5BC0 @ =0x02039828
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	bne _080C5BC4
	ldrh r0, [r5, #0x00]
	b _080C5BC6
	.byte 0x00, 0x00
_080C5BBC: .4byte 0x0000AFAF
_080C5BC0: .4byte 0x02039828
_080C5BC4:
	ldrh r0, [r5, #0x02]
_080C5BC6:
	cmp r0, r4
	bne _080C5C18
	ldr r0, _080C5BD8 @ =0x0203BEAC
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C5C18
	bl _call_via_r0
	b _080C5C18
_080C5BD8: .4byte 0x0203BEAC
_080C5BDC:
	ldr r0, _080C5BFC @ =0x020397E0
	ldrh r1, [r0, #0x00]
	ldr r0, _080C5C00 @ =0x0000ECEC
	cmp r1, r0
	beq _080C5C08
	ldr r1, _080C5C04 @ =0x0203C38C
	ldrb r0, [r1, #0x00]
	adds r0, #0x01
	strb r0, [r1, #0x00]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r0, #0x0A
	ble _080C5C18
	movs r0, #0x01
	b _080C5C1A
	.byte 0x00, 0x00
_080C5BFC: .4byte 0x020397E0
_080C5C00: .4byte 0x0000ECEC
_080C5C04: .4byte 0x0203C38C
_080C5C08:
	movs r0, #0x01
	strb r0, [r2, #0x00]
	ldr r0, _080C5C20 @ =0x0203C3AC
	ldr r0, [r0, #0x00]
	cmp r0, #0x00
	beq _080C5C18
	bl _call_via_r0
_080C5C18:
	movs r0, #0x00
_080C5C1A:
	pop {r4, r5}
	pop {r1}
	bx r1
_080C5C20: .4byte 0x0203C3AC
.syntax divided
