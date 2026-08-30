.syntax unified
	.align 2, 0
	.global func_080BD7F8
	.thumb
	.thumb_func
	.type func_080BD7F8, %function
func_080BD7F8: @ 080BD7F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0x0
	ldr r0, _080BD84C @ =0x0203ACC4
	movs r1, #0x00
	ldsh r0, [r0, r1]
	adds r0, #0x01
	lsls r0, r0, #0x0B
	negs r1, r0
	ldr r0, _080BD850 @ =0x0203ACD4
	movs r2, #0x00
	ldsh r0, [r0, r2]
	adds r0, #0x01
	lsls r0, r0, #0x0B
	negs r5, r0
	ldr r0, _080BD854 @ =0x0203ACC0
	movs r2, #0x00
	ldsh r0, [r0, r2]
	adds r0, #0x01
	lsls r0, r0, #0x0B
	negs r4, r0
	ldr r2, [r6, #0x00]
	ldr r0, _080BD858 @ =0x000259FF
	cmp r2, r0
	bgt _080BD8C8
	ldr r0, _080BD85C @ =0x000221FF
	cmp r2, r0
	bgt _080BD8A8
	ldr r0, _080BD860 @ =0x0001E9FF
	cmp r2, r0
	bgt _080BD884
	ldr r0, _080BD864 @ =0x0001B1FF
	cmp r2, r0
	bgt _080BD868
	movs r0, #0x00
	str r0, [r3, #0x00]
	movs r0, #0xD7
	lsls r0, r0, #0x09
	cmp r2, r0
	ble _080BD8D2
_080BD846:
	movs r0, #0x00
	b _080BD8D4
	.byte 0x00, 0x00
_080BD84C: .4byte 0x0203ACC4
_080BD850: .4byte 0x0203ACD4
_080BD854: .4byte 0x0203ACC0
_080BD858: .4byte 0x000259FF
_080BD85C: .4byte 0x000221FF
_080BD860: .4byte 0x0001E9FF
_080BD864: .4byte 0x0001B1FF
_080BD868:
	str r1, [r3, #0x00]
	ldr r0, _080BD880 @ =0x0001B5FF
	cmp r2, r0
	ble _080BD846
	movs r0, #0xF3
	lsls r0, r0, #0x09
	cmp r2, r0
	ble _080BD8D2
	cmp r1, r5
	beq _080BD8D2
	b _080BD846
	.byte 0x00, 0x00
_080BD880: .4byte 0x0001B5FF
_080BD884:
	str r5, [r3, #0x00]
	ldr r0, _080BD8A0 @ =0x0001EDFF
	cmp r2, r0
	bgt _080BD890
	cmp r1, r5
	bne _080BD846
_080BD890:
	ldr r1, [r6, #0x00]
	ldr r0, _080BD8A4 @ =0x00021E00
	cmp r1, r0
	ble _080BD8D2
	cmp r5, r4
	beq _080BD8D2
	b _080BD846
	.byte 0x00, 0x00
_080BD8A0: .4byte 0x0001EDFF
_080BD8A4: .4byte 0x00021E00
_080BD8A8:
	str r4, [r3, #0x00]
	ldr r0, _080BD8C0 @ =0x000225FF
	cmp r2, r0
	bgt _080BD8B4
	cmp r5, r4
	bne _080BD846
_080BD8B4:
	ldr r1, [r6, #0x00]
	ldr r0, _080BD8C4 @ =0x00025600
	cmp r1, r0
	ble _080BD8D2
	b _080BD846
	.byte 0x00, 0x00
_080BD8C0: .4byte 0x000225FF
_080BD8C4: .4byte 0x00025600
_080BD8C8:
	movs r0, #0x00
	str r0, [r3, #0x00]
	ldr r0, _080BD8DC @ =0x00025DFF
	cmp r2, r0
	ble _080BD846
_080BD8D2:
	movs r0, #0x01
_080BD8D4:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.byte 0x00, 0x00
_080BD8DC: .4byte 0x00025DFF
.syntax divided
