.syntax unified
	.align 2, 0
	.global func_080E0780
	.thumb
	.thumb_func
	.type func_080E0780, %function
func_080E0780: @ 080E0780
	push {r4, r5, r6, lr}
	ldr r0, _080E07A4 @ =0x02039BA0
	ldr r2, [r0, #0x00]
	adds r3, r2, #0x0
	adds r3, #0x6C
	movs r1, #0x00
	ldsh r0, [r3, r1]
	cmp r0, #0x00
	ble _080E07A8
	ldr r0, [r2, #0x70]
	movs r1, #0x01
	orrs r0, r1
	str r0, [r2, #0x70]
	ldrh r0, [r3, #0x00]
	subs r0, #0x01
	strh r0, [r3, #0x00]
	b _080E07B2
	.byte 0x00, 0x00
_080E07A4: .4byte 0x02039BA0
_080E07A8:
	ldr r0, [r2, #0x70]
	movs r1, #0x02
	negs r1, r1
	ands r0, r1
	str r0, [r2, #0x70]
_080E07B2:
	ldr r6, _080E0818 @ =0x0203C7AC
	ldr r0, [r6, #0x00]
	movs r5, #0x00
	str r5, [r0, #0x1C]
	ldr r4, _080E081C @ =0x02039BA0
	ldr r0, [r4, #0x00]
	adds r0, #0x78
	bl func_08000EA4
	ldr r0, [r6, #0x00]
	adds r0, #0x20
	strb r5, [r0, #0x00]
	ldr r4, [r4, #0x00]
	ldr r0, [r4, #0x70]
	movs r1, #0x80
	lsls r1, r1, #0x05
	ands r0, r1
	cmp r0, #0x00
	bne _080E07EC
	ldr r0, [r6, #0x00]
	ldr r0, [r0, #0x00]
	movs r1, #0x04
	ands r0, r1
	cmp r0, #0x00
	bne _080E07EC
	adds r0, r4, #0x0
	adds r0, #0x8C
	bl func_08000EA4
_080E07EC:
	ldr r4, _080E081C @ =0x02039BA0
	ldr r2, [r4, #0x00]
	ldr r0, [r2, #0x70]
	movs r1, #0x80
	ands r0, r1
	cmp r0, #0x00
	bne _080E0802
	adds r0, r2, #0x0
	adds r0, #0xB4
	bl func_08000EA4
_080E0802:
	ldr r0, [r4, #0x00]
	adds r0, #0xA0
	bl func_08000EA4
	ldr r0, [r4, #0x00]
	adds r0, #0xC8
	bl func_08000EA4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
_080E0818: .4byte 0x0203C7AC
_080E081C: .4byte 0x02039BA0
.syntax divided
