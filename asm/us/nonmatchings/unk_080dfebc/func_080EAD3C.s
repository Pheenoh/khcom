.syntax unified
	.align 2, 0
	.global func_080EAD3C
	.thumb
	.thumb_func
	.type func_080EAD3C, %function
func_080EAD3C: @ 080EAD3C
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r5, #0x03
	ldr r0, _080EAD5C @ =0x02039D6C
	adds r4, r1, r0
	ldrb r0, [r4, #0x02]
	cmp r0, #0x00
	bne _080EAD60
	adds r0, r5, #0x0
	movs r1, #0x00
	movs r2, #0x0D
	bl func_080EAB20
	movs r0, #0x00
	b _080EAD7C
_080EAD5C: .4byte 0x02039D6C
_080EAD60:
	ldrb r1, [r4, #0x02]
	adds r0, r5, #0x0
	bl func_080EABB8
	ldr r1, [r4, #0x04]
	adds r0, r5, #0x0
	bl func_080EAC60
	ldrb r2, [r4, #0x00]
	adds r0, r5, #0x0
	movs r1, #0x00
	bl func_080EAB20
	movs r0, #0x01
_080EAD7C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
.syntax divided
