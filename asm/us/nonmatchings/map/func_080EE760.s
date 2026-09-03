.syntax unified
	.align 2, 0
	.global func_080EE760
	.thumb
	.thumb_func
	.type func_080EE760, %function
func_080EE760: @ 080EE760
	push {r4, r5, lr}
	adds r5, r0, #0x0
	lsls r1, r1, #0x18
	lsrs r1, r1, #0x15
	ldr r0, _080EE77C @ =0x02039D6C
	adds r4, r1, r0
	ldrb r1, [r4, #0x02]
	cmp r1, #0x00
	bne _080EE780
	movs r2, #0xB2
	lsls r2, r2, #0x01
	adds r0, r5, r2
	strb r1, [r0, #0x00]
	b _080EE7A8
_080EE77C: .4byte 0x02039D6C
_080EE780:
	ldrb r0, [r4, #0x00]
	bl func_080EE5E0
	ldrb r0, [r4, #0x02]
	bl func_080EE62C
	ldr r0, [r4, #0x04]
	bl func_080EE6AC
	ldrb r0, [r4, #0x01]
	bl func_080DF804
	adds r1, r5, #0x0
	adds r1, #0x44
	bl func_08065B6C
	movs r2, #0xB2
	lsls r2, r2, #0x01
	adds r1, r5, r2
	strb r0, [r1, #0x00]
_080EE7A8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.byte 0x00, 0x00
.syntax divided
