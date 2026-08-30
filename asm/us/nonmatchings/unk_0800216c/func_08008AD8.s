.syntax unified
	.align 2, 0
	.global func_08008AD8
	.thumb
	.thumb_func
	.type func_08008AD8, %function
func_08008AD8: @ 08008AD8
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0x0
	adds r5, r1, #0x0
	adds r7, r2, #0x0
	lsls r3, r3, #0x10
	asrs r6, r3, #0x10
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	bl func_080089E0
	ldr r0, _08008B20 @ =0x0203C7BC
	ldr r3, [r0, #0x00]
	adds r0, r4, #0x0
	adds r1, r7, #0x0
	adds r2, r6, #0x0
	bl _call_via_r3
	ldr r0, _08008B24 @ =0x09EDB7E8
	ldr r1, [r0, #0x00]
	adds r0, r5, #0x0
	movs r2, #0x18
	bl func_08008A54
	lsls r0, r0, #0x18
	cmp r0, #0x00
	beq _08008B28
	adds r0, r7, #0x0
	adds r1, r6, #0x0
	bl func_08008A8C
	lsls r0, r0, #0x10
	movs r1, #0x01
	cmp r0, #0x00
	bne _08008B2A
	movs r1, #0x02
	b _08008B2A
_08008B20: .4byte 0x0203C7BC
_08008B24: .4byte 0x09EDB7E8
_08008B28:
	movs r1, #0x00
_08008B2A:
	adds r0, r1, #0x0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.byte 0x00, 0x00, 0x00, 0xB5, 0x0F, 0xF1, 0xD3, 0xFA, 0x01, 0xBC, 0x00, 0x47, 0x00, 0x00
.syntax divided
