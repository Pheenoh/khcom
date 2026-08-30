.syntax unified
	.align 2, 0
	.global func_080EAB20
	.thumb
	.thumb_func
	.type func_080EAB20, %function
func_080EAB20: @ 080EAB20
	push {r4, r5, lr}
	lsls r0, r0, #0x18
	lsrs r5, r0, #0x18
	lsls r1, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	adds r3, r2, #0x0
	movs r0, #0x01
	ands r5, r0
	cmp r1, #0x00
	beq _080EAB64
	ldr r0, _080EAB4C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080EAB54
	lsls r0, r2, #0x02
	adds r0, r0, r2
	lsls r0, r0, #0x06
	ldr r1, _080EAB50 @ =0x09963D64
	b _080EAB8C
_080EAB4C: .4byte 0x02039BB0
_080EAB50: .4byte 0x09963D64
_080EAB54:
	lsls r0, r2, #0x02
	adds r0, r0, r2
	lsls r0, r0, #0x06
	ldr r1, _080EAB60 @ =0x09961A64
	b _080EAB8C
	.byte 0x00, 0x00
_080EAB60: .4byte 0x09961A64
_080EAB64:
	ldr r0, _080EAB7C @ =0x02039BB0
	ldr r0, [r0, #0x08]
	movs r1, #0x08
	ands r0, r1
	cmp r0, #0x00
	beq _080EAB84
	lsls r0, r2, #0x02
	adds r0, r0, r2
	lsls r0, r0, #0x06
	ldr r1, _080EAB80 @ =0x09964EE4
	b _080EAB8C
	.byte 0x00, 0x00
_080EAB7C: .4byte 0x02039BB0
_080EAB80: .4byte 0x09964EE4
_080EAB84:
	lsls r0, r3, #0x02
	adds r0, r0, r3
	lsls r0, r0, #0x06
	ldr r1, _080EABB4 @ =0x09962BE4
_080EAB8C:
	adds r4, r0, r1
	movs r0, #0x01
	bl func_08005130
	adds r1, r0, #0x0
	lsls r0, r5, #0x02
	adds r0, r0, r5
	lsls r0, r0, #0x02
	subs r0, r0, r5
	lsls r0, r0, #0x05
	movs r2, #0xA0
	lsls r2, r2, #0x01
	adds r0, r0, r2
	adds r1, r1, r0
	adds r0, r4, #0x0
	bl func_080043B4
	pop {r4, r5}
	pop {r0}
	bx r0
_080EABB4: .4byte 0x09962BE4
.syntax divided
